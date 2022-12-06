// Auto-generated with: android/scripts/gen-entries.py --mode=funcargs stream-servers/gl/OpenGLESDispatch/gles1_extensions.entries --output=include/OpenGLESDispatch/gles1_extensions_functions.h
// DO NOT EDIT THIS FILE

#ifndef GLES1_EXTENSIONS_FUNCTIONS_H
#define GLES1_EXTENSIONS_FUNCTIONS_H

#define LIST_GLES1_EXTENSIONS_FUNCTIONS(X) \
  X(void, glCurrentPaletteMatrixARB, (GLint index), (index)) \
  X(void, glMatrixIndexuivARB, (GLint size, GLuint * indices), (size, indices)) \
  X(void, glMatrixIndexPointerARB, (GLint size, GLenum type, GLsizei stride, const GLvoid* pointer), (size, type, stride, pointer)) \
  X(void, glWeightPointerARB, (GLint size, GLenum type, GLsizei stride, const GLvoid* pointer), (size, type, stride, pointer)) \
  X(void, glTexGenf, (GLenum coord, GLenum pname, GLfloat param), (coord, pname, param)) \
  X(void, glTexGeni, (GLenum coord, GLenum pname, GLint param), (coord, pname, param)) \
  X(void, glTexGenfv, (GLenum coord, GLenum pname, const GLfloat * params), (coord, pname, params)) \
  X(void, glTexGeniv, (GLenum coord, GLenum pname, const GLint * params), (coord, pname, params)) \
  X(void, glGetTexGenfv, (GLenum coord, GLenum pname, GLfloat * params), (coord, pname, params)) \
  X(void, glGetTexGeniv, (GLenum coord, GLenum pname, GLint * params), (coord, pname, params)) \
  X(void, glColorPointerWithDataSize, (GLint size, GLenum type, GLsizei stride, const GLvoid * pointer, GLsizei dataSize), (size, type, stride, pointer, dataSize)) \
  X(void, glNormalPointerWithDataSize, (GLenum type, GLsizei stride, const GLvoid * pointer, GLsizei dataSize), (type, stride, pointer, dataSize)) \
  X(void, glTexCoordPointerWithDataSize, (GLint size, GLenum type, GLsizei stride, const GLvoid * pointer, GLsizei dataSize), (size, type, stride, pointer, dataSize)) \
  X(void, glVertexPointerWithDataSize, (GLint size, GLenum type, GLsizei stride, const GLvoid * pointer, GLsizei dataSize), (size, type, stride, pointer, dataSize)) \
  X(void, glPointSizePointerOES, (GLenum type, GLsizei stride, const GLvoid * pointer), (type, stride, pointer)) \
  X(void, glBlendEquationSeparateOES, (GLenum modeRGB, GLenum modeAlpha), (modeRGB, modeAlpha)) \
  X(void, glBlendFuncSeparateOES, (GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha), (srcRGB, dstRGB, srcAlpha, dstAlpha)) \
  X(void, glBlendEquationOES, (GLenum mode), (mode)) \
  X(void, glDrawTexsOES, (GLshort x, GLshort y, GLshort z, GLshort width, GLshort height), (x, y, z, width, height)) \
  X(void, glDrawTexiOES, (GLint x, GLint y, GLint z, GLint width, GLint height), (x, y, z, width, height)) \
  X(void, glDrawTexxOES, (GLfixed x, GLfixed y, GLfixed z, GLfixed width, GLfixed height), (x, y, z, width, height)) \
  X(void, glDrawTexsvOES, (const GLshort * coords), (coords)) \
  X(void, glDrawTexivOES, (const GLint * coords), (coords)) \
  X(void, glDrawTexxvOES, (const GLfixed * coords), (coords)) \
  X(void, glDrawTexfOES, (GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height), (x, y, z, width, height)) \
  X(void, glDrawTexfvOES, (const GLfloat * coords), (coords)) \
  X(GLboolean, glIsRenderbufferOES, (GLuint renderbuffer), (renderbuffer)) \
  X(void, glBindRenderbufferOES, (GLenum target, GLuint renderbuffer), (target, renderbuffer)) \
  X(void, glDeleteRenderbuffersOES, (GLsizei n, const GLuint* renderbuffers), (n, renderbuffers)) \
  X(void, glGenRenderbuffersOES, (GLsizei n, GLuint* renderbuffers), (n, renderbuffers)) \
  X(void, glRenderbufferStorageOES, (GLenum target, GLenum internalformat, GLsizei width, GLsizei height), (target, internalformat, width, height)) \
  X(void, glGetRenderbufferParameterivOES, (GLenum target, GLenum pname, GLint* params), (target, pname, params)) \
  X(GLboolean, glIsFramebufferOES, (GLuint framebuffer), (framebuffer)) \
  X(void, glBindFramebufferOES, (GLenum target, GLuint framebuffer), (target, framebuffer)) \
  X(void, glDeleteFramebuffersOES, (GLsizei n, const GLuint* framebuffers), (n, framebuffers)) \
  X(void, glGenFramebuffersOES, (GLsizei n, GLuint* framebuffers), (n, framebuffers)) \
  X(GLenum, glCheckFramebufferStatusOES, (GLenum target), (target)) \
  X(void, glFramebufferRenderbufferOES, (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer), (target, attachment, renderbuffertarget, renderbuffer)) \
  X(void, glFramebufferTexture2DOES, (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level), (target, attachment, textarget, texture, level)) \
  X(void, glGetFramebufferAttachmentParameterivOES, (GLenum target, GLenum attachment, GLenum pname, GLint* params), (target, attachment, pname, params)) \
  X(void, glGenerateMipmapOES, (GLenum target), (target)) \
  X(void, glCurrentPaletteMatrixOES, (GLuint matrixpaletteindex), (matrixpaletteindex)) \
  X(void, glLoadPaletteFromModelViewMatrixOES, (), ()) \
  X(void, glMatrixIndexPointerOES, (GLint size, GLenum type, GLsizei stride, const GLvoid * pointer), (size, type, stride, pointer)) \
  X(void, glWeightPointerOES, (GLint size, GLenum type, GLsizei stride, const GLvoid * pointer), (size, type, stride, pointer)) \
  X(void, glTexGenfOES, (GLenum coord, GLenum pname, GLfloat param), (coord, pname, param)) \
  X(void, glTexGenfvOES, (GLenum coord, GLenum pname, const GLfloat * params), (coord, pname, params)) \
  X(void, glTexGeniOES, (GLenum coord, GLenum pname, GLint param), (coord, pname, param)) \
  X(void, glTexGenivOES, (GLenum coord, GLenum pname, const GLint * params), (coord, pname, params)) \
  X(void, glTexGenxOES, (GLenum coord, GLenum pname, GLfixed param), (coord, pname, param)) \
  X(void, glTexGenxvOES, (GLenum coord, GLenum pname, const GLfixed * params), (coord, pname, params)) \
  X(void, glGetTexGenfvOES, (GLenum coord, GLenum pname, GLfloat * params), (coord, pname, params)) \
  X(void, glGetTexGenivOES, (GLenum coord, GLenum pname, GLint * params), (coord, pname, params)) \
  X(void, glGetTexGenxvOES, (GLenum coord, GLenum pname, GLfixed * params), (coord, pname, params)) \


#endif  // GLES1_EXTENSIONS_FUNCTIONS_H
