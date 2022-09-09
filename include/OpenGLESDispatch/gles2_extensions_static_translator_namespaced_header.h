// Auto-generated with: android/scripts/gen-entries.py --mode=static_translator_namespaced_header stream-servers/gl/OpenGLESDispatch/gles2_extensions.entries --output=gldispatch/include/OpenGLESDispatch/gles2_extensions_static_translator_namespaced_header.h
// DO NOT EDIT THIS FILE

#pragma once

#include <GLES/gl.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
namespace translator {
namespace gles2 {
GL_APICALL void GL_APIENTRY glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision);
GL_APICALL void GL_APIENTRY glReleaseShaderCompiler();
GL_APICALL void GL_APIENTRY glShaderBinary(GLsizei n, const GLuint* shaders, GLenum binaryformat, const GLvoid* binary, GLsizei length);
GL_APICALL void GL_APIENTRY glVertexAttribPointerWithDataSize(GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* ptr, GLsizei dataSize);
GL_APICALL void GL_APIENTRY glFramebufferTexture3DOES(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
GL_APICALL void GL_APIENTRY glTestHostDriverPerformance(GLuint count, uint64_t* duration_us, uint64_t* duration_cpu_us);
GL_APICALL void GL_APIENTRY glBindVertexArrayOES(GLuint array);
GL_APICALL void GL_APIENTRY glDeleteVertexArraysOES(GLsizei n, const GLuint * arrays);
GL_APICALL void GL_APIENTRY glGenVertexArraysOES(GLsizei n, GLuint * arrays);
GL_APICALL GLboolean GL_APIENTRY glIsVertexArrayOES(GLuint array);
GL_APICALL void GL_APIENTRY glDebugMessageControlKHR(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint * ids, GLboolean enabled);
GL_APICALL void GL_APIENTRY glDebugMessageInsertKHR(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar * buf);
GL_APICALL void GL_APIENTRY glDebugMessageCallbackKHR(GLDEBUGPROCKHR callback, const void * userParam);
GL_APICALL GLuint GL_APIENTRY glGetDebugMessageLogKHR(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog);
GL_APICALL void GL_APIENTRY glPushDebugGroupKHR(GLenum source, GLuint id, GLsizei length, const GLchar* message);
GL_APICALL void GL_APIENTRY glPopDebugGroupKHR();
} // namespace translator
} // namespace gles2
