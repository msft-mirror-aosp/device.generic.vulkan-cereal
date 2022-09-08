// Auto-generated with: android/scripts/gen-entries.py --mode=static_translator_namespaced_header stream-servers/gl/OpenGLESDispatch/gles1_extensions.entries --output=gldispatch/include/OpenGLESDispatch/gles1_extensions_static_translator_namespaced_header.h
// DO NOT EDIT THIS FILE

#pragma once

namespace translator {
namespace gles1 {
GL_APICALL void GL_APIENTRY glCurrentPaletteMatrixARB(GLint index);
GL_APICALL void GL_APIENTRY glMatrixIndexuivARB(GLint size, GLuint * indices);
GL_APICALL void GL_APIENTRY glMatrixIndexPointerARB(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
GL_APICALL void GL_APIENTRY glWeightPointerARB(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
GL_APICALL void GL_APIENTRY glTexGenf(GLenum coord, GLenum pname, GLfloat param);
GL_APICALL void GL_APIENTRY glTexGeni(GLenum coord, GLenum pname, GLint param);
GL_APICALL void GL_APIENTRY glTexGenfv(GLenum coord, GLenum pname, const GLfloat * params);
GL_APICALL void GL_APIENTRY glTexGeniv(GLenum coord, GLenum pname, const GLint * params);
GL_APICALL void GL_APIENTRY glGetTexGenfv(GLenum coord, GLenum pname, GLfloat * params);
GL_APICALL void GL_APIENTRY glGetTexGeniv(GLenum coord, GLenum pname, GLint * params);
GL_APICALL void GL_APIENTRY glColorPointerWithDataSize(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer, GLsizei dataSize);
GL_APICALL void GL_APIENTRY glNormalPointerWithDataSize(GLenum type, GLsizei stride, const GLvoid * pointer, GLsizei dataSize);
GL_APICALL void GL_APIENTRY glTexCoordPointerWithDataSize(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer, GLsizei dataSize);
GL_APICALL void GL_APIENTRY glVertexPointerWithDataSize(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer, GLsizei dataSize);
GL_APICALL void GL_APIENTRY glPointSizePointerOES(GLenum type, GLsizei stride, const GLvoid * pointer);
GL_APICALL void GL_APIENTRY glBlendEquationSeparateOES(GLenum modeRGB, GLenum modeAlpha);
GL_APICALL void GL_APIENTRY glBlendFuncSeparateOES(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
GL_APICALL void GL_APIENTRY glBlendEquationOES(GLenum mode);
GL_APICALL void GL_APIENTRY glDrawTexsOES(GLshort x, GLshort y, GLshort z, GLshort width, GLshort height);
GL_APICALL void GL_APIENTRY glDrawTexiOES(GLint x, GLint y, GLint z, GLint width, GLint height);
GL_APICALL void GL_APIENTRY glDrawTexxOES(GLfixed x, GLfixed y, GLfixed z, GLfixed width, GLfixed height);
GL_APICALL void GL_APIENTRY glDrawTexsvOES(const GLshort * coords);
GL_APICALL void GL_APIENTRY glDrawTexivOES(const GLint * coords);
GL_APICALL void GL_APIENTRY glDrawTexxvOES(const GLfixed * coords);
GL_APICALL void GL_APIENTRY glDrawTexfOES(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height);
GL_APICALL void GL_APIENTRY glDrawTexfvOES(const GLfloat * coords);
GL_APICALL GLboolean GL_APIENTRY glIsRenderbufferOES(GLuint renderbuffer);
GL_APICALL void GL_APIENTRY glBindRenderbufferOES(GLenum target, GLuint renderbuffer);
GL_APICALL void GL_APIENTRY glDeleteRenderbuffersOES(GLsizei n, const GLuint* renderbuffers);
GL_APICALL void GL_APIENTRY glGenRenderbuffersOES(GLsizei n, GLuint* renderbuffers);
GL_APICALL void GL_APIENTRY glRenderbufferStorageOES(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
GL_APICALL void GL_APIENTRY glGetRenderbufferParameterivOES(GLenum target, GLenum pname, GLint* params);
GL_APICALL GLboolean GL_APIENTRY glIsFramebufferOES(GLuint framebuffer);
GL_APICALL void GL_APIENTRY glBindFramebufferOES(GLenum target, GLuint framebuffer);
GL_APICALL void GL_APIENTRY glDeleteFramebuffersOES(GLsizei n, const GLuint* framebuffers);
GL_APICALL void GL_APIENTRY glGenFramebuffersOES(GLsizei n, GLuint* framebuffers);
GL_APICALL GLenum GL_APIENTRY glCheckFramebufferStatusOES(GLenum target);
GL_APICALL void GL_APIENTRY glFramebufferRenderbufferOES(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GL_APICALL void GL_APIENTRY glFramebufferTexture2DOES(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GL_APICALL void GL_APIENTRY glGetFramebufferAttachmentParameterivOES(GLenum target, GLenum attachment, GLenum pname, GLint* params);
GL_APICALL void GL_APIENTRY glGenerateMipmapOES(GLenum target);
GL_APICALL void GL_APIENTRY glCurrentPaletteMatrixOES(GLuint matrixpaletteindex);
GL_APICALL void GL_APIENTRY glLoadPaletteFromModelViewMatrixOES();
GL_APICALL void GL_APIENTRY glMatrixIndexPointerOES(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
GL_APICALL void GL_APIENTRY glWeightPointerOES(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
GL_APICALL void GL_APIENTRY glTexGenfOES(GLenum coord, GLenum pname, GLfloat param);
GL_APICALL void GL_APIENTRY glTexGenfvOES(GLenum coord, GLenum pname, const GLfloat * params);
GL_APICALL void GL_APIENTRY glTexGeniOES(GLenum coord, GLenum pname, GLint param);
GL_APICALL void GL_APIENTRY glTexGenivOES(GLenum coord, GLenum pname, const GLint * params);
GL_APICALL void GL_APIENTRY glTexGenxOES(GLenum coord, GLenum pname, GLfixed param);
GL_APICALL void GL_APIENTRY glTexGenxvOES(GLenum coord, GLenum pname, const GLfixed * params);
GL_APICALL void GL_APIENTRY glGetTexGenfvOES(GLenum coord, GLenum pname, GLfloat * params);
GL_APICALL void GL_APIENTRY glGetTexGenivOES(GLenum coord, GLenum pname, GLint * params);
GL_APICALL void GL_APIENTRY glGetTexGenxvOES(GLenum coord, GLenum pname, GLfixed * params);
} // namespace translator
} // namespace gles1
