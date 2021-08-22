// Copyright (C) 2018 The Android Open Source Project
// Copyright (C) 2018 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#pragma once

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>
#include "goldfish_vk_private_defs.h"

template <class T> struct vk_get_vk_struct_id;

#define REGISTER_VK_STRUCT_ID(T, ID) \
    template <> struct vk_get_vk_struct_id<T> { static constexpr VkStructureType id = ID; };

REGISTER_VK_STRUCT_ID(VkBufferCreateInfo, VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO);
REGISTER_VK_STRUCT_ID(VkImageCreateInfo, VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO);
REGISTER_VK_STRUCT_ID(VkImageFormatProperties2, VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2);
REGISTER_VK_STRUCT_ID(VkNativeBufferANDROID, VK_STRUCTURE_TYPE_NATIVE_BUFFER_ANDROID);
REGISTER_VK_STRUCT_ID(VkExternalMemoryBufferCreateInfo, VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO);
REGISTER_VK_STRUCT_ID(VkExternalMemoryImageCreateInfo, VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO);
REGISTER_VK_STRUCT_ID(VkMemoryAllocateInfo, VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO);
REGISTER_VK_STRUCT_ID(VkMemoryDedicatedAllocateInfo, VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO);
REGISTER_VK_STRUCT_ID(VkMemoryDedicatedRequirements, VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS);
REGISTER_VK_STRUCT_ID(VkExportMemoryAllocateInfo, VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO);
REGISTER_VK_STRUCT_ID(VkMemoryRequirements2, VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2);
REGISTER_VK_STRUCT_ID(VkSemaphoreCreateInfo, VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO);
REGISTER_VK_STRUCT_ID(VkExportSemaphoreCreateInfoKHR, VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO_KHR);
REGISTER_VK_STRUCT_ID(VkSamplerYcbcrConversionCreateInfo, VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO);
REGISTER_VK_STRUCT_ID(VkImportColorBufferGOOGLE, VK_STRUCTURE_TYPE_IMPORT_COLOR_BUFFER_GOOGLE);
REGISTER_VK_STRUCT_ID(VkImageViewCreateInfo, VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO);
REGISTER_VK_STRUCT_ID(VkImportMemoryZirconHandleInfoFUCHSIA, VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA);
REGISTER_VK_STRUCT_ID(VkSamplerCreateInfo, VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO);
REGISTER_VK_STRUCT_ID(VkSamplerYcbcrConversionInfo, VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO);
REGISTER_VK_STRUCT_ID(VkImportPhysicalAddressGOOGLE, VK_STRUCTURE_TYPE_IMPORT_PHYSICAL_ADDRESS_GOOGLE);
REGISTER_VK_STRUCT_ID(VkImportBufferGOOGLE, VK_STRUCTURE_TYPE_IMPORT_BUFFER_GOOGLE);

#ifdef _WIN32
REGISTER_VK_STRUCT_ID(VkImportMemoryWin32HandleInfoKHR, VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR);
#else
REGISTER_VK_STRUCT_ID(VkImportMemoryFdInfoKHR, VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR);
#endif

REGISTER_VK_STRUCT_ID(VkPhysicalDeviceImageFormatInfo2, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2);
REGISTER_VK_STRUCT_ID(VkPhysicalDeviceExternalImageFormatInfo, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO);
REGISTER_VK_STRUCT_ID(VkExternalImageFormatProperties, VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES);
REGISTER_VK_STRUCT_ID(VkPhysicalDeviceFeatures2, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2);
REGISTER_VK_STRUCT_ID(VkPhysicalDeviceDescriptorIndexingFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT);
REGISTER_VK_STRUCT_ID(VkSemaphoreTypeCreateInfoKHR, VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO_KHR)
REGISTER_VK_STRUCT_ID(VkTimelineSemaphoreSubmitInfoKHR, VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO_KHR)
REGISTER_VK_STRUCT_ID(VkBindSparseInfo, VK_STRUCTURE_TYPE_BIND_SPARSE_INFO)

#undef REGISTER_VK_STRUCT_ID
