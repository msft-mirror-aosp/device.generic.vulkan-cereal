// Auto-generated with: android/scripts/gen-entries.py --mode=funcargs stream-servers/gl/OpenGLESDispatch/gles_extensions.entries --output=include/OpenGLESDispatch/gles_extensions_functions.h
// DO NOT EDIT THIS FILE

#ifndef GLES_EXTENSIONS_FUNCTIONS_H
#define GLES_EXTENSIONS_FUNCTIONS_H

#define LIST_GLES_EXTENSIONS_FUNCTIONS(X) \
  X(GLboolean, glIsRenderbufferEXT, (GLuint renderbuffer), (renderbuffer)) \
  X(void, glBindRenderbufferEXT, (GLenum target, GLuint renderbuffer), (target, renderbuffer)) \
  X(void, glDeleteRenderbuffersEXT, (GLsizei n, const GLuint * renderbuffers), (n, renderbuffers)) \
  X(void, glGenRenderbuffersEXT, (GLsizei n, GLuint * renderbuffers), (n, renderbuffers)) \
  X(void, glRenderbufferStorageEXT, (GLenum target, GLenum internalformat, GLsizei width, GLsizei height), (target, internalformat, width, height)) \
  X(void, glGetRenderbufferParameterivEXT, (GLenum target, GLenum pname, GLint * params), (target, pname, params)) \
  X(GLboolean, glIsFramebufferEXT, (GLuint framebuffer), (framebuffer)) \
  X(void, glBindFramebufferEXT, (GLenum target, GLuint framebuffer), (target, framebuffer)) \
  X(void, glDeleteFramebuffersEXT, (GLsizei n, const GLuint * framebuffers), (n, framebuffers)) \
  X(void, glGenFramebuffersEXT, (GLsizei n, GLuint * framebuffers), (n, framebuffers)) \
  X(GLenum, glCheckFramebufferStatusEXT, (GLenum target), (target)) \
  X(void, glFramebufferTexture1DEXT, (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level), (target, attachment, textarget, texture, level)) \
  X(void, glFramebufferTexture2DEXT, (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level), (target, attachment, textarget, texture, level)) \
  X(void, glFramebufferTexture3DEXT, (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset), (target, attachment, textarget, texture, level, zoffset)) \
  X(void, glFramebufferRenderbufferEXT, (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer), (target, attachment, renderbuffertarget, renderbuffer)) \
  X(void, glGetFramebufferAttachmentParameterivEXT, (GLenum target, GLenum attachment, GLenum pname, GLint * params), (target, attachment, pname, params)) \
  X(void, glGenerateMipmapEXT, (GLenum target), (target)) \
  X(GLenum, glGetGraphicsResetStatusEXT, (), ()) \
  X(void, glReadnPixelsEXT, (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void * data), (x, y, width, height, format, type, bufSize, data)) \
  X(void, glGetnUniformfvEXT, (GLuint program, GLint location, GLsizei bufSize, float * params), (program, location, bufSize, params)) \
  X(void, glGetnUniformivEXT, (GLuint program, GLint location, GLsizei bufSize, GLint * params), (program, location, bufSize, params)) \
  X(void, glEGLImageTargetTexture2DOES, (GLenum target, GLeglImageOES image), (target, image)) \
  X(void, glEGLImageTargetRenderbufferStorageOES, (GLenum target, GLeglImageOES image), (target, image)) \
  X(void, glDrawArraysNullAEMU, (GLenum mode, GLint first, GLsizei count), (mode, first, count)) \
  X(void, glDrawElementsNullAEMU, (GLenum mode, GLsizei count, GLenum type, const void * indices), (mode, count, type, indices)) \
  X(void, glGetUnsignedBytevEXT, (GLenum pname, GLubyte* data), (pname, data)) \
  X(void, glGetUnsignedBytei_vEXT, (GLenum target, GLuint index, GLubyte* data), (target, index, data)) \
  X(void, glImportMemoryFdEXT, (GLuint memory, GLuint64 size, GLenum handleType, GLint fd), (memory, size, handleType, fd)) \
  X(void, glImportMemoryWin32HandleEXT, (GLuint memory, GLuint64 size, GLenum handleType, void* handle), (memory, size, handleType, handle)) \
  X(void, glDeleteMemoryObjectsEXT, (GLsizei n, const GLuint * memoryObjects), (n, memoryObjects)) \
  X(GLboolean, glIsMemoryObjectEXT, (GLuint memoryObject), (memoryObject)) \
  X(void, glCreateMemoryObjectsEXT, (GLsizei n, GLuint * memoryObjects), (n, memoryObjects)) \
  X(void, glMemoryObjectParameterivEXT, (GLuint memoryObject, GLenum pname, const GLint * params), (memoryObject, pname, params)) \
  X(void, glGetMemoryObjectParameterivEXT, (GLuint memoryObject, GLenum pname, GLint * params), (memoryObject, pname, params)) \
  X(void, glTexStorageMem2DEXT, (GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLuint memory, GLuint64 offset), (target, levels, internalFormat, width, height, memory, offset)) \
  X(void, glTexStorageMem2DMultisampleEXT, (GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset), (target, samples, internalFormat, width, height, fixedSampleLocations, memory, offset)) \
  X(void, glTexStorageMem3DEXT, (GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset), (target, levels, internalFormat, width, height, depth, memory, offset)) \
  X(void, glTexStorageMem3DMultisampleEXT, (GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset), (target, samples, internalFormat, width, height, depth, fixedSampleLocations, memory, offset)) \
  X(void, glBufferStorageMemEXT, (GLenum target, GLsizeiptr size, GLuint memory, GLuint64 offset), (target, size, memory, offset)) \
  X(void, glTexParameteriHOST, (GLenum target, GLenum pname, GLint param), (target, pname, param)) \
  X(void, glImportSemaphoreFdEXT, (GLuint semaphore, GLenum handleType, GLint fd), (semaphore, handleType, fd)) \
  X(void, glImportSemaphoreWin32HandleEXT, (GLuint semaphore, GLenum handleType, void* handle), (semaphore, handleType, handle)) \
  X(void, glGenSemaphoresEXT, (GLsizei n, GLuint * semaphores), (n, semaphores)) \
  X(void, glDeleteSemaphoresEXT, (GLsizei n, const GLuint * semaphores), (n, semaphores)) \
  X(GLboolean, glIsSemaphoreEXT, (GLuint semaphore), (semaphore)) \
  X(void, glSemaphoreParameterui64vEXT, (GLuint semaphore, GLenum pname, const GLuint64 * params), (semaphore, pname, params)) \
  X(void, glGetSemaphoreParameterui64vEXT, (GLuint semaphore, GLenum pname, GLuint64 * params), (semaphore, pname, params)) \
  X(void, glWaitSemaphoreEXT, (GLuint semaphore, GLuint numBufferBarriers, const GLuint * buffers, GLuint numTextureBarriers, const GLuint * textures, const GLenum * srcLayouts), (semaphore, numBufferBarriers, buffers, numTextureBarriers, textures, srcLayouts)) \
  X(void, glSignalSemaphoreEXT, (GLuint semaphore, GLuint numBufferBarriers, const GLuint * buffers, GLuint numTextureBarriers, const GLuint * textures, const GLenum * dstLayouts), (semaphore, numBufferBarriers, buffers, numTextureBarriers, textures, dstLayouts)) \
  X(GLuint, glGetGlobalTexName, (GLuint localTexName), (localTexName)) \


#endif  // GLES_EXTENSIONS_FUNCTIONS_H
