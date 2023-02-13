// Copyright 2022 The Android Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either expresso or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "ColorBuffer.h"

#include "gl/EmulationGl.h"
#include "vulkan/VkCommonOperations.h"

using android::base::ManagedDescriptor;
using emugl::ABORT_REASON_OTHER;
using emugl::FatalError;

namespace {

// ColorBufferVk natively supports YUV images. However, ColorBufferGl
// needs to emulate YUV support by having an underlying RGBA texture
// and adding in additional YUV<->RGBA conversions when needed. The
// memory should not be shared between the VK YUV image and the GL RGBA
// texture.
bool shouldAttemptExternalMemorySharing(FrameworkFormat format) {
    return format == FrameworkFormat::FRAMEWORK_FORMAT_GL_COMPATIBLE;
}

}  // namespace

ColorBuffer::ColorBuffer(HandleType handle, uint32_t width, uint32_t height, GLenum format,
                         FrameworkFormat frameworkFormat)
    : mHandle(handle),
      mWidth(width),
      mHeight(height),
      mFormat(format),
      mFrameworkFormat(frameworkFormat) {}

/*static*/
std::shared_ptr<ColorBuffer> ColorBuffer::create(gfxstream::EmulationGl* emulationGl,
                                                 goldfish_vk::VkEmulation* emulationVk,
                                                 uint32_t width, uint32_t height, GLenum format,
                                                 FrameworkFormat frameworkFormat,
                                                 HandleType handle) {
    std::shared_ptr<ColorBuffer> colorBuffer(
        new ColorBuffer(handle, width, height, format, frameworkFormat));

    if (emulationGl) {
        colorBuffer->mColorBufferGl =
            emulationGl->createColorBuffer(width, height, format, frameworkFormat, handle);
        if (!colorBuffer->mColorBufferGl) {
            ERR("Failed to initialize ColorBufferGl.");
            return nullptr;
        }
    }

    if (emulationVk && emulationVk->live) {
        const bool vulkanOnly = colorBuffer->mColorBufferGl == nullptr;

        colorBuffer->mColorBufferVk = std::make_unique<ColorBufferVk>();
        if (!goldfish_vk::setupVkColorBuffer(width, height, format, frameworkFormat, handle,
                                             vulkanOnly, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT)) {
            if (emulationGl) {
                // Historically, ColorBufferVk setup was deferred until the first actual Vulkan
                // usage. This allowed ColorBufferVk setup failures to be unintentionally avoided.
                colorBuffer->mColorBufferVk.reset();
            } else {
                ERR("Failed to initialize ColorBufferVk.");
                return nullptr;
            }
        }
    }

    if (colorBuffer->mColorBufferGl && colorBuffer->mColorBufferVk &&
        shouldAttemptExternalMemorySharing(frameworkFormat)) {
        auto memoryExport = goldfish_vk::exportColorBufferMemory(handle);
        if (memoryExport) {
            if (colorBuffer->mColorBufferGl->importMemory(
                    std::move(memoryExport->descriptor), memoryExport->size,
                    memoryExport->dedicatedAllocation, memoryExport->linearTiling)) {
                colorBuffer->mGlAndVkAreSharingExternalMemory = true;
            } else {
                ERR("Failed to import memory to ColorBufferGl:%d", handle);
                return nullptr;
            }
        }
    }

    return colorBuffer;
}

/*static*/
std::shared_ptr<ColorBuffer> ColorBuffer::onLoad(gfxstream::EmulationGl* emulationGl,
                                                 goldfish_vk::VkEmulation*,
                                                 android::base::Stream* stream) {
    const auto handle = static_cast<HandleType>(stream->getBe32());
    const auto width = static_cast<uint32_t>(stream->getBe32());
    const auto height = static_cast<uint32_t>(stream->getBe32());
    const auto format = static_cast<GLenum>(stream->getBe32());
    const auto frameworkFormat = static_cast<FrameworkFormat>(stream->getBe32());

    std::shared_ptr<ColorBuffer> colorBuffer(
        new ColorBuffer(handle, width, height, format, frameworkFormat));

    if (emulationGl) {
        colorBuffer->mColorBufferGl = emulationGl->loadColorBuffer(stream);
        if (!colorBuffer->mColorBufferGl) {
            ERR("Failed to load ColorBufferGl.");
            return nullptr;
        }
    }

    colorBuffer->mNeedRestore = true;

    return colorBuffer;
}

void ColorBuffer::onSave(android::base::Stream* stream) {
    stream->putBe32(getHndl());
    stream->putBe32(mWidth);
    stream->putBe32(mHeight);
    stream->putBe32(static_cast<uint32_t>(mFormat));
    stream->putBe32(static_cast<uint32_t>(mFrameworkFormat));

    if (mColorBufferGl) {
        mColorBufferGl->onSave(stream);
    }
}

void ColorBuffer::restore() {
    if (mColorBufferGl) {
        mColorBufferGl->restore();
    }
}

void ColorBuffer::readToBytes(int x, int y, int width, int height, GLenum pixelsFormat,
                              GLenum pixelsType, void* outPixels) {
    touch();

    if (mColorBufferVk) {
        goldfish_vk::readColorBufferToBytes(mHandle, x, y, width, height, outPixels);
        return;
    }
    if (mColorBufferGl) {
        mColorBufferGl->readPixels(x, y, width, height, pixelsFormat, pixelsType, outPixels);
        return;
    }

    GFXSTREAM_ABORT(FatalError(ABORT_REASON_OTHER)) << "No ColorBuffer impl?";
}

void ColorBuffer::readToBytesScaled(int pixelsWidth, int pixelsHeight, GLenum pixelsFormat,
                                    GLenum pixelsType, int pixelsRotation, emugl::Rect rect,
                                    void* outPixels) {
    touch();

    if (mColorBufferGl) {
        mColorBufferGl->readPixelsScaled(pixelsWidth, pixelsHeight, pixelsFormat, pixelsType,
                                         pixelsRotation, rect, outPixels);
        return;
    }

    GFXSTREAM_ABORT(FatalError(ABORT_REASON_OTHER)) << "Unimplemented.";
}

void ColorBuffer::readYuvToBytes(int x, int y, int width, int height, void* outPixels,
                                 uint32_t pixelsSize) {
    touch();

    if (mColorBufferVk) {
        goldfish_vk::readColorBufferToBytes(mHandle, x, y, width, height, outPixels);
        return;
    }
    if (mColorBufferGl) {
        mColorBufferGl->readPixelsYUVCached(x, y, width, height, outPixels, pixelsSize);
        return;
    }

    GFXSTREAM_ABORT(FatalError(ABORT_REASON_OTHER)) << "No ColorBuffer impl?";
}

bool ColorBuffer::updateFromBytes(int x, int y, int width, int height,
                                  FrameworkFormat frameworkFormat, GLenum pixelsFormat,
                                  GLenum pixelsType, const void* pixels) {
    touch();

    if (mColorBufferVk) {
        return goldfish_vk::updateColorBufferFromBytes(mHandle, x, y, width, height, pixels);
    }
    if (mColorBufferGl) {
        mColorBufferGl->subUpdateFromFrameworkFormat(x, y, width, height, frameworkFormat,
                                                     pixelsFormat, pixelsType, pixels);
        return true;
    }

    GFXSTREAM_ABORT(FatalError(ABORT_REASON_OTHER)) << "No ColorBuffer impl?";
    return false;
}

bool ColorBuffer::updateFromBytes(int x, int y, int width, int height, GLenum pixelsFormat,
                                  GLenum pixelsType, const void* pixels) {
    touch();

    if (mColorBufferVk) {
        return goldfish_vk::updateColorBufferFromBytes(mHandle, x, y, width, height, pixels);
    }
    if (mColorBufferGl) {
        return mColorBufferGl->subUpdate(x, y, width, height, pixelsFormat, pixelsType, pixels);
    }

    GFXSTREAM_ABORT(FatalError(ABORT_REASON_OTHER)) << "No ColorBuffer impl?";
    return false;
}

bool ColorBuffer::updateGlFromBytes(const void* bytes, std::size_t bytesSize) {
    if (mColorBufferGl) {
        touch();

        return mColorBufferGl->replaceContents(bytes, bytesSize);
    }

    return true;
}

std::unique_ptr<BorrowedImageInfo> ColorBuffer::borrowForComposition(UsedApi api, bool isTarget) {
    switch (api) {
        case UsedApi::kGl: {
            if (!mColorBufferGl) {
                GFXSTREAM_ABORT(FatalError(ABORT_REASON_OTHER)) << "ColorBufferGl not available.";
            }
            return mColorBufferGl->getBorrowedImageInfo();
        }
        case UsedApi::kVk: {
            if (!mColorBufferVk) {
                GFXSTREAM_ABORT(FatalError(ABORT_REASON_OTHER)) << "ColorBufferGl not available.";
            }
            return goldfish_vk::borrowColorBufferForComposition(getHndl(), isTarget);
        }
    }
    GFXSTREAM_ABORT(FatalError(ABORT_REASON_OTHER)) << "Unimplemented";
    return nullptr;
}

std::unique_ptr<BorrowedImageInfo> ColorBuffer::borrowForDisplay(UsedApi api) {
    switch (api) {
        case UsedApi::kGl: {
            if (!mColorBufferGl) {
                GFXSTREAM_ABORT(FatalError(ABORT_REASON_OTHER)) << "ColorBufferGl not available.";
            }
            return mColorBufferGl->getBorrowedImageInfo();
        }
        case UsedApi::kVk: {
            if (!mColorBufferVk) {
                GFXSTREAM_ABORT(FatalError(ABORT_REASON_OTHER)) << "ColorBufferGl not available.";
            }
            return goldfish_vk::borrowColorBufferForDisplay(getHndl());
        }
    }
    GFXSTREAM_ABORT(FatalError(ABORT_REASON_OTHER)) << "Unimplemented";
    return nullptr;
}

void ColorBuffer::updateFromGl() {
    if (!(mColorBufferGl && mColorBufferVk)) {
        return;
    }

    if (mGlAndVkAreSharingExternalMemory) {
        return;
    }

    std::size_t contentsSize = 0;
    if (!mColorBufferGl->readContents(&contentsSize, nullptr)) {
        ERR("Failed to get GL contents size for ColorBuffer:%d", mHandle);
        return;
    }

    std::vector<uint8_t> contents(contentsSize, 0);

    if (!mColorBufferGl->readContents(&contentsSize, contents.data())) {
        ERR("Failed to get GL contents for ColorBuffer:%d", mHandle);
        return;
    }

    if (!goldfish_vk::updateColorBufferFromBytes(mHandle, contents)) {
        ERR("Failed to set VK contents for ColorBuffer:%d", mHandle);
        return;
    }
}

void ColorBuffer::updateFromVk() {
    if (!(mColorBufferGl && mColorBufferVk)) {
        return;
    }

    if (mGlAndVkAreSharingExternalMemory) {
        return;
    }

    std::vector<uint8_t> contents;
    if (!goldfish_vk::readColorBufferToBytes(mHandle, &contents)) {
        ERR("Failed to get VK contents for ColorBuffer:%d", mHandle);
        return;
    }

    if (contents.empty()) return;

    if (!mColorBufferGl->replaceContents(contents.data(), contents.size())) {
        ERR("Failed to set GL contents for ColorBuffer:%d", mHandle);
        return;
    }
}

bool ColorBuffer::glOpBlitFromCurrentReadBuffer() {
    if (!mColorBufferGl) {
        GFXSTREAM_ABORT(FatalError(ABORT_REASON_OTHER)) << "ColorBufferGl not available.";
    }

    touch();

    return mColorBufferGl->blitFromCurrentReadBuffer();
}

bool ColorBuffer::glOpBindToTexture() {
    if (!mColorBufferGl) {
        GFXSTREAM_ABORT(FatalError(ABORT_REASON_OTHER)) << "ColorBufferGl not available.";
    }

    touch();

    return mColorBufferGl->bindToTexture();
}

bool ColorBuffer::glOpBindToTexture2() {
    if (!mColorBufferGl) {
        GFXSTREAM_ABORT(FatalError(ABORT_REASON_OTHER)) << "ColorBufferGl not available.";
    }

    return mColorBufferGl->bindToTexture2();
}

bool ColorBuffer::glOpBindToRenderbuffer() {
    if (!mColorBufferGl) {
        GFXSTREAM_ABORT(FatalError(ABORT_REASON_OTHER)) << "ColorBufferGl not available.";
    }

    touch();

    return mColorBufferGl->bindToRenderbuffer();
}

GLuint ColorBuffer::glOpGetTexture() {
    if (!mColorBufferGl) {
        GFXSTREAM_ABORT(FatalError(ABORT_REASON_OTHER)) << "ColorBufferGl not available.";
    }

    touch();

    return mColorBufferGl->getTexture();
}

void ColorBuffer::glOpReadback(unsigned char* img, bool readbackBgra) {
    if (!mColorBufferGl) {
        GFXSTREAM_ABORT(FatalError(ABORT_REASON_OTHER)) << "ColorBufferGl not available.";
    }

    touch();

    return mColorBufferGl->readback(img, readbackBgra);
}

void ColorBuffer::glOpReadbackAsync(GLuint buffer, bool readbackBgra) {
    if (!mColorBufferGl) {
        GFXSTREAM_ABORT(FatalError(ABORT_REASON_OTHER)) << "ColorBufferGl not available.";
    }

    touch();

    mColorBufferGl->readbackAsync(buffer, readbackBgra);
}

bool ColorBuffer::glOpImportEglImage(void* image, bool preserveContent) {
    if (!mColorBufferGl) {
        GFXSTREAM_ABORT(FatalError(ABORT_REASON_OTHER)) << "ColorBufferGl not available.";
    }

    return mColorBufferGl->importEglImage(image, preserveContent);
}

bool ColorBuffer::glOpImportEglNativePixmap(void* pixmap, bool preserveContent) {
    if (!mColorBufferGl) {
        GFXSTREAM_ABORT(FatalError(ABORT_REASON_OTHER)) << "ColorBufferGl not available.";
    }

    return mColorBufferGl->importEglNativePixmap(pixmap, preserveContent);
}

void ColorBuffer::glOpSwapYuvTexturesAndUpdate(GLenum format, GLenum type,
                                               FrameworkFormat frameworkFormat, GLuint* textures) {
    if (!mColorBufferGl) {
        GFXSTREAM_ABORT(FatalError(ABORT_REASON_OTHER)) << "ColorBufferGl not available.";
    }

    mColorBufferGl->swapYUVTextures(frameworkFormat, textures);

    // This makes ColorBufferGl regenerate the RGBA texture using
    // YUVConverter::drawConvert() with the updated YUV textures.
    mColorBufferGl->subUpdate(0, 0, mWidth, mHeight, format, type, nullptr);

    updateFromGl();
}

bool ColorBuffer::glOpReadContents(size_t* outNumBytes, void* outContents) {
    if (!mColorBufferGl) {
        GFXSTREAM_ABORT(FatalError(ABORT_REASON_OTHER)) << "ColorBufferGl not available.";
    }

    return mColorBufferGl->readContents(outNumBytes, outContents);
}

bool ColorBuffer::glOpReplaceContents(size_t numBytes, const void* contents) {
    if (mColorBufferGl) {
        return mColorBufferGl->replaceContents(contents, numBytes);
    }
    return false;
}

bool ColorBuffer::glOpIsFastBlitSupported() const {
    if (!mColorBufferGl) {
        GFXSTREAM_ABORT(FatalError(ABORT_REASON_OTHER)) << "ColorBufferGl not available.";
    }

    return mColorBufferGl->isFastBlitSupported();
}

void ColorBuffer::glOpPostLayer(const ComposeLayer& l, int frameWidth, int frameHeight) {
    if (!mColorBufferGl) {
        GFXSTREAM_ABORT(FatalError(ABORT_REASON_OTHER)) << "ColorBufferGl not available.";
    }

    mColorBufferGl->postLayer(l, frameWidth, frameHeight);
}

void ColorBuffer::glOpPostViewportScaledWithOverlay(float rotation, float dx, float dy) {
    if (!mColorBufferGl) {
        GFXSTREAM_ABORT(FatalError(ABORT_REASON_OTHER)) << "ColorBufferGl not available.";
    }

    mColorBufferGl->postViewportScaledWithOverlay(rotation, dx, dy);
}
