#pragma once

// Prevent inclusion of other OpenGL-related headers

#if defined(__glew_h__) || defined(__GLEW_H__)
#error Attempt to include auto-generated header after including glew.h
#endif
#if defined(__gl_h_) || defined(__GL_H__)
#error Attempt to include auto-generated header after including gl.h
#endif
#if defined(__glext_h_) || defined(__GLEXT_H_)
#error Attempt to include auto-generated header after including glext.h
#endif
#if defined(__gltypes_h_)
#error Attempt to include auto-generated header after gltypes.h
#endif
#if defined(__gl_ATI_h_)
#error Attempt to include auto-generated header after including glATI.h
#endif

#define __glew_h__
#define __GLEW_H__
#define __gl_h_
#define __GL_H__
#define __glext_h_
#define __GLEXT_H_
#define __gltypes_h_
#define __gl_ATI_h_

// Undefine some macros that may interfere with OpenGL constants

#undef ZERO
#undef NONE
#undef TRUE
#undef ONE
#undef LOAD
#undef MULT
#undef ADD
#undef LESS
#undef BACK
#undef LEFT
#undef AUX0
#undef AUX1
#undef AUX2
#undef AUX3
#undef EXP
#undef EXP2
#undef CW
#undef CCW
#undef FOG
#undef BYTE
#undef INT
#undef AND
#undef COPY
#undef NOOP
#undef XOR
#undef OR
#undef NOR
#undef NAND
#undef SET
#undef RED
#undef BLUE
#undef RGB
#undef RGBA
#undef LINE
#undef FILL
#undef FLAT
#undef KEEP
#undef INCR
#undef DECR
#undef S
#undef T
#undef R
#undef Q
#undef V2F
#undef V3F
#undef MIN
#undef MAX
#undef RGB4
#undef RGB5
#undef RGB8
#undef BGR
#undef BGRA
#undef RG
#undef R8
#undef R16
#undef RG8
#undef RG16
#undef R16F
#undef R32F
#undef R8I
#undef R8UI
#undef R16I
#undef R32I
#undef RG8I
#undef BOOL
#undef SRGB
#undef TYPE

// OpenGL type definitions

#include <KHR/khrplatform.h>
typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef void GLvoid;
typedef khronos_int8_t GLbyte;
typedef khronos_uint8_t GLubyte;
typedef khronos_int16_t GLshort;
typedef khronos_uint16_t GLushort;
typedef int GLint;
typedef unsigned int GLuint;
typedef khronos_int32_t GLclampx;
typedef int GLsizei;
typedef khronos_float_t GLfloat;
typedef khronos_float_t GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void *GLeglClientBufferEXT;
typedef void *GLeglImageOES;
typedef char GLchar;
typedef char GLcharARB;
#ifdef __APPLE__
typedef void *GLhandleARB;
#else
typedef unsigned int GLhandleARB;
#endif
typedef khronos_uint16_t GLhalf;
typedef khronos_uint16_t GLhalfARB;
typedef khronos_int32_t GLfixed;
typedef khronos_intptr_t GLintptr;
typedef khronos_intptr_t GLintptrARB;
typedef khronos_ssize_t GLsizeiptr;
typedef khronos_ssize_t GLsizeiptrARB;
typedef khronos_int64_t GLint64;
typedef khronos_int64_t GLint64EXT;
typedef khronos_uint64_t GLuint64;
typedef khronos_uint64_t GLuint64EXT;
typedef struct __GLsync *GLsync;
struct _cl_context;
struct _cl_event;
typedef void (GLDEBUGPROC)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
typedef void (GLDEBUGPROCARB)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
typedef void (GLDEBUGPROCKHR)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
typedef void (GLDEBUGPROCAMD)(GLuint id,GLenum category,GLenum severity,GLsizei length,const GLchar *message,void *userParam);
typedef unsigned short GLhalfNV;
typedef GLintptr GLvdpauSurfaceNV;
typedef void (GLVULKANPROCNV)(void);

namespace gl
{

	namespace internal
	{

		// OpenGL 1.0

		extern void (*glCullFace)(GLenum mode);
		extern void (*glFrontFace)(GLenum mode);
		extern void (*glHint)(GLenum target, GLenum mode);
		extern void (*glLineWidth)(GLfloat width);
		extern void (*glPointSize)(GLfloat size);
		extern void (*glPolygonMode)(GLenum face, GLenum mode);
		extern void (*glScissor)(GLint x, GLint y, GLsizei width, GLsizei height);
		extern void (*glTexParameterf)(GLenum target, GLenum pname, GLfloat param);
		extern void (*glTexParameterfv)(GLenum target, GLenum pname, const GLfloat *params);
		extern void (*glTexParameteri)(GLenum target, GLenum pname, GLint param);
		extern void (*glTexParameteriv)(GLenum target, GLenum pname, const GLint *params);
		extern void (*glTexImage1D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
		extern void (*glTexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
		extern void (*glDrawBuffer)(GLenum buf);
		extern void (*glClear)(GLbitfield mask);
		extern void (*glClearColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
		extern void (*glClearStencil)(GLint s);
		extern void (*glClearDepth)(GLdouble depth);
		extern void (*glStencilMask)(GLuint mask);
		extern void (*glColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
		extern void (*glDepthMask)(GLboolean flag);
		extern void (*glDisable)(GLenum cap);
		extern void (*glEnable)(GLenum cap);
		extern void (*glFinish)();
		extern void (*glFlush)();
		extern void (*glBlendFunc)(GLenum sfactor, GLenum dfactor);
		extern void (*glLogicOp)(GLenum opcode);
		extern void (*glStencilFunc)(GLenum func, GLint ref, GLuint mask);
		extern void (*glStencilOp)(GLenum fail, GLenum zfail, GLenum zpass);
		extern void (*glDepthFunc)(GLenum func);
		extern void (*glPixelStoref)(GLenum pname, GLfloat param);
		extern void (*glPixelStorei)(GLenum pname, GLint param);
		extern void (*glReadBuffer)(GLenum src);
		extern void (*glReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
		extern void (*glGetBooleanv)(GLenum pname, GLboolean *data);
		extern void (*glGetDoublev)(GLenum pname, GLdouble *data);
		extern GLenum (*glGetError)();
		extern void (*glGetFloatv)(GLenum pname, GLfloat *data);
		extern void (*glGetIntegerv)(GLenum pname, GLint *data);
		extern const GLubyte *(*glGetString)(GLenum name);
		extern void (*glGetTexImage)(GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
		extern void (*glGetTexParameterfv)(GLenum target, GLenum pname, GLfloat *params);
		extern void (*glGetTexParameteriv)(GLenum target, GLenum pname, GLint *params);
		extern void (*glGetTexLevelParameterfv)(GLenum target, GLint level, GLenum pname, GLfloat *params);
		extern void (*glGetTexLevelParameteriv)(GLenum target, GLint level, GLenum pname, GLint *params);
		extern GLboolean (*glIsEnabled)(GLenum cap);
		extern void (*glDepthRange)(GLdouble n, GLdouble f);
		extern void (*glViewport)(GLint x, GLint y, GLsizei width, GLsizei height);

		// OpenGL 1.1

		extern void (*glDrawArrays)(GLenum mode, GLint first, GLsizei count);
		extern void (*glDrawElements)(GLenum mode, GLsizei count, GLenum type, const void *indices);
		extern void (*glPolygonOffset)(GLfloat factor, GLfloat units);
		extern void (*glCopyTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
		extern void (*glCopyTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
		extern void (*glCopyTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
		extern void (*glCopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
		extern void (*glTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
		extern void (*glTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
		extern void (*glBindTexture)(GLenum target, GLuint texture);
		extern void (*glDeleteTextures)(GLsizei n, const GLuint *textures);
		extern void (*glGenTextures)(GLsizei n, GLuint *textures);
		extern GLboolean (*glIsTexture)(GLuint texture);

		// OpenGL 1.2

		extern void (*glDrawRangeElements)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
		extern void (*glTexImage3D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
		extern void (*glTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
		extern void (*glCopyTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);

		// OpenGL 1.3

		extern void (*glActiveTexture)(GLenum texture);
		extern void (*glSampleCoverage)(GLfloat value, GLboolean invert);
		extern void (*glCompressedTexImage3D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
		extern void (*glCompressedTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
		extern void (*glCompressedTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
		extern void (*glCompressedTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
		extern void (*glCompressedTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
		extern void (*glCompressedTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
		extern void (*glGetCompressedTexImage)(GLenum target, GLint level, void *img);

		// OpenGL 1.4

		extern void (*glBlendFuncSeparate)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
		extern void (*glMultiDrawArrays)(GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
		extern void (*glMultiDrawElements)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
		extern void (*glPointParameterf)(GLenum pname, GLfloat param);
		extern void (*glPointParameterfv)(GLenum pname, const GLfloat *params);
		extern void (*glPointParameteri)(GLenum pname, GLint param);
		extern void (*glPointParameteriv)(GLenum pname, const GLint *params);
		extern void (*glBlendColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
		extern void (*glBlendEquation)(GLenum mode);

		// OpenGL 1.5

		extern void (*glGenQueries)(GLsizei n, GLuint *ids);
		extern void (*glDeleteQueries)(GLsizei n, const GLuint *ids);
		extern GLboolean (*glIsQuery)(GLuint id);
		extern void (*glBeginQuery)(GLenum target, GLuint id);
		extern void (*glEndQuery)(GLenum target);
		extern void (*glGetQueryiv)(GLenum target, GLenum pname, GLint *params);
		extern void (*glGetQueryObjectiv)(GLuint id, GLenum pname, GLint *params);
		extern void (*glGetQueryObjectuiv)(GLuint id, GLenum pname, GLuint *params);
		extern void (*glBindBuffer)(GLenum target, GLuint buffer);
		extern void (*glDeleteBuffers)(GLsizei n, const GLuint *buffers);
		extern void (*glGenBuffers)(GLsizei n, GLuint *buffers);
		extern GLboolean (*glIsBuffer)(GLuint buffer);
		extern void (*glBufferData)(GLenum target, GLsizeiptr size, const void *data, GLenum usage);
		extern void (*glBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
		extern void (*glGetBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, void *data);
		extern void *(*glMapBuffer)(GLenum target, GLenum access);
		extern GLboolean (*glUnmapBuffer)(GLenum target);
		extern void (*glGetBufferParameteriv)(GLenum target, GLenum pname, GLint *params);
		extern void (*glGetBufferPointerv)(GLenum target, GLenum pname, void **params);

		// OpenGL 2.0

		extern void (*glBlendEquationSeparate)(GLenum modeRGB, GLenum modeAlpha);
		extern void (*glDrawBuffers)(GLsizei n, const GLenum *bufs);
		extern void (*glStencilOpSeparate)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
		extern void (*glStencilFuncSeparate)(GLenum face, GLenum func, GLint ref, GLuint mask);
		extern void (*glStencilMaskSeparate)(GLenum face, GLuint mask);
		extern void (*glAttachShader)(GLuint program, GLuint shader);
		extern void (*glBindAttribLocation)(GLuint program, GLuint index, const GLchar *name);
		extern void (*glCompileShader)(GLuint shader);
		extern GLuint (*glCreateProgram)();
		extern GLuint (*glCreateShader)(GLenum type);
		extern void (*glDeleteProgram)(GLuint program);
		extern void (*glDeleteShader)(GLuint shader);
		extern void (*glDetachShader)(GLuint program, GLuint shader);
		extern void (*glDisableVertexAttribArray)(GLuint index);
		extern void (*glEnableVertexAttribArray)(GLuint index);
		extern void (*glGetActiveAttrib)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
		extern void (*glGetActiveUniform)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
		extern void (*glGetAttachedShaders)(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
		extern GLint (*glGetAttribLocation)(GLuint program, const GLchar *name);
		extern void (*glGetProgramiv)(GLuint program, GLenum pname, GLint *params);
		extern void (*glGetProgramInfoLog)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
		extern void (*glGetShaderiv)(GLuint shader, GLenum pname, GLint *params);
		extern void (*glGetShaderInfoLog)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
		extern void (*glGetShaderSource)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
		extern GLint (*glGetUniformLocation)(GLuint program, const GLchar *name);
		extern void (*glGetUniformfv)(GLuint program, GLint location, GLfloat *params);
		extern void (*glGetUniformiv)(GLuint program, GLint location, GLint *params);
		extern void (*glGetVertexAttribdv)(GLuint index, GLenum pname, GLdouble *params);
		extern void (*glGetVertexAttribfv)(GLuint index, GLenum pname, GLfloat *params);
		extern void (*glGetVertexAttribiv)(GLuint index, GLenum pname, GLint *params);
		extern void (*glGetVertexAttribPointerv)(GLuint index, GLenum pname, void **pointer);
		extern GLboolean (*glIsProgram)(GLuint program);
		extern GLboolean (*glIsShader)(GLuint shader);
		extern void (*glLinkProgram)(GLuint program);
		extern void (*glShaderSource)(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
		extern void (*glUseProgram)(GLuint program);
		extern void (*glUniform1f)(GLint location, GLfloat v0);
		extern void (*glUniform2f)(GLint location, GLfloat v0, GLfloat v1);
		extern void (*glUniform3f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
		extern void (*glUniform4f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
		extern void (*glUniform1i)(GLint location, GLint v0);
		extern void (*glUniform2i)(GLint location, GLint v0, GLint v1);
		extern void (*glUniform3i)(GLint location, GLint v0, GLint v1, GLint v2);
		extern void (*glUniform4i)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
		extern void (*glUniform1fv)(GLint location, GLsizei count, const GLfloat *value);
		extern void (*glUniform2fv)(GLint location, GLsizei count, const GLfloat *value);
		extern void (*glUniform3fv)(GLint location, GLsizei count, const GLfloat *value);
		extern void (*glUniform4fv)(GLint location, GLsizei count, const GLfloat *value);
		extern void (*glUniform1iv)(GLint location, GLsizei count, const GLint *value);
		extern void (*glUniform2iv)(GLint location, GLsizei count, const GLint *value);
		extern void (*glUniform3iv)(GLint location, GLsizei count, const GLint *value);
		extern void (*glUniform4iv)(GLint location, GLsizei count, const GLint *value);
		extern void (*glUniformMatrix2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
		extern void (*glUniformMatrix3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
		extern void (*glUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
		extern void (*glValidateProgram)(GLuint program);
		extern void (*glVertexAttrib1d)(GLuint index, GLdouble x);
		extern void (*glVertexAttrib1dv)(GLuint index, const GLdouble *v);
		extern void (*glVertexAttrib1f)(GLuint index, GLfloat x);
		extern void (*glVertexAttrib1fv)(GLuint index, const GLfloat *v);
		extern void (*glVertexAttrib1s)(GLuint index, GLshort x);
		extern void (*glVertexAttrib1sv)(GLuint index, const GLshort *v);
		extern void (*glVertexAttrib2d)(GLuint index, GLdouble x, GLdouble y);
		extern void (*glVertexAttrib2dv)(GLuint index, const GLdouble *v);
		extern void (*glVertexAttrib2f)(GLuint index, GLfloat x, GLfloat y);
		extern void (*glVertexAttrib2fv)(GLuint index, const GLfloat *v);
		extern void (*glVertexAttrib2s)(GLuint index, GLshort x, GLshort y);
		extern void (*glVertexAttrib2sv)(GLuint index, const GLshort *v);
		extern void (*glVertexAttrib3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
		extern void (*glVertexAttrib3dv)(GLuint index, const GLdouble *v);
		extern void (*glVertexAttrib3f)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
		extern void (*glVertexAttrib3fv)(GLuint index, const GLfloat *v);
		extern void (*glVertexAttrib3s)(GLuint index, GLshort x, GLshort y, GLshort z);
		extern void (*glVertexAttrib3sv)(GLuint index, const GLshort *v);
		extern void (*glVertexAttrib4Nbv)(GLuint index, const GLbyte *v);
		extern void (*glVertexAttrib4Niv)(GLuint index, const GLint *v);
		extern void (*glVertexAttrib4Nsv)(GLuint index, const GLshort *v);
		extern void (*glVertexAttrib4Nub)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
		extern void (*glVertexAttrib4Nubv)(GLuint index, const GLubyte *v);
		extern void (*glVertexAttrib4Nuiv)(GLuint index, const GLuint *v);
		extern void (*glVertexAttrib4Nusv)(GLuint index, const GLushort *v);
		extern void (*glVertexAttrib4bv)(GLuint index, const GLbyte *v);
		extern void (*glVertexAttrib4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
		extern void (*glVertexAttrib4dv)(GLuint index, const GLdouble *v);
		extern void (*glVertexAttrib4f)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
		extern void (*glVertexAttrib4fv)(GLuint index, const GLfloat *v);
		extern void (*glVertexAttrib4iv)(GLuint index, const GLint *v);
		extern void (*glVertexAttrib4s)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
		extern void (*glVertexAttrib4sv)(GLuint index, const GLshort *v);
		extern void (*glVertexAttrib4ubv)(GLuint index, const GLubyte *v);
		extern void (*glVertexAttrib4uiv)(GLuint index, const GLuint *v);
		extern void (*glVertexAttrib4usv)(GLuint index, const GLushort *v);
		extern void (*glVertexAttribPointer)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);

		// OpenGL 2.1

		extern void (*glUniformMatrix2x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
		extern void (*glUniformMatrix3x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
		extern void (*glUniformMatrix2x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
		extern void (*glUniformMatrix4x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
		extern void (*glUniformMatrix3x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
		extern void (*glUniformMatrix4x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);

		// OpenGL 3.0

		extern void (*glColorMaski)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
		extern void (*glGetBooleani_v)(GLenum target, GLuint index, GLboolean *data);
		extern void (*glGetIntegeri_v)(GLenum target, GLuint index, GLint *data);
		extern void (*glEnablei)(GLenum target, GLuint index);
		extern void (*glDisablei)(GLenum target, GLuint index);
		extern GLboolean (*glIsEnabledi)(GLenum target, GLuint index);
		extern void (*glBeginTransformFeedback)(GLenum primitiveMode);
		extern void (*glEndTransformFeedback)();
		extern void (*glBindBufferRange)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
		extern void (*glBindBufferBase)(GLenum target, GLuint index, GLuint buffer);
		extern void (*glTransformFeedbackVaryings)(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
		extern void (*glGetTransformFeedbackVarying)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
		extern void (*glClampColor)(GLenum target, GLenum clamp);
		extern void (*glBeginConditionalRender)(GLuint id, GLenum mode);
		extern void (*glEndConditionalRender)();
		extern void (*glVertexAttribIPointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
		extern void (*glGetVertexAttribIiv)(GLuint index, GLenum pname, GLint *params);
		extern void (*glGetVertexAttribIuiv)(GLuint index, GLenum pname, GLuint *params);
		extern void (*glVertexAttribI1i)(GLuint index, GLint x);
		extern void (*glVertexAttribI2i)(GLuint index, GLint x, GLint y);
		extern void (*glVertexAttribI3i)(GLuint index, GLint x, GLint y, GLint z);
		extern void (*glVertexAttribI4i)(GLuint index, GLint x, GLint y, GLint z, GLint w);
		extern void (*glVertexAttribI1ui)(GLuint index, GLuint x);
		extern void (*glVertexAttribI2ui)(GLuint index, GLuint x, GLuint y);
		extern void (*glVertexAttribI3ui)(GLuint index, GLuint x, GLuint y, GLuint z);
		extern void (*glVertexAttribI4ui)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
		extern void (*glVertexAttribI1iv)(GLuint index, const GLint *v);
		extern void (*glVertexAttribI2iv)(GLuint index, const GLint *v);
		extern void (*glVertexAttribI3iv)(GLuint index, const GLint *v);
		extern void (*glVertexAttribI4iv)(GLuint index, const GLint *v);
		extern void (*glVertexAttribI1uiv)(GLuint index, const GLuint *v);
		extern void (*glVertexAttribI2uiv)(GLuint index, const GLuint *v);
		extern void (*glVertexAttribI3uiv)(GLuint index, const GLuint *v);
		extern void (*glVertexAttribI4uiv)(GLuint index, const GLuint *v);
		extern void (*glVertexAttribI4bv)(GLuint index, const GLbyte *v);
		extern void (*glVertexAttribI4sv)(GLuint index, const GLshort *v);
		extern void (*glVertexAttribI4ubv)(GLuint index, const GLubyte *v);
		extern void (*glVertexAttribI4usv)(GLuint index, const GLushort *v);
		extern void (*glGetUniformuiv)(GLuint program, GLint location, GLuint *params);
		extern void (*glBindFragDataLocation)(GLuint program, GLuint color, const GLchar *name);
		extern GLint (*glGetFragDataLocation)(GLuint program, const GLchar *name);
		extern void (*glUniform1ui)(GLint location, GLuint v0);
		extern void (*glUniform2ui)(GLint location, GLuint v0, GLuint v1);
		extern void (*glUniform3ui)(GLint location, GLuint v0, GLuint v1, GLuint v2);
		extern void (*glUniform4ui)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
		extern void (*glUniform1uiv)(GLint location, GLsizei count, const GLuint *value);
		extern void (*glUniform2uiv)(GLint location, GLsizei count, const GLuint *value);
		extern void (*glUniform3uiv)(GLint location, GLsizei count, const GLuint *value);
		extern void (*glUniform4uiv)(GLint location, GLsizei count, const GLuint *value);
		extern void (*glTexParameterIiv)(GLenum target, GLenum pname, const GLint *params);
		extern void (*glTexParameterIuiv)(GLenum target, GLenum pname, const GLuint *params);
		extern void (*glGetTexParameterIiv)(GLenum target, GLenum pname, GLint *params);
		extern void (*glGetTexParameterIuiv)(GLenum target, GLenum pname, GLuint *params);
		extern void (*glClearBufferiv)(GLenum buffer, GLint drawbuffer, const GLint *value);
		extern void (*glClearBufferuiv)(GLenum buffer, GLint drawbuffer, const GLuint *value);
		extern void (*glClearBufferfv)(GLenum buffer, GLint drawbuffer, const GLfloat *value);
		extern void (*glClearBufferfi)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
		extern const GLubyte *(*glGetStringi)(GLenum name, GLuint index);
		extern GLboolean (*glIsRenderbuffer)(GLuint renderbuffer);
		extern void (*glBindRenderbuffer)(GLenum target, GLuint renderbuffer);
		extern void (*glDeleteRenderbuffers)(GLsizei n, const GLuint *renderbuffers);
		extern void (*glGenRenderbuffers)(GLsizei n, GLuint *renderbuffers);
		extern void (*glRenderbufferStorage)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
		extern void (*glGetRenderbufferParameteriv)(GLenum target, GLenum pname, GLint *params);
		extern GLboolean (*glIsFramebuffer)(GLuint framebuffer);
		extern void (*glBindFramebuffer)(GLenum target, GLuint framebuffer);
		extern void (*glDeleteFramebuffers)(GLsizei n, const GLuint *framebuffers);
		extern void (*glGenFramebuffers)(GLsizei n, GLuint *framebuffers);
		extern GLenum (*glCheckFramebufferStatus)(GLenum target);
		extern void (*glFramebufferTexture1D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
		extern void (*glFramebufferTexture2D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
		extern void (*glFramebufferTexture3D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
		extern void (*glFramebufferRenderbuffer)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
		extern void (*glGetFramebufferAttachmentParameteriv)(GLenum target, GLenum attachment, GLenum pname, GLint *params);
		extern void (*glGenerateMipmap)(GLenum target);
		extern void (*glBlitFramebuffer)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
		extern void (*glRenderbufferStorageMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
		extern void (*glFramebufferTextureLayer)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
		extern void *(*glMapBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
		extern void (*glFlushMappedBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length);
		extern void (*glBindVertexArray)(GLuint array);
		extern void (*glDeleteVertexArrays)(GLsizei n, const GLuint *arrays);
		extern void (*glGenVertexArrays)(GLsizei n, GLuint *arrays);
		extern GLboolean (*glIsVertexArray)(GLuint array);

		// OpenGL 3.1

		extern void (*glDrawArraysInstanced)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
		extern void (*glDrawElementsInstanced)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
		extern void (*glTexBuffer)(GLenum target, GLenum internalformat, GLuint buffer);
		extern void (*glPrimitiveRestartIndex)(GLuint index);
		extern void (*glCopyBufferSubData)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
		extern void (*glGetUniformIndices)(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
		extern void (*glGetActiveUniformsiv)(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
		extern void (*glGetActiveUniformName)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
		extern GLuint (*glGetUniformBlockIndex)(GLuint program, const GLchar *uniformBlockName);
		extern void (*glGetActiveUniformBlockiv)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
		extern void (*glGetActiveUniformBlockName)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
		extern void (*glUniformBlockBinding)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);

		// OpenGL 3.2

		extern void (*glDrawElementsBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
		extern void (*glDrawRangeElementsBaseVertex)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
		extern void (*glDrawElementsInstancedBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
		extern void (*glMultiDrawElementsBaseVertex)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
		extern void (*glProvokingVertex)(GLenum mode);
		extern GLsync (*glFenceSync)(GLenum condition, GLbitfield flags);
		extern GLboolean (*glIsSync)(GLsync sync);
		extern void (*glDeleteSync)(GLsync sync);
		extern GLenum (*glClientWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout);
		extern void (*glWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout);
		extern void (*glGetInteger64v)(GLenum pname, GLint64 *data);
		extern void (*glGetSynciv)(GLsync sync, GLenum pname, GLsizei count, GLsizei *length, GLint *values);
		extern void (*glGetInteger64i_v)(GLenum target, GLuint index, GLint64 *data);
		extern void (*glGetBufferParameteri64v)(GLenum target, GLenum pname, GLint64 *params);
		extern void (*glFramebufferTexture)(GLenum target, GLenum attachment, GLuint texture, GLint level);
		extern void (*glTexImage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
		extern void (*glTexImage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
		extern void (*glGetMultisamplefv)(GLenum pname, GLuint index, GLfloat *val);
		extern void (*glSampleMaski)(GLuint maskNumber, GLbitfield mask);

		// OpenGL 3.3

		extern void (*glBindFragDataLocationIndexed)(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
		extern GLint (*glGetFragDataIndex)(GLuint program, const GLchar *name);
		extern void (*glGenSamplers)(GLsizei count, GLuint *samplers);
		extern void (*glDeleteSamplers)(GLsizei count, const GLuint *samplers);
		extern GLboolean (*glIsSampler)(GLuint sampler);
		extern void (*glBindSampler)(GLuint unit, GLuint sampler);
		extern void (*glSamplerParameteri)(GLuint sampler, GLenum pname, GLint param);
		extern void (*glSamplerParameteriv)(GLuint sampler, GLenum pname, const GLint *param);
		extern void (*glSamplerParameterf)(GLuint sampler, GLenum pname, GLfloat param);
		extern void (*glSamplerParameterfv)(GLuint sampler, GLenum pname, const GLfloat *param);
		extern void (*glSamplerParameterIiv)(GLuint sampler, GLenum pname, const GLint *param);
		extern void (*glSamplerParameterIuiv)(GLuint sampler, GLenum pname, const GLuint *param);
		extern void (*glGetSamplerParameteriv)(GLuint sampler, GLenum pname, GLint *params);
		extern void (*glGetSamplerParameterIiv)(GLuint sampler, GLenum pname, GLint *params);
		extern void (*glGetSamplerParameterfv)(GLuint sampler, GLenum pname, GLfloat *params);
		extern void (*glGetSamplerParameterIuiv)(GLuint sampler, GLenum pname, GLuint *params);
		extern void (*glQueryCounter)(GLuint id, GLenum target);
		extern void (*glGetQueryObjecti64v)(GLuint id, GLenum pname, GLint64 *params);
		extern void (*glGetQueryObjectui64v)(GLuint id, GLenum pname, GLuint64 *params);
		extern void (*glVertexAttribDivisor)(GLuint index, GLuint divisor);
		extern void (*glVertexAttribP1ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
		extern void (*glVertexAttribP1uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
		extern void (*glVertexAttribP2ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
		extern void (*glVertexAttribP2uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
		extern void (*glVertexAttribP3ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
		extern void (*glVertexAttribP3uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
		extern void (*glVertexAttribP4ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
		extern void (*glVertexAttribP4uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);

		// GL_ARB_compute_shader

		extern void (*glDispatchCompute)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
		extern void (*glDispatchComputeIndirect)(GLintptr indirect);

		// GL_ARB_texture_filter_anisotropic


	} // namespace internal

	// OpenGL 1.0

	constexpr GLenum DEPTH_BUFFER_BIT = 0x00000100;
	constexpr GLenum STENCIL_BUFFER_BIT = 0x00000400;
	constexpr GLenum COLOR_BUFFER_BIT = 0x00004000;
	constexpr GLenum FALSE = 0;
	constexpr GLenum TRUE = 1;
	constexpr GLenum POINTS = 0x0000;
	constexpr GLenum LINES = 0x0001;
	constexpr GLenum LINE_LOOP = 0x0002;
	constexpr GLenum LINE_STRIP = 0x0003;
	constexpr GLenum TRIANGLES = 0x0004;
	constexpr GLenum TRIANGLE_STRIP = 0x0005;
	constexpr GLenum TRIANGLE_FAN = 0x0006;
	constexpr GLenum NEVER = 0x0200;
	constexpr GLenum LESS = 0x0201;
	constexpr GLenum EQUAL = 0x0202;
	constexpr GLenum LEQUAL = 0x0203;
	constexpr GLenum GREATER = 0x0204;
	constexpr GLenum NOTEQUAL = 0x0205;
	constexpr GLenum GEQUAL = 0x0206;
	constexpr GLenum ALWAYS = 0x0207;
	constexpr GLenum ZERO = 0;
	constexpr GLenum ONE = 1;
	constexpr GLenum SRC_COLOR = 0x0300;
	constexpr GLenum ONE_MINUS_SRC_COLOR = 0x0301;
	constexpr GLenum SRC_ALPHA = 0x0302;
	constexpr GLenum ONE_MINUS_SRC_ALPHA = 0x0303;
	constexpr GLenum DST_ALPHA = 0x0304;
	constexpr GLenum ONE_MINUS_DST_ALPHA = 0x0305;
	constexpr GLenum DST_COLOR = 0x0306;
	constexpr GLenum ONE_MINUS_DST_COLOR = 0x0307;
	constexpr GLenum SRC_ALPHA_SATURATE = 0x0308;
	constexpr GLenum NONE = 0;
	constexpr GLenum FRONT_LEFT = 0x0400;
	constexpr GLenum FRONT_RIGHT = 0x0401;
	constexpr GLenum BACK_LEFT = 0x0402;
	constexpr GLenum BACK_RIGHT = 0x0403;
	constexpr GLenum FRONT = 0x0404;
	constexpr GLenum BACK = 0x0405;
	constexpr GLenum LEFT = 0x0406;
	constexpr GLenum RIGHT = 0x0407;
	constexpr GLenum FRONT_AND_BACK = 0x0408;
	constexpr GLenum NO_ERROR = 0;
	constexpr GLenum INVALID_ENUM = 0x0500;
	constexpr GLenum INVALID_VALUE = 0x0501;
	constexpr GLenum INVALID_OPERATION = 0x0502;
	constexpr GLenum OUT_OF_MEMORY = 0x0505;
	constexpr GLenum CW = 0x0900;
	constexpr GLenum CCW = 0x0901;
	constexpr GLenum POINT_SIZE = 0x0B11;
	constexpr GLenum POINT_SIZE_RANGE = 0x0B12;
	constexpr GLenum POINT_SIZE_GRANULARITY = 0x0B13;
	constexpr GLenum LINE_SMOOTH = 0x0B20;
	constexpr GLenum LINE_WIDTH = 0x0B21;
	constexpr GLenum LINE_WIDTH_RANGE = 0x0B22;
	constexpr GLenum LINE_WIDTH_GRANULARITY = 0x0B23;
	constexpr GLenum POLYGON_MODE = 0x0B40;
	constexpr GLenum POLYGON_SMOOTH = 0x0B41;
	constexpr GLenum CULL_FACE = 0x0B44;
	constexpr GLenum CULL_FACE_MODE = 0x0B45;
	constexpr GLenum FRONT_FACE = 0x0B46;
	constexpr GLenum DEPTH_RANGE = 0x0B70;
	constexpr GLenum DEPTH_TEST = 0x0B71;
	constexpr GLenum DEPTH_WRITEMASK = 0x0B72;
	constexpr GLenum DEPTH_CLEAR_VALUE = 0x0B73;
	constexpr GLenum DEPTH_FUNC = 0x0B74;
	constexpr GLenum STENCIL_TEST = 0x0B90;
	constexpr GLenum STENCIL_CLEAR_VALUE = 0x0B91;
	constexpr GLenum STENCIL_FUNC = 0x0B92;
	constexpr GLenum STENCIL_VALUE_MASK = 0x0B93;
	constexpr GLenum STENCIL_FAIL = 0x0B94;
	constexpr GLenum STENCIL_PASS_DEPTH_FAIL = 0x0B95;
	constexpr GLenum STENCIL_PASS_DEPTH_PASS = 0x0B96;
	constexpr GLenum STENCIL_REF = 0x0B97;
	constexpr GLenum STENCIL_WRITEMASK = 0x0B98;
	constexpr GLenum VIEWPORT = 0x0BA2;
	constexpr GLenum DITHER = 0x0BD0;
	constexpr GLenum BLEND_DST = 0x0BE0;
	constexpr GLenum BLEND_SRC = 0x0BE1;
	constexpr GLenum BLEND = 0x0BE2;
	constexpr GLenum LOGIC_OP_MODE = 0x0BF0;
	constexpr GLenum DRAW_BUFFER = 0x0C01;
	constexpr GLenum READ_BUFFER = 0x0C02;
	constexpr GLenum SCISSOR_BOX = 0x0C10;
	constexpr GLenum SCISSOR_TEST = 0x0C11;
	constexpr GLenum COLOR_CLEAR_VALUE = 0x0C22;
	constexpr GLenum COLOR_WRITEMASK = 0x0C23;
	constexpr GLenum DOUBLEBUFFER = 0x0C32;
	constexpr GLenum STEREO = 0x0C33;
	constexpr GLenum LINE_SMOOTH_HINT = 0x0C52;
	constexpr GLenum POLYGON_SMOOTH_HINT = 0x0C53;
	constexpr GLenum UNPACK_SWAP_BYTES = 0x0CF0;
	constexpr GLenum UNPACK_LSB_FIRST = 0x0CF1;
	constexpr GLenum UNPACK_ROW_LENGTH = 0x0CF2;
	constexpr GLenum UNPACK_SKIP_ROWS = 0x0CF3;
	constexpr GLenum UNPACK_SKIP_PIXELS = 0x0CF4;
	constexpr GLenum UNPACK_ALIGNMENT = 0x0CF5;
	constexpr GLenum PACK_SWAP_BYTES = 0x0D00;
	constexpr GLenum PACK_LSB_FIRST = 0x0D01;
	constexpr GLenum PACK_ROW_LENGTH = 0x0D02;
	constexpr GLenum PACK_SKIP_ROWS = 0x0D03;
	constexpr GLenum PACK_SKIP_PIXELS = 0x0D04;
	constexpr GLenum PACK_ALIGNMENT = 0x0D05;
	constexpr GLenum MAX_TEXTURE_SIZE = 0x0D33;
	constexpr GLenum MAX_VIEWPORT_DIMS = 0x0D3A;
	constexpr GLenum SUBPIXEL_BITS = 0x0D50;
	constexpr GLenum TEXTURE_1D = 0x0DE0;
	constexpr GLenum TEXTURE_2D = 0x0DE1;
	constexpr GLenum TEXTURE_WIDTH = 0x1000;
	constexpr GLenum TEXTURE_HEIGHT = 0x1001;
	constexpr GLenum TEXTURE_BORDER_COLOR = 0x1004;
	constexpr GLenum DONT_CARE = 0x1100;
	constexpr GLenum FASTEST = 0x1101;
	constexpr GLenum NICEST = 0x1102;
	constexpr GLenum BYTE = 0x1400;
	constexpr GLenum UNSIGNED_BYTE = 0x1401;
	constexpr GLenum SHORT = 0x1402;
	constexpr GLenum UNSIGNED_SHORT = 0x1403;
	constexpr GLenum INT = 0x1404;
	constexpr GLenum UNSIGNED_INT = 0x1405;
	constexpr GLenum FLOAT = 0x1406;
	constexpr GLenum CLEAR = 0x1500;
	constexpr GLenum AND = 0x1501;
	constexpr GLenum AND_REVERSE = 0x1502;
	constexpr GLenum COPY = 0x1503;
	constexpr GLenum AND_INVERTED = 0x1504;
	constexpr GLenum NOOP = 0x1505;
	constexpr GLenum XOR = 0x1506;
	constexpr GLenum OR = 0x1507;
	constexpr GLenum NOR = 0x1508;
	constexpr GLenum EQUIV = 0x1509;
	constexpr GLenum INVERT = 0x150A;
	constexpr GLenum OR_REVERSE = 0x150B;
	constexpr GLenum COPY_INVERTED = 0x150C;
	constexpr GLenum OR_INVERTED = 0x150D;
	constexpr GLenum NAND = 0x150E;
	constexpr GLenum SET = 0x150F;
	constexpr GLenum TEXTURE = 0x1702;
	constexpr GLenum COLOR = 0x1800;
	constexpr GLenum DEPTH = 0x1801;
	constexpr GLenum STENCIL = 0x1802;
	constexpr GLenum STENCIL_INDEX = 0x1901;
	constexpr GLenum DEPTH_COMPONENT = 0x1902;
	constexpr GLenum RED = 0x1903;
	constexpr GLenum GREEN = 0x1904;
	constexpr GLenum BLUE = 0x1905;
	constexpr GLenum ALPHA = 0x1906;
	constexpr GLenum RGB = 0x1907;
	constexpr GLenum RGBA = 0x1908;
	constexpr GLenum POINT = 0x1B00;
	constexpr GLenum LINE = 0x1B01;
	constexpr GLenum FILL = 0x1B02;
	constexpr GLenum KEEP = 0x1E00;
	constexpr GLenum REPLACE = 0x1E01;
	constexpr GLenum INCR = 0x1E02;
	constexpr GLenum DECR = 0x1E03;
	constexpr GLenum VENDOR = 0x1F00;
	constexpr GLenum RENDERER = 0x1F01;
	constexpr GLenum VERSION = 0x1F02;
	constexpr GLenum EXTENSIONS = 0x1F03;
	constexpr GLenum NEAREST = 0x2600;
	constexpr GLenum LINEAR = 0x2601;
	constexpr GLenum NEAREST_MIPMAP_NEAREST = 0x2700;
	constexpr GLenum LINEAR_MIPMAP_NEAREST = 0x2701;
	constexpr GLenum NEAREST_MIPMAP_LINEAR = 0x2702;
	constexpr GLenum LINEAR_MIPMAP_LINEAR = 0x2703;
	constexpr GLenum TEXTURE_MAG_FILTER = 0x2800;
	constexpr GLenum TEXTURE_MIN_FILTER = 0x2801;
	constexpr GLenum TEXTURE_WRAP_S = 0x2802;
	constexpr GLenum TEXTURE_WRAP_T = 0x2803;
	constexpr GLenum REPEAT = 0x2901;

	inline void CullFace(GLenum mode){ return internal::glCullFace(mode); }
	inline void FrontFace(GLenum mode){ return internal::glFrontFace(mode); }
	inline void Hint(GLenum target, GLenum mode){ return internal::glHint(target, mode); }
	inline void LineWidth(GLfloat width){ return internal::glLineWidth(width); }
	inline void PointSize(GLfloat size){ return internal::glPointSize(size); }
	inline void PolygonMode(GLenum face, GLenum mode){ return internal::glPolygonMode(face, mode); }
	inline void Scissor(GLint x, GLint y, GLsizei width, GLsizei height){ return internal::glScissor(x, y, width, height); }
	inline void TexParameterf(GLenum target, GLenum pname, GLfloat param){ return internal::glTexParameterf(target, pname, param); }
	inline void TexParameterfv(GLenum target, GLenum pname, const GLfloat *params){ return internal::glTexParameterfv(target, pname, params); }
	inline void TexParameteri(GLenum target, GLenum pname, GLint param){ return internal::glTexParameteri(target, pname, param); }
	inline void TexParameteriv(GLenum target, GLenum pname, const GLint *params){ return internal::glTexParameteriv(target, pname, params); }
	inline void TexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels){ return internal::glTexImage1D(target, level, internalformat, width, border, format, type, pixels); }
	inline void TexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels){ return internal::glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels); }
	inline void DrawBuffer(GLenum buf){ return internal::glDrawBuffer(buf); }
	inline void Clear(GLbitfield mask){ return internal::glClear(mask); }
	inline void ClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha){ return internal::glClearColor(red, green, blue, alpha); }
	inline void ClearStencil(GLint s){ return internal::glClearStencil(s); }
	inline void ClearDepth(GLdouble depth){ return internal::glClearDepth(depth); }
	inline void StencilMask(GLuint mask){ return internal::glStencilMask(mask); }
	inline void ColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha){ return internal::glColorMask(red, green, blue, alpha); }
	inline void DepthMask(GLboolean flag){ return internal::glDepthMask(flag); }
	inline void Disable(GLenum cap){ return internal::glDisable(cap); }
	inline void Enable(GLenum cap){ return internal::glEnable(cap); }
	inline void Finish(){ return internal::glFinish(); }
	inline void Flush(){ return internal::glFlush(); }
	inline void BlendFunc(GLenum sfactor, GLenum dfactor){ return internal::glBlendFunc(sfactor, dfactor); }
	inline void LogicOp(GLenum opcode){ return internal::glLogicOp(opcode); }
	inline void StencilFunc(GLenum func, GLint ref, GLuint mask){ return internal::glStencilFunc(func, ref, mask); }
	inline void StencilOp(GLenum fail, GLenum zfail, GLenum zpass){ return internal::glStencilOp(fail, zfail, zpass); }
	inline void DepthFunc(GLenum func){ return internal::glDepthFunc(func); }
	inline void PixelStoref(GLenum pname, GLfloat param){ return internal::glPixelStoref(pname, param); }
	inline void PixelStorei(GLenum pname, GLint param){ return internal::glPixelStorei(pname, param); }
	inline void ReadBuffer(GLenum src){ return internal::glReadBuffer(src); }
	inline void ReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels){ return internal::glReadPixels(x, y, width, height, format, type, pixels); }
	inline void GetBooleanv(GLenum pname, GLboolean *data){ return internal::glGetBooleanv(pname, data); }
	inline void GetDoublev(GLenum pname, GLdouble *data){ return internal::glGetDoublev(pname, data); }
	inline GLenum GetError(){ return internal::glGetError(); }
	inline void GetFloatv(GLenum pname, GLfloat *data){ return internal::glGetFloatv(pname, data); }
	inline void GetIntegerv(GLenum pname, GLint *data){ return internal::glGetIntegerv(pname, data); }
	inline const GLubyte *GetString(GLenum name){ return internal::glGetString(name); }
	inline void GetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void *pixels){ return internal::glGetTexImage(target, level, format, type, pixels); }
	inline void GetTexParameterfv(GLenum target, GLenum pname, GLfloat *params){ return internal::glGetTexParameterfv(target, pname, params); }
	inline void GetTexParameteriv(GLenum target, GLenum pname, GLint *params){ return internal::glGetTexParameteriv(target, pname, params); }
	inline void GetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params){ return internal::glGetTexLevelParameterfv(target, level, pname, params); }
	inline void GetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params){ return internal::glGetTexLevelParameteriv(target, level, pname, params); }
	inline GLboolean IsEnabled(GLenum cap){ return internal::glIsEnabled(cap); }
	inline void DepthRange(GLdouble n, GLdouble f){ return internal::glDepthRange(n, f); }
	inline void Viewport(GLint x, GLint y, GLsizei width, GLsizei height){ return internal::glViewport(x, y, width, height); }

	// OpenGL 1.1

	constexpr GLenum COLOR_LOGIC_OP = 0x0BF2;
	constexpr GLenum POLYGON_OFFSET_UNITS = 0x2A00;
	constexpr GLenum POLYGON_OFFSET_POINT = 0x2A01;
	constexpr GLenum POLYGON_OFFSET_LINE = 0x2A02;
	constexpr GLenum POLYGON_OFFSET_FILL = 0x8037;
	constexpr GLenum POLYGON_OFFSET_FACTOR = 0x8038;
	constexpr GLenum TEXTURE_BINDING_1D = 0x8068;
	constexpr GLenum TEXTURE_BINDING_2D = 0x8069;
	constexpr GLenum TEXTURE_INTERNAL_FORMAT = 0x1003;
	constexpr GLenum TEXTURE_RED_SIZE = 0x805C;
	constexpr GLenum TEXTURE_GREEN_SIZE = 0x805D;
	constexpr GLenum TEXTURE_BLUE_SIZE = 0x805E;
	constexpr GLenum TEXTURE_ALPHA_SIZE = 0x805F;
	constexpr GLenum DOUBLE = 0x140A;
	constexpr GLenum PROXY_TEXTURE_1D = 0x8063;
	constexpr GLenum PROXY_TEXTURE_2D = 0x8064;
	constexpr GLenum R3_G3_B2 = 0x2A10;
	constexpr GLenum RGB4 = 0x804F;
	constexpr GLenum RGB5 = 0x8050;
	constexpr GLenum RGB8 = 0x8051;
	constexpr GLenum RGB10 = 0x8052;
	constexpr GLenum RGB12 = 0x8053;
	constexpr GLenum RGB16 = 0x8054;
	constexpr GLenum RGBA2 = 0x8055;
	constexpr GLenum RGBA4 = 0x8056;
	constexpr GLenum RGB5_A1 = 0x8057;
	constexpr GLenum RGBA8 = 0x8058;
	constexpr GLenum RGB10_A2 = 0x8059;
	constexpr GLenum RGBA12 = 0x805A;
	constexpr GLenum RGBA16 = 0x805B;

	inline void DrawArrays(GLenum mode, GLint first, GLsizei count){ return internal::glDrawArrays(mode, first, count); }
	inline void DrawElements(GLenum mode, GLsizei count, GLenum type, const void *indices){ return internal::glDrawElements(mode, count, type, indices); }
	inline void PolygonOffset(GLfloat factor, GLfloat units){ return internal::glPolygonOffset(factor, units); }
	inline void CopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border){ return internal::glCopyTexImage1D(target, level, internalformat, x, y, width, border); }
	inline void CopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border){ return internal::glCopyTexImage2D(target, level, internalformat, x, y, width, height, border); }
	inline void CopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width){ return internal::glCopyTexSubImage1D(target, level, xoffset, x, y, width); }
	inline void CopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height){ return internal::glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height); }
	inline void TexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels){ return internal::glTexSubImage1D(target, level, xoffset, width, format, type, pixels); }
	inline void TexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels){ return internal::glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels); }
	inline void BindTexture(GLenum target, GLuint texture){ return internal::glBindTexture(target, texture); }
	inline void DeleteTextures(GLsizei n, const GLuint *textures){ return internal::glDeleteTextures(n, textures); }
	inline void GenTextures(GLsizei n, GLuint *textures){ return internal::glGenTextures(n, textures); }
	inline GLboolean IsTexture(GLuint texture){ return internal::glIsTexture(texture); }

	// OpenGL 1.2

	constexpr GLenum UNSIGNED_BYTE_3_3_2 = 0x8032;
	constexpr GLenum UNSIGNED_SHORT_4_4_4_4 = 0x8033;
	constexpr GLenum UNSIGNED_SHORT_5_5_5_1 = 0x8034;
	constexpr GLenum UNSIGNED_INT_8_8_8_8 = 0x8035;
	constexpr GLenum UNSIGNED_INT_10_10_10_2 = 0x8036;
	constexpr GLenum TEXTURE_BINDING_3D = 0x806A;
	constexpr GLenum PACK_SKIP_IMAGES = 0x806B;
	constexpr GLenum PACK_IMAGE_HEIGHT = 0x806C;
	constexpr GLenum UNPACK_SKIP_IMAGES = 0x806D;
	constexpr GLenum UNPACK_IMAGE_HEIGHT = 0x806E;
	constexpr GLenum TEXTURE_3D = 0x806F;
	constexpr GLenum PROXY_TEXTURE_3D = 0x8070;
	constexpr GLenum TEXTURE_DEPTH = 0x8071;
	constexpr GLenum TEXTURE_WRAP_R = 0x8072;
	constexpr GLenum MAX_3D_TEXTURE_SIZE = 0x8073;
	constexpr GLenum UNSIGNED_BYTE_2_3_3_REV = 0x8362;
	constexpr GLenum UNSIGNED_SHORT_5_6_5 = 0x8363;
	constexpr GLenum UNSIGNED_SHORT_5_6_5_REV = 0x8364;
	constexpr GLenum UNSIGNED_SHORT_4_4_4_4_REV = 0x8365;
	constexpr GLenum UNSIGNED_SHORT_1_5_5_5_REV = 0x8366;
	constexpr GLenum UNSIGNED_INT_8_8_8_8_REV = 0x8367;
	constexpr GLenum UNSIGNED_INT_2_10_10_10_REV = 0x8368;
	constexpr GLenum BGR = 0x80E0;
	constexpr GLenum BGRA = 0x80E1;
	constexpr GLenum MAX_ELEMENTS_VERTICES = 0x80E8;
	constexpr GLenum MAX_ELEMENTS_INDICES = 0x80E9;
	constexpr GLenum CLAMP_TO_EDGE = 0x812F;
	constexpr GLenum TEXTURE_MIN_LOD = 0x813A;
	constexpr GLenum TEXTURE_MAX_LOD = 0x813B;
	constexpr GLenum TEXTURE_BASE_LEVEL = 0x813C;
	constexpr GLenum TEXTURE_MAX_LEVEL = 0x813D;
	constexpr GLenum SMOOTH_POINT_SIZE_RANGE = 0x0B12;
	constexpr GLenum SMOOTH_POINT_SIZE_GRANULARITY = 0x0B13;
	constexpr GLenum SMOOTH_LINE_WIDTH_RANGE = 0x0B22;
	constexpr GLenum SMOOTH_LINE_WIDTH_GRANULARITY = 0x0B23;
	constexpr GLenum ALIASED_LINE_WIDTH_RANGE = 0x846E;

	inline void DrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices){ return internal::glDrawRangeElements(mode, start, end, count, type, indices); }
	inline void TexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels){ return internal::glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels); }
	inline void TexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels){ return internal::glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels); }
	inline void CopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height){ return internal::glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height); }

	// OpenGL 1.3

	constexpr GLenum TEXTURE0 = 0x84C0;
	constexpr GLenum TEXTURE1 = 0x84C1;
	constexpr GLenum TEXTURE2 = 0x84C2;
	constexpr GLenum TEXTURE3 = 0x84C3;
	constexpr GLenum TEXTURE4 = 0x84C4;
	constexpr GLenum TEXTURE5 = 0x84C5;
	constexpr GLenum TEXTURE6 = 0x84C6;
	constexpr GLenum TEXTURE7 = 0x84C7;
	constexpr GLenum TEXTURE8 = 0x84C8;
	constexpr GLenum TEXTURE9 = 0x84C9;
	constexpr GLenum TEXTURE10 = 0x84CA;
	constexpr GLenum TEXTURE11 = 0x84CB;
	constexpr GLenum TEXTURE12 = 0x84CC;
	constexpr GLenum TEXTURE13 = 0x84CD;
	constexpr GLenum TEXTURE14 = 0x84CE;
	constexpr GLenum TEXTURE15 = 0x84CF;
	constexpr GLenum TEXTURE16 = 0x84D0;
	constexpr GLenum TEXTURE17 = 0x84D1;
	constexpr GLenum TEXTURE18 = 0x84D2;
	constexpr GLenum TEXTURE19 = 0x84D3;
	constexpr GLenum TEXTURE20 = 0x84D4;
	constexpr GLenum TEXTURE21 = 0x84D5;
	constexpr GLenum TEXTURE22 = 0x84D6;
	constexpr GLenum TEXTURE23 = 0x84D7;
	constexpr GLenum TEXTURE24 = 0x84D8;
	constexpr GLenum TEXTURE25 = 0x84D9;
	constexpr GLenum TEXTURE26 = 0x84DA;
	constexpr GLenum TEXTURE27 = 0x84DB;
	constexpr GLenum TEXTURE28 = 0x84DC;
	constexpr GLenum TEXTURE29 = 0x84DD;
	constexpr GLenum TEXTURE30 = 0x84DE;
	constexpr GLenum TEXTURE31 = 0x84DF;
	constexpr GLenum ACTIVE_TEXTURE = 0x84E0;
	constexpr GLenum MULTISAMPLE = 0x809D;
	constexpr GLenum SAMPLE_ALPHA_TO_COVERAGE = 0x809E;
	constexpr GLenum SAMPLE_ALPHA_TO_ONE = 0x809F;
	constexpr GLenum SAMPLE_COVERAGE = 0x80A0;
	constexpr GLenum SAMPLE_BUFFERS = 0x80A8;
	constexpr GLenum SAMPLES = 0x80A9;
	constexpr GLenum SAMPLE_COVERAGE_VALUE = 0x80AA;
	constexpr GLenum SAMPLE_COVERAGE_INVERT = 0x80AB;
	constexpr GLenum TEXTURE_CUBE_MAP = 0x8513;
	constexpr GLenum TEXTURE_BINDING_CUBE_MAP = 0x8514;
	constexpr GLenum TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515;
	constexpr GLenum TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516;
	constexpr GLenum TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517;
	constexpr GLenum TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518;
	constexpr GLenum TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519;
	constexpr GLenum TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851A;
	constexpr GLenum PROXY_TEXTURE_CUBE_MAP = 0x851B;
	constexpr GLenum MAX_CUBE_MAP_TEXTURE_SIZE = 0x851C;
	constexpr GLenum COMPRESSED_RGB = 0x84ED;
	constexpr GLenum COMPRESSED_RGBA = 0x84EE;
	constexpr GLenum TEXTURE_COMPRESSION_HINT = 0x84EF;
	constexpr GLenum TEXTURE_COMPRESSED_IMAGE_SIZE = 0x86A0;
	constexpr GLenum TEXTURE_COMPRESSED = 0x86A1;
	constexpr GLenum NUM_COMPRESSED_TEXTURE_FORMATS = 0x86A2;
	constexpr GLenum COMPRESSED_TEXTURE_FORMATS = 0x86A3;
	constexpr GLenum CLAMP_TO_BORDER = 0x812D;

	inline void ActiveTexture(GLenum texture){ return internal::glActiveTexture(texture); }
	inline void SampleCoverage(GLfloat value, GLboolean invert){ return internal::glSampleCoverage(value, invert); }
	inline void CompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data){ return internal::glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data); }
	inline void CompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data){ return internal::glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data); }
	inline void CompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data){ return internal::glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data); }
	inline void CompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data){ return internal::glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data); }
	inline void CompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data){ return internal::glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data); }
	inline void CompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data){ return internal::glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data); }
	inline void GetCompressedTexImage(GLenum target, GLint level, void *img){ return internal::glGetCompressedTexImage(target, level, img); }

	// OpenGL 1.4

	constexpr GLenum BLEND_DST_RGB = 0x80C8;
	constexpr GLenum BLEND_SRC_RGB = 0x80C9;
	constexpr GLenum BLEND_DST_ALPHA = 0x80CA;
	constexpr GLenum BLEND_SRC_ALPHA = 0x80CB;
	constexpr GLenum POINT_FADE_THRESHOLD_SIZE = 0x8128;
	constexpr GLenum DEPTH_COMPONENT16 = 0x81A5;
	constexpr GLenum DEPTH_COMPONENT24 = 0x81A6;
	constexpr GLenum DEPTH_COMPONENT32 = 0x81A7;
	constexpr GLenum MIRRORED_REPEAT = 0x8370;
	constexpr GLenum MAX_TEXTURE_LOD_BIAS = 0x84FD;
	constexpr GLenum TEXTURE_LOD_BIAS = 0x8501;
	constexpr GLenum INCR_WRAP = 0x8507;
	constexpr GLenum DECR_WRAP = 0x8508;
	constexpr GLenum TEXTURE_DEPTH_SIZE = 0x884A;
	constexpr GLenum TEXTURE_COMPARE_MODE = 0x884C;
	constexpr GLenum TEXTURE_COMPARE_FUNC = 0x884D;
	constexpr GLenum BLEND_COLOR = 0x8005;
	constexpr GLenum BLEND_EQUATION = 0x8009;
	constexpr GLenum CONSTANT_COLOR = 0x8001;
	constexpr GLenum ONE_MINUS_CONSTANT_COLOR = 0x8002;
	constexpr GLenum CONSTANT_ALPHA = 0x8003;
	constexpr GLenum ONE_MINUS_CONSTANT_ALPHA = 0x8004;
	constexpr GLenum FUNC_ADD = 0x8006;
	constexpr GLenum FUNC_REVERSE_SUBTRACT = 0x800B;
	constexpr GLenum FUNC_SUBTRACT = 0x800A;
	constexpr GLenum MIN = 0x8007;
	constexpr GLenum MAX = 0x8008;

	inline void BlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha){ return internal::glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha); }
	inline void MultiDrawArrays(GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount){ return internal::glMultiDrawArrays(mode, first, count, drawcount); }
	inline void MultiDrawElements(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount){ return internal::glMultiDrawElements(mode, count, type, indices, drawcount); }
	inline void PointParameterf(GLenum pname, GLfloat param){ return internal::glPointParameterf(pname, param); }
	inline void PointParameterfv(GLenum pname, const GLfloat *params){ return internal::glPointParameterfv(pname, params); }
	inline void PointParameteri(GLenum pname, GLint param){ return internal::glPointParameteri(pname, param); }
	inline void PointParameteriv(GLenum pname, const GLint *params){ return internal::glPointParameteriv(pname, params); }
	inline void BlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha){ return internal::glBlendColor(red, green, blue, alpha); }
	inline void BlendEquation(GLenum mode){ return internal::glBlendEquation(mode); }

	// OpenGL 1.5

	constexpr GLenum BUFFER_SIZE = 0x8764;
	constexpr GLenum BUFFER_USAGE = 0x8765;
	constexpr GLenum QUERY_COUNTER_BITS = 0x8864;
	constexpr GLenum CURRENT_QUERY = 0x8865;
	constexpr GLenum QUERY_RESULT = 0x8866;
	constexpr GLenum QUERY_RESULT_AVAILABLE = 0x8867;
	constexpr GLenum ARRAY_BUFFER = 0x8892;
	constexpr GLenum ELEMENT_ARRAY_BUFFER = 0x8893;
	constexpr GLenum ARRAY_BUFFER_BINDING = 0x8894;
	constexpr GLenum ELEMENT_ARRAY_BUFFER_BINDING = 0x8895;
	constexpr GLenum VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F;
	constexpr GLenum READ_ONLY = 0x88B8;
	constexpr GLenum WRITE_ONLY = 0x88B9;
	constexpr GLenum READ_WRITE = 0x88BA;
	constexpr GLenum BUFFER_ACCESS = 0x88BB;
	constexpr GLenum BUFFER_MAPPED = 0x88BC;
	constexpr GLenum BUFFER_MAP_POINTER = 0x88BD;
	constexpr GLenum STREAM_DRAW = 0x88E0;
	constexpr GLenum STREAM_READ = 0x88E1;
	constexpr GLenum STREAM_COPY = 0x88E2;
	constexpr GLenum STATIC_DRAW = 0x88E4;
	constexpr GLenum STATIC_READ = 0x88E5;
	constexpr GLenum STATIC_COPY = 0x88E6;
	constexpr GLenum DYNAMIC_DRAW = 0x88E8;
	constexpr GLenum DYNAMIC_READ = 0x88E9;
	constexpr GLenum DYNAMIC_COPY = 0x88EA;
	constexpr GLenum SAMPLES_PASSED = 0x8914;
	constexpr GLenum SRC1_ALPHA = 0x8589;

	inline void GenQueries(GLsizei n, GLuint *ids){ return internal::glGenQueries(n, ids); }
	inline void DeleteQueries(GLsizei n, const GLuint *ids){ return internal::glDeleteQueries(n, ids); }
	inline GLboolean IsQuery(GLuint id){ return internal::glIsQuery(id); }
	inline void BeginQuery(GLenum target, GLuint id){ return internal::glBeginQuery(target, id); }
	inline void EndQuery(GLenum target){ return internal::glEndQuery(target); }
	inline void GetQueryiv(GLenum target, GLenum pname, GLint *params){ return internal::glGetQueryiv(target, pname, params); }
	inline void GetQueryObjectiv(GLuint id, GLenum pname, GLint *params){ return internal::glGetQueryObjectiv(id, pname, params); }
	inline void GetQueryObjectuiv(GLuint id, GLenum pname, GLuint *params){ return internal::glGetQueryObjectuiv(id, pname, params); }
	inline void BindBuffer(GLenum target, GLuint buffer){ return internal::glBindBuffer(target, buffer); }
	inline void DeleteBuffers(GLsizei n, const GLuint *buffers){ return internal::glDeleteBuffers(n, buffers); }
	inline void GenBuffers(GLsizei n, GLuint *buffers){ return internal::glGenBuffers(n, buffers); }
	inline GLboolean IsBuffer(GLuint buffer){ return internal::glIsBuffer(buffer); }
	inline void BufferData(GLenum target, GLsizeiptr size, const void *data, GLenum usage){ return internal::glBufferData(target, size, data, usage); }
	inline void BufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void *data){ return internal::glBufferSubData(target, offset, size, data); }
	inline void GetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void *data){ return internal::glGetBufferSubData(target, offset, size, data); }
	inline void *MapBuffer(GLenum target, GLenum access){ return internal::glMapBuffer(target, access); }
	inline GLboolean UnmapBuffer(GLenum target){ return internal::glUnmapBuffer(target); }
	inline void GetBufferParameteriv(GLenum target, GLenum pname, GLint *params){ return internal::glGetBufferParameteriv(target, pname, params); }
	inline void GetBufferPointerv(GLenum target, GLenum pname, void **params){ return internal::glGetBufferPointerv(target, pname, params); }

	// OpenGL 2.0

	constexpr GLenum BLEND_EQUATION_RGB = 0x8009;
	constexpr GLenum VERTEX_ATTRIB_ARRAY_ENABLED = 0x8622;
	constexpr GLenum VERTEX_ATTRIB_ARRAY_SIZE = 0x8623;
	constexpr GLenum VERTEX_ATTRIB_ARRAY_STRIDE = 0x8624;
	constexpr GLenum VERTEX_ATTRIB_ARRAY_TYPE = 0x8625;
	constexpr GLenum CURRENT_VERTEX_ATTRIB = 0x8626;
	constexpr GLenum VERTEX_PROGRAM_POINT_SIZE = 0x8642;
	constexpr GLenum VERTEX_ATTRIB_ARRAY_POINTER = 0x8645;
	constexpr GLenum STENCIL_BACK_FUNC = 0x8800;
	constexpr GLenum STENCIL_BACK_FAIL = 0x8801;
	constexpr GLenum STENCIL_BACK_PASS_DEPTH_FAIL = 0x8802;
	constexpr GLenum STENCIL_BACK_PASS_DEPTH_PASS = 0x8803;
	constexpr GLenum MAX_DRAW_BUFFERS = 0x8824;
	constexpr GLenum DRAW_BUFFER0 = 0x8825;
	constexpr GLenum DRAW_BUFFER1 = 0x8826;
	constexpr GLenum DRAW_BUFFER2 = 0x8827;
	constexpr GLenum DRAW_BUFFER3 = 0x8828;
	constexpr GLenum DRAW_BUFFER4 = 0x8829;
	constexpr GLenum DRAW_BUFFER5 = 0x882A;
	constexpr GLenum DRAW_BUFFER6 = 0x882B;
	constexpr GLenum DRAW_BUFFER7 = 0x882C;
	constexpr GLenum DRAW_BUFFER8 = 0x882D;
	constexpr GLenum DRAW_BUFFER9 = 0x882E;
	constexpr GLenum DRAW_BUFFER10 = 0x882F;
	constexpr GLenum DRAW_BUFFER11 = 0x8830;
	constexpr GLenum DRAW_BUFFER12 = 0x8831;
	constexpr GLenum DRAW_BUFFER13 = 0x8832;
	constexpr GLenum DRAW_BUFFER14 = 0x8833;
	constexpr GLenum DRAW_BUFFER15 = 0x8834;
	constexpr GLenum BLEND_EQUATION_ALPHA = 0x883D;
	constexpr GLenum MAX_VERTEX_ATTRIBS = 0x8869;
	constexpr GLenum VERTEX_ATTRIB_ARRAY_NORMALIZED = 0x886A;
	constexpr GLenum MAX_TEXTURE_IMAGE_UNITS = 0x8872;
	constexpr GLenum FRAGMENT_SHADER = 0x8B30;
	constexpr GLenum VERTEX_SHADER = 0x8B31;
	constexpr GLenum MAX_FRAGMENT_UNIFORM_COMPONENTS = 0x8B49;
	constexpr GLenum MAX_VERTEX_UNIFORM_COMPONENTS = 0x8B4A;
	constexpr GLenum MAX_VARYING_FLOATS = 0x8B4B;
	constexpr GLenum MAX_VERTEX_TEXTURE_IMAGE_UNITS = 0x8B4C;
	constexpr GLenum MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8B4D;
	constexpr GLenum SHADER_TYPE = 0x8B4F;
	constexpr GLenum FLOAT_VEC2 = 0x8B50;
	constexpr GLenum FLOAT_VEC3 = 0x8B51;
	constexpr GLenum FLOAT_VEC4 = 0x8B52;
	constexpr GLenum INT_VEC2 = 0x8B53;
	constexpr GLenum INT_VEC3 = 0x8B54;
	constexpr GLenum INT_VEC4 = 0x8B55;
	constexpr GLenum BOOL = 0x8B56;
	constexpr GLenum BOOL_VEC2 = 0x8B57;
	constexpr GLenum BOOL_VEC3 = 0x8B58;
	constexpr GLenum BOOL_VEC4 = 0x8B59;
	constexpr GLenum FLOAT_MAT2 = 0x8B5A;
	constexpr GLenum FLOAT_MAT3 = 0x8B5B;
	constexpr GLenum FLOAT_MAT4 = 0x8B5C;
	constexpr GLenum SAMPLER_1D = 0x8B5D;
	constexpr GLenum SAMPLER_2D = 0x8B5E;
	constexpr GLenum SAMPLER_3D = 0x8B5F;
	constexpr GLenum SAMPLER_CUBE = 0x8B60;
	constexpr GLenum SAMPLER_1D_SHADOW = 0x8B61;
	constexpr GLenum SAMPLER_2D_SHADOW = 0x8B62;
	constexpr GLenum DELETE_STATUS = 0x8B80;
	constexpr GLenum COMPILE_STATUS = 0x8B81;
	constexpr GLenum LINK_STATUS = 0x8B82;
	constexpr GLenum VALIDATE_STATUS = 0x8B83;
	constexpr GLenum INFO_LOG_LENGTH = 0x8B84;
	constexpr GLenum ATTACHED_SHADERS = 0x8B85;
	constexpr GLenum ACTIVE_UNIFORMS = 0x8B86;
	constexpr GLenum ACTIVE_UNIFORM_MAX_LENGTH = 0x8B87;
	constexpr GLenum SHADER_SOURCE_LENGTH = 0x8B88;
	constexpr GLenum ACTIVE_ATTRIBUTES = 0x8B89;
	constexpr GLenum ACTIVE_ATTRIBUTE_MAX_LENGTH = 0x8B8A;
	constexpr GLenum FRAGMENT_SHADER_DERIVATIVE_HINT = 0x8B8B;
	constexpr GLenum SHADING_LANGUAGE_VERSION = 0x8B8C;
	constexpr GLenum CURRENT_PROGRAM = 0x8B8D;
	constexpr GLenum POINT_SPRITE_COORD_ORIGIN = 0x8CA0;
	constexpr GLenum LOWER_LEFT = 0x8CA1;
	constexpr GLenum UPPER_LEFT = 0x8CA2;
	constexpr GLenum STENCIL_BACK_REF = 0x8CA3;
	constexpr GLenum STENCIL_BACK_VALUE_MASK = 0x8CA4;
	constexpr GLenum STENCIL_BACK_WRITEMASK = 0x8CA5;

	inline void BlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha){ return internal::glBlendEquationSeparate(modeRGB, modeAlpha); }
	inline void DrawBuffers(GLsizei n, const GLenum *bufs){ return internal::glDrawBuffers(n, bufs); }
	inline void StencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass){ return internal::glStencilOpSeparate(face, sfail, dpfail, dppass); }
	inline void StencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask){ return internal::glStencilFuncSeparate(face, func, ref, mask); }
	inline void StencilMaskSeparate(GLenum face, GLuint mask){ return internal::glStencilMaskSeparate(face, mask); }
	inline void AttachShader(GLuint program, GLuint shader){ return internal::glAttachShader(program, shader); }
	inline void BindAttribLocation(GLuint program, GLuint index, const GLchar *name){ return internal::glBindAttribLocation(program, index, name); }
	inline void CompileShader(GLuint shader){ return internal::glCompileShader(shader); }
	inline GLuint CreateProgram(){ return internal::glCreateProgram(); }
	inline GLuint CreateShader(GLenum type){ return internal::glCreateShader(type); }
	inline void DeleteProgram(GLuint program){ return internal::glDeleteProgram(program); }
	inline void DeleteShader(GLuint shader){ return internal::glDeleteShader(shader); }
	inline void DetachShader(GLuint program, GLuint shader){ return internal::glDetachShader(program, shader); }
	inline void DisableVertexAttribArray(GLuint index){ return internal::glDisableVertexAttribArray(index); }
	inline void EnableVertexAttribArray(GLuint index){ return internal::glEnableVertexAttribArray(index); }
	inline void GetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name){ return internal::glGetActiveAttrib(program, index, bufSize, length, size, type, name); }
	inline void GetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name){ return internal::glGetActiveUniform(program, index, bufSize, length, size, type, name); }
	inline void GetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders){ return internal::glGetAttachedShaders(program, maxCount, count, shaders); }
	inline GLint GetAttribLocation(GLuint program, const GLchar *name){ return internal::glGetAttribLocation(program, name); }
	inline void GetProgramiv(GLuint program, GLenum pname, GLint *params){ return internal::glGetProgramiv(program, pname, params); }
	inline void GetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog){ return internal::glGetProgramInfoLog(program, bufSize, length, infoLog); }
	inline void GetShaderiv(GLuint shader, GLenum pname, GLint *params){ return internal::glGetShaderiv(shader, pname, params); }
	inline void GetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog){ return internal::glGetShaderInfoLog(shader, bufSize, length, infoLog); }
	inline void GetShaderSource(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source){ return internal::glGetShaderSource(shader, bufSize, length, source); }
	inline GLint GetUniformLocation(GLuint program, const GLchar *name){ return internal::glGetUniformLocation(program, name); }
	inline void GetUniformfv(GLuint program, GLint location, GLfloat *params){ return internal::glGetUniformfv(program, location, params); }
	inline void GetUniformiv(GLuint program, GLint location, GLint *params){ return internal::glGetUniformiv(program, location, params); }
	inline void GetVertexAttribdv(GLuint index, GLenum pname, GLdouble *params){ return internal::glGetVertexAttribdv(index, pname, params); }
	inline void GetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params){ return internal::glGetVertexAttribfv(index, pname, params); }
	inline void GetVertexAttribiv(GLuint index, GLenum pname, GLint *params){ return internal::glGetVertexAttribiv(index, pname, params); }
	inline void GetVertexAttribPointerv(GLuint index, GLenum pname, void **pointer){ return internal::glGetVertexAttribPointerv(index, pname, pointer); }
	inline GLboolean IsProgram(GLuint program){ return internal::glIsProgram(program); }
	inline GLboolean IsShader(GLuint shader){ return internal::glIsShader(shader); }
	inline void LinkProgram(GLuint program){ return internal::glLinkProgram(program); }
	inline void ShaderSource(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length){ return internal::glShaderSource(shader, count, string, length); }
	inline void UseProgram(GLuint program){ return internal::glUseProgram(program); }
	inline void Uniform1f(GLint location, GLfloat v0){ return internal::glUniform1f(location, v0); }
	inline void Uniform2f(GLint location, GLfloat v0, GLfloat v1){ return internal::glUniform2f(location, v0, v1); }
	inline void Uniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2){ return internal::glUniform3f(location, v0, v1, v2); }
	inline void Uniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3){ return internal::glUniform4f(location, v0, v1, v2, v3); }
	inline void Uniform1i(GLint location, GLint v0){ return internal::glUniform1i(location, v0); }
	inline void Uniform2i(GLint location, GLint v0, GLint v1){ return internal::glUniform2i(location, v0, v1); }
	inline void Uniform3i(GLint location, GLint v0, GLint v1, GLint v2){ return internal::glUniform3i(location, v0, v1, v2); }
	inline void Uniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3){ return internal::glUniform4i(location, v0, v1, v2, v3); }
	inline void Uniform1fv(GLint location, GLsizei count, const GLfloat *value){ return internal::glUniform1fv(location, count, value); }
	inline void Uniform2fv(GLint location, GLsizei count, const GLfloat *value){ return internal::glUniform2fv(location, count, value); }
	inline void Uniform3fv(GLint location, GLsizei count, const GLfloat *value){ return internal::glUniform3fv(location, count, value); }
	inline void Uniform4fv(GLint location, GLsizei count, const GLfloat *value){ return internal::glUniform4fv(location, count, value); }
	inline void Uniform1iv(GLint location, GLsizei count, const GLint *value){ return internal::glUniform1iv(location, count, value); }
	inline void Uniform2iv(GLint location, GLsizei count, const GLint *value){ return internal::glUniform2iv(location, count, value); }
	inline void Uniform3iv(GLint location, GLsizei count, const GLint *value){ return internal::glUniform3iv(location, count, value); }
	inline void Uniform4iv(GLint location, GLsizei count, const GLint *value){ return internal::glUniform4iv(location, count, value); }
	inline void UniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value){ return internal::glUniformMatrix2fv(location, count, transpose, value); }
	inline void UniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value){ return internal::glUniformMatrix3fv(location, count, transpose, value); }
	inline void UniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value){ return internal::glUniformMatrix4fv(location, count, transpose, value); }
	inline void ValidateProgram(GLuint program){ return internal::glValidateProgram(program); }
	inline void VertexAttrib1d(GLuint index, GLdouble x){ return internal::glVertexAttrib1d(index, x); }
	inline void VertexAttrib1dv(GLuint index, const GLdouble *v){ return internal::glVertexAttrib1dv(index, v); }
	inline void VertexAttrib1f(GLuint index, GLfloat x){ return internal::glVertexAttrib1f(index, x); }
	inline void VertexAttrib1fv(GLuint index, const GLfloat *v){ return internal::glVertexAttrib1fv(index, v); }
	inline void VertexAttrib1s(GLuint index, GLshort x){ return internal::glVertexAttrib1s(index, x); }
	inline void VertexAttrib1sv(GLuint index, const GLshort *v){ return internal::glVertexAttrib1sv(index, v); }
	inline void VertexAttrib2d(GLuint index, GLdouble x, GLdouble y){ return internal::glVertexAttrib2d(index, x, y); }
	inline void VertexAttrib2dv(GLuint index, const GLdouble *v){ return internal::glVertexAttrib2dv(index, v); }
	inline void VertexAttrib2f(GLuint index, GLfloat x, GLfloat y){ return internal::glVertexAttrib2f(index, x, y); }
	inline void VertexAttrib2fv(GLuint index, const GLfloat *v){ return internal::glVertexAttrib2fv(index, v); }
	inline void VertexAttrib2s(GLuint index, GLshort x, GLshort y){ return internal::glVertexAttrib2s(index, x, y); }
	inline void VertexAttrib2sv(GLuint index, const GLshort *v){ return internal::glVertexAttrib2sv(index, v); }
	inline void VertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z){ return internal::glVertexAttrib3d(index, x, y, z); }
	inline void VertexAttrib3dv(GLuint index, const GLdouble *v){ return internal::glVertexAttrib3dv(index, v); }
	inline void VertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z){ return internal::glVertexAttrib3f(index, x, y, z); }
	inline void VertexAttrib3fv(GLuint index, const GLfloat *v){ return internal::glVertexAttrib3fv(index, v); }
	inline void VertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z){ return internal::glVertexAttrib3s(index, x, y, z); }
	inline void VertexAttrib3sv(GLuint index, const GLshort *v){ return internal::glVertexAttrib3sv(index, v); }
	inline void VertexAttrib4Nbv(GLuint index, const GLbyte *v){ return internal::glVertexAttrib4Nbv(index, v); }
	inline void VertexAttrib4Niv(GLuint index, const GLint *v){ return internal::glVertexAttrib4Niv(index, v); }
	inline void VertexAttrib4Nsv(GLuint index, const GLshort *v){ return internal::glVertexAttrib4Nsv(index, v); }
	inline void VertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w){ return internal::glVertexAttrib4Nub(index, x, y, z, w); }
	inline void VertexAttrib4Nubv(GLuint index, const GLubyte *v){ return internal::glVertexAttrib4Nubv(index, v); }
	inline void VertexAttrib4Nuiv(GLuint index, const GLuint *v){ return internal::glVertexAttrib4Nuiv(index, v); }
	inline void VertexAttrib4Nusv(GLuint index, const GLushort *v){ return internal::glVertexAttrib4Nusv(index, v); }
	inline void VertexAttrib4bv(GLuint index, const GLbyte *v){ return internal::glVertexAttrib4bv(index, v); }
	inline void VertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w){ return internal::glVertexAttrib4d(index, x, y, z, w); }
	inline void VertexAttrib4dv(GLuint index, const GLdouble *v){ return internal::glVertexAttrib4dv(index, v); }
	inline void VertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w){ return internal::glVertexAttrib4f(index, x, y, z, w); }
	inline void VertexAttrib4fv(GLuint index, const GLfloat *v){ return internal::glVertexAttrib4fv(index, v); }
	inline void VertexAttrib4iv(GLuint index, const GLint *v){ return internal::glVertexAttrib4iv(index, v); }
	inline void VertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w){ return internal::glVertexAttrib4s(index, x, y, z, w); }
	inline void VertexAttrib4sv(GLuint index, const GLshort *v){ return internal::glVertexAttrib4sv(index, v); }
	inline void VertexAttrib4ubv(GLuint index, const GLubyte *v){ return internal::glVertexAttrib4ubv(index, v); }
	inline void VertexAttrib4uiv(GLuint index, const GLuint *v){ return internal::glVertexAttrib4uiv(index, v); }
	inline void VertexAttrib4usv(GLuint index, const GLushort *v){ return internal::glVertexAttrib4usv(index, v); }
	inline void VertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer){ return internal::glVertexAttribPointer(index, size, type, normalized, stride, pointer); }

	// OpenGL 2.1

	constexpr GLenum PIXEL_PACK_BUFFER = 0x88EB;
	constexpr GLenum PIXEL_UNPACK_BUFFER = 0x88EC;
	constexpr GLenum PIXEL_PACK_BUFFER_BINDING = 0x88ED;
	constexpr GLenum PIXEL_UNPACK_BUFFER_BINDING = 0x88EF;
	constexpr GLenum FLOAT_MAT2x3 = 0x8B65;
	constexpr GLenum FLOAT_MAT2x4 = 0x8B66;
	constexpr GLenum FLOAT_MAT3x2 = 0x8B67;
	constexpr GLenum FLOAT_MAT3x4 = 0x8B68;
	constexpr GLenum FLOAT_MAT4x2 = 0x8B69;
	constexpr GLenum FLOAT_MAT4x3 = 0x8B6A;
	constexpr GLenum SRGB = 0x8C40;
	constexpr GLenum SRGB8 = 0x8C41;
	constexpr GLenum SRGB_ALPHA = 0x8C42;
	constexpr GLenum SRGB8_ALPHA8 = 0x8C43;
	constexpr GLenum COMPRESSED_SRGB = 0x8C48;
	constexpr GLenum COMPRESSED_SRGB_ALPHA = 0x8C49;

	inline void UniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value){ return internal::glUniformMatrix2x3fv(location, count, transpose, value); }
	inline void UniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value){ return internal::glUniformMatrix3x2fv(location, count, transpose, value); }
	inline void UniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value){ return internal::glUniformMatrix2x4fv(location, count, transpose, value); }
	inline void UniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value){ return internal::glUniformMatrix4x2fv(location, count, transpose, value); }
	inline void UniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value){ return internal::glUniformMatrix3x4fv(location, count, transpose, value); }
	inline void UniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value){ return internal::glUniformMatrix4x3fv(location, count, transpose, value); }

	// OpenGL 3.0

	constexpr GLenum COMPARE_REF_TO_TEXTURE = 0x884E;
	constexpr GLenum CLIP_DISTANCE0 = 0x3000;
	constexpr GLenum CLIP_DISTANCE1 = 0x3001;
	constexpr GLenum CLIP_DISTANCE2 = 0x3002;
	constexpr GLenum CLIP_DISTANCE3 = 0x3003;
	constexpr GLenum CLIP_DISTANCE4 = 0x3004;
	constexpr GLenum CLIP_DISTANCE5 = 0x3005;
	constexpr GLenum CLIP_DISTANCE6 = 0x3006;
	constexpr GLenum CLIP_DISTANCE7 = 0x3007;
	constexpr GLenum MAX_CLIP_DISTANCES = 0x0D32;
	constexpr GLenum MAJOR_VERSION = 0x821B;
	constexpr GLenum MINOR_VERSION = 0x821C;
	constexpr GLenum NUM_EXTENSIONS = 0x821D;
	constexpr GLenum CONTEXT_FLAGS = 0x821E;
	constexpr GLenum COMPRESSED_RED = 0x8225;
	constexpr GLenum COMPRESSED_RG = 0x8226;
	constexpr GLenum CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT = 0x00000001;
	constexpr GLenum RGBA32F = 0x8814;
	constexpr GLenum RGB32F = 0x8815;
	constexpr GLenum RGBA16F = 0x881A;
	constexpr GLenum RGB16F = 0x881B;
	constexpr GLenum VERTEX_ATTRIB_ARRAY_INTEGER = 0x88FD;
	constexpr GLenum MAX_ARRAY_TEXTURE_LAYERS = 0x88FF;
	constexpr GLenum MIN_PROGRAM_TEXEL_OFFSET = 0x8904;
	constexpr GLenum MAX_PROGRAM_TEXEL_OFFSET = 0x8905;
	constexpr GLenum CLAMP_READ_COLOR = 0x891C;
	constexpr GLenum FIXED_ONLY = 0x891D;
	constexpr GLenum MAX_VARYING_COMPONENTS = 0x8B4B;
	constexpr GLenum TEXTURE_1D_ARRAY = 0x8C18;
	constexpr GLenum PROXY_TEXTURE_1D_ARRAY = 0x8C19;
	constexpr GLenum TEXTURE_2D_ARRAY = 0x8C1A;
	constexpr GLenum PROXY_TEXTURE_2D_ARRAY = 0x8C1B;
	constexpr GLenum TEXTURE_BINDING_1D_ARRAY = 0x8C1C;
	constexpr GLenum TEXTURE_BINDING_2D_ARRAY = 0x8C1D;
	constexpr GLenum R11F_G11F_B10F = 0x8C3A;
	constexpr GLenum UNSIGNED_INT_10F_11F_11F_REV = 0x8C3B;
	constexpr GLenum RGB9_E5 = 0x8C3D;
	constexpr GLenum UNSIGNED_INT_5_9_9_9_REV = 0x8C3E;
	constexpr GLenum TEXTURE_SHARED_SIZE = 0x8C3F;
	constexpr GLenum TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH = 0x8C76;
	constexpr GLenum TRANSFORM_FEEDBACK_BUFFER_MODE = 0x8C7F;
	constexpr GLenum MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS = 0x8C80;
	constexpr GLenum TRANSFORM_FEEDBACK_VARYINGS = 0x8C83;
	constexpr GLenum TRANSFORM_FEEDBACK_BUFFER_START = 0x8C84;
	constexpr GLenum TRANSFORM_FEEDBACK_BUFFER_SIZE = 0x8C85;
	constexpr GLenum PRIMITIVES_GENERATED = 0x8C87;
	constexpr GLenum TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN = 0x8C88;
	constexpr GLenum RASTERIZER_DISCARD = 0x8C89;
	constexpr GLenum MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS = 0x8C8A;
	constexpr GLenum MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS = 0x8C8B;
	constexpr GLenum INTERLEAVED_ATTRIBS = 0x8C8C;
	constexpr GLenum SEPARATE_ATTRIBS = 0x8C8D;
	constexpr GLenum TRANSFORM_FEEDBACK_BUFFER = 0x8C8E;
	constexpr GLenum TRANSFORM_FEEDBACK_BUFFER_BINDING = 0x8C8F;
	constexpr GLenum RGBA32UI = 0x8D70;
	constexpr GLenum RGB32UI = 0x8D71;
	constexpr GLenum RGBA16UI = 0x8D76;
	constexpr GLenum RGB16UI = 0x8D77;
	constexpr GLenum RGBA8UI = 0x8D7C;
	constexpr GLenum RGB8UI = 0x8D7D;
	constexpr GLenum RGBA32I = 0x8D82;
	constexpr GLenum RGB32I = 0x8D83;
	constexpr GLenum RGBA16I = 0x8D88;
	constexpr GLenum RGB16I = 0x8D89;
	constexpr GLenum RGBA8I = 0x8D8E;
	constexpr GLenum RGB8I = 0x8D8F;
	constexpr GLenum RED_INTEGER = 0x8D94;
	constexpr GLenum GREEN_INTEGER = 0x8D95;
	constexpr GLenum BLUE_INTEGER = 0x8D96;
	constexpr GLenum RGB_INTEGER = 0x8D98;
	constexpr GLenum RGBA_INTEGER = 0x8D99;
	constexpr GLenum BGR_INTEGER = 0x8D9A;
	constexpr GLenum BGRA_INTEGER = 0x8D9B;
	constexpr GLenum SAMPLER_1D_ARRAY = 0x8DC0;
	constexpr GLenum SAMPLER_2D_ARRAY = 0x8DC1;
	constexpr GLenum SAMPLER_1D_ARRAY_SHADOW = 0x8DC3;
	constexpr GLenum SAMPLER_2D_ARRAY_SHADOW = 0x8DC4;
	constexpr GLenum SAMPLER_CUBE_SHADOW = 0x8DC5;
	constexpr GLenum UNSIGNED_INT_VEC2 = 0x8DC6;
	constexpr GLenum UNSIGNED_INT_VEC3 = 0x8DC7;
	constexpr GLenum UNSIGNED_INT_VEC4 = 0x8DC8;
	constexpr GLenum INT_SAMPLER_1D = 0x8DC9;
	constexpr GLenum INT_SAMPLER_2D = 0x8DCA;
	constexpr GLenum INT_SAMPLER_3D = 0x8DCB;
	constexpr GLenum INT_SAMPLER_CUBE = 0x8DCC;
	constexpr GLenum INT_SAMPLER_1D_ARRAY = 0x8DCE;
	constexpr GLenum INT_SAMPLER_2D_ARRAY = 0x8DCF;
	constexpr GLenum UNSIGNED_INT_SAMPLER_1D = 0x8DD1;
	constexpr GLenum UNSIGNED_INT_SAMPLER_2D = 0x8DD2;
	constexpr GLenum UNSIGNED_INT_SAMPLER_3D = 0x8DD3;
	constexpr GLenum UNSIGNED_INT_SAMPLER_CUBE = 0x8DD4;
	constexpr GLenum UNSIGNED_INT_SAMPLER_1D_ARRAY = 0x8DD6;
	constexpr GLenum UNSIGNED_INT_SAMPLER_2D_ARRAY = 0x8DD7;
	constexpr GLenum QUERY_WAIT = 0x8E13;
	constexpr GLenum QUERY_NO_WAIT = 0x8E14;
	constexpr GLenum QUERY_BY_REGION_WAIT = 0x8E15;
	constexpr GLenum QUERY_BY_REGION_NO_WAIT = 0x8E16;
	constexpr GLenum BUFFER_ACCESS_FLAGS = 0x911F;
	constexpr GLenum BUFFER_MAP_LENGTH = 0x9120;
	constexpr GLenum BUFFER_MAP_OFFSET = 0x9121;
	constexpr GLenum DEPTH_COMPONENT32F = 0x8CAC;
	constexpr GLenum DEPTH32F_STENCIL8 = 0x8CAD;
	constexpr GLenum FLOAT_32_UNSIGNED_INT_24_8_REV = 0x8DAD;
	constexpr GLenum INVALID_FRAMEBUFFER_OPERATION = 0x0506;
	constexpr GLenum FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING = 0x8210;
	constexpr GLenum FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE = 0x8211;
	constexpr GLenum FRAMEBUFFER_ATTACHMENT_RED_SIZE = 0x8212;
	constexpr GLenum FRAMEBUFFER_ATTACHMENT_GREEN_SIZE = 0x8213;
	constexpr GLenum FRAMEBUFFER_ATTACHMENT_BLUE_SIZE = 0x8214;
	constexpr GLenum FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE = 0x8215;
	constexpr GLenum FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE = 0x8216;
	constexpr GLenum FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE = 0x8217;
	constexpr GLenum FRAMEBUFFER_DEFAULT = 0x8218;
	constexpr GLenum FRAMEBUFFER_UNDEFINED = 0x8219;
	constexpr GLenum DEPTH_STENCIL_ATTACHMENT = 0x821A;
	constexpr GLenum MAX_RENDERBUFFER_SIZE = 0x84E8;
	constexpr GLenum DEPTH_STENCIL = 0x84F9;
	constexpr GLenum UNSIGNED_INT_24_8 = 0x84FA;
	constexpr GLenum DEPTH24_STENCIL8 = 0x88F0;
	constexpr GLenum TEXTURE_STENCIL_SIZE = 0x88F1;
	constexpr GLenum TEXTURE_RED_TYPE = 0x8C10;
	constexpr GLenum TEXTURE_GREEN_TYPE = 0x8C11;
	constexpr GLenum TEXTURE_BLUE_TYPE = 0x8C12;
	constexpr GLenum TEXTURE_ALPHA_TYPE = 0x8C13;
	constexpr GLenum TEXTURE_DEPTH_TYPE = 0x8C16;
	constexpr GLenum UNSIGNED_NORMALIZED = 0x8C17;
	constexpr GLenum FRAMEBUFFER_BINDING = 0x8CA6;
	constexpr GLenum DRAW_FRAMEBUFFER_BINDING = 0x8CA6;
	constexpr GLenum RENDERBUFFER_BINDING = 0x8CA7;
	constexpr GLenum READ_FRAMEBUFFER = 0x8CA8;
	constexpr GLenum DRAW_FRAMEBUFFER = 0x8CA9;
	constexpr GLenum READ_FRAMEBUFFER_BINDING = 0x8CAA;
	constexpr GLenum RENDERBUFFER_SAMPLES = 0x8CAB;
	constexpr GLenum FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE = 0x8CD0;
	constexpr GLenum FRAMEBUFFER_ATTACHMENT_OBJECT_NAME = 0x8CD1;
	constexpr GLenum FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL = 0x8CD2;
	constexpr GLenum FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 0x8CD3;
	constexpr GLenum FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER = 0x8CD4;
	constexpr GLenum FRAMEBUFFER_COMPLETE = 0x8CD5;
	constexpr GLenum FRAMEBUFFER_INCOMPLETE_ATTACHMENT = 0x8CD6;
	constexpr GLenum FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 0x8CD7;
	constexpr GLenum FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER = 0x8CDB;
	constexpr GLenum FRAMEBUFFER_INCOMPLETE_READ_BUFFER = 0x8CDC;
	constexpr GLenum FRAMEBUFFER_UNSUPPORTED = 0x8CDD;
	constexpr GLenum MAX_COLOR_ATTACHMENTS = 0x8CDF;
	constexpr GLenum COLOR_ATTACHMENT0 = 0x8CE0;
	constexpr GLenum COLOR_ATTACHMENT1 = 0x8CE1;
	constexpr GLenum COLOR_ATTACHMENT2 = 0x8CE2;
	constexpr GLenum COLOR_ATTACHMENT3 = 0x8CE3;
	constexpr GLenum COLOR_ATTACHMENT4 = 0x8CE4;
	constexpr GLenum COLOR_ATTACHMENT5 = 0x8CE5;
	constexpr GLenum COLOR_ATTACHMENT6 = 0x8CE6;
	constexpr GLenum COLOR_ATTACHMENT7 = 0x8CE7;
	constexpr GLenum COLOR_ATTACHMENT8 = 0x8CE8;
	constexpr GLenum COLOR_ATTACHMENT9 = 0x8CE9;
	constexpr GLenum COLOR_ATTACHMENT10 = 0x8CEA;
	constexpr GLenum COLOR_ATTACHMENT11 = 0x8CEB;
	constexpr GLenum COLOR_ATTACHMENT12 = 0x8CEC;
	constexpr GLenum COLOR_ATTACHMENT13 = 0x8CED;
	constexpr GLenum COLOR_ATTACHMENT14 = 0x8CEE;
	constexpr GLenum COLOR_ATTACHMENT15 = 0x8CEF;
	constexpr GLenum COLOR_ATTACHMENT16 = 0x8CF0;
	constexpr GLenum COLOR_ATTACHMENT17 = 0x8CF1;
	constexpr GLenum COLOR_ATTACHMENT18 = 0x8CF2;
	constexpr GLenum COLOR_ATTACHMENT19 = 0x8CF3;
	constexpr GLenum COLOR_ATTACHMENT20 = 0x8CF4;
	constexpr GLenum COLOR_ATTACHMENT21 = 0x8CF5;
	constexpr GLenum COLOR_ATTACHMENT22 = 0x8CF6;
	constexpr GLenum COLOR_ATTACHMENT23 = 0x8CF7;
	constexpr GLenum COLOR_ATTACHMENT24 = 0x8CF8;
	constexpr GLenum COLOR_ATTACHMENT25 = 0x8CF9;
	constexpr GLenum COLOR_ATTACHMENT26 = 0x8CFA;
	constexpr GLenum COLOR_ATTACHMENT27 = 0x8CFB;
	constexpr GLenum COLOR_ATTACHMENT28 = 0x8CFC;
	constexpr GLenum COLOR_ATTACHMENT29 = 0x8CFD;
	constexpr GLenum COLOR_ATTACHMENT30 = 0x8CFE;
	constexpr GLenum COLOR_ATTACHMENT31 = 0x8CFF;
	constexpr GLenum DEPTH_ATTACHMENT = 0x8D00;
	constexpr GLenum STENCIL_ATTACHMENT = 0x8D20;
	constexpr GLenum FRAMEBUFFER = 0x8D40;
	constexpr GLenum RENDERBUFFER = 0x8D41;
	constexpr GLenum RENDERBUFFER_WIDTH = 0x8D42;
	constexpr GLenum RENDERBUFFER_HEIGHT = 0x8D43;
	constexpr GLenum RENDERBUFFER_INTERNAL_FORMAT = 0x8D44;
	constexpr GLenum STENCIL_INDEX1 = 0x8D46;
	constexpr GLenum STENCIL_INDEX4 = 0x8D47;
	constexpr GLenum STENCIL_INDEX8 = 0x8D48;
	constexpr GLenum STENCIL_INDEX16 = 0x8D49;
	constexpr GLenum RENDERBUFFER_RED_SIZE = 0x8D50;
	constexpr GLenum RENDERBUFFER_GREEN_SIZE = 0x8D51;
	constexpr GLenum RENDERBUFFER_BLUE_SIZE = 0x8D52;
	constexpr GLenum RENDERBUFFER_ALPHA_SIZE = 0x8D53;
	constexpr GLenum RENDERBUFFER_DEPTH_SIZE = 0x8D54;
	constexpr GLenum RENDERBUFFER_STENCIL_SIZE = 0x8D55;
	constexpr GLenum FRAMEBUFFER_INCOMPLETE_MULTISAMPLE = 0x8D56;
	constexpr GLenum MAX_SAMPLES = 0x8D57;
	constexpr GLenum FRAMEBUFFER_SRGB = 0x8DB9;
	constexpr GLenum HALF_FLOAT = 0x140B;
	constexpr GLenum MAP_READ_BIT = 0x0001;
	constexpr GLenum MAP_WRITE_BIT = 0x0002;
	constexpr GLenum MAP_INVALIDATE_RANGE_BIT = 0x0004;
	constexpr GLenum MAP_INVALIDATE_BUFFER_BIT = 0x0008;
	constexpr GLenum MAP_FLUSH_EXPLICIT_BIT = 0x0010;
	constexpr GLenum MAP_UNSYNCHRONIZED_BIT = 0x0020;
	constexpr GLenum COMPRESSED_RED_RGTC1 = 0x8DBB;
	constexpr GLenum COMPRESSED_SIGNED_RED_RGTC1 = 0x8DBC;
	constexpr GLenum COMPRESSED_RG_RGTC2 = 0x8DBD;
	constexpr GLenum COMPRESSED_SIGNED_RG_RGTC2 = 0x8DBE;
	constexpr GLenum RG = 0x8227;
	constexpr GLenum RG_INTEGER = 0x8228;
	constexpr GLenum R8 = 0x8229;
	constexpr GLenum R16 = 0x822A;
	constexpr GLenum RG8 = 0x822B;
	constexpr GLenum RG16 = 0x822C;
	constexpr GLenum R16F = 0x822D;
	constexpr GLenum R32F = 0x822E;
	constexpr GLenum RG16F = 0x822F;
	constexpr GLenum RG32F = 0x8230;
	constexpr GLenum R8I = 0x8231;
	constexpr GLenum R8UI = 0x8232;
	constexpr GLenum R16I = 0x8233;
	constexpr GLenum R16UI = 0x8234;
	constexpr GLenum R32I = 0x8235;
	constexpr GLenum R32UI = 0x8236;
	constexpr GLenum RG8I = 0x8237;
	constexpr GLenum RG8UI = 0x8238;
	constexpr GLenum RG16I = 0x8239;
	constexpr GLenum RG16UI = 0x823A;
	constexpr GLenum RG32I = 0x823B;
	constexpr GLenum RG32UI = 0x823C;
	constexpr GLenum VERTEX_ARRAY_BINDING = 0x85B5;

	inline void ColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a){ return internal::glColorMaski(index, r, g, b, a); }
	inline void GetBooleani_v(GLenum target, GLuint index, GLboolean *data){ return internal::glGetBooleani_v(target, index, data); }
	inline void GetIntegeri_v(GLenum target, GLuint index, GLint *data){ return internal::glGetIntegeri_v(target, index, data); }
	inline void Enablei(GLenum target, GLuint index){ return internal::glEnablei(target, index); }
	inline void Disablei(GLenum target, GLuint index){ return internal::glDisablei(target, index); }
	inline GLboolean IsEnabledi(GLenum target, GLuint index){ return internal::glIsEnabledi(target, index); }
	inline void BeginTransformFeedback(GLenum primitiveMode){ return internal::glBeginTransformFeedback(primitiveMode); }
	inline void EndTransformFeedback(){ return internal::glEndTransformFeedback(); }
	inline void BindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size){ return internal::glBindBufferRange(target, index, buffer, offset, size); }
	inline void BindBufferBase(GLenum target, GLuint index, GLuint buffer){ return internal::glBindBufferBase(target, index, buffer); }
	inline void TransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode){ return internal::glTransformFeedbackVaryings(program, count, varyings, bufferMode); }
	inline void GetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name){ return internal::glGetTransformFeedbackVarying(program, index, bufSize, length, size, type, name); }
	inline void ClampColor(GLenum target, GLenum clamp){ return internal::glClampColor(target, clamp); }
	inline void BeginConditionalRender(GLuint id, GLenum mode){ return internal::glBeginConditionalRender(id, mode); }
	inline void EndConditionalRender(){ return internal::glEndConditionalRender(); }
	inline void VertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer){ return internal::glVertexAttribIPointer(index, size, type, stride, pointer); }
	inline void GetVertexAttribIiv(GLuint index, GLenum pname, GLint *params){ return internal::glGetVertexAttribIiv(index, pname, params); }
	inline void GetVertexAttribIuiv(GLuint index, GLenum pname, GLuint *params){ return internal::glGetVertexAttribIuiv(index, pname, params); }
	inline void VertexAttribI1i(GLuint index, GLint x){ return internal::glVertexAttribI1i(index, x); }
	inline void VertexAttribI2i(GLuint index, GLint x, GLint y){ return internal::glVertexAttribI2i(index, x, y); }
	inline void VertexAttribI3i(GLuint index, GLint x, GLint y, GLint z){ return internal::glVertexAttribI3i(index, x, y, z); }
	inline void VertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w){ return internal::glVertexAttribI4i(index, x, y, z, w); }
	inline void VertexAttribI1ui(GLuint index, GLuint x){ return internal::glVertexAttribI1ui(index, x); }
	inline void VertexAttribI2ui(GLuint index, GLuint x, GLuint y){ return internal::glVertexAttribI2ui(index, x, y); }
	inline void VertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z){ return internal::glVertexAttribI3ui(index, x, y, z); }
	inline void VertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w){ return internal::glVertexAttribI4ui(index, x, y, z, w); }
	inline void VertexAttribI1iv(GLuint index, const GLint *v){ return internal::glVertexAttribI1iv(index, v); }
	inline void VertexAttribI2iv(GLuint index, const GLint *v){ return internal::glVertexAttribI2iv(index, v); }
	inline void VertexAttribI3iv(GLuint index, const GLint *v){ return internal::glVertexAttribI3iv(index, v); }
	inline void VertexAttribI4iv(GLuint index, const GLint *v){ return internal::glVertexAttribI4iv(index, v); }
	inline void VertexAttribI1uiv(GLuint index, const GLuint *v){ return internal::glVertexAttribI1uiv(index, v); }
	inline void VertexAttribI2uiv(GLuint index, const GLuint *v){ return internal::glVertexAttribI2uiv(index, v); }
	inline void VertexAttribI3uiv(GLuint index, const GLuint *v){ return internal::glVertexAttribI3uiv(index, v); }
	inline void VertexAttribI4uiv(GLuint index, const GLuint *v){ return internal::glVertexAttribI4uiv(index, v); }
	inline void VertexAttribI4bv(GLuint index, const GLbyte *v){ return internal::glVertexAttribI4bv(index, v); }
	inline void VertexAttribI4sv(GLuint index, const GLshort *v){ return internal::glVertexAttribI4sv(index, v); }
	inline void VertexAttribI4ubv(GLuint index, const GLubyte *v){ return internal::glVertexAttribI4ubv(index, v); }
	inline void VertexAttribI4usv(GLuint index, const GLushort *v){ return internal::glVertexAttribI4usv(index, v); }
	inline void GetUniformuiv(GLuint program, GLint location, GLuint *params){ return internal::glGetUniformuiv(program, location, params); }
	inline void BindFragDataLocation(GLuint program, GLuint color, const GLchar *name){ return internal::glBindFragDataLocation(program, color, name); }
	inline GLint GetFragDataLocation(GLuint program, const GLchar *name){ return internal::glGetFragDataLocation(program, name); }
	inline void Uniform1ui(GLint location, GLuint v0){ return internal::glUniform1ui(location, v0); }
	inline void Uniform2ui(GLint location, GLuint v0, GLuint v1){ return internal::glUniform2ui(location, v0, v1); }
	inline void Uniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2){ return internal::glUniform3ui(location, v0, v1, v2); }
	inline void Uniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3){ return internal::glUniform4ui(location, v0, v1, v2, v3); }
	inline void Uniform1uiv(GLint location, GLsizei count, const GLuint *value){ return internal::glUniform1uiv(location, count, value); }
	inline void Uniform2uiv(GLint location, GLsizei count, const GLuint *value){ return internal::glUniform2uiv(location, count, value); }
	inline void Uniform3uiv(GLint location, GLsizei count, const GLuint *value){ return internal::glUniform3uiv(location, count, value); }
	inline void Uniform4uiv(GLint location, GLsizei count, const GLuint *value){ return internal::glUniform4uiv(location, count, value); }
	inline void TexParameterIiv(GLenum target, GLenum pname, const GLint *params){ return internal::glTexParameterIiv(target, pname, params); }
	inline void TexParameterIuiv(GLenum target, GLenum pname, const GLuint *params){ return internal::glTexParameterIuiv(target, pname, params); }
	inline void GetTexParameterIiv(GLenum target, GLenum pname, GLint *params){ return internal::glGetTexParameterIiv(target, pname, params); }
	inline void GetTexParameterIuiv(GLenum target, GLenum pname, GLuint *params){ return internal::glGetTexParameterIuiv(target, pname, params); }
	inline void ClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint *value){ return internal::glClearBufferiv(buffer, drawbuffer, value); }
	inline void ClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint *value){ return internal::glClearBufferuiv(buffer, drawbuffer, value); }
	inline void ClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat *value){ return internal::glClearBufferfv(buffer, drawbuffer, value); }
	inline void ClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil){ return internal::glClearBufferfi(buffer, drawbuffer, depth, stencil); }
	inline const GLubyte *GetStringi(GLenum name, GLuint index){ return internal::glGetStringi(name, index); }
	inline GLboolean IsRenderbuffer(GLuint renderbuffer){ return internal::glIsRenderbuffer(renderbuffer); }
	inline void BindRenderbuffer(GLenum target, GLuint renderbuffer){ return internal::glBindRenderbuffer(target, renderbuffer); }
	inline void DeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers){ return internal::glDeleteRenderbuffers(n, renderbuffers); }
	inline void GenRenderbuffers(GLsizei n, GLuint *renderbuffers){ return internal::glGenRenderbuffers(n, renderbuffers); }
	inline void RenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height){ return internal::glRenderbufferStorage(target, internalformat, width, height); }
	inline void GetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params){ return internal::glGetRenderbufferParameteriv(target, pname, params); }
	inline GLboolean IsFramebuffer(GLuint framebuffer){ return internal::glIsFramebuffer(framebuffer); }
	inline void BindFramebuffer(GLenum target, GLuint framebuffer){ return internal::glBindFramebuffer(target, framebuffer); }
	inline void DeleteFramebuffers(GLsizei n, const GLuint *framebuffers){ return internal::glDeleteFramebuffers(n, framebuffers); }
	inline void GenFramebuffers(GLsizei n, GLuint *framebuffers){ return internal::glGenFramebuffers(n, framebuffers); }
	inline GLenum CheckFramebufferStatus(GLenum target){ return internal::glCheckFramebufferStatus(target); }
	inline void FramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level){ return internal::glFramebufferTexture1D(target, attachment, textarget, texture, level); }
	inline void FramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level){ return internal::glFramebufferTexture2D(target, attachment, textarget, texture, level); }
	inline void FramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset){ return internal::glFramebufferTexture3D(target, attachment, textarget, texture, level, zoffset); }
	inline void FramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer){ return internal::glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer); }
	inline void GetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params){ return internal::glGetFramebufferAttachmentParameteriv(target, attachment, pname, params); }
	inline void GenerateMipmap(GLenum target){ return internal::glGenerateMipmap(target); }
	inline void BlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter){ return internal::glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter); }
	inline void RenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height){ return internal::glRenderbufferStorageMultisample(target, samples, internalformat, width, height); }
	inline void FramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer){ return internal::glFramebufferTextureLayer(target, attachment, texture, level, layer); }
	inline void *MapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access){ return internal::glMapBufferRange(target, offset, length, access); }
	inline void FlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length){ return internal::glFlushMappedBufferRange(target, offset, length); }
	inline void BindVertexArray(GLuint array){ return internal::glBindVertexArray(array); }
	inline void DeleteVertexArrays(GLsizei n, const GLuint *arrays){ return internal::glDeleteVertexArrays(n, arrays); }
	inline void GenVertexArrays(GLsizei n, GLuint *arrays){ return internal::glGenVertexArrays(n, arrays); }
	inline GLboolean IsVertexArray(GLuint array){ return internal::glIsVertexArray(array); }

	// OpenGL 3.1

	constexpr GLenum SAMPLER_2D_RECT = 0x8B63;
	constexpr GLenum SAMPLER_2D_RECT_SHADOW = 0x8B64;
	constexpr GLenum SAMPLER_BUFFER = 0x8DC2;
	constexpr GLenum INT_SAMPLER_2D_RECT = 0x8DCD;
	constexpr GLenum INT_SAMPLER_BUFFER = 0x8DD0;
	constexpr GLenum UNSIGNED_INT_SAMPLER_2D_RECT = 0x8DD5;
	constexpr GLenum UNSIGNED_INT_SAMPLER_BUFFER = 0x8DD8;
	constexpr GLenum TEXTURE_BUFFER = 0x8C2A;
	constexpr GLenum MAX_TEXTURE_BUFFER_SIZE = 0x8C2B;
	constexpr GLenum TEXTURE_BINDING_BUFFER = 0x8C2C;
	constexpr GLenum TEXTURE_BUFFER_DATA_STORE_BINDING = 0x8C2D;
	constexpr GLenum TEXTURE_RECTANGLE = 0x84F5;
	constexpr GLenum TEXTURE_BINDING_RECTANGLE = 0x84F6;
	constexpr GLenum PROXY_TEXTURE_RECTANGLE = 0x84F7;
	constexpr GLenum MAX_RECTANGLE_TEXTURE_SIZE = 0x84F8;
	constexpr GLenum R8_SNORM = 0x8F94;
	constexpr GLenum RG8_SNORM = 0x8F95;
	constexpr GLenum RGB8_SNORM = 0x8F96;
	constexpr GLenum RGBA8_SNORM = 0x8F97;
	constexpr GLenum R16_SNORM = 0x8F98;
	constexpr GLenum RG16_SNORM = 0x8F99;
	constexpr GLenum RGB16_SNORM = 0x8F9A;
	constexpr GLenum RGBA16_SNORM = 0x8F9B;
	constexpr GLenum SIGNED_NORMALIZED = 0x8F9C;
	constexpr GLenum PRIMITIVE_RESTART = 0x8F9D;
	constexpr GLenum PRIMITIVE_RESTART_INDEX = 0x8F9E;
	constexpr GLenum COPY_READ_BUFFER = 0x8F36;
	constexpr GLenum COPY_WRITE_BUFFER = 0x8F37;
	constexpr GLenum UNIFORM_BUFFER = 0x8A11;
	constexpr GLenum UNIFORM_BUFFER_BINDING = 0x8A28;
	constexpr GLenum UNIFORM_BUFFER_START = 0x8A29;
	constexpr GLenum UNIFORM_BUFFER_SIZE = 0x8A2A;
	constexpr GLenum MAX_VERTEX_UNIFORM_BLOCKS = 0x8A2B;
	constexpr GLenum MAX_GEOMETRY_UNIFORM_BLOCKS = 0x8A2C;
	constexpr GLenum MAX_FRAGMENT_UNIFORM_BLOCKS = 0x8A2D;
	constexpr GLenum MAX_COMBINED_UNIFORM_BLOCKS = 0x8A2E;
	constexpr GLenum MAX_UNIFORM_BUFFER_BINDINGS = 0x8A2F;
	constexpr GLenum MAX_UNIFORM_BLOCK_SIZE = 0x8A30;
	constexpr GLenum MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS = 0x8A31;
	constexpr GLenum MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS = 0x8A32;
	constexpr GLenum MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS = 0x8A33;
	constexpr GLenum UNIFORM_BUFFER_OFFSET_ALIGNMENT = 0x8A34;
	constexpr GLenum ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH = 0x8A35;
	constexpr GLenum ACTIVE_UNIFORM_BLOCKS = 0x8A36;
	constexpr GLenum UNIFORM_TYPE = 0x8A37;
	constexpr GLenum UNIFORM_SIZE = 0x8A38;
	constexpr GLenum UNIFORM_NAME_LENGTH = 0x8A39;
	constexpr GLenum UNIFORM_BLOCK_INDEX = 0x8A3A;
	constexpr GLenum UNIFORM_OFFSET = 0x8A3B;
	constexpr GLenum UNIFORM_ARRAY_STRIDE = 0x8A3C;
	constexpr GLenum UNIFORM_MATRIX_STRIDE = 0x8A3D;
	constexpr GLenum UNIFORM_IS_ROW_MAJOR = 0x8A3E;
	constexpr GLenum UNIFORM_BLOCK_BINDING = 0x8A3F;
	constexpr GLenum UNIFORM_BLOCK_DATA_SIZE = 0x8A40;
	constexpr GLenum UNIFORM_BLOCK_NAME_LENGTH = 0x8A41;
	constexpr GLenum UNIFORM_BLOCK_ACTIVE_UNIFORMS = 0x8A42;
	constexpr GLenum UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES = 0x8A43;
	constexpr GLenum UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER = 0x8A44;
	constexpr GLenum UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER = 0x8A45;
	constexpr GLenum UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER = 0x8A46;
	constexpr unsigned INVALID_INDEX = 0xFFFFFFFF;

	inline void DrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount){ return internal::glDrawArraysInstanced(mode, first, count, instancecount); }
	inline void DrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount){ return internal::glDrawElementsInstanced(mode, count, type, indices, instancecount); }
	inline void TexBuffer(GLenum target, GLenum internalformat, GLuint buffer){ return internal::glTexBuffer(target, internalformat, buffer); }
	inline void PrimitiveRestartIndex(GLuint index){ return internal::glPrimitiveRestartIndex(index); }
	inline void CopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size){ return internal::glCopyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size); }
	inline void GetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices){ return internal::glGetUniformIndices(program, uniformCount, uniformNames, uniformIndices); }
	inline void GetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params){ return internal::glGetActiveUniformsiv(program, uniformCount, uniformIndices, pname, params); }
	inline void GetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName){ return internal::glGetActiveUniformName(program, uniformIndex, bufSize, length, uniformName); }
	inline GLuint GetUniformBlockIndex(GLuint program, const GLchar *uniformBlockName){ return internal::glGetUniformBlockIndex(program, uniformBlockName); }
	inline void GetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params){ return internal::glGetActiveUniformBlockiv(program, uniformBlockIndex, pname, params); }
	inline void GetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName){ return internal::glGetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName); }
	inline void UniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding){ return internal::glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding); }

	// OpenGL 3.2

	constexpr GLenum CONTEXT_CORE_PROFILE_BIT = 0x00000001;
	constexpr GLenum CONTEXT_COMPATIBILITY_PROFILE_BIT = 0x00000002;
	constexpr GLenum LINES_ADJACENCY = 0x000A;
	constexpr GLenum LINE_STRIP_ADJACENCY = 0x000B;
	constexpr GLenum TRIANGLES_ADJACENCY = 0x000C;
	constexpr GLenum TRIANGLE_STRIP_ADJACENCY = 0x000D;
	constexpr GLenum PROGRAM_POINT_SIZE = 0x8642;
	constexpr GLenum MAX_GEOMETRY_TEXTURE_IMAGE_UNITS = 0x8C29;
	constexpr GLenum FRAMEBUFFER_ATTACHMENT_LAYERED = 0x8DA7;
	constexpr GLenum FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS = 0x8DA8;
	constexpr GLenum GEOMETRY_SHADER = 0x8DD9;
	constexpr GLenum GEOMETRY_VERTICES_OUT = 0x8916;
	constexpr GLenum GEOMETRY_INPUT_TYPE = 0x8917;
	constexpr GLenum GEOMETRY_OUTPUT_TYPE = 0x8918;
	constexpr GLenum MAX_GEOMETRY_UNIFORM_COMPONENTS = 0x8DDF;
	constexpr GLenum MAX_GEOMETRY_OUTPUT_VERTICES = 0x8DE0;
	constexpr GLenum MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS = 0x8DE1;
	constexpr GLenum MAX_VERTEX_OUTPUT_COMPONENTS = 0x9122;
	constexpr GLenum MAX_GEOMETRY_INPUT_COMPONENTS = 0x9123;
	constexpr GLenum MAX_GEOMETRY_OUTPUT_COMPONENTS = 0x9124;
	constexpr GLenum MAX_FRAGMENT_INPUT_COMPONENTS = 0x9125;
	constexpr GLenum CONTEXT_PROFILE_MASK = 0x9126;
	constexpr GLenum DEPTH_CLAMP = 0x864F;
	constexpr GLenum QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION = 0x8E4C;
	constexpr GLenum FIRST_VERTEX_CONVENTION = 0x8E4D;
	constexpr GLenum LAST_VERTEX_CONVENTION = 0x8E4E;
	constexpr GLenum PROVOKING_VERTEX = 0x8E4F;
	constexpr GLenum TEXTURE_CUBE_MAP_SEAMLESS = 0x884F;
	constexpr GLenum MAX_SERVER_WAIT_TIMEOUT = 0x9111;
	constexpr GLenum OBJECT_TYPE = 0x9112;
	constexpr GLenum SYNC_CONDITION = 0x9113;
	constexpr GLenum SYNC_STATUS = 0x9114;
	constexpr GLenum SYNC_FLAGS = 0x9115;
	constexpr GLenum SYNC_FENCE = 0x9116;
	constexpr GLenum SYNC_GPU_COMMANDS_COMPLETE = 0x9117;
	constexpr GLenum UNSIGNALED = 0x9118;
	constexpr GLenum SIGNALED = 0x9119;
	constexpr GLenum ALREADY_SIGNALED = 0x911A;
	constexpr GLenum TIMEOUT_EXPIRED = 0x911B;
	constexpr GLenum CONDITION_SATISFIED = 0x911C;
	constexpr GLenum WAIT_FAILED = 0x911D;
	constexpr unsigned long long TIMEOUT_IGNORED = 0xFFFFFFFFFFFFFFFF;
	constexpr GLenum SYNC_FLUSH_COMMANDS_BIT = 0x00000001;
	constexpr GLenum SAMPLE_POSITION = 0x8E50;
	constexpr GLenum SAMPLE_MASK = 0x8E51;
	constexpr GLenum SAMPLE_MASK_VALUE = 0x8E52;
	constexpr GLenum MAX_SAMPLE_MASK_WORDS = 0x8E59;
	constexpr GLenum TEXTURE_2D_MULTISAMPLE = 0x9100;
	constexpr GLenum PROXY_TEXTURE_2D_MULTISAMPLE = 0x9101;
	constexpr GLenum TEXTURE_2D_MULTISAMPLE_ARRAY = 0x9102;
	constexpr GLenum PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY = 0x9103;
	constexpr GLenum TEXTURE_BINDING_2D_MULTISAMPLE = 0x9104;
	constexpr GLenum TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY = 0x9105;
	constexpr GLenum TEXTURE_SAMPLES = 0x9106;
	constexpr GLenum TEXTURE_FIXED_SAMPLE_LOCATIONS = 0x9107;
	constexpr GLenum SAMPLER_2D_MULTISAMPLE = 0x9108;
	constexpr GLenum INT_SAMPLER_2D_MULTISAMPLE = 0x9109;
	constexpr GLenum UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE = 0x910A;
	constexpr GLenum SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910B;
	constexpr GLenum INT_SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910C;
	constexpr GLenum UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910D;
	constexpr GLenum MAX_COLOR_TEXTURE_SAMPLES = 0x910E;
	constexpr GLenum MAX_DEPTH_TEXTURE_SAMPLES = 0x910F;
	constexpr GLenum MAX_INTEGER_SAMPLES = 0x9110;

	inline void DrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex){ return internal::glDrawElementsBaseVertex(mode, count, type, indices, basevertex); }
	inline void DrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex){ return internal::glDrawRangeElementsBaseVertex(mode, start, end, count, type, indices, basevertex); }
	inline void DrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex){ return internal::glDrawElementsInstancedBaseVertex(mode, count, type, indices, instancecount, basevertex); }
	inline void MultiDrawElementsBaseVertex(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex){ return internal::glMultiDrawElementsBaseVertex(mode, count, type, indices, drawcount, basevertex); }
	inline void ProvokingVertex(GLenum mode){ return internal::glProvokingVertex(mode); }
	inline GLsync FenceSync(GLenum condition, GLbitfield flags){ return internal::glFenceSync(condition, flags); }
	inline GLboolean IsSync(GLsync sync){ return internal::glIsSync(sync); }
	inline void DeleteSync(GLsync sync){ return internal::glDeleteSync(sync); }
	inline GLenum ClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout){ return internal::glClientWaitSync(sync, flags, timeout); }
	inline void WaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout){ return internal::glWaitSync(sync, flags, timeout); }
	inline void GetInteger64v(GLenum pname, GLint64 *data){ return internal::glGetInteger64v(pname, data); }
	inline void GetSynciv(GLsync sync, GLenum pname, GLsizei count, GLsizei *length, GLint *values){ return internal::glGetSynciv(sync, pname, count, length, values); }
	inline void GetInteger64i_v(GLenum target, GLuint index, GLint64 *data){ return internal::glGetInteger64i_v(target, index, data); }
	inline void GetBufferParameteri64v(GLenum target, GLenum pname, GLint64 *params){ return internal::glGetBufferParameteri64v(target, pname, params); }
	inline void FramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level){ return internal::glFramebufferTexture(target, attachment, texture, level); }
	inline void TexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations){ return internal::glTexImage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations); }
	inline void TexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations){ return internal::glTexImage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations); }
	inline void GetMultisamplefv(GLenum pname, GLuint index, GLfloat *val){ return internal::glGetMultisamplefv(pname, index, val); }
	inline void SampleMaski(GLuint maskNumber, GLbitfield mask){ return internal::glSampleMaski(maskNumber, mask); }

	// OpenGL 3.3

	constexpr GLenum VERTEX_ATTRIB_ARRAY_DIVISOR = 0x88FE;
	constexpr GLenum SRC1_COLOR = 0x88F9;
	constexpr GLenum ONE_MINUS_SRC1_COLOR = 0x88FA;
	constexpr GLenum ONE_MINUS_SRC1_ALPHA = 0x88FB;
	constexpr GLenum MAX_DUAL_SOURCE_DRAW_BUFFERS = 0x88FC;
	constexpr GLenum ANY_SAMPLES_PASSED = 0x8C2F;
	constexpr GLenum SAMPLER_BINDING = 0x8919;
	constexpr GLenum RGB10_A2UI = 0x906F;
	constexpr GLenum TEXTURE_SWIZZLE_R = 0x8E42;
	constexpr GLenum TEXTURE_SWIZZLE_G = 0x8E43;
	constexpr GLenum TEXTURE_SWIZZLE_B = 0x8E44;
	constexpr GLenum TEXTURE_SWIZZLE_A = 0x8E45;
	constexpr GLenum TEXTURE_SWIZZLE_RGBA = 0x8E46;
	constexpr GLenum TIME_ELAPSED = 0x88BF;
	constexpr GLenum TIMESTAMP = 0x8E28;
	constexpr GLenum INT_2_10_10_10_REV = 0x8D9F;

	inline void BindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name){ return internal::glBindFragDataLocationIndexed(program, colorNumber, index, name); }
	inline GLint GetFragDataIndex(GLuint program, const GLchar *name){ return internal::glGetFragDataIndex(program, name); }
	inline void GenSamplers(GLsizei count, GLuint *samplers){ return internal::glGenSamplers(count, samplers); }
	inline void DeleteSamplers(GLsizei count, const GLuint *samplers){ return internal::glDeleteSamplers(count, samplers); }
	inline GLboolean IsSampler(GLuint sampler){ return internal::glIsSampler(sampler); }
	inline void BindSampler(GLuint unit, GLuint sampler){ return internal::glBindSampler(unit, sampler); }
	inline void SamplerParameteri(GLuint sampler, GLenum pname, GLint param){ return internal::glSamplerParameteri(sampler, pname, param); }
	inline void SamplerParameteriv(GLuint sampler, GLenum pname, const GLint *param){ return internal::glSamplerParameteriv(sampler, pname, param); }
	inline void SamplerParameterf(GLuint sampler, GLenum pname, GLfloat param){ return internal::glSamplerParameterf(sampler, pname, param); }
	inline void SamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat *param){ return internal::glSamplerParameterfv(sampler, pname, param); }
	inline void SamplerParameterIiv(GLuint sampler, GLenum pname, const GLint *param){ return internal::glSamplerParameterIiv(sampler, pname, param); }
	inline void SamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint *param){ return internal::glSamplerParameterIuiv(sampler, pname, param); }
	inline void GetSamplerParameteriv(GLuint sampler, GLenum pname, GLint *params){ return internal::glGetSamplerParameteriv(sampler, pname, params); }
	inline void GetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint *params){ return internal::glGetSamplerParameterIiv(sampler, pname, params); }
	inline void GetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat *params){ return internal::glGetSamplerParameterfv(sampler, pname, params); }
	inline void GetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint *params){ return internal::glGetSamplerParameterIuiv(sampler, pname, params); }
	inline void QueryCounter(GLuint id, GLenum target){ return internal::glQueryCounter(id, target); }
	inline void GetQueryObjecti64v(GLuint id, GLenum pname, GLint64 *params){ return internal::glGetQueryObjecti64v(id, pname, params); }
	inline void GetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 *params){ return internal::glGetQueryObjectui64v(id, pname, params); }
	inline void VertexAttribDivisor(GLuint index, GLuint divisor){ return internal::glVertexAttribDivisor(index, divisor); }
	inline void VertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value){ return internal::glVertexAttribP1ui(index, type, normalized, value); }
	inline void VertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value){ return internal::glVertexAttribP1uiv(index, type, normalized, value); }
	inline void VertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value){ return internal::glVertexAttribP2ui(index, type, normalized, value); }
	inline void VertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value){ return internal::glVertexAttribP2uiv(index, type, normalized, value); }
	inline void VertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value){ return internal::glVertexAttribP3ui(index, type, normalized, value); }
	inline void VertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value){ return internal::glVertexAttribP3uiv(index, type, normalized, value); }
	inline void VertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value){ return internal::glVertexAttribP4ui(index, type, normalized, value); }
	inline void VertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value){ return internal::glVertexAttribP4uiv(index, type, normalized, value); }

	// GL_ARB_compute_shader

	constexpr GLenum COMPUTE_SHADER = 0x91B9;
	constexpr GLenum MAX_COMPUTE_UNIFORM_BLOCKS = 0x91BB;
	constexpr GLenum MAX_COMPUTE_TEXTURE_IMAGE_UNITS = 0x91BC;
	constexpr GLenum MAX_COMPUTE_IMAGE_UNIFORMS = 0x91BD;
	constexpr GLenum MAX_COMPUTE_SHARED_MEMORY_SIZE = 0x8262;
	constexpr GLenum MAX_COMPUTE_UNIFORM_COMPONENTS = 0x8263;
	constexpr GLenum MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS = 0x8264;
	constexpr GLenum MAX_COMPUTE_ATOMIC_COUNTERS = 0x8265;
	constexpr GLenum MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS = 0x8266;
	constexpr GLenum MAX_COMPUTE_WORK_GROUP_INVOCATIONS = 0x90EB;
	constexpr GLenum MAX_COMPUTE_WORK_GROUP_COUNT = 0x91BE;
	constexpr GLenum MAX_COMPUTE_WORK_GROUP_SIZE = 0x91BF;
	constexpr GLenum COMPUTE_WORK_GROUP_SIZE = 0x8267;
	constexpr GLenum UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER = 0x90EC;
	constexpr GLenum ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER = 0x90ED;
	constexpr GLenum DISPATCH_INDIRECT_BUFFER = 0x90EE;
	constexpr GLenum DISPATCH_INDIRECT_BUFFER_BINDING = 0x90EF;
	constexpr GLenum COMPUTE_SHADER_BIT = 0x00000020;

	inline void DispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z){ return internal::glDispatchCompute(num_groups_x, num_groups_y, num_groups_z); }
	inline void DispatchComputeIndirect(GLintptr indirect){ return internal::glDispatchComputeIndirect(indirect); }

	// GL_ARB_texture_filter_anisotropic

	constexpr GLenum TEXTURE_MAX_ANISOTROPY = 0x84FE;
	constexpr GLenum MAX_TEXTURE_MAX_ANISOTROPY = 0x84FF;


	namespace sys
	{

		bool initialize();
		const char * api();
		int major_version();
		int minor_version();

		bool has_extension(const char * name);
		bool ext_ARB_compute_shader();
		bool ext_ARB_texture_filter_anisotropic();

	} // namespace sys

} // namespace gl

