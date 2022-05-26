/*
 * Copyright © 2017 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */
#ifndef VK_UTIL_H
#define VK_UTIL_H

/* common inlines and macros for vulkan drivers */

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <vulkan/vulkan.h>

#include <chrono>
#include <functional>
#include <memory>
#include <optional>
#include <string>
#include <thread>
#include <tuple>
#include <type_traits>
#include <vector>

#include "VulkanDispatch.h"
#include "base/Lock.h"
#include "common/vk_struct_id.h"
#include "host-common/GfxstreamFatalError.h"
#include "host-common/logging.h"
#include "vk_fn_info.h"

struct vk_struct_common {
    VkStructureType sType;
    struct vk_struct_common* pNext;
};

struct vk_struct_chain_iterator {
    vk_struct_common* value;
};

#define vk_foreach_struct(__iter, __start)                                              \
    for (struct vk_struct_common* __iter = (struct vk_struct_common*)(__start); __iter; \
         __iter = __iter->pNext)

#define vk_foreach_struct_const(__iter, __start)                                            \
    for (const struct vk_struct_common* __iter = (const struct vk_struct_common*)(__start); \
         __iter; __iter = __iter->pNext)

/**
 * A wrapper for a Vulkan output array. A Vulkan output array is one that
 * follows the convention of the parameters to
 * vkGetPhysicalDeviceQueueFamilyProperties().
 *
 * Example Usage:
 *
 *    VkResult
 *    vkGetPhysicalDeviceQueueFamilyProperties(
 *       VkPhysicalDevice           physicalDevice,
 *       uint32_t*                  pQueueFamilyPropertyCount,
 *       VkQueueFamilyProperties*   pQueueFamilyProperties)
 *    {
 *       VK_OUTARRAY_MAKE(props, pQueueFamilyProperties,
 *                         pQueueFamilyPropertyCount);
 *
 *       vk_outarray_append(&props, p) {
 *          p->queueFlags = ...;
 *          p->queueCount = ...;
 *       }
 *
 *       vk_outarray_append(&props, p) {
 *          p->queueFlags = ...;
 *          p->queueCount = ...;
 *       }
 *
 *       return vk_outarray_status(&props);
 *    }
 */
struct __vk_outarray {
    /** May be null. */
    void* data;

    /**
     * Capacity, in number of elements. Capacity is unlimited (UINT32_MAX) if
     * data is null.
     */
    uint32_t cap;

    /**
     * Count of elements successfully written to the array. Every write is
     * considered successful if data is null.
     */
    uint32_t* filled_len;

    /**
     * Count of elements that would have been written to the array if its
     * capacity were sufficient. Vulkan functions often return VK_INCOMPLETE
     * when `*filled_len < wanted_len`.
     */
    uint32_t wanted_len;
};

static inline void __vk_outarray_init(struct __vk_outarray* a, void* data, uint32_t* len) {
    a->data = data;
    a->cap = *len;
    a->filled_len = len;
    *a->filled_len = 0;
    a->wanted_len = 0;

    if (a->data == NULL) a->cap = UINT32_MAX;
}

static inline VkResult __vk_outarray_status(const struct __vk_outarray* a) {
    if (*a->filled_len < a->wanted_len)
        return VK_INCOMPLETE;
    else
        return VK_SUCCESS;
}

static inline void* __vk_outarray_next(struct __vk_outarray* a, size_t elem_size) {
    void* p = NULL;

    a->wanted_len += 1;

    if (*a->filled_len >= a->cap) return NULL;

    if (a->data != NULL) p = ((uint8_t*)a->data) + (*a->filled_len) * elem_size;

    *a->filled_len += 1;

    return p;
}

#define vk_outarray(elem_t)        \
    struct {                       \
        struct __vk_outarray base; \
        elem_t meta[];             \
    }

#define vk_outarray_typeof_elem(a) __typeof__((a)->meta[0])
#define vk_outarray_sizeof_elem(a) sizeof((a)->meta[0])

#define vk_outarray_init(a, data, len) __vk_outarray_init(&(a)->base, (data), (len))

#define VK_OUTARRAY_MAKE(name, data, len)    \
    vk_outarray(__typeof__((data)[0])) name; \
    vk_outarray_init(&name, (data), (len))

#define vk_outarray_status(a) __vk_outarray_status(&(a)->base)

#define vk_outarray_next(a) \
    ((vk_outarray_typeof_elem(a)*)__vk_outarray_next(&(a)->base, vk_outarray_sizeof_elem(a)))

/**
 * Append to a Vulkan output array.
 *
 * This is a block-based macro. For example:
 *
 *    vk_outarray_append(&a, elem) {
 *       elem->foo = ...;
 *       elem->bar = ...;
 *    }
 *
 * The array `a` has type `vk_outarray(elem_t) *`. It is usually declared with
 * VK_OUTARRAY_MAKE(). The variable `elem` is block-scoped and has type
 * `elem_t *`.
 *
 * The macro unconditionally increments the array's `wanted_len`. If the array
 * is not full, then the macro also increment its `filled_len` and then
 * executes the block. When the block is executed, `elem` is non-null and
 * points to the newly appended element.
 */
#define vk_outarray_append(a, elem) \
    for (vk_outarray_typeof_elem(a)* elem = vk_outarray_next(a); elem != NULL; elem = NULL)

static inline void* __vk_find_struct(void* start, VkStructureType sType) {
    vk_foreach_struct(s, start) {
        if (s->sType == sType) return s;
    }

    return NULL;
}

template <class T, class H>
T* vk_find_struct(H* head) {
    (void)vk_get_vk_struct_id<H>::id;
    return static_cast<T*>(__vk_find_struct(static_cast<void*>(head), vk_get_vk_struct_id<T>::id));
}

template <class T, class H>
const T* vk_find_struct(const H* head) {
    (void)vk_get_vk_struct_id<H>::id;
    return static_cast<const T*>(__vk_find_struct(const_cast<void*>(static_cast<const void*>(head)),
                                                  vk_get_vk_struct_id<T>::id));
}

uint32_t vk_get_driver_version(void);

uint32_t vk_get_version_override(void);

#define VK_EXT_OFFSET (1000000000UL)
#define VK_ENUM_EXTENSION(__enum) \
    ((__enum) >= VK_EXT_OFFSET ? ((((__enum)-VK_EXT_OFFSET) / 1000UL) + 1) : 0)
#define VK_ENUM_OFFSET(__enum) ((__enum) >= VK_EXT_OFFSET ? ((__enum) % 1000) : (__enum))

template <class T>
T vk_make_orphan_copy(const T& vk_struct) {
    T copy = vk_struct;
    copy.pNext = NULL;
    return copy;
}

template <class T>
vk_struct_chain_iterator vk_make_chain_iterator(T* vk_struct) {
    vk_get_vk_struct_id<T>::id;
    vk_struct_chain_iterator result = {reinterpret_cast<vk_struct_common*>(vk_struct)};
    return result;
}

template <class T>
void vk_append_struct(vk_struct_chain_iterator* i, T* vk_struct) {
    vk_get_vk_struct_id<T>::id;

    vk_struct_common* p = i->value;
    if (p->pNext) {
        ::abort();
    }

    p->pNext = reinterpret_cast<vk_struct_common*>(vk_struct);
    vk_struct->pNext = NULL;

    *i = vk_make_chain_iterator(vk_struct);
}

template <class S, class T>
void vk_struct_chain_remove(S* unwanted, T* vk_struct) {
    if (!unwanted) return;

    vk_foreach_struct(current, vk_struct) {
        if ((void*)unwanted == current->pNext) {
            const vk_struct_common* unwanted_as_common =
                reinterpret_cast<const vk_struct_common*>(unwanted);
            current->pNext = unwanted_as_common->pNext;
        }
    }
}

#define VK_CHECK(x)                                                     \
    do {                                                                \
        VkResult err = x;                                               \
        if (err != VK_SUCCESS) {                                        \
            if (err == VK_ERROR_DEVICE_LOST) {                          \
                ::vk_util::getVkCheckCallbacks().callIfExists(          \
                    &::vk_util::VkCheckCallbacks::onVkErrorDeviceLost); \
            }                                                           \
            GFXSTREAM_ABORT(::emugl::FatalError(err));                  \
        }                                                               \
    } while (0)

namespace vk_util {

inline VkResult waitForVkQueueIdleWithRetry(const VulkanDispatch& vk, VkQueue queue) {
    using namespace std::chrono_literals;
    constexpr uint32_t retryLimit = 5;
    constexpr std::chrono::duration waitInterval = 4ms;
    VkResult res = vk.vkQueueWaitIdle(queue);
    for (uint32_t retryTimes = 1; retryTimes < retryLimit && res == VK_TIMEOUT; retryTimes++) {
        INFO("VK_TIMEOUT returned from vkQueueWaitIdle with %" PRIu32 " attempt. Wait for %" PRIu32
             "ms before another attempt.",
             retryTimes,
             static_cast<uint32_t>(
                 std::chrono::duration_cast<std::chrono::milliseconds>(waitInterval).count()));
        std::this_thread::sleep_for(waitInterval);
        res = vk.vkQueueWaitIdle(queue);
    }
    return res;
}

typedef struct {
    std::function<void()> onVkErrorDeviceLost;
} VkCheckCallbacks;

template <class T>
class CallbacksWrapper {
   public:
    CallbacksWrapper(std::unique_ptr<T> callbacks) : mCallbacks(std::move(callbacks)) {}
    // function should be a member function pointer to T.
    template <class U, class... Args>
    void callIfExists(U function, Args&&... args) const {
        if (mCallbacks && (*mCallbacks.*function)) {
            (*mCallbacks.*function)(std::forward(args)...);
        }
    }

   private:
    std::unique_ptr<T> mCallbacks;
};

void setVkCheckCallbacks(std::unique_ptr<VkCheckCallbacks>);
const CallbacksWrapper<VkCheckCallbacks>& getVkCheckCallbacks();

class CRTPBase {};

template <class T, class U = CRTPBase>
class FindMemoryType : public U {
   protected:
    std::optional<uint32_t> findMemoryType(uint32_t typeFilter,
                                           VkMemoryPropertyFlags properties) const {
        const T& self = static_cast<const T&>(*this);
        VkPhysicalDeviceMemoryProperties memProperties;
        self.m_vk.vkGetPhysicalDeviceMemoryProperties(self.m_vkPhysicalDevice, &memProperties);

        for (uint32_t i = 0; i < memProperties.memoryTypeCount; i++) {
            if ((typeFilter & (1 << i)) &&
                (memProperties.memoryTypes[i].propertyFlags & properties) == properties) {
                return i;
            }
        }
        return std::nullopt;
    }
};

template <class T, class U = CRTPBase>
class RunSingleTimeCommand : public U {
   protected:
    void runSingleTimeCommands(VkQueue queue, std::shared_ptr<android::base::Lock> queueLock,
                               std::function<void(const VkCommandBuffer& commandBuffer)> f) const {
        const T& self = static_cast<const T&>(*this);
        VkCommandBuffer cmdBuff;
        VkCommandBufferAllocateInfo cmdBuffAllocInfo = {
            .sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
            .commandPool = self.m_vkCommandPool,
            .level = VK_COMMAND_BUFFER_LEVEL_PRIMARY,
            .commandBufferCount = 1};
        VK_CHECK(self.m_vk.vkAllocateCommandBuffers(self.m_vkDevice, &cmdBuffAllocInfo, &cmdBuff));
        VkCommandBufferBeginInfo beginInfo = {.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO,
                                              .flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT};
        VK_CHECK(self.m_vk.vkBeginCommandBuffer(cmdBuff, &beginInfo));
        f(cmdBuff);
        VK_CHECK(self.m_vk.vkEndCommandBuffer(cmdBuff));
        VkSubmitInfo submitInfo = {.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO,
                                   .commandBufferCount = 1,
                                   .pCommandBuffers = &cmdBuff};
        {
            std::unique_ptr<android::base::AutoLock> lock = nullptr;
            if (queueLock) {
                lock = std::make_unique<android::base::AutoLock>(*queueLock);
            }
            VK_CHECK(self.m_vk.vkQueueSubmit(queue, 1, &submitInfo, VK_NULL_HANDLE));
            VK_CHECK(self.m_vk.vkQueueWaitIdle(queue));
        }
        self.m_vk.vkFreeCommandBuffers(self.m_vkDevice, self.m_vkCommandPool, 1, &cmdBuff);
    }
};
template <class T, class U = CRTPBase>
class RecordImageLayoutTransformCommands : public U {
   protected:
    void recordImageLayoutTransformCommands(VkCommandBuffer cmdBuff, VkImage image,
                                            VkImageLayout oldLayout,
                                            VkImageLayout newLayout) const {
        const T& self = static_cast<const T&>(*this);
        VkImageMemoryBarrier imageBarrier = {
            .sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
            .srcAccessMask = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT,
            .dstAccessMask = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT,
            .oldLayout = oldLayout,
            .newLayout = newLayout,
            .srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
            .dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
            .image = image,
            .subresourceRange = {.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT,
                                 .baseMipLevel = 0,
                                 .levelCount = 1,
                                 .baseArrayLayer = 0,
                                 .layerCount = 1}};
        self.m_vk.vkCmdPipelineBarrier(cmdBuff, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                       VK_PIPELINE_STAGE_ALL_COMMANDS_BIT, 0, 0, nullptr, 0,
                                       nullptr, 1, &imageBarrier);
    }
};

template <class T>
typename vk_fn_info::GetVkFnInfo<T>::type getVkInstanceProcAddrWithFallback(
    const std::vector<std::function<std::remove_pointer_t<PFN_vkGetInstanceProcAddr>>>&
        vkGetInstanceProcAddrs,
    VkInstance instance) {
    for (const auto& vkGetInstanceProcAddr : vkGetInstanceProcAddrs) {
        if (!vkGetInstanceProcAddr) {
            continue;
        }
        PFN_vkVoidFunction resWithCurrentVkGetInstanceProcAddr = std::apply(
            [&vkGetInstanceProcAddr, instance](auto&&... names) -> PFN_vkVoidFunction {
                for (const char* name : {names...}) {
                    if (PFN_vkVoidFunction resWithCurrentName =
                            vkGetInstanceProcAddr(instance, name)) {
                        return resWithCurrentName;
                    }
                }
                return nullptr;
            },
            vk_fn_info::GetVkFnInfo<T>::names);
        if (resWithCurrentVkGetInstanceProcAddr) {
            return reinterpret_cast<typename vk_fn_info::GetVkFnInfo<T>::type>(
                resWithCurrentVkGetInstanceProcAddr);
        }
    }
    return nullptr;
}
}  // namespace vk_util

#endif /* VK_UTIL_H */
