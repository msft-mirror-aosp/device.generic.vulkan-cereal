// Auto-generated with: android/scripts/gen-entries.py --mode=static_translator_namespaced_header stream-servers/gl/OpenGLESDispatch/gles3_only.entries --output=gldispatch/include/OpenGLESDispatch/gles3_only_static_translator_namespaced_header.h
// DO NOT EDIT THIS FILE

#pragma once

#include <GLES/gl.h>
#include <GLES3/gl3.h>
namespace translator {
namespace gles2 {
GL_APICALL GLconstubyteptr GL_APIENTRY glGetStringi(GLenum name, GLint index);
GL_APICALL void GL_APIENTRY glGenVertexArrays(GLsizei n, GLuint* arrays);
GL_APICALL void GL_APIENTRY glBindVertexArray(GLuint array);
GL_APICALL void GL_APIENTRY glDeleteVertexArrays(GLsizei n, const GLuint * arrays);
GL_APICALL GLboolean GL_APIENTRY glIsVertexArray(GLuint array);
GL_APICALL void * GL_APIENTRY glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
GL_APICALL GLboolean GL_APIENTRY glUnmapBuffer(GLenum target);
GL_APICALL void GL_APIENTRY glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length);
GL_APICALL void GL_APIENTRY glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
GL_APICALL void GL_APIENTRY glBindBufferBase(GLenum target, GLuint index, GLuint buffer);
GL_APICALL void GL_APIENTRY glCopyBufferSubData(GLenum readtarget, GLenum writetarget, GLintptr readoffset, GLintptr writeoffset, GLsizeiptr size);
GL_APICALL void GL_APIENTRY glClearBufferiv(GLenum buffer, GLint drawBuffer, const GLint * value);
GL_APICALL void GL_APIENTRY glClearBufferuiv(GLenum buffer, GLint drawBuffer, const GLuint * value);
GL_APICALL void GL_APIENTRY glClearBufferfv(GLenum buffer, GLint drawBuffer, const GLfloat * value);
GL_APICALL void GL_APIENTRY glClearBufferfi(GLenum buffer, GLint drawBuffer, GLfloat depth, GLint stencil);
GL_APICALL void GL_APIENTRY glGetBufferParameteri64v(GLenum target, GLenum value, GLint64 * data);
GL_APICALL void GL_APIENTRY glGetBufferPointerv(GLenum target, GLenum pname, GLvoid ** params);
GL_APICALL void GL_APIENTRY glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
GL_APICALL GLuint GL_APIENTRY glGetUniformBlockIndex(GLuint program, const GLchar * uniformBlockName);
GL_APICALL void GL_APIENTRY glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar ** uniformNames, GLuint * uniformIndices);
GL_APICALL void GL_APIENTRY glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params);
GL_APICALL void GL_APIENTRY glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName);
GL_APICALL void GL_APIENTRY glUniform1ui(GLint location, GLuint v0);
GL_APICALL void GL_APIENTRY glUniform2ui(GLint location, GLuint v0, GLuint v1);
GL_APICALL void GL_APIENTRY glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2);
GL_APICALL void GL_APIENTRY glUniform4ui(GLint location, GLint v0, GLuint v1, GLuint v2, GLuint v3);
GL_APICALL void GL_APIENTRY glUniform1uiv(GLint location, GLsizei count, const GLuint * value);
GL_APICALL void GL_APIENTRY glUniform2uiv(GLint location, GLsizei count, const GLuint * value);
GL_APICALL void GL_APIENTRY glUniform3uiv(GLint location, GLsizei count, const GLuint * value);
GL_APICALL void GL_APIENTRY glUniform4uiv(GLint location, GLsizei count, const GLuint * value);
GL_APICALL void GL_APIENTRY glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
GL_APICALL void GL_APIENTRY glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
GL_APICALL void GL_APIENTRY glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
GL_APICALL void GL_APIENTRY glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
GL_APICALL void GL_APIENTRY glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
GL_APICALL void GL_APIENTRY glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
GL_APICALL void GL_APIENTRY glGetUniformuiv(GLuint program, GLint location, GLuint * params);
GL_APICALL void GL_APIENTRY glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint * uniformIndices, GLenum pname, GLint * params);
GL_APICALL void GL_APIENTRY glVertexAttribI4i(GLuint index, GLint v0, GLint v1, GLint v2, GLint v3);
GL_APICALL void GL_APIENTRY glVertexAttribI4ui(GLuint index, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GL_APICALL void GL_APIENTRY glVertexAttribI4iv(GLuint index, const GLint * v);
GL_APICALL void GL_APIENTRY glVertexAttribI4uiv(GLuint index, const GLuint * v);
GL_APICALL void GL_APIENTRY glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
GL_APICALL void GL_APIENTRY glGetVertexAttribIiv(GLuint index, GLenum pname, GLint * params);
GL_APICALL void GL_APIENTRY glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint * params);
GL_APICALL void GL_APIENTRY glVertexAttribDivisor(GLuint index, GLuint divisor);
GL_APICALL void GL_APIENTRY glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
GL_APICALL void GL_APIENTRY glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei primcount);
GL_APICALL void GL_APIENTRY glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid * indices);
GL_APICALL GLsync GL_APIENTRY glFenceSync(GLenum condition, GLbitfield flags);
GL_APICALL GLenum GL_APIENTRY glClientWaitSync(GLsync wait_on, GLbitfield flags, GLuint64 timeout);
GL_APICALL void GL_APIENTRY glWaitSync(GLsync wait_on, GLbitfield flags, GLuint64 timeout);
GL_APICALL void GL_APIENTRY glDeleteSync(GLsync to_delete);
GL_APICALL GLboolean GL_APIENTRY glIsSync(GLsync sync);
GL_APICALL void GL_APIENTRY glGetSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei * length, GLint * values);
GL_APICALL void GL_APIENTRY glDrawBuffers(GLsizei n, const GLenum * bufs);
GL_APICALL void GL_APIENTRY glReadBuffer(GLenum src);
GL_APICALL void GL_APIENTRY glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GL_APICALL void GL_APIENTRY glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum * attachments);
GL_APICALL void GL_APIENTRY glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height);
GL_APICALL void GL_APIENTRY glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
GL_APICALL void GL_APIENTRY glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint * params);
GL_APICALL void GL_APIENTRY glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
GL_APICALL void GL_APIENTRY glBeginTransformFeedback(GLenum primitiveMode);
GL_APICALL void GL_APIENTRY glEndTransformFeedback();
GL_APICALL void GL_APIENTRY glGenTransformFeedbacks(GLsizei n, GLuint * ids);
GL_APICALL void GL_APIENTRY glDeleteTransformFeedbacks(GLsizei n, const GLuint * ids);
GL_APICALL void GL_APIENTRY glBindTransformFeedback(GLenum target, GLuint id);
GL_APICALL void GL_APIENTRY glPauseTransformFeedback();
GL_APICALL void GL_APIENTRY glResumeTransformFeedback();
GL_APICALL GLboolean GL_APIENTRY glIsTransformFeedback(GLuint id);
GL_APICALL void GL_APIENTRY glTransformFeedbackVaryings(GLuint program, GLsizei count, const char ** varyings, GLenum bufferMode);
GL_APICALL void GL_APIENTRY glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, char * name);
GL_APICALL void GL_APIENTRY glGenSamplers(GLsizei n, GLuint * samplers);
GL_APICALL void GL_APIENTRY glDeleteSamplers(GLsizei n, const GLuint * samplers);
GL_APICALL void GL_APIENTRY glBindSampler(GLuint unit, GLuint sampler);
GL_APICALL void GL_APIENTRY glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param);
GL_APICALL void GL_APIENTRY glSamplerParameteri(GLuint sampler, GLenum pname, GLint param);
GL_APICALL void GL_APIENTRY glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat * params);
GL_APICALL void GL_APIENTRY glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint * params);
GL_APICALL void GL_APIENTRY glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat * params);
GL_APICALL void GL_APIENTRY glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint * params);
GL_APICALL GLboolean GL_APIENTRY glIsSampler(GLuint sampler);
GL_APICALL void GL_APIENTRY glGenQueries(GLsizei n, GLuint * queries);
GL_APICALL void GL_APIENTRY glDeleteQueries(GLsizei n, const GLuint * queries);
GL_APICALL void GL_APIENTRY glBeginQuery(GLenum target, GLuint query);
GL_APICALL void GL_APIENTRY glEndQuery(GLenum target);
GL_APICALL void GL_APIENTRY glGetQueryiv(GLenum target, GLenum pname, GLint * params);
GL_APICALL void GL_APIENTRY glGetQueryObjectuiv(GLuint query, GLenum pname, GLuint * params);
GL_APICALL GLboolean GL_APIENTRY glIsQuery(GLuint query);
GL_APICALL void GL_APIENTRY glProgramParameteri(GLuint program, GLenum pname, GLint value);
GL_APICALL void GL_APIENTRY glProgramBinary(GLuint program, GLenum binaryFormat, const void * binary, GLsizei length);
GL_APICALL void GL_APIENTRY glGetProgramBinary(GLuint program, GLsizei bufsize, GLsizei * length, GLenum * binaryFormat, void * binary);
GL_APICALL GLint GL_APIENTRY glGetFragDataLocation(GLuint program, const char * name);
GL_APICALL void GL_APIENTRY glGetInteger64v(GLenum pname, GLint64 * data);
GL_APICALL void GL_APIENTRY glGetIntegeri_v(GLenum target, GLuint index, GLint * data);
GL_APICALL void GL_APIENTRY glGetInteger64i_v(GLenum target, GLuint index, GLint64 * data);
GL_APICALL void GL_APIENTRY glTexImage3D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid * data);
GL_APICALL void GL_APIENTRY glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
GL_APICALL void GL_APIENTRY glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * data);
GL_APICALL void GL_APIENTRY glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid * data);
GL_APICALL void GL_APIENTRY glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid * data);
GL_APICALL void GL_APIENTRY glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
} // namespace translator
} // namespace gles2
