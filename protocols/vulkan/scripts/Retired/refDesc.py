#!/usr/bin/python3
#
# Copyright 2016-2021 The Khronos Group Inc.
#
# SPDX-License-Identifier: Apache-2.0

refDesc = {}

# These are extracted from the original handwritten ref pages
# This is a one-time measure to inject // refBegin markup into the spec.

refDesc['vkAcquireNextImageKHR'] = 'Retrieve the index of the next available presentable image'
refDesc['vkAllocateCommandBuffers'] = 'Allocate command buffers from an existing command pool'
refDesc['vkAllocateDescriptorSets'] = 'Allocate one or more descriptor sets'
refDesc['vkAllocateMemory'] = 'Allocate GPU memory'
refDesc['VkAllocationCallbacks'] = 'Structure containing callback function pointers for memory allocation'
refDesc['vkBeginCommandBuffer'] = 'Start recording a command buffer'
refDesc['vkBindBufferMemory'] = 'Bind device memory to a buffer object'
refDesc['vkBindImageMemory'] = 'Bind device memory to an image object'
refDesc['VkBufferCreateFlags'] = 'Buffer object creation flags'
refDesc['VkBufferCreateInfo'] = 'Structure specifying the parameters of a newly created buffer object'
refDesc['VkBufferMemoryBarrier'] = 'Structure specifying the parameters of a buffer memory barrier'
refDesc['VkBufferUsageFlags'] = 'Buffer object usage flags'
refDesc['vkCmdBeginQuery'] = 'Begin a query'
refDesc['vkCmdBeginRenderPass'] = 'Begin a new render pass'
refDesc['vkCmdBindDescriptorSets'] = 'Binds descriptor sets to a command buffer'
refDesc['vkCmdBindIndexBuffer'] = 'Bind an index buffer to a command buffer'
refDesc['vkCmdBindPipeline'] = 'Bind a pipeline object to a command buffer'
refDesc['vkCmdBindVertexBuffers'] = 'Bind vertex buffers to a command buffer'
refDesc['vkCmdBlitImage'] = 'Copy regions of an image, potentially performing format conversion,'
refDesc['vkCmdClearAttachments'] = 'Clear regions within currently bound framebuffer attachments'
refDesc['vkCmdClearColorImage'] = 'Clear regions of a color image'
refDesc['vkCmdClearDepthStencilImage'] = 'Fill regions of a combined depth-stencil image'
refDesc['vkCmdCopyBufferToImage'] = 'Copy data from a buffer into an image'
refDesc['vkCmdCopyBuffer'] = 'Copy data between buffer regions'
refDesc['vkCmdCopyImageToBuffer'] = 'Copy image data into a buffer'
refDesc['vkCmdCopyImage'] = 'Copy data between images'
refDesc['vkCmdCopyQueryPoolResults'] = 'Copy the results of queries in a query pool to a buffer object'
refDesc['vkCmdDispatchIndirect'] = 'Dispatch compute work items using indirect parameters'
refDesc['vkCmdDispatch'] = 'Dispatch compute work items'
refDesc['vkCmdDrawIndexedIndirect'] = 'Perform an indexed indirect draw'
refDesc['vkCmdDrawIndexed'] = 'Issue an indexed draw into a command buffer'
refDesc['vkCmdDrawIndirect'] = 'Issue an indirect draw into a command buffer'
refDesc['vkCmdDraw'] = 'Draw primitives'
refDesc['vkCmdEndQuery'] = 'Ends a query'
refDesc['vkCmdEndRenderPass'] = 'End the current render pass'
refDesc['vkCmdExecuteCommands'] = 'Execute a secondary command buffer from a primary command buffer'
refDesc['vkCmdFillBuffer'] = 'Fill a region of a buffer with a fixed value'
refDesc['vkCmdNextSubpass'] = 'Transition to the next subpass of a render pass'
refDesc['vkCmdPipelineBarrier'] = 'Insert a set of execution and memory barriers'
refDesc['vkCmdPushConstants'] = 'Update the values of push constants'
refDesc['vkCmdResetEvent'] = 'Reset an event object to non-signaled state'
refDesc['vkCmdResetQueryPool'] = 'Reset queries in a query pool'
refDesc['vkCmdResolveImage'] = 'Resolve regions of an image'
refDesc['vkCmdSetBlendConstants'] = 'Set the values of blend constants'
refDesc['vkCmdSetDepthBias'] = 'Set the depth bias dynamic state'
refDesc['vkCmdSetDepthBounds'] = 'Set the depth bounds test values for a command buffer'
refDesc['vkCmdSetEvent'] = 'Set an event object to signaled state'
refDesc['vkCmdSetLineWidth'] = 'Set the dynamic line width state'
refDesc['vkCmdSetScissor'] = 'Set the dynamic scissor rectangles on a command buffer'
refDesc['vkCmdSetStencilCompareMask'] = 'Set the stencil compare mask dynamic state'
refDesc['vkCmdSetStencilReference'] = 'Set the stencil reference dynamic state'
refDesc['vkCmdSetStencilWriteMask'] = 'Set the stencil write mask dynamic state'
refDesc['vkCmdSetViewport'] = 'Set the viewport on a command buffer'
refDesc['vkCmdUpdateBuffer'] = 'Update a buffer\'s contents from host memory'
refDesc['vkCmdWaitEvents'] = 'Wait for one or more events and insert a set of memory'
refDesc['vkCmdWriteTimestamp'] = 'Write a device timestamp into a query object'
refDesc['VkCommandBufferAllocateInfo'] = 'Structure specifying the allocation parameters for command buffer object'
refDesc['vkCreateAndroidSurfaceKHR'] = 'Create a slink:VkSurfaceKHR object for an Android native window'
refDesc['vkCreateBuffer'] = 'Create a new buffer object'
refDesc['vkCreateBufferView'] = 'Create a new buffer view object'
refDesc['vkCreateCommandPool'] = 'Create a new command pool object'
refDesc['vkCreateComputePipelines'] = 'Creates a new compute pipeline object'
refDesc['vkCreateDescriptorPool'] = 'Creates a descriptor pool object'
refDesc['vkCreateDescriptorSetLayout'] = 'Create a new descriptor set layout'
refDesc['vkCreateDevice'] = 'Create a new device instance'
refDesc['vkCreateDisplayModeKHR'] = 'Create a display mode'
refDesc['vkCreateDisplayPlaneSurfaceKHR'] = 'Create a slink:VkSurfaceKHR structure representing a display plane and mode'
refDesc['vkCreateEvent'] = 'Create a new event object'
refDesc['vkCreateFence'] = 'Create a new fence object'
refDesc['vkCreateFramebuffer'] = 'Create a new framebuffer object'
refDesc['vkCreateGraphicsPipelines'] = 'Create graphics pipelines'
refDesc['vkCreateImage'] = 'Create a new image object'
refDesc['vkCreateImageView'] = 'Create an image view from an existing image'
refDesc['vkCreateInstance'] = 'Create a new Vulkan instance'
refDesc['vkCreateMirSurfaceKHR'] = 'Create a slink:VkSurfaceKHR object for a Mir window'
refDesc['vkCreatePipelineCache'] = 'Creates a new pipeline cache'
refDesc['vkCreatePipelineLayout'] = 'Creates a new pipeline layout object'
refDesc['vkCreateQueryPool'] = 'Create a new query pool object'
refDesc['vkCreateRenderPass'] = 'Create a new render pass object'
refDesc['vkCreateSampler'] = 'Create a new sampler object'
refDesc['vkCreateSemaphore'] = 'Create a new queue semaphore object'
refDesc['vkCreateShaderModule'] = 'Creates a new shader module object'
refDesc['vkCreateSharedSwapchainsKHR'] = 'Create multiple swapchains that share presentable images'
refDesc['vkCreateSwapchainKHR'] = 'Create a swapchain'
refDesc['vkCreateWaylandSurfaceKHR'] = 'Create a slink:VkSurfaceKHR object for a Wayland window'
refDesc['vkCreateXcbSurfaceKHR'] = 'Create a slink:VkSurfaceKHR object for a X11 window, using the XCB client-side library'
refDesc['vkCreateXlibSurfaceKHR'] = 'Create a slink:VkSurfaceKHR object for an X11 window, using the Xlib client-side library'
refDesc['VkDescriptorSetAllocateInfo'] = 'Structure specifying the allocation parameters for descriptor sets'
refDesc['VkDescriptorType'] = 'Specifies the type of a descriptor in a descriptor set'
refDesc['vkDestroyBuffer'] = 'Destroy a buffer object'
refDesc['vkDestroyBufferView'] = 'Destroy a buffer view object'
refDesc['vkDestroyCommandPool'] = 'Destroy a command pool object'
refDesc['vkDestroyDescriptorPool'] = 'Destroy a descriptor pool object'
refDesc['vkDestroyDescriptorSetLayout'] = 'Destroy a descriptor set layout object'
refDesc['vkDestroyDevice'] = 'Destroy a logical device'
refDesc['vkDestroyEvent'] = 'Destroy an event object'
refDesc['vkDestroyFence'] = 'Destroy a fence object'
refDesc['vkDestroyFramebuffer'] = 'Destroy a framebuffer object'
refDesc['vkDestroyImage'] = 'Destroy an image object'
refDesc['vkDestroyImageView'] = 'Destroy an image view object'
refDesc['vkDestroyInstance'] = 'Destroy an instance of Vulkan'
refDesc['vkDestroyPipelineCache'] = 'Destroy a pipeline cache object'
refDesc['vkDestroyPipelineLayout'] = 'Destroy a pipeline layout object'
refDesc['vkDestroyPipeline'] = 'Destroy a pipeline object'
refDesc['vkDestroyQueryPool'] = 'Destroy a query pool object'
refDesc['vkDestroyRenderPass'] = 'Destroy a render pass object'
refDesc['vkDestroySampler'] = 'Destroy a sampler object'
refDesc['vkDestroySemaphore'] = 'Destroy a semaphore object'
refDesc['vkDestroyShaderModule'] = 'Destroy a shader module'
refDesc['vkDestroySurfaceKHR'] = 'Destroy a VkSurfaceKHR object'
refDesc['vkDestroySwapchainKHR'] = 'Destroy a swapchain object'
refDesc['vkDeviceWaitIdle'] = 'Wait for a device to become idle'
refDesc['vkEndCommandBuffer'] = 'Finish recording a command buffer'
refDesc['vkEnumerateDeviceExtensionProperties'] = 'Returns properties of available physical device extensions'
refDesc['vkEnumerateDeviceLayerProperties'] = 'Returns properties of available physical device layers'
refDesc['vkEnumerateInstanceExtensionProperties'] = 'Returns up to requested number of global extension properties'
refDesc['vkEnumerateInstanceLayerProperties'] = 'Returns up to requested number of global layer properties'
refDesc['vkEnumeratePhysicalDevices'] = 'Enumerates the physical devices accessible to a Vulkan instance'
refDesc['vkFlushMappedMemoryRanges'] = 'Flush mapped memory ranges'
refDesc['VkFormatFeatureFlags'] = 'Capability flags of a particular format'
refDesc['vkFreeCommandBuffers'] = 'Free command buffers'
refDesc['vkFreeDescriptorSets'] = 'Free one or more descriptor sets'
refDesc['vkFreeMemory'] = 'Free GPU memory'
refDesc['vkGetBufferMemoryRequirements'] = 'Returns the memory requirements for specified Vulkan object'
refDesc['vkGetDeviceMemoryCommitment'] = 'Query the current commitment for a VkDeviceMemory'
refDesc['vkGetDeviceProcAddr'] = 'Return a function pointer for a command'
refDesc['vkGetDeviceQueue'] = 'Get a queue handle from a device'
refDesc['vkGetDisplayModePropertiesKHR'] = 'Query the set of mode properties supported by the display'
refDesc['vkGetDisplayPlaneCapabilitiesKHR'] = 'Query capabilities of a mode and plane combination'
refDesc['vkGetDisplayPlaneSupportedDisplaysKHR'] = 'Query the list of displays a plane supports'
refDesc['vkGetEventStatus'] = 'Retrieve the status of an event object'
refDesc['vkGetFenceStatus'] = 'Return the status of a fence'
refDesc['vkGetImageMemoryRequirements'] = 'Returns the memory requirements for specified Vulkan object'
refDesc['vkGetImageSparseMemoryRequirements'] = 'Query the memory requirements for a sparse image'
refDesc['vkGetImageSubresourceLayout'] = 'Retrieve information about an image subresource'
refDesc['vkGetInstanceProcAddr'] = 'Return a function pointer for a command'
refDesc['vkGetPhysicalDeviceDisplayPlanePropertiesKHR'] = 'Query the plane properties'
refDesc['vkGetPhysicalDeviceDisplayPropertiesKHR'] = 'Query information about the available displays'
refDesc['vkGetPhysicalDeviceFeatures'] = 'Reports capabilities of a physical device'
refDesc['vkGetPhysicalDeviceFormatProperties'] = 'Lists physical device\'s format capabilities'
refDesc['vkGetPhysicalDeviceImageFormatProperties'] = 'Lists physical device\'s image format capabilities'
refDesc['vkGetPhysicalDeviceMemoryProperties'] = 'Reports memory information for the specified physical device'
refDesc['vkGetPhysicalDeviceMirPresentationSupportKHR'] = 'Query physical device for presentation to Mir'
refDesc['vkGetPhysicalDeviceProperties'] = 'Returns properties of a physical device'
refDesc['vkGetPhysicalDeviceQueueFamilyProperties'] = 'Reports properties of the queues of the specified physical device'
refDesc['vkGetPhysicalDeviceSparseImageFormatProperties'] = 'Retrieve properties of an image format applied to sparse images'
refDesc['vkGetPhysicalDeviceSurfaceCapabilitiesKHR'] = 'Query surface capabilities'
refDesc['vkGetPhysicalDeviceSurfaceFormatsKHR'] = 'Query color formats supported by surface'
refDesc['vkGetPhysicalDeviceSurfacePresentModesKHR'] = 'Query supported presentation modes'
refDesc['vkGetPhysicalDeviceSurfaceSupportKHR'] = 'Query if presentation is supported'
refDesc['vkGetPhysicalDeviceWaylandPresentationSupportKHR'] = 'Query physical device for presentation to Wayland'
refDesc['vkGetPhysicalDeviceXcbPresentationSupportKHR'] = 'Query physical device for presentation to X11 server using XCB'
refDesc['vkGetPhysicalDeviceXlibPresentationSupportKHR'] = 'Query physical device for presentation to X11 server using Xlib'
refDesc['vkGetPipelineCacheData'] = 'Get the data store from a pipeline cache'
refDesc['vkGetQueryPoolResults'] = 'Copy results of queries in a query pool to a host memory region'
refDesc['vkGetRenderAreaGranularity'] = 'Returns the granularity for optimal render area'
refDesc['vkGetSwapchainImagesKHR'] = 'Obtain the array of presentable images associated with a swapchain'
refDesc['VkImageCreateFlags'] = 'Image object creation flags'
refDesc['VkImageCreateInfo'] = 'Structure specifying the parameters of a newly created image object'
refDesc['VkImageLayout'] = 'Layout of image and image subresources'
refDesc['VkImageMemoryBarrier'] = 'Structure specifying the parameters of an image memory barrier'
refDesc['VkImageType'] = 'Specifies the type of an image object'
refDesc['VkImageUsageFlags'] = 'Image object usage flags'
refDesc['VkImageViewType'] = 'Image view types'
refDesc['vkInvalidateMappedMemoryRanges'] = 'Invalidate ranges of mapped memory objects'
refDesc['vkMapMemory'] = 'Map a memory object into application address space'
refDesc['VkMemoryAllocateInfo'] = 'Structure containing parameters of a memory allocation'
refDesc['VkMemoryPropertyFlags'] = 'Memory pool properties'
refDesc['vkMergePipelineCaches'] = 'Combine the data stores of pipeline caches'
refDesc['VkPhysicalDeviceFeatures'] = 'Structure describing the fine-grained features that can be supported by an implementation'
refDesc['VkPhysicalDeviceLimits'] = 'Structure'
refDesc['VkPipelineLayoutCreateInfo'] = 'Structure specifying the parameters of a newly created pipeline layout object'
refDesc['VkPipelineStageFlags'] = 'Pipeline stage identifiers'
refDesc['VkQueryControlFlags'] = 'Query control flags'
refDesc['VkQueryResultFlags'] = 'Query result flags'
refDesc['vkQueueBindSparse'] = 'Bind device memory to a sparse resource object'
refDesc['VkQueueFamilyProperties'] = 'Structure providing information about a queue family'
refDesc['VkQueueFlags'] = 'Queue capability flags'
refDesc['vkQueuePresentKHR'] = 'Queue an image for presentation'
refDesc['vkQueueSubmit'] = 'Submits a sequence of semaphores or command buffers to a queue'
refDesc['vkQueueWaitIdle'] = 'Wait for a queue to become idle'
refDesc['vkResetCommandBuffer'] = 'Reset a command buffer'
refDesc['vkResetCommandPool'] = 'Reset a command pool'
refDesc['vkResetDescriptorPool'] = 'Resets a descriptor pool object'
refDesc['vkResetEvent'] = 'Reset an event to non-signaled state'
refDesc['vkResetFences'] = 'Resets one or more fence objects'
refDesc['vkSetEvent'] = 'Set an event to signaled state'
refDesc['VkSharingMode'] = 'Buffer and image sharing modes'
refDesc['vkUnmapMemory'] = 'Unmap a previously mapped memory object'
refDesc['vkUpdateDescriptorSets'] = 'Update the contents of a descriptor set object'
refDesc['vkWaitForFences'] = 'Wait for one or more fences to become signaled'
refDesc['VkWriteDescriptorSet'] = 'Structure specifying the parameters of a descriptor set write operation'
refDesc['VkAndroidSurfaceCreateInfoKHR'] = 'Structure specifying parameters of a newly created Android surface object'
refDesc['VkDebugReportCallbackCreateInfoEXT'] = 'Structure specifying parameters of a newly created debug report object'
refDesc['VkDisplayModeCreateInfoKHR'] = 'Structure specifying parameters of a newly created display mode object'
refDesc['VkDisplayModeParametersKHR'] = 'Structure describing display parameters associated with a display mode'
refDesc['VkDisplayModePropertiesKHR'] = 'Structure describing display mode properties'
refDesc['VkDisplayPlaneCapabilitiesKHR'] = 'Structure describing capabilities of a mode and plane combination'
refDesc['VkDisplayPlanePropertiesKHR'] = 'Structure describing display plane properties'
refDesc['VkDisplayPresentInfoKHR'] = 'Structure describing parameters of a queue presentation to a swapchain'
refDesc['VkDisplayPropertiesKHR'] = 'Structure describing an available display device'
refDesc['VkDisplaySurfaceCreateInfoKHR'] = 'Structure specifying parameters of a newly created display plane surface object'
refDesc['VkMirSurfaceCreateInfoKHR'] = 'Structure specifying parameters of a newly created Mir surface object'
refDesc['VkPresentInfoKHR'] = 'Structure describing parameters of a queue presentation'
refDesc['VkSurfaceCapabilitiesKHR'] = 'Structure describing capabilities of a surface'
refDesc['VkSurfaceFormatKHR'] = 'Structure describing a supported swapchain format-colorspace pair'
refDesc['VkSwapchainCreateInfoKHR'] = 'Structure specifying parameters of a newly created swapchain object'
refDesc['VkWaylandSurfaceCreateInfoKHR'] = 'Structure specifying parameters of a newly created Wayland surface object'
refDesc['VkWin32SurfaceCreateInfoKHR'] = 'Structure specifying parameters of a newly created Win32 surface object'
refDesc['VkXcbSurfaceCreateInfoKHR'] = 'Structure specifying parameters of a newly created Xcb surface object'
refDesc['VkXlibSurfaceCreateInfoKHR'] = 'Structure specifying parameters of a newly created Xlib surface object'

# These are generated based on the structure name

refDesc['VkBufferViewCreateInfo'] =                 'Structure specifying parameters of a newly created buffer view'
refDesc['VkCommandPoolCreateInfo'] =                'Structure specifying parameters of a newly created command pool'
refDesc['VkComputePipelineCreateInfo'] =            'Structure specifying parameters of a newly created compute pipeline'
refDesc['VkDescriptorPoolCreateInfo'] =             'Structure specifying parameters of a newly created descriptor pool'
refDesc['VkDescriptorSetLayoutCreateInfo'] =        'Structure specifying parameters of a newly created descriptor set layout'
refDesc['VkDeviceCreateInfo'] =                     'Structure specifying parameters of a newly created device'
refDesc['VkDeviceQueueCreateInfo'] =                'Structure specifying parameters of a newly created device queue'
refDesc['VkEventCreateInfo'] =                      'Structure specifying parameters of a newly created event'
refDesc['VkExtent2D'] =                             'Structure specifying a two-dimensional extent'
refDesc['VkExtent3D'] =                             'Structure specifying a three-dimensional extent'
refDesc['VkFenceCreateInfo'] =                      'Structure specifying parameters of a newly created fence'
refDesc['VkFramebufferCreateInfo'] =                'Structure specifying parameters of a newly created framebuffer'
refDesc['VkGraphicsPipelineCreateInfo'] =           'Structure specifying parameters of a newly created graphics pipeline'
refDesc['VkImageViewCreateInfo'] =                  'Structure specifying parameters of a newly created image view'
refDesc['VkInstanceCreateInfo'] =                   'Structure specifying parameters of a newly created instance'
refDesc['VkOffset2D'] =                             'Structure specifying a two-dimensional offset'
refDesc['VkOffset3D'] =                             'Structure specifying a three-dimensional offset'
refDesc['VkPipelineCacheCreateInfo'] =              'Structure specifying parameters of a newly created pipeline cache'
refDesc['VkPipelineColorBlendStateCreateInfo'] =    'Structure specifying parameters of a newly created pipeline color blend state'
refDesc['VkPipelineDepthStencilStateCreateInfo'] =  'Structure specifying parameters of a newly created pipeline depth stencil state'
refDesc['VkPipelineDynamicStateCreateInfo'] =       'Structure specifying parameters of a newly created pipeline dynamic state'
refDesc['VkPipelineInputAssemblyStateCreateInfo'] = 'Structure specifying parameters of a newly created pipeline input assembly state'
refDesc['VkPipelineMultisampleStateCreateInfo'] =   'Structure specifying parameters of a newly created pipeline multisample state'
refDesc['VkPipelineRasterizationStateCreateInfo'] = 'Structure specifying parameters of a newly created pipeline rasterization state'
refDesc['VkPipelineShaderStageCreateInfo'] =        'Structure specifying parameters of a newly created pipeline shader stage'
refDesc['VkPipelineTessellationStateCreateInfo'] =  'Structure specifying parameters of a newly created pipeline tessellation state'
refDesc['VkPipelineVertexInputStateCreateInfo'] =   'Structure specifying parameters of a newly created pipeline vertex input state'
refDesc['VkPipelineViewportStateCreateInfo'] =      'Structure specifying parameters of a newly created pipeline viewport state'
refDesc['VkQueryPoolCreateInfo'] =                  'Structure specifying parameters of a newly created query pool'
refDesc['VkRect2D'] =                               'Structure specifying a two-dimensional subregion'
refDesc['VkRenderPassCreateInfo'] =                 'Structure specifying parameters of a newly created render pass'
refDesc['VkSamplerCreateInfo'] =                    'Structure specifying parameters of a newly created sampler'
refDesc['VkSemaphoreCreateInfo'] =                  'Structure specifying parameters of a newly created semaphore'
refDesc['VkShaderModuleCreateInfo'] =               'Structure specifying parameters of a newly created shader module'

# These are TBD

refDesc['VkApplicationInfo'] =                      'Structure specifying application info'
refDesc['VkAttachmentDescription'] =                'Structure specifying an attachment description'
refDesc['VkAttachmentReference'] =                  'Structure specifying an attachment reference'
refDesc['VkBindSparseInfo'] =                       'Structure specifying a sparse binding operation'
refDesc['VkBufferCopy'] =                           'Structure specifying a buffer copy operation'
refDesc['VkBufferImageCopy'] =                      'Structure specifying a buffer image copy operation'
refDesc['VkClearAttachment'] =                      'Structure specifying a clear attachment'
refDesc['VkClearColorValue'] =                      'Structure specifying a clear color value'
refDesc['VkClearDepthStencilValue'] =               'Structure specifying a clear depth stencil value'
refDesc['VkClearRect'] =                            'Structure specifying a clear rectangle'
refDesc['VkClearValue'] =                           'Structure specifying a clear value'
refDesc['VkCommandBufferBeginInfo'] =               'Structure specifying a command buffer begin operation'
refDesc['VkCommandBufferInheritanceInfo'] =         'Structure specifying command buffer inheritance info'
refDesc['VkCommandBufferLevel'] =                   'Structure specifying a command buffer level'
refDesc['VkComponentMapping'] =                     'Structure specifying a color component mapping'
refDesc['VkCopyDescriptorSet'] =                    'Structure specifying a copy descriptor set operation'
refDesc['VkDescriptorBufferInfo'] =                 'Structure specifying descriptor buffer info'
refDesc['VkDescriptorImageInfo'] =                  'Structure specifying descriptor image info'
refDesc['VkDescriptorPoolSize'] =                   'Structure specifying descriptor pool size'
refDesc['VkDescriptorSetLayoutBinding'] =           'Structure specifying a descriptor set layout binding'
refDesc['VkDispatchIndirectCommand'] =              'Structure specifying a dispatch indirect command'
refDesc['VkDrawIndexedIndirectCommand'] =           'Structure specifying a draw indexed indirect command'
refDesc['VkDrawIndirectCommand'] =                  'Structure specifying a draw indirect command'
refDesc['VkExtensionProperties'] =                  'Structure specifying a extension properties'
refDesc['VkFormatProperties'] =                     'Structure specifying image format properties'
refDesc['VkImageBlit'] =                            'Structure specifying an image blit operation'
refDesc['VkImageCopy'] =                            'Structure specifying an image copy operation'
refDesc['VkImageFormatProperties'] =                'Structure specifying a image format properties'
refDesc['VkImageResolve'] =                         'Structure specifying an image resolve operation'
refDesc['VkImageSubresource'] =                     'Structure specifying a image subresource'
refDesc['VkImageSubresourceLayers'] =               'Structure specifying a image subresource layers'
refDesc['VkImageSubresourceRange'] =                'Structure specifying a image subresource range'
refDesc['VkLayerProperties'] =                      'Structure specifying layer properties'
refDesc['VkMappedMemoryRange'] =                    'Structure specifying a mapped memory range'
refDesc['VkMemoryBarrier'] =                        'Structure specifying a memory barrier'
refDesc['VkMemoryHeap'] =                           'Structure specifying a memory heap'
refDesc['VkMemoryRequirements'] =                   'Structure specifying memory requirements'
refDesc['VkMemoryType'] =                           'Structure specifying memory type'
refDesc['VkPhysicalDeviceMemoryProperties'] =       'Structure specifying physical device memory properties'
refDesc['VkPhysicalDeviceProperties'] =             'Structure specifying physical device properties'
refDesc['VkPhysicalDeviceSparseProperties'] =       'Structure specifying physical device sparse memory properties'
refDesc['VkPipelineColorBlendAttachmentState'] =    'Structure specifying a pipeline color blend attachment state'
refDesc['VkPushConstantRange'] =                    'Structure specifying a push constant range'
refDesc['VkRenderPassBeginInfo'] =                  'Structure specifying render pass begin info'
refDesc['VkSparseBufferMemoryBindInfo'] =           'Structure specifying a sparse buffer memory bind operation'
refDesc['VkSparseImageFormatProperties'] =          'Structure specifying sparse image format properties'
refDesc['VkSparseImageMemoryBind'] =                'Structure specifying sparse image memory bind'
refDesc['VkSparseImageMemoryBindInfo'] =            'Structure specifying sparse image memory bind info'
refDesc['VkSparseImageMemoryRequirements'] =        'Structure specifying sparse image memory requirements'
refDesc['VkSparseImageOpaqueMemoryBindInfo'] =      'Structure specifying sparse image opaque memory bind info'
refDesc['VkSparseMemoryBind'] =                     'Structure specifying a sparse memory bind operation'
refDesc['VkSpecializationInfo'] =                   'Structure specifying specialization info'
refDesc['VkSpecializationMapEntry'] =               'Structure specifying a specialization map entry'
refDesc['VkStencilOpState'] =                       'Structure specifying stencil operation state'
refDesc['VkSubmitInfo'] =                           'Structure specifying a queue submit operation'
refDesc['VkSubpassDependency'] =                    'Structure specifying a subpass dependency'
refDesc['VkSubpassDescription'] =                   'Structure specifying a subpass description'
refDesc['VkSubresourceLayout'] =                    'Structure specifying subresource layout'
refDesc['VkVertexInputAttributeDescription'] =      'Structure specifying vertex input attribute description'
refDesc['VkVertexInputBindingDescription'] =        'Structure specifying vertex input binding description'
refDesc['VkViewport'] =                             'Structure specifying a viewport'

# These are constructed from spec text

refDesc['VkAccessFlagBits'] =                  'Bitmask specifying classes of memory access the will participate in a memory barrier dependency'
refDesc['VkAttachmentDescriptionFlagBits'] =   'Bitmask specifying additional properties of an attachment'
refDesc['VkBufferCreateFlagBits'] =            'Bitmask specifying additional parameters of a buffer'
refDesc['VkBufferUsageFlagBits'] =             'Bitmask specifying allowed usage of a buffer'
refDesc['VkColorComponentFlagBits'] =          'Bitmask controlling which components are written to the framebuffer'
refDesc['VkCommandBufferResetFlagBits'] =      'Bitmask controlling behavior of a command buffer reset'
refDesc['VkCommandBufferUsageFlagBits'] =      'Bitmask specifying usage behavior for command buffer'
refDesc['VkCommandPoolCreateFlagBits'] =       'Bitmask specifying usage behavior for a command pool'
refDesc['VkCommandPoolResetFlagBits'] =        'Bitmask controlling behavior of a command pool reset'
refDesc['VkCullModeFlagBits'] =                'Bitmask controlling triangle culling'
refDesc['VkDependencyFlagBits'] =              'Bitmask specifying dependencies between subpasses'
refDesc['VkDescriptorPoolCreateFlagBits'] =    'Bitmask specifying certain supported operations on a descriptor pool'
refDesc['VkFenceCreateFlagBits'] =             'Bitmask specifying initial state and behavior of a fence'
refDesc['VkFormatFeatureFlagBits'] =           'Bitmask specifying features supported by a buffer'
refDesc['VkImageAspectFlagBits'] =             'Bitmask specifying which aspects of an image are included in a view'
refDesc['VkImageCreateFlagBits'] =             'Bitmask specifying additional parameters of an image'
refDesc['VkImageUsageFlagBits'] =              'Bitmask specifying intended usage of an image'
refDesc['VkMemoryHeapFlagBits'] =              'Bitmask specifying attribute flags for a heap'
refDesc['VkMemoryPropertyFlagBits'] =          'Bitmask specifying properties for a memory type'
refDesc['VkPipelineCreateFlagBits'] =          'Bitmask controlling how a pipeline is generated'
refDesc['VkPipelineStageFlagBits'] =           'Bitmask specifying pipeline stages'
refDesc['VkQueryControlFlagBits'] =            'Bitmask specifying constraints on a query'
refDesc['VkQueryPipelineStatisticFlagBits'] =  'Bitmask specifying queried pipeline statistics'
refDesc['VkQueryResultFlagBits'] =             'Bitmask specifying how and when query results are returned'
refDesc['VkQueueFlagBits'] =                   'Bitmask specifying capabilities of queues in a queue family'
refDesc['VkSampleCountFlagBits'] =             'Bitmask specifying sample counts supported for an image used for storage operations'
refDesc['VkShaderStageFlagBits'] =             'Bitmask specifying a pipeline stage'
refDesc['VkSparseImageFormatFlagBits'] =       'Bitmask specifying additional information about a sparse image resource'
refDesc['VkSparseMemoryBindFlagBits'] =        'Bitmask specifying usage of a sparse memory binding operation'
refDesc['VkStencilFaceFlagBits'] =             'Bitmask specifying sets of stencil state for which to update the compare mask'
