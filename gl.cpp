#include "gl.hpp"


#include <unordered_set>
#include <string>

#if defined(__APPLE__)
#include <dlfcn.h>
#elif defined(__sgi) || defined (__sun)
#include <dlfcn.h>
#include <stdio.h>
#elif defined(_WIN32)
#include <windows.h>
#elif defined(__ANDROID__)
#include <EGL/egl.h>
#else
#include <GL/glx.h>
#endif

namespace gl
{

	namespace internal
	{

		
		#if defined(__APPLE__)
		
		static void * get_proc_address(const char *func)
		{
			static void * image = dlopen("/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL", RTLD_LAZY);
		
			if (!image) return nullptr;
		
			return dlsym(image, func);
		}
		
		#elif defined(__sgi) || defined (__sun)
		
		static void * get_proc_address(const char *func)
		{
			static void * image = dlopen(nullptr, RTLD_LAZY | RTLD_LOCAL);
			static void * gpa = image ? dlsym(image, "glXGetProcAddress") : nullptr;
		
			if (gpa)
				return reinterpret_cast<void(*)(const GLubyte*)>(gpa)(reinterpret_cast<const char *>(name));
			else
				return dlsym(image, name);
		}
		
		#elif defined(_WIN32)
		
		#ifdef _MSC_VER
		#pragma warning(disable: 4055)
		#pragma warning(disable: 4054)
		#pragma warning(disable: 4996)
		#endif
		
		static int test_pointer(const PROC p)
		{
			ptrdiff_t i;
			if (!p) return 0;
			i = (ptrdiff_t)p;
		
			if(i == 1 || i == 2 || i == 3 || i == -1) return 0;
		
			return 1;
		}
		
		static void * get_proc_address(const char *name)
		{
			static HMODULE image = GetModuleHandleA("opengl32.dll");
		
			PROC func = wglGetProcAddress(reinterpret_cast<LPCSTR>(name));
			if (test_pointer(func))
			{
				return reinterpret_cast<void*>(func);
			}
		
			return reinterpret_cast<void*>(GetProcAddress(image, reinterpret_cast<LPCSTR>(name)));
		}
		
		#elif defined(__ANDROID__)
		
		static void * get_proc_address(const char *func)
		{
			return reinterpret_cast<void *>(eglGetProcAddress(func));
		}
			
		#else // GLX
		
		static void * get_proc_address(const char *func)
		{
			return reinterpret_cast<void *>(glXGetProcAddress(reinterpret_cast<const GLubyte*>(func)));
		}
		
		#endif

		// OpenGL 1.0

		void (*glCullFace)(GLenum mode) = nullptr;
		void (*glFrontFace)(GLenum mode) = nullptr;
		void (*glHint)(GLenum target, GLenum mode) = nullptr;
		void (*glLineWidth)(GLfloat width) = nullptr;
		void (*glPointSize)(GLfloat size) = nullptr;
		void (*glPolygonMode)(GLenum face, GLenum mode) = nullptr;
		void (*glScissor)(GLint x, GLint y, GLsizei width, GLsizei height) = nullptr;
		void (*glTexParameterf)(GLenum target, GLenum pname, GLfloat param) = nullptr;
		void (*glTexParameterfv)(GLenum target, GLenum pname, const GLfloat *params) = nullptr;
		void (*glTexParameteri)(GLenum target, GLenum pname, GLint param) = nullptr;
		void (*glTexParameteriv)(GLenum target, GLenum pname, const GLint *params) = nullptr;
		void (*glTexImage1D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels) = nullptr;
		void (*glTexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels) = nullptr;
		void (*glDrawBuffer)(GLenum buf) = nullptr;
		void (*glClear)(GLbitfield mask) = nullptr;
		void (*glClearColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) = nullptr;
		void (*glClearStencil)(GLint s) = nullptr;
		void (*glClearDepth)(GLdouble depth) = nullptr;
		void (*glStencilMask)(GLuint mask) = nullptr;
		void (*glColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) = nullptr;
		void (*glDepthMask)(GLboolean flag) = nullptr;
		void (*glDisable)(GLenum cap) = nullptr;
		void (*glEnable)(GLenum cap) = nullptr;
		void (*glFinish)() = nullptr;
		void (*glFlush)() = nullptr;
		void (*glBlendFunc)(GLenum sfactor, GLenum dfactor) = nullptr;
		void (*glLogicOp)(GLenum opcode) = nullptr;
		void (*glStencilFunc)(GLenum func, GLint ref, GLuint mask) = nullptr;
		void (*glStencilOp)(GLenum fail, GLenum zfail, GLenum zpass) = nullptr;
		void (*glDepthFunc)(GLenum func) = nullptr;
		void (*glPixelStoref)(GLenum pname, GLfloat param) = nullptr;
		void (*glPixelStorei)(GLenum pname, GLint param) = nullptr;
		void (*glReadBuffer)(GLenum src) = nullptr;
		void (*glReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels) = nullptr;
		void (*glGetBooleanv)(GLenum pname, GLboolean *data) = nullptr;
		void (*glGetDoublev)(GLenum pname, GLdouble *data) = nullptr;
		GLenum (*glGetError)() = nullptr;
		void (*glGetFloatv)(GLenum pname, GLfloat *data) = nullptr;
		void (*glGetIntegerv)(GLenum pname, GLint *data) = nullptr;
		const GLubyte *(*glGetString)(GLenum name) = nullptr;
		void (*glGetTexImage)(GLenum target, GLint level, GLenum format, GLenum type, void *pixels) = nullptr;
		void (*glGetTexParameterfv)(GLenum target, GLenum pname, GLfloat *params) = nullptr;
		void (*glGetTexParameteriv)(GLenum target, GLenum pname, GLint *params) = nullptr;
		void (*glGetTexLevelParameterfv)(GLenum target, GLint level, GLenum pname, GLfloat *params) = nullptr;
		void (*glGetTexLevelParameteriv)(GLenum target, GLint level, GLenum pname, GLint *params) = nullptr;
		GLboolean (*glIsEnabled)(GLenum cap) = nullptr;
		void (*glDepthRange)(GLdouble n, GLdouble f) = nullptr;
		void (*glViewport)(GLint x, GLint y, GLsizei width, GLsizei height) = nullptr;

		// OpenGL 1.1

		void (*glDrawArrays)(GLenum mode, GLint first, GLsizei count) = nullptr;
		void (*glDrawElements)(GLenum mode, GLsizei count, GLenum type, const void *indices) = nullptr;
		void (*glPolygonOffset)(GLfloat factor, GLfloat units) = nullptr;
		void (*glCopyTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) = nullptr;
		void (*glCopyTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) = nullptr;
		void (*glCopyTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) = nullptr;
		void (*glCopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) = nullptr;
		void (*glTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels) = nullptr;
		void (*glTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) = nullptr;
		void (*glBindTexture)(GLenum target, GLuint texture) = nullptr;
		void (*glDeleteTextures)(GLsizei n, const GLuint *textures) = nullptr;
		void (*glGenTextures)(GLsizei n, GLuint *textures) = nullptr;
		GLboolean (*glIsTexture)(GLuint texture) = nullptr;

		// OpenGL 1.2

		void (*glDrawRangeElements)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices) = nullptr;
		void (*glTexImage3D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels) = nullptr;
		void (*glTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) = nullptr;
		void (*glCopyTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) = nullptr;

		// OpenGL 1.3

		void (*glActiveTexture)(GLenum texture) = nullptr;
		void (*glSampleCoverage)(GLfloat value, GLboolean invert) = nullptr;
		void (*glCompressedTexImage3D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data) = nullptr;
		void (*glCompressedTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data) = nullptr;
		void (*glCompressedTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data) = nullptr;
		void (*glCompressedTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data) = nullptr;
		void (*glCompressedTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) = nullptr;
		void (*glCompressedTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data) = nullptr;
		void (*glGetCompressedTexImage)(GLenum target, GLint level, void *img) = nullptr;

		// OpenGL 1.4

		void (*glBlendFuncSeparate)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) = nullptr;
		void (*glMultiDrawArrays)(GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount) = nullptr;
		void (*glMultiDrawElements)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount) = nullptr;
		void (*glPointParameterf)(GLenum pname, GLfloat param) = nullptr;
		void (*glPointParameterfv)(GLenum pname, const GLfloat *params) = nullptr;
		void (*glPointParameteri)(GLenum pname, GLint param) = nullptr;
		void (*glPointParameteriv)(GLenum pname, const GLint *params) = nullptr;
		void (*glBlendColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) = nullptr;
		void (*glBlendEquation)(GLenum mode) = nullptr;

		// OpenGL 1.5

		void (*glGenQueries)(GLsizei n, GLuint *ids) = nullptr;
		void (*glDeleteQueries)(GLsizei n, const GLuint *ids) = nullptr;
		GLboolean (*glIsQuery)(GLuint id) = nullptr;
		void (*glBeginQuery)(GLenum target, GLuint id) = nullptr;
		void (*glEndQuery)(GLenum target) = nullptr;
		void (*glGetQueryiv)(GLenum target, GLenum pname, GLint *params) = nullptr;
		void (*glGetQueryObjectiv)(GLuint id, GLenum pname, GLint *params) = nullptr;
		void (*glGetQueryObjectuiv)(GLuint id, GLenum pname, GLuint *params) = nullptr;
		void (*glBindBuffer)(GLenum target, GLuint buffer) = nullptr;
		void (*glDeleteBuffers)(GLsizei n, const GLuint *buffers) = nullptr;
		void (*glGenBuffers)(GLsizei n, GLuint *buffers) = nullptr;
		GLboolean (*glIsBuffer)(GLuint buffer) = nullptr;
		void (*glBufferData)(GLenum target, GLsizeiptr size, const void *data, GLenum usage) = nullptr;
		void (*glBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, const void *data) = nullptr;
		void (*glGetBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, void *data) = nullptr;
		void *(*glMapBuffer)(GLenum target, GLenum access) = nullptr;
		GLboolean (*glUnmapBuffer)(GLenum target) = nullptr;
		void (*glGetBufferParameteriv)(GLenum target, GLenum pname, GLint *params) = nullptr;
		void (*glGetBufferPointerv)(GLenum target, GLenum pname, void **params) = nullptr;

		// OpenGL 2.0

		void (*glBlendEquationSeparate)(GLenum modeRGB, GLenum modeAlpha) = nullptr;
		void (*glDrawBuffers)(GLsizei n, const GLenum *bufs) = nullptr;
		void (*glStencilOpSeparate)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) = nullptr;
		void (*glStencilFuncSeparate)(GLenum face, GLenum func, GLint ref, GLuint mask) = nullptr;
		void (*glStencilMaskSeparate)(GLenum face, GLuint mask) = nullptr;
		void (*glAttachShader)(GLuint program, GLuint shader) = nullptr;
		void (*glBindAttribLocation)(GLuint program, GLuint index, const GLchar *name) = nullptr;
		void (*glCompileShader)(GLuint shader) = nullptr;
		GLuint (*glCreateProgram)() = nullptr;
		GLuint (*glCreateShader)(GLenum type) = nullptr;
		void (*glDeleteProgram)(GLuint program) = nullptr;
		void (*glDeleteShader)(GLuint shader) = nullptr;
		void (*glDetachShader)(GLuint program, GLuint shader) = nullptr;
		void (*glDisableVertexAttribArray)(GLuint index) = nullptr;
		void (*glEnableVertexAttribArray)(GLuint index) = nullptr;
		void (*glGetActiveAttrib)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) = nullptr;
		void (*glGetActiveUniform)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) = nullptr;
		void (*glGetAttachedShaders)(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders) = nullptr;
		GLint (*glGetAttribLocation)(GLuint program, const GLchar *name) = nullptr;
		void (*glGetProgramiv)(GLuint program, GLenum pname, GLint *params) = nullptr;
		void (*glGetProgramInfoLog)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog) = nullptr;
		void (*glGetShaderiv)(GLuint shader, GLenum pname, GLint *params) = nullptr;
		void (*glGetShaderInfoLog)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog) = nullptr;
		void (*glGetShaderSource)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source) = nullptr;
		GLint (*glGetUniformLocation)(GLuint program, const GLchar *name) = nullptr;
		void (*glGetUniformfv)(GLuint program, GLint location, GLfloat *params) = nullptr;
		void (*glGetUniformiv)(GLuint program, GLint location, GLint *params) = nullptr;
		void (*glGetVertexAttribdv)(GLuint index, GLenum pname, GLdouble *params) = nullptr;
		void (*glGetVertexAttribfv)(GLuint index, GLenum pname, GLfloat *params) = nullptr;
		void (*glGetVertexAttribiv)(GLuint index, GLenum pname, GLint *params) = nullptr;
		void (*glGetVertexAttribPointerv)(GLuint index, GLenum pname, void **pointer) = nullptr;
		GLboolean (*glIsProgram)(GLuint program) = nullptr;
		GLboolean (*glIsShader)(GLuint shader) = nullptr;
		void (*glLinkProgram)(GLuint program) = nullptr;
		void (*glShaderSource)(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length) = nullptr;
		void (*glUseProgram)(GLuint program) = nullptr;
		void (*glUniform1f)(GLint location, GLfloat v0) = nullptr;
		void (*glUniform2f)(GLint location, GLfloat v0, GLfloat v1) = nullptr;
		void (*glUniform3f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) = nullptr;
		void (*glUniform4f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) = nullptr;
		void (*glUniform1i)(GLint location, GLint v0) = nullptr;
		void (*glUniform2i)(GLint location, GLint v0, GLint v1) = nullptr;
		void (*glUniform3i)(GLint location, GLint v0, GLint v1, GLint v2) = nullptr;
		void (*glUniform4i)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) = nullptr;
		void (*glUniform1fv)(GLint location, GLsizei count, const GLfloat *value) = nullptr;
		void (*glUniform2fv)(GLint location, GLsizei count, const GLfloat *value) = nullptr;
		void (*glUniform3fv)(GLint location, GLsizei count, const GLfloat *value) = nullptr;
		void (*glUniform4fv)(GLint location, GLsizei count, const GLfloat *value) = nullptr;
		void (*glUniform1iv)(GLint location, GLsizei count, const GLint *value) = nullptr;
		void (*glUniform2iv)(GLint location, GLsizei count, const GLint *value) = nullptr;
		void (*glUniform3iv)(GLint location, GLsizei count, const GLint *value) = nullptr;
		void (*glUniform4iv)(GLint location, GLsizei count, const GLint *value) = nullptr;
		void (*glUniformMatrix2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
		void (*glUniformMatrix3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
		void (*glUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
		void (*glValidateProgram)(GLuint program) = nullptr;
		void (*glVertexAttrib1d)(GLuint index, GLdouble x) = nullptr;
		void (*glVertexAttrib1dv)(GLuint index, const GLdouble *v) = nullptr;
		void (*glVertexAttrib1f)(GLuint index, GLfloat x) = nullptr;
		void (*glVertexAttrib1fv)(GLuint index, const GLfloat *v) = nullptr;
		void (*glVertexAttrib1s)(GLuint index, GLshort x) = nullptr;
		void (*glVertexAttrib1sv)(GLuint index, const GLshort *v) = nullptr;
		void (*glVertexAttrib2d)(GLuint index, GLdouble x, GLdouble y) = nullptr;
		void (*glVertexAttrib2dv)(GLuint index, const GLdouble *v) = nullptr;
		void (*glVertexAttrib2f)(GLuint index, GLfloat x, GLfloat y) = nullptr;
		void (*glVertexAttrib2fv)(GLuint index, const GLfloat *v) = nullptr;
		void (*glVertexAttrib2s)(GLuint index, GLshort x, GLshort y) = nullptr;
		void (*glVertexAttrib2sv)(GLuint index, const GLshort *v) = nullptr;
		void (*glVertexAttrib3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z) = nullptr;
		void (*glVertexAttrib3dv)(GLuint index, const GLdouble *v) = nullptr;
		void (*glVertexAttrib3f)(GLuint index, GLfloat x, GLfloat y, GLfloat z) = nullptr;
		void (*glVertexAttrib3fv)(GLuint index, const GLfloat *v) = nullptr;
		void (*glVertexAttrib3s)(GLuint index, GLshort x, GLshort y, GLshort z) = nullptr;
		void (*glVertexAttrib3sv)(GLuint index, const GLshort *v) = nullptr;
		void (*glVertexAttrib4Nbv)(GLuint index, const GLbyte *v) = nullptr;
		void (*glVertexAttrib4Niv)(GLuint index, const GLint *v) = nullptr;
		void (*glVertexAttrib4Nsv)(GLuint index, const GLshort *v) = nullptr;
		void (*glVertexAttrib4Nub)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) = nullptr;
		void (*glVertexAttrib4Nubv)(GLuint index, const GLubyte *v) = nullptr;
		void (*glVertexAttrib4Nuiv)(GLuint index, const GLuint *v) = nullptr;
		void (*glVertexAttrib4Nusv)(GLuint index, const GLushort *v) = nullptr;
		void (*glVertexAttrib4bv)(GLuint index, const GLbyte *v) = nullptr;
		void (*glVertexAttrib4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) = nullptr;
		void (*glVertexAttrib4dv)(GLuint index, const GLdouble *v) = nullptr;
		void (*glVertexAttrib4f)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) = nullptr;
		void (*glVertexAttrib4fv)(GLuint index, const GLfloat *v) = nullptr;
		void (*glVertexAttrib4iv)(GLuint index, const GLint *v) = nullptr;
		void (*glVertexAttrib4s)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) = nullptr;
		void (*glVertexAttrib4sv)(GLuint index, const GLshort *v) = nullptr;
		void (*glVertexAttrib4ubv)(GLuint index, const GLubyte *v) = nullptr;
		void (*glVertexAttrib4uiv)(GLuint index, const GLuint *v) = nullptr;
		void (*glVertexAttrib4usv)(GLuint index, const GLushort *v) = nullptr;
		void (*glVertexAttribPointer)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) = nullptr;

		// OpenGL 2.1

		void (*glUniformMatrix2x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
		void (*glUniformMatrix3x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
		void (*glUniformMatrix2x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
		void (*glUniformMatrix4x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
		void (*glUniformMatrix3x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
		void (*glUniformMatrix4x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;

		// OpenGL 3.0

		void (*glColorMaski)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) = nullptr;
		void (*glGetBooleani_v)(GLenum target, GLuint index, GLboolean *data) = nullptr;
		void (*glGetIntegeri_v)(GLenum target, GLuint index, GLint *data) = nullptr;
		void (*glEnablei)(GLenum target, GLuint index) = nullptr;
		void (*glDisablei)(GLenum target, GLuint index) = nullptr;
		GLboolean (*glIsEnabledi)(GLenum target, GLuint index) = nullptr;
		void (*glBeginTransformFeedback)(GLenum primitiveMode) = nullptr;
		void (*glEndTransformFeedback)() = nullptr;
		void (*glBindBufferRange)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) = nullptr;
		void (*glBindBufferBase)(GLenum target, GLuint index, GLuint buffer) = nullptr;
		void (*glTransformFeedbackVaryings)(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode) = nullptr;
		void (*glGetTransformFeedbackVarying)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name) = nullptr;
		void (*glClampColor)(GLenum target, GLenum clamp) = nullptr;
		void (*glBeginConditionalRender)(GLuint id, GLenum mode) = nullptr;
		void (*glEndConditionalRender)() = nullptr;
		void (*glVertexAttribIPointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) = nullptr;
		void (*glGetVertexAttribIiv)(GLuint index, GLenum pname, GLint *params) = nullptr;
		void (*glGetVertexAttribIuiv)(GLuint index, GLenum pname, GLuint *params) = nullptr;
		void (*glVertexAttribI1i)(GLuint index, GLint x) = nullptr;
		void (*glVertexAttribI2i)(GLuint index, GLint x, GLint y) = nullptr;
		void (*glVertexAttribI3i)(GLuint index, GLint x, GLint y, GLint z) = nullptr;
		void (*glVertexAttribI4i)(GLuint index, GLint x, GLint y, GLint z, GLint w) = nullptr;
		void (*glVertexAttribI1ui)(GLuint index, GLuint x) = nullptr;
		void (*glVertexAttribI2ui)(GLuint index, GLuint x, GLuint y) = nullptr;
		void (*glVertexAttribI3ui)(GLuint index, GLuint x, GLuint y, GLuint z) = nullptr;
		void (*glVertexAttribI4ui)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) = nullptr;
		void (*glVertexAttribI1iv)(GLuint index, const GLint *v) = nullptr;
		void (*glVertexAttribI2iv)(GLuint index, const GLint *v) = nullptr;
		void (*glVertexAttribI3iv)(GLuint index, const GLint *v) = nullptr;
		void (*glVertexAttribI4iv)(GLuint index, const GLint *v) = nullptr;
		void (*glVertexAttribI1uiv)(GLuint index, const GLuint *v) = nullptr;
		void (*glVertexAttribI2uiv)(GLuint index, const GLuint *v) = nullptr;
		void (*glVertexAttribI3uiv)(GLuint index, const GLuint *v) = nullptr;
		void (*glVertexAttribI4uiv)(GLuint index, const GLuint *v) = nullptr;
		void (*glVertexAttribI4bv)(GLuint index, const GLbyte *v) = nullptr;
		void (*glVertexAttribI4sv)(GLuint index, const GLshort *v) = nullptr;
		void (*glVertexAttribI4ubv)(GLuint index, const GLubyte *v) = nullptr;
		void (*glVertexAttribI4usv)(GLuint index, const GLushort *v) = nullptr;
		void (*glGetUniformuiv)(GLuint program, GLint location, GLuint *params) = nullptr;
		void (*glBindFragDataLocation)(GLuint program, GLuint color, const GLchar *name) = nullptr;
		GLint (*glGetFragDataLocation)(GLuint program, const GLchar *name) = nullptr;
		void (*glUniform1ui)(GLint location, GLuint v0) = nullptr;
		void (*glUniform2ui)(GLint location, GLuint v0, GLuint v1) = nullptr;
		void (*glUniform3ui)(GLint location, GLuint v0, GLuint v1, GLuint v2) = nullptr;
		void (*glUniform4ui)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) = nullptr;
		void (*glUniform1uiv)(GLint location, GLsizei count, const GLuint *value) = nullptr;
		void (*glUniform2uiv)(GLint location, GLsizei count, const GLuint *value) = nullptr;
		void (*glUniform3uiv)(GLint location, GLsizei count, const GLuint *value) = nullptr;
		void (*glUniform4uiv)(GLint location, GLsizei count, const GLuint *value) = nullptr;
		void (*glTexParameterIiv)(GLenum target, GLenum pname, const GLint *params) = nullptr;
		void (*glTexParameterIuiv)(GLenum target, GLenum pname, const GLuint *params) = nullptr;
		void (*glGetTexParameterIiv)(GLenum target, GLenum pname, GLint *params) = nullptr;
		void (*glGetTexParameterIuiv)(GLenum target, GLenum pname, GLuint *params) = nullptr;
		void (*glClearBufferiv)(GLenum buffer, GLint drawbuffer, const GLint *value) = nullptr;
		void (*glClearBufferuiv)(GLenum buffer, GLint drawbuffer, const GLuint *value) = nullptr;
		void (*glClearBufferfv)(GLenum buffer, GLint drawbuffer, const GLfloat *value) = nullptr;
		void (*glClearBufferfi)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) = nullptr;
		const GLubyte *(*glGetStringi)(GLenum name, GLuint index) = nullptr;
		GLboolean (*glIsRenderbuffer)(GLuint renderbuffer) = nullptr;
		void (*glBindRenderbuffer)(GLenum target, GLuint renderbuffer) = nullptr;
		void (*glDeleteRenderbuffers)(GLsizei n, const GLuint *renderbuffers) = nullptr;
		void (*glGenRenderbuffers)(GLsizei n, GLuint *renderbuffers) = nullptr;
		void (*glRenderbufferStorage)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) = nullptr;
		void (*glGetRenderbufferParameteriv)(GLenum target, GLenum pname, GLint *params) = nullptr;
		GLboolean (*glIsFramebuffer)(GLuint framebuffer) = nullptr;
		void (*glBindFramebuffer)(GLenum target, GLuint framebuffer) = nullptr;
		void (*glDeleteFramebuffers)(GLsizei n, const GLuint *framebuffers) = nullptr;
		void (*glGenFramebuffers)(GLsizei n, GLuint *framebuffers) = nullptr;
		GLenum (*glCheckFramebufferStatus)(GLenum target) = nullptr;
		void (*glFramebufferTexture1D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) = nullptr;
		void (*glFramebufferTexture2D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) = nullptr;
		void (*glFramebufferTexture3D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) = nullptr;
		void (*glFramebufferRenderbuffer)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) = nullptr;
		void (*glGetFramebufferAttachmentParameteriv)(GLenum target, GLenum attachment, GLenum pname, GLint *params) = nullptr;
		void (*glGenerateMipmap)(GLenum target) = nullptr;
		void (*glBlitFramebuffer)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) = nullptr;
		void (*glRenderbufferStorageMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) = nullptr;
		void (*glFramebufferTextureLayer)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) = nullptr;
		void *(*glMapBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) = nullptr;
		void (*glFlushMappedBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length) = nullptr;
		void (*glBindVertexArray)(GLuint array) = nullptr;
		void (*glDeleteVertexArrays)(GLsizei n, const GLuint *arrays) = nullptr;
		void (*glGenVertexArrays)(GLsizei n, GLuint *arrays) = nullptr;
		GLboolean (*glIsVertexArray)(GLuint array) = nullptr;

		// OpenGL 3.1

		void (*glDrawArraysInstanced)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount) = nullptr;
		void (*glDrawElementsInstanced)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount) = nullptr;
		void (*glTexBuffer)(GLenum target, GLenum internalformat, GLuint buffer) = nullptr;
		void (*glPrimitiveRestartIndex)(GLuint index) = nullptr;
		void (*glCopyBufferSubData)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) = nullptr;
		void (*glGetUniformIndices)(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices) = nullptr;
		void (*glGetActiveUniformsiv)(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params) = nullptr;
		void (*glGetActiveUniformName)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName) = nullptr;
		GLuint (*glGetUniformBlockIndex)(GLuint program, const GLchar *uniformBlockName) = nullptr;
		void (*glGetActiveUniformBlockiv)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params) = nullptr;
		void (*glGetActiveUniformBlockName)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName) = nullptr;
		void (*glUniformBlockBinding)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) = nullptr;

		// OpenGL 3.2

		void (*glDrawElementsBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex) = nullptr;
		void (*glDrawRangeElementsBaseVertex)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex) = nullptr;
		void (*glDrawElementsInstancedBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex) = nullptr;
		void (*glMultiDrawElementsBaseVertex)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex) = nullptr;
		void (*glProvokingVertex)(GLenum mode) = nullptr;
		GLsync (*glFenceSync)(GLenum condition, GLbitfield flags) = nullptr;
		GLboolean (*glIsSync)(GLsync sync) = nullptr;
		void (*glDeleteSync)(GLsync sync) = nullptr;
		GLenum (*glClientWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout) = nullptr;
		void (*glWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout) = nullptr;
		void (*glGetInteger64v)(GLenum pname, GLint64 *data) = nullptr;
		void (*glGetSynciv)(GLsync sync, GLenum pname, GLsizei count, GLsizei *length, GLint *values) = nullptr;
		void (*glGetInteger64i_v)(GLenum target, GLuint index, GLint64 *data) = nullptr;
		void (*glGetBufferParameteri64v)(GLenum target, GLenum pname, GLint64 *params) = nullptr;
		void (*glFramebufferTexture)(GLenum target, GLenum attachment, GLuint texture, GLint level) = nullptr;
		void (*glTexImage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) = nullptr;
		void (*glTexImage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) = nullptr;
		void (*glGetMultisamplefv)(GLenum pname, GLuint index, GLfloat *val) = nullptr;
		void (*glSampleMaski)(GLuint maskNumber, GLbitfield mask) = nullptr;

		// OpenGL 3.3

		void (*glBindFragDataLocationIndexed)(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name) = nullptr;
		GLint (*glGetFragDataIndex)(GLuint program, const GLchar *name) = nullptr;
		void (*glGenSamplers)(GLsizei count, GLuint *samplers) = nullptr;
		void (*glDeleteSamplers)(GLsizei count, const GLuint *samplers) = nullptr;
		GLboolean (*glIsSampler)(GLuint sampler) = nullptr;
		void (*glBindSampler)(GLuint unit, GLuint sampler) = nullptr;
		void (*glSamplerParameteri)(GLuint sampler, GLenum pname, GLint param) = nullptr;
		void (*glSamplerParameteriv)(GLuint sampler, GLenum pname, const GLint *param) = nullptr;
		void (*glSamplerParameterf)(GLuint sampler, GLenum pname, GLfloat param) = nullptr;
		void (*glSamplerParameterfv)(GLuint sampler, GLenum pname, const GLfloat *param) = nullptr;
		void (*glSamplerParameterIiv)(GLuint sampler, GLenum pname, const GLint *param) = nullptr;
		void (*glSamplerParameterIuiv)(GLuint sampler, GLenum pname, const GLuint *param) = nullptr;
		void (*glGetSamplerParameteriv)(GLuint sampler, GLenum pname, GLint *params) = nullptr;
		void (*glGetSamplerParameterIiv)(GLuint sampler, GLenum pname, GLint *params) = nullptr;
		void (*glGetSamplerParameterfv)(GLuint sampler, GLenum pname, GLfloat *params) = nullptr;
		void (*glGetSamplerParameterIuiv)(GLuint sampler, GLenum pname, GLuint *params) = nullptr;
		void (*glQueryCounter)(GLuint id, GLenum target) = nullptr;
		void (*glGetQueryObjecti64v)(GLuint id, GLenum pname, GLint64 *params) = nullptr;
		void (*glGetQueryObjectui64v)(GLuint id, GLenum pname, GLuint64 *params) = nullptr;
		void (*glVertexAttribDivisor)(GLuint index, GLuint divisor) = nullptr;
		void (*glVertexAttribP1ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value) = nullptr;
		void (*glVertexAttribP1uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) = nullptr;
		void (*glVertexAttribP2ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value) = nullptr;
		void (*glVertexAttribP2uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) = nullptr;
		void (*glVertexAttribP3ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value) = nullptr;
		void (*glVertexAttribP3uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) = nullptr;
		void (*glVertexAttribP4ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value) = nullptr;
		void (*glVertexAttribP4uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) = nullptr;

		// GL_ARB_compute_shader

		void (*glDispatchCompute)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z) = nullptr;
		void (*glDispatchComputeIndirect)(GLintptr indirect) = nullptr;

		// GL_ARB_texture_filter_anisotropic


	} // namespace internal

	namespace sys
	{

		static bool ext_GL_ARB_compute_shader_loaded = false;
		static bool ext_GL_ARB_texture_filter_anisotropic_loaded = false;

		static bool load_core()
		{
			// OpenGL 1.0

			internal::glCullFace = reinterpret_cast<void (*)(GLenum )>(internal::get_proc_address("glCullFace"));
			if (!internal::glCullFace) return false;
			internal::glFrontFace = reinterpret_cast<void (*)(GLenum )>(internal::get_proc_address("glFrontFace"));
			if (!internal::glFrontFace) return false;
			internal::glHint = reinterpret_cast<void (*)(GLenum , GLenum )>(internal::get_proc_address("glHint"));
			if (!internal::glHint) return false;
			internal::glLineWidth = reinterpret_cast<void (*)(GLfloat )>(internal::get_proc_address("glLineWidth"));
			if (!internal::glLineWidth) return false;
			internal::glPointSize = reinterpret_cast<void (*)(GLfloat )>(internal::get_proc_address("glPointSize"));
			if (!internal::glPointSize) return false;
			internal::glPolygonMode = reinterpret_cast<void (*)(GLenum , GLenum )>(internal::get_proc_address("glPolygonMode"));
			if (!internal::glPolygonMode) return false;
			internal::glScissor = reinterpret_cast<void (*)(GLint , GLint , GLsizei , GLsizei )>(internal::get_proc_address("glScissor"));
			if (!internal::glScissor) return false;
			internal::glTexParameterf = reinterpret_cast<void (*)(GLenum , GLenum , GLfloat )>(internal::get_proc_address("glTexParameterf"));
			if (!internal::glTexParameterf) return false;
			internal::glTexParameterfv = reinterpret_cast<void (*)(GLenum , GLenum , const GLfloat *)>(internal::get_proc_address("glTexParameterfv"));
			if (!internal::glTexParameterfv) return false;
			internal::glTexParameteri = reinterpret_cast<void (*)(GLenum , GLenum , GLint )>(internal::get_proc_address("glTexParameteri"));
			if (!internal::glTexParameteri) return false;
			internal::glTexParameteriv = reinterpret_cast<void (*)(GLenum , GLenum , const GLint *)>(internal::get_proc_address("glTexParameteriv"));
			if (!internal::glTexParameteriv) return false;
			internal::glTexImage1D = reinterpret_cast<void (*)(GLenum , GLint , GLint , GLsizei , GLint , GLenum , GLenum , const void *)>(internal::get_proc_address("glTexImage1D"));
			if (!internal::glTexImage1D) return false;
			internal::glTexImage2D = reinterpret_cast<void (*)(GLenum , GLint , GLint , GLsizei , GLsizei , GLint , GLenum , GLenum , const void *)>(internal::get_proc_address("glTexImage2D"));
			if (!internal::glTexImage2D) return false;
			internal::glDrawBuffer = reinterpret_cast<void (*)(GLenum )>(internal::get_proc_address("glDrawBuffer"));
			if (!internal::glDrawBuffer) return false;
			internal::glClear = reinterpret_cast<void (*)(GLbitfield )>(internal::get_proc_address("glClear"));
			if (!internal::glClear) return false;
			internal::glClearColor = reinterpret_cast<void (*)(GLfloat , GLfloat , GLfloat , GLfloat )>(internal::get_proc_address("glClearColor"));
			if (!internal::glClearColor) return false;
			internal::glClearStencil = reinterpret_cast<void (*)(GLint )>(internal::get_proc_address("glClearStencil"));
			if (!internal::glClearStencil) return false;
			internal::glClearDepth = reinterpret_cast<void (*)(GLdouble )>(internal::get_proc_address("glClearDepth"));
			if (!internal::glClearDepth) return false;
			internal::glStencilMask = reinterpret_cast<void (*)(GLuint )>(internal::get_proc_address("glStencilMask"));
			if (!internal::glStencilMask) return false;
			internal::glColorMask = reinterpret_cast<void (*)(GLboolean , GLboolean , GLboolean , GLboolean )>(internal::get_proc_address("glColorMask"));
			if (!internal::glColorMask) return false;
			internal::glDepthMask = reinterpret_cast<void (*)(GLboolean )>(internal::get_proc_address("glDepthMask"));
			if (!internal::glDepthMask) return false;
			internal::glDisable = reinterpret_cast<void (*)(GLenum )>(internal::get_proc_address("glDisable"));
			if (!internal::glDisable) return false;
			internal::glEnable = reinterpret_cast<void (*)(GLenum )>(internal::get_proc_address("glEnable"));
			if (!internal::glEnable) return false;
			internal::glFinish = reinterpret_cast<void (*)()>(internal::get_proc_address("glFinish"));
			if (!internal::glFinish) return false;
			internal::glFlush = reinterpret_cast<void (*)()>(internal::get_proc_address("glFlush"));
			if (!internal::glFlush) return false;
			internal::glBlendFunc = reinterpret_cast<void (*)(GLenum , GLenum )>(internal::get_proc_address("glBlendFunc"));
			if (!internal::glBlendFunc) return false;
			internal::glLogicOp = reinterpret_cast<void (*)(GLenum )>(internal::get_proc_address("glLogicOp"));
			if (!internal::glLogicOp) return false;
			internal::glStencilFunc = reinterpret_cast<void (*)(GLenum , GLint , GLuint )>(internal::get_proc_address("glStencilFunc"));
			if (!internal::glStencilFunc) return false;
			internal::glStencilOp = reinterpret_cast<void (*)(GLenum , GLenum , GLenum )>(internal::get_proc_address("glStencilOp"));
			if (!internal::glStencilOp) return false;
			internal::glDepthFunc = reinterpret_cast<void (*)(GLenum )>(internal::get_proc_address("glDepthFunc"));
			if (!internal::glDepthFunc) return false;
			internal::glPixelStoref = reinterpret_cast<void (*)(GLenum , GLfloat )>(internal::get_proc_address("glPixelStoref"));
			if (!internal::glPixelStoref) return false;
			internal::glPixelStorei = reinterpret_cast<void (*)(GLenum , GLint )>(internal::get_proc_address("glPixelStorei"));
			if (!internal::glPixelStorei) return false;
			internal::glReadBuffer = reinterpret_cast<void (*)(GLenum )>(internal::get_proc_address("glReadBuffer"));
			if (!internal::glReadBuffer) return false;
			internal::glReadPixels = reinterpret_cast<void (*)(GLint , GLint , GLsizei , GLsizei , GLenum , GLenum , void *)>(internal::get_proc_address("glReadPixels"));
			if (!internal::glReadPixels) return false;
			internal::glGetBooleanv = reinterpret_cast<void (*)(GLenum , GLboolean *)>(internal::get_proc_address("glGetBooleanv"));
			if (!internal::glGetBooleanv) return false;
			internal::glGetDoublev = reinterpret_cast<void (*)(GLenum , GLdouble *)>(internal::get_proc_address("glGetDoublev"));
			if (!internal::glGetDoublev) return false;
			internal::glGetError = reinterpret_cast<GLenum (*)()>(internal::get_proc_address("glGetError"));
			if (!internal::glGetError) return false;
			internal::glGetFloatv = reinterpret_cast<void (*)(GLenum , GLfloat *)>(internal::get_proc_address("glGetFloatv"));
			if (!internal::glGetFloatv) return false;
			internal::glGetIntegerv = reinterpret_cast<void (*)(GLenum , GLint *)>(internal::get_proc_address("glGetIntegerv"));
			if (!internal::glGetIntegerv) return false;
			internal::glGetString = reinterpret_cast<const GLubyte *(*)(GLenum )>(internal::get_proc_address("glGetString"));
			if (!internal::glGetString) return false;
			internal::glGetTexImage = reinterpret_cast<void (*)(GLenum , GLint , GLenum , GLenum , void *)>(internal::get_proc_address("glGetTexImage"));
			if (!internal::glGetTexImage) return false;
			internal::glGetTexParameterfv = reinterpret_cast<void (*)(GLenum , GLenum , GLfloat *)>(internal::get_proc_address("glGetTexParameterfv"));
			if (!internal::glGetTexParameterfv) return false;
			internal::glGetTexParameteriv = reinterpret_cast<void (*)(GLenum , GLenum , GLint *)>(internal::get_proc_address("glGetTexParameteriv"));
			if (!internal::glGetTexParameteriv) return false;
			internal::glGetTexLevelParameterfv = reinterpret_cast<void (*)(GLenum , GLint , GLenum , GLfloat *)>(internal::get_proc_address("glGetTexLevelParameterfv"));
			if (!internal::glGetTexLevelParameterfv) return false;
			internal::glGetTexLevelParameteriv = reinterpret_cast<void (*)(GLenum , GLint , GLenum , GLint *)>(internal::get_proc_address("glGetTexLevelParameteriv"));
			if (!internal::glGetTexLevelParameteriv) return false;
			internal::glIsEnabled = reinterpret_cast<GLboolean (*)(GLenum )>(internal::get_proc_address("glIsEnabled"));
			if (!internal::glIsEnabled) return false;
			internal::glDepthRange = reinterpret_cast<void (*)(GLdouble , GLdouble )>(internal::get_proc_address("glDepthRange"));
			if (!internal::glDepthRange) return false;
			internal::glViewport = reinterpret_cast<void (*)(GLint , GLint , GLsizei , GLsizei )>(internal::get_proc_address("glViewport"));
			if (!internal::glViewport) return false;

			// OpenGL 1.1

			internal::glDrawArrays = reinterpret_cast<void (*)(GLenum , GLint , GLsizei )>(internal::get_proc_address("glDrawArrays"));
			if (!internal::glDrawArrays) return false;
			internal::glDrawElements = reinterpret_cast<void (*)(GLenum , GLsizei , GLenum , const void *)>(internal::get_proc_address("glDrawElements"));
			if (!internal::glDrawElements) return false;
			internal::glPolygonOffset = reinterpret_cast<void (*)(GLfloat , GLfloat )>(internal::get_proc_address("glPolygonOffset"));
			if (!internal::glPolygonOffset) return false;
			internal::glCopyTexImage1D = reinterpret_cast<void (*)(GLenum , GLint , GLenum , GLint , GLint , GLsizei , GLint )>(internal::get_proc_address("glCopyTexImage1D"));
			if (!internal::glCopyTexImage1D) return false;
			internal::glCopyTexImage2D = reinterpret_cast<void (*)(GLenum , GLint , GLenum , GLint , GLint , GLsizei , GLsizei , GLint )>(internal::get_proc_address("glCopyTexImage2D"));
			if (!internal::glCopyTexImage2D) return false;
			internal::glCopyTexSubImage1D = reinterpret_cast<void (*)(GLenum , GLint , GLint , GLint , GLint , GLsizei )>(internal::get_proc_address("glCopyTexSubImage1D"));
			if (!internal::glCopyTexSubImage1D) return false;
			internal::glCopyTexSubImage2D = reinterpret_cast<void (*)(GLenum , GLint , GLint , GLint , GLint , GLint , GLsizei , GLsizei )>(internal::get_proc_address("glCopyTexSubImage2D"));
			if (!internal::glCopyTexSubImage2D) return false;
			internal::glTexSubImage1D = reinterpret_cast<void (*)(GLenum , GLint , GLint , GLsizei , GLenum , GLenum , const void *)>(internal::get_proc_address("glTexSubImage1D"));
			if (!internal::glTexSubImage1D) return false;
			internal::glTexSubImage2D = reinterpret_cast<void (*)(GLenum , GLint , GLint , GLint , GLsizei , GLsizei , GLenum , GLenum , const void *)>(internal::get_proc_address("glTexSubImage2D"));
			if (!internal::glTexSubImage2D) return false;
			internal::glBindTexture = reinterpret_cast<void (*)(GLenum , GLuint )>(internal::get_proc_address("glBindTexture"));
			if (!internal::glBindTexture) return false;
			internal::glDeleteTextures = reinterpret_cast<void (*)(GLsizei , const GLuint *)>(internal::get_proc_address("glDeleteTextures"));
			if (!internal::glDeleteTextures) return false;
			internal::glGenTextures = reinterpret_cast<void (*)(GLsizei , GLuint *)>(internal::get_proc_address("glGenTextures"));
			if (!internal::glGenTextures) return false;
			internal::glIsTexture = reinterpret_cast<GLboolean (*)(GLuint )>(internal::get_proc_address("glIsTexture"));
			if (!internal::glIsTexture) return false;

			// OpenGL 1.2

			internal::glDrawRangeElements = reinterpret_cast<void (*)(GLenum , GLuint , GLuint , GLsizei , GLenum , const void *)>(internal::get_proc_address("glDrawRangeElements"));
			if (!internal::glDrawRangeElements) return false;
			internal::glTexImage3D = reinterpret_cast<void (*)(GLenum , GLint , GLint , GLsizei , GLsizei , GLsizei , GLint , GLenum , GLenum , const void *)>(internal::get_proc_address("glTexImage3D"));
			if (!internal::glTexImage3D) return false;
			internal::glTexSubImage3D = reinterpret_cast<void (*)(GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei , GLenum , GLenum , const void *)>(internal::get_proc_address("glTexSubImage3D"));
			if (!internal::glTexSubImage3D) return false;
			internal::glCopyTexSubImage3D = reinterpret_cast<void (*)(GLenum , GLint , GLint , GLint , GLint , GLint , GLint , GLsizei , GLsizei )>(internal::get_proc_address("glCopyTexSubImage3D"));
			if (!internal::glCopyTexSubImage3D) return false;

			// OpenGL 1.3

			internal::glActiveTexture = reinterpret_cast<void (*)(GLenum )>(internal::get_proc_address("glActiveTexture"));
			if (!internal::glActiveTexture) return false;
			internal::glSampleCoverage = reinterpret_cast<void (*)(GLfloat , GLboolean )>(internal::get_proc_address("glSampleCoverage"));
			if (!internal::glSampleCoverage) return false;
			internal::glCompressedTexImage3D = reinterpret_cast<void (*)(GLenum , GLint , GLenum , GLsizei , GLsizei , GLsizei , GLint , GLsizei , const void *)>(internal::get_proc_address("glCompressedTexImage3D"));
			if (!internal::glCompressedTexImage3D) return false;
			internal::glCompressedTexImage2D = reinterpret_cast<void (*)(GLenum , GLint , GLenum , GLsizei , GLsizei , GLint , GLsizei , const void *)>(internal::get_proc_address("glCompressedTexImage2D"));
			if (!internal::glCompressedTexImage2D) return false;
			internal::glCompressedTexImage1D = reinterpret_cast<void (*)(GLenum , GLint , GLenum , GLsizei , GLint , GLsizei , const void *)>(internal::get_proc_address("glCompressedTexImage1D"));
			if (!internal::glCompressedTexImage1D) return false;
			internal::glCompressedTexSubImage3D = reinterpret_cast<void (*)(GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei , GLenum , GLsizei , const void *)>(internal::get_proc_address("glCompressedTexSubImage3D"));
			if (!internal::glCompressedTexSubImage3D) return false;
			internal::glCompressedTexSubImage2D = reinterpret_cast<void (*)(GLenum , GLint , GLint , GLint , GLsizei , GLsizei , GLenum , GLsizei , const void *)>(internal::get_proc_address("glCompressedTexSubImage2D"));
			if (!internal::glCompressedTexSubImage2D) return false;
			internal::glCompressedTexSubImage1D = reinterpret_cast<void (*)(GLenum , GLint , GLint , GLsizei , GLenum , GLsizei , const void *)>(internal::get_proc_address("glCompressedTexSubImage1D"));
			if (!internal::glCompressedTexSubImage1D) return false;
			internal::glGetCompressedTexImage = reinterpret_cast<void (*)(GLenum , GLint , void *)>(internal::get_proc_address("glGetCompressedTexImage"));
			if (!internal::glGetCompressedTexImage) return false;

			// OpenGL 1.4

			internal::glBlendFuncSeparate = reinterpret_cast<void (*)(GLenum , GLenum , GLenum , GLenum )>(internal::get_proc_address("glBlendFuncSeparate"));
			if (!internal::glBlendFuncSeparate) return false;
			internal::glMultiDrawArrays = reinterpret_cast<void (*)(GLenum , const GLint *, const GLsizei *, GLsizei )>(internal::get_proc_address("glMultiDrawArrays"));
			if (!internal::glMultiDrawArrays) return false;
			internal::glMultiDrawElements = reinterpret_cast<void (*)(GLenum , const GLsizei *, GLenum , const void *const*, GLsizei )>(internal::get_proc_address("glMultiDrawElements"));
			if (!internal::glMultiDrawElements) return false;
			internal::glPointParameterf = reinterpret_cast<void (*)(GLenum , GLfloat )>(internal::get_proc_address("glPointParameterf"));
			if (!internal::glPointParameterf) return false;
			internal::glPointParameterfv = reinterpret_cast<void (*)(GLenum , const GLfloat *)>(internal::get_proc_address("glPointParameterfv"));
			if (!internal::glPointParameterfv) return false;
			internal::glPointParameteri = reinterpret_cast<void (*)(GLenum , GLint )>(internal::get_proc_address("glPointParameteri"));
			if (!internal::glPointParameteri) return false;
			internal::glPointParameteriv = reinterpret_cast<void (*)(GLenum , const GLint *)>(internal::get_proc_address("glPointParameteriv"));
			if (!internal::glPointParameteriv) return false;
			internal::glBlendColor = reinterpret_cast<void (*)(GLfloat , GLfloat , GLfloat , GLfloat )>(internal::get_proc_address("glBlendColor"));
			if (!internal::glBlendColor) return false;
			internal::glBlendEquation = reinterpret_cast<void (*)(GLenum )>(internal::get_proc_address("glBlendEquation"));
			if (!internal::glBlendEquation) return false;

			// OpenGL 1.5

			internal::glGenQueries = reinterpret_cast<void (*)(GLsizei , GLuint *)>(internal::get_proc_address("glGenQueries"));
			if (!internal::glGenQueries) return false;
			internal::glDeleteQueries = reinterpret_cast<void (*)(GLsizei , const GLuint *)>(internal::get_proc_address("glDeleteQueries"));
			if (!internal::glDeleteQueries) return false;
			internal::glIsQuery = reinterpret_cast<GLboolean (*)(GLuint )>(internal::get_proc_address("glIsQuery"));
			if (!internal::glIsQuery) return false;
			internal::glBeginQuery = reinterpret_cast<void (*)(GLenum , GLuint )>(internal::get_proc_address("glBeginQuery"));
			if (!internal::glBeginQuery) return false;
			internal::glEndQuery = reinterpret_cast<void (*)(GLenum )>(internal::get_proc_address("glEndQuery"));
			if (!internal::glEndQuery) return false;
			internal::glGetQueryiv = reinterpret_cast<void (*)(GLenum , GLenum , GLint *)>(internal::get_proc_address("glGetQueryiv"));
			if (!internal::glGetQueryiv) return false;
			internal::glGetQueryObjectiv = reinterpret_cast<void (*)(GLuint , GLenum , GLint *)>(internal::get_proc_address("glGetQueryObjectiv"));
			if (!internal::glGetQueryObjectiv) return false;
			internal::glGetQueryObjectuiv = reinterpret_cast<void (*)(GLuint , GLenum , GLuint *)>(internal::get_proc_address("glGetQueryObjectuiv"));
			if (!internal::glGetQueryObjectuiv) return false;
			internal::glBindBuffer = reinterpret_cast<void (*)(GLenum , GLuint )>(internal::get_proc_address("glBindBuffer"));
			if (!internal::glBindBuffer) return false;
			internal::glDeleteBuffers = reinterpret_cast<void (*)(GLsizei , const GLuint *)>(internal::get_proc_address("glDeleteBuffers"));
			if (!internal::glDeleteBuffers) return false;
			internal::glGenBuffers = reinterpret_cast<void (*)(GLsizei , GLuint *)>(internal::get_proc_address("glGenBuffers"));
			if (!internal::glGenBuffers) return false;
			internal::glIsBuffer = reinterpret_cast<GLboolean (*)(GLuint )>(internal::get_proc_address("glIsBuffer"));
			if (!internal::glIsBuffer) return false;
			internal::glBufferData = reinterpret_cast<void (*)(GLenum , GLsizeiptr , const void *, GLenum )>(internal::get_proc_address("glBufferData"));
			if (!internal::glBufferData) return false;
			internal::glBufferSubData = reinterpret_cast<void (*)(GLenum , GLintptr , GLsizeiptr , const void *)>(internal::get_proc_address("glBufferSubData"));
			if (!internal::glBufferSubData) return false;
			internal::glGetBufferSubData = reinterpret_cast<void (*)(GLenum , GLintptr , GLsizeiptr , void *)>(internal::get_proc_address("glGetBufferSubData"));
			if (!internal::glGetBufferSubData) return false;
			internal::glMapBuffer = reinterpret_cast<void *(*)(GLenum , GLenum )>(internal::get_proc_address("glMapBuffer"));
			if (!internal::glMapBuffer) return false;
			internal::glUnmapBuffer = reinterpret_cast<GLboolean (*)(GLenum )>(internal::get_proc_address("glUnmapBuffer"));
			if (!internal::glUnmapBuffer) return false;
			internal::glGetBufferParameteriv = reinterpret_cast<void (*)(GLenum , GLenum , GLint *)>(internal::get_proc_address("glGetBufferParameteriv"));
			if (!internal::glGetBufferParameteriv) return false;
			internal::glGetBufferPointerv = reinterpret_cast<void (*)(GLenum , GLenum , void **)>(internal::get_proc_address("glGetBufferPointerv"));
			if (!internal::glGetBufferPointerv) return false;

			// OpenGL 2.0

			internal::glBlendEquationSeparate = reinterpret_cast<void (*)(GLenum , GLenum )>(internal::get_proc_address("glBlendEquationSeparate"));
			if (!internal::glBlendEquationSeparate) return false;
			internal::glDrawBuffers = reinterpret_cast<void (*)(GLsizei , const GLenum *)>(internal::get_proc_address("glDrawBuffers"));
			if (!internal::glDrawBuffers) return false;
			internal::glStencilOpSeparate = reinterpret_cast<void (*)(GLenum , GLenum , GLenum , GLenum )>(internal::get_proc_address("glStencilOpSeparate"));
			if (!internal::glStencilOpSeparate) return false;
			internal::glStencilFuncSeparate = reinterpret_cast<void (*)(GLenum , GLenum , GLint , GLuint )>(internal::get_proc_address("glStencilFuncSeparate"));
			if (!internal::glStencilFuncSeparate) return false;
			internal::glStencilMaskSeparate = reinterpret_cast<void (*)(GLenum , GLuint )>(internal::get_proc_address("glStencilMaskSeparate"));
			if (!internal::glStencilMaskSeparate) return false;
			internal::glAttachShader = reinterpret_cast<void (*)(GLuint , GLuint )>(internal::get_proc_address("glAttachShader"));
			if (!internal::glAttachShader) return false;
			internal::glBindAttribLocation = reinterpret_cast<void (*)(GLuint , GLuint , const GLchar *)>(internal::get_proc_address("glBindAttribLocation"));
			if (!internal::glBindAttribLocation) return false;
			internal::glCompileShader = reinterpret_cast<void (*)(GLuint )>(internal::get_proc_address("glCompileShader"));
			if (!internal::glCompileShader) return false;
			internal::glCreateProgram = reinterpret_cast<GLuint (*)()>(internal::get_proc_address("glCreateProgram"));
			if (!internal::glCreateProgram) return false;
			internal::glCreateShader = reinterpret_cast<GLuint (*)(GLenum )>(internal::get_proc_address("glCreateShader"));
			if (!internal::glCreateShader) return false;
			internal::glDeleteProgram = reinterpret_cast<void (*)(GLuint )>(internal::get_proc_address("glDeleteProgram"));
			if (!internal::glDeleteProgram) return false;
			internal::glDeleteShader = reinterpret_cast<void (*)(GLuint )>(internal::get_proc_address("glDeleteShader"));
			if (!internal::glDeleteShader) return false;
			internal::glDetachShader = reinterpret_cast<void (*)(GLuint , GLuint )>(internal::get_proc_address("glDetachShader"));
			if (!internal::glDetachShader) return false;
			internal::glDisableVertexAttribArray = reinterpret_cast<void (*)(GLuint )>(internal::get_proc_address("glDisableVertexAttribArray"));
			if (!internal::glDisableVertexAttribArray) return false;
			internal::glEnableVertexAttribArray = reinterpret_cast<void (*)(GLuint )>(internal::get_proc_address("glEnableVertexAttribArray"));
			if (!internal::glEnableVertexAttribArray) return false;
			internal::glGetActiveAttrib = reinterpret_cast<void (*)(GLuint , GLuint , GLsizei , GLsizei *, GLint *, GLenum *, GLchar *)>(internal::get_proc_address("glGetActiveAttrib"));
			if (!internal::glGetActiveAttrib) return false;
			internal::glGetActiveUniform = reinterpret_cast<void (*)(GLuint , GLuint , GLsizei , GLsizei *, GLint *, GLenum *, GLchar *)>(internal::get_proc_address("glGetActiveUniform"));
			if (!internal::glGetActiveUniform) return false;
			internal::glGetAttachedShaders = reinterpret_cast<void (*)(GLuint , GLsizei , GLsizei *, GLuint *)>(internal::get_proc_address("glGetAttachedShaders"));
			if (!internal::glGetAttachedShaders) return false;
			internal::glGetAttribLocation = reinterpret_cast<GLint (*)(GLuint , const GLchar *)>(internal::get_proc_address("glGetAttribLocation"));
			if (!internal::glGetAttribLocation) return false;
			internal::glGetProgramiv = reinterpret_cast<void (*)(GLuint , GLenum , GLint *)>(internal::get_proc_address("glGetProgramiv"));
			if (!internal::glGetProgramiv) return false;
			internal::glGetProgramInfoLog = reinterpret_cast<void (*)(GLuint , GLsizei , GLsizei *, GLchar *)>(internal::get_proc_address("glGetProgramInfoLog"));
			if (!internal::glGetProgramInfoLog) return false;
			internal::glGetShaderiv = reinterpret_cast<void (*)(GLuint , GLenum , GLint *)>(internal::get_proc_address("glGetShaderiv"));
			if (!internal::glGetShaderiv) return false;
			internal::glGetShaderInfoLog = reinterpret_cast<void (*)(GLuint , GLsizei , GLsizei *, GLchar *)>(internal::get_proc_address("glGetShaderInfoLog"));
			if (!internal::glGetShaderInfoLog) return false;
			internal::glGetShaderSource = reinterpret_cast<void (*)(GLuint , GLsizei , GLsizei *, GLchar *)>(internal::get_proc_address("glGetShaderSource"));
			if (!internal::glGetShaderSource) return false;
			internal::glGetUniformLocation = reinterpret_cast<GLint (*)(GLuint , const GLchar *)>(internal::get_proc_address("glGetUniformLocation"));
			if (!internal::glGetUniformLocation) return false;
			internal::glGetUniformfv = reinterpret_cast<void (*)(GLuint , GLint , GLfloat *)>(internal::get_proc_address("glGetUniformfv"));
			if (!internal::glGetUniformfv) return false;
			internal::glGetUniformiv = reinterpret_cast<void (*)(GLuint , GLint , GLint *)>(internal::get_proc_address("glGetUniformiv"));
			if (!internal::glGetUniformiv) return false;
			internal::glGetVertexAttribdv = reinterpret_cast<void (*)(GLuint , GLenum , GLdouble *)>(internal::get_proc_address("glGetVertexAttribdv"));
			if (!internal::glGetVertexAttribdv) return false;
			internal::glGetVertexAttribfv = reinterpret_cast<void (*)(GLuint , GLenum , GLfloat *)>(internal::get_proc_address("glGetVertexAttribfv"));
			if (!internal::glGetVertexAttribfv) return false;
			internal::glGetVertexAttribiv = reinterpret_cast<void (*)(GLuint , GLenum , GLint *)>(internal::get_proc_address("glGetVertexAttribiv"));
			if (!internal::glGetVertexAttribiv) return false;
			internal::glGetVertexAttribPointerv = reinterpret_cast<void (*)(GLuint , GLenum , void **)>(internal::get_proc_address("glGetVertexAttribPointerv"));
			if (!internal::glGetVertexAttribPointerv) return false;
			internal::glIsProgram = reinterpret_cast<GLboolean (*)(GLuint )>(internal::get_proc_address("glIsProgram"));
			if (!internal::glIsProgram) return false;
			internal::glIsShader = reinterpret_cast<GLboolean (*)(GLuint )>(internal::get_proc_address("glIsShader"));
			if (!internal::glIsShader) return false;
			internal::glLinkProgram = reinterpret_cast<void (*)(GLuint )>(internal::get_proc_address("glLinkProgram"));
			if (!internal::glLinkProgram) return false;
			internal::glShaderSource = reinterpret_cast<void (*)(GLuint , GLsizei , const GLchar *const*, const GLint *)>(internal::get_proc_address("glShaderSource"));
			if (!internal::glShaderSource) return false;
			internal::glUseProgram = reinterpret_cast<void (*)(GLuint )>(internal::get_proc_address("glUseProgram"));
			if (!internal::glUseProgram) return false;
			internal::glUniform1f = reinterpret_cast<void (*)(GLint , GLfloat )>(internal::get_proc_address("glUniform1f"));
			if (!internal::glUniform1f) return false;
			internal::glUniform2f = reinterpret_cast<void (*)(GLint , GLfloat , GLfloat )>(internal::get_proc_address("glUniform2f"));
			if (!internal::glUniform2f) return false;
			internal::glUniform3f = reinterpret_cast<void (*)(GLint , GLfloat , GLfloat , GLfloat )>(internal::get_proc_address("glUniform3f"));
			if (!internal::glUniform3f) return false;
			internal::glUniform4f = reinterpret_cast<void (*)(GLint , GLfloat , GLfloat , GLfloat , GLfloat )>(internal::get_proc_address("glUniform4f"));
			if (!internal::glUniform4f) return false;
			internal::glUniform1i = reinterpret_cast<void (*)(GLint , GLint )>(internal::get_proc_address("glUniform1i"));
			if (!internal::glUniform1i) return false;
			internal::glUniform2i = reinterpret_cast<void (*)(GLint , GLint , GLint )>(internal::get_proc_address("glUniform2i"));
			if (!internal::glUniform2i) return false;
			internal::glUniform3i = reinterpret_cast<void (*)(GLint , GLint , GLint , GLint )>(internal::get_proc_address("glUniform3i"));
			if (!internal::glUniform3i) return false;
			internal::glUniform4i = reinterpret_cast<void (*)(GLint , GLint , GLint , GLint , GLint )>(internal::get_proc_address("glUniform4i"));
			if (!internal::glUniform4i) return false;
			internal::glUniform1fv = reinterpret_cast<void (*)(GLint , GLsizei , const GLfloat *)>(internal::get_proc_address("glUniform1fv"));
			if (!internal::glUniform1fv) return false;
			internal::glUniform2fv = reinterpret_cast<void (*)(GLint , GLsizei , const GLfloat *)>(internal::get_proc_address("glUniform2fv"));
			if (!internal::glUniform2fv) return false;
			internal::glUniform3fv = reinterpret_cast<void (*)(GLint , GLsizei , const GLfloat *)>(internal::get_proc_address("glUniform3fv"));
			if (!internal::glUniform3fv) return false;
			internal::glUniform4fv = reinterpret_cast<void (*)(GLint , GLsizei , const GLfloat *)>(internal::get_proc_address("glUniform4fv"));
			if (!internal::glUniform4fv) return false;
			internal::glUniform1iv = reinterpret_cast<void (*)(GLint , GLsizei , const GLint *)>(internal::get_proc_address("glUniform1iv"));
			if (!internal::glUniform1iv) return false;
			internal::glUniform2iv = reinterpret_cast<void (*)(GLint , GLsizei , const GLint *)>(internal::get_proc_address("glUniform2iv"));
			if (!internal::glUniform2iv) return false;
			internal::glUniform3iv = reinterpret_cast<void (*)(GLint , GLsizei , const GLint *)>(internal::get_proc_address("glUniform3iv"));
			if (!internal::glUniform3iv) return false;
			internal::glUniform4iv = reinterpret_cast<void (*)(GLint , GLsizei , const GLint *)>(internal::get_proc_address("glUniform4iv"));
			if (!internal::glUniform4iv) return false;
			internal::glUniformMatrix2fv = reinterpret_cast<void (*)(GLint , GLsizei , GLboolean , const GLfloat *)>(internal::get_proc_address("glUniformMatrix2fv"));
			if (!internal::glUniformMatrix2fv) return false;
			internal::glUniformMatrix3fv = reinterpret_cast<void (*)(GLint , GLsizei , GLboolean , const GLfloat *)>(internal::get_proc_address("glUniformMatrix3fv"));
			if (!internal::glUniformMatrix3fv) return false;
			internal::glUniformMatrix4fv = reinterpret_cast<void (*)(GLint , GLsizei , GLboolean , const GLfloat *)>(internal::get_proc_address("glUniformMatrix4fv"));
			if (!internal::glUniformMatrix4fv) return false;
			internal::glValidateProgram = reinterpret_cast<void (*)(GLuint )>(internal::get_proc_address("glValidateProgram"));
			if (!internal::glValidateProgram) return false;
			internal::glVertexAttrib1d = reinterpret_cast<void (*)(GLuint , GLdouble )>(internal::get_proc_address("glVertexAttrib1d"));
			if (!internal::glVertexAttrib1d) return false;
			internal::glVertexAttrib1dv = reinterpret_cast<void (*)(GLuint , const GLdouble *)>(internal::get_proc_address("glVertexAttrib1dv"));
			if (!internal::glVertexAttrib1dv) return false;
			internal::glVertexAttrib1f = reinterpret_cast<void (*)(GLuint , GLfloat )>(internal::get_proc_address("glVertexAttrib1f"));
			if (!internal::glVertexAttrib1f) return false;
			internal::glVertexAttrib1fv = reinterpret_cast<void (*)(GLuint , const GLfloat *)>(internal::get_proc_address("glVertexAttrib1fv"));
			if (!internal::glVertexAttrib1fv) return false;
			internal::glVertexAttrib1s = reinterpret_cast<void (*)(GLuint , GLshort )>(internal::get_proc_address("glVertexAttrib1s"));
			if (!internal::glVertexAttrib1s) return false;
			internal::glVertexAttrib1sv = reinterpret_cast<void (*)(GLuint , const GLshort *)>(internal::get_proc_address("glVertexAttrib1sv"));
			if (!internal::glVertexAttrib1sv) return false;
			internal::glVertexAttrib2d = reinterpret_cast<void (*)(GLuint , GLdouble , GLdouble )>(internal::get_proc_address("glVertexAttrib2d"));
			if (!internal::glVertexAttrib2d) return false;
			internal::glVertexAttrib2dv = reinterpret_cast<void (*)(GLuint , const GLdouble *)>(internal::get_proc_address("glVertexAttrib2dv"));
			if (!internal::glVertexAttrib2dv) return false;
			internal::glVertexAttrib2f = reinterpret_cast<void (*)(GLuint , GLfloat , GLfloat )>(internal::get_proc_address("glVertexAttrib2f"));
			if (!internal::glVertexAttrib2f) return false;
			internal::glVertexAttrib2fv = reinterpret_cast<void (*)(GLuint , const GLfloat *)>(internal::get_proc_address("glVertexAttrib2fv"));
			if (!internal::glVertexAttrib2fv) return false;
			internal::glVertexAttrib2s = reinterpret_cast<void (*)(GLuint , GLshort , GLshort )>(internal::get_proc_address("glVertexAttrib2s"));
			if (!internal::glVertexAttrib2s) return false;
			internal::glVertexAttrib2sv = reinterpret_cast<void (*)(GLuint , const GLshort *)>(internal::get_proc_address("glVertexAttrib2sv"));
			if (!internal::glVertexAttrib2sv) return false;
			internal::glVertexAttrib3d = reinterpret_cast<void (*)(GLuint , GLdouble , GLdouble , GLdouble )>(internal::get_proc_address("glVertexAttrib3d"));
			if (!internal::glVertexAttrib3d) return false;
			internal::glVertexAttrib3dv = reinterpret_cast<void (*)(GLuint , const GLdouble *)>(internal::get_proc_address("glVertexAttrib3dv"));
			if (!internal::glVertexAttrib3dv) return false;
			internal::glVertexAttrib3f = reinterpret_cast<void (*)(GLuint , GLfloat , GLfloat , GLfloat )>(internal::get_proc_address("glVertexAttrib3f"));
			if (!internal::glVertexAttrib3f) return false;
			internal::glVertexAttrib3fv = reinterpret_cast<void (*)(GLuint , const GLfloat *)>(internal::get_proc_address("glVertexAttrib3fv"));
			if (!internal::glVertexAttrib3fv) return false;
			internal::glVertexAttrib3s = reinterpret_cast<void (*)(GLuint , GLshort , GLshort , GLshort )>(internal::get_proc_address("glVertexAttrib3s"));
			if (!internal::glVertexAttrib3s) return false;
			internal::glVertexAttrib3sv = reinterpret_cast<void (*)(GLuint , const GLshort *)>(internal::get_proc_address("glVertexAttrib3sv"));
			if (!internal::glVertexAttrib3sv) return false;
			internal::glVertexAttrib4Nbv = reinterpret_cast<void (*)(GLuint , const GLbyte *)>(internal::get_proc_address("glVertexAttrib4Nbv"));
			if (!internal::glVertexAttrib4Nbv) return false;
			internal::glVertexAttrib4Niv = reinterpret_cast<void (*)(GLuint , const GLint *)>(internal::get_proc_address("glVertexAttrib4Niv"));
			if (!internal::glVertexAttrib4Niv) return false;
			internal::glVertexAttrib4Nsv = reinterpret_cast<void (*)(GLuint , const GLshort *)>(internal::get_proc_address("glVertexAttrib4Nsv"));
			if (!internal::glVertexAttrib4Nsv) return false;
			internal::glVertexAttrib4Nub = reinterpret_cast<void (*)(GLuint , GLubyte , GLubyte , GLubyte , GLubyte )>(internal::get_proc_address("glVertexAttrib4Nub"));
			if (!internal::glVertexAttrib4Nub) return false;
			internal::glVertexAttrib4Nubv = reinterpret_cast<void (*)(GLuint , const GLubyte *)>(internal::get_proc_address("glVertexAttrib4Nubv"));
			if (!internal::glVertexAttrib4Nubv) return false;
			internal::glVertexAttrib4Nuiv = reinterpret_cast<void (*)(GLuint , const GLuint *)>(internal::get_proc_address("glVertexAttrib4Nuiv"));
			if (!internal::glVertexAttrib4Nuiv) return false;
			internal::glVertexAttrib4Nusv = reinterpret_cast<void (*)(GLuint , const GLushort *)>(internal::get_proc_address("glVertexAttrib4Nusv"));
			if (!internal::glVertexAttrib4Nusv) return false;
			internal::glVertexAttrib4bv = reinterpret_cast<void (*)(GLuint , const GLbyte *)>(internal::get_proc_address("glVertexAttrib4bv"));
			if (!internal::glVertexAttrib4bv) return false;
			internal::glVertexAttrib4d = reinterpret_cast<void (*)(GLuint , GLdouble , GLdouble , GLdouble , GLdouble )>(internal::get_proc_address("glVertexAttrib4d"));
			if (!internal::glVertexAttrib4d) return false;
			internal::glVertexAttrib4dv = reinterpret_cast<void (*)(GLuint , const GLdouble *)>(internal::get_proc_address("glVertexAttrib4dv"));
			if (!internal::glVertexAttrib4dv) return false;
			internal::glVertexAttrib4f = reinterpret_cast<void (*)(GLuint , GLfloat , GLfloat , GLfloat , GLfloat )>(internal::get_proc_address("glVertexAttrib4f"));
			if (!internal::glVertexAttrib4f) return false;
			internal::glVertexAttrib4fv = reinterpret_cast<void (*)(GLuint , const GLfloat *)>(internal::get_proc_address("glVertexAttrib4fv"));
			if (!internal::glVertexAttrib4fv) return false;
			internal::glVertexAttrib4iv = reinterpret_cast<void (*)(GLuint , const GLint *)>(internal::get_proc_address("glVertexAttrib4iv"));
			if (!internal::glVertexAttrib4iv) return false;
			internal::glVertexAttrib4s = reinterpret_cast<void (*)(GLuint , GLshort , GLshort , GLshort , GLshort )>(internal::get_proc_address("glVertexAttrib4s"));
			if (!internal::glVertexAttrib4s) return false;
			internal::glVertexAttrib4sv = reinterpret_cast<void (*)(GLuint , const GLshort *)>(internal::get_proc_address("glVertexAttrib4sv"));
			if (!internal::glVertexAttrib4sv) return false;
			internal::glVertexAttrib4ubv = reinterpret_cast<void (*)(GLuint , const GLubyte *)>(internal::get_proc_address("glVertexAttrib4ubv"));
			if (!internal::glVertexAttrib4ubv) return false;
			internal::glVertexAttrib4uiv = reinterpret_cast<void (*)(GLuint , const GLuint *)>(internal::get_proc_address("glVertexAttrib4uiv"));
			if (!internal::glVertexAttrib4uiv) return false;
			internal::glVertexAttrib4usv = reinterpret_cast<void (*)(GLuint , const GLushort *)>(internal::get_proc_address("glVertexAttrib4usv"));
			if (!internal::glVertexAttrib4usv) return false;
			internal::glVertexAttribPointer = reinterpret_cast<void (*)(GLuint , GLint , GLenum , GLboolean , GLsizei , const void *)>(internal::get_proc_address("glVertexAttribPointer"));
			if (!internal::glVertexAttribPointer) return false;

			// OpenGL 2.1

			internal::glUniformMatrix2x3fv = reinterpret_cast<void (*)(GLint , GLsizei , GLboolean , const GLfloat *)>(internal::get_proc_address("glUniformMatrix2x3fv"));
			if (!internal::glUniformMatrix2x3fv) return false;
			internal::glUniformMatrix3x2fv = reinterpret_cast<void (*)(GLint , GLsizei , GLboolean , const GLfloat *)>(internal::get_proc_address("glUniformMatrix3x2fv"));
			if (!internal::glUniformMatrix3x2fv) return false;
			internal::glUniformMatrix2x4fv = reinterpret_cast<void (*)(GLint , GLsizei , GLboolean , const GLfloat *)>(internal::get_proc_address("glUniformMatrix2x4fv"));
			if (!internal::glUniformMatrix2x4fv) return false;
			internal::glUniformMatrix4x2fv = reinterpret_cast<void (*)(GLint , GLsizei , GLboolean , const GLfloat *)>(internal::get_proc_address("glUniformMatrix4x2fv"));
			if (!internal::glUniformMatrix4x2fv) return false;
			internal::glUniformMatrix3x4fv = reinterpret_cast<void (*)(GLint , GLsizei , GLboolean , const GLfloat *)>(internal::get_proc_address("glUniformMatrix3x4fv"));
			if (!internal::glUniformMatrix3x4fv) return false;
			internal::glUniformMatrix4x3fv = reinterpret_cast<void (*)(GLint , GLsizei , GLboolean , const GLfloat *)>(internal::get_proc_address("glUniformMatrix4x3fv"));
			if (!internal::glUniformMatrix4x3fv) return false;

			// OpenGL 3.0

			internal::glColorMaski = reinterpret_cast<void (*)(GLuint , GLboolean , GLboolean , GLboolean , GLboolean )>(internal::get_proc_address("glColorMaski"));
			if (!internal::glColorMaski) return false;
			internal::glGetBooleani_v = reinterpret_cast<void (*)(GLenum , GLuint , GLboolean *)>(internal::get_proc_address("glGetBooleani_v"));
			if (!internal::glGetBooleani_v) return false;
			internal::glGetIntegeri_v = reinterpret_cast<void (*)(GLenum , GLuint , GLint *)>(internal::get_proc_address("glGetIntegeri_v"));
			if (!internal::glGetIntegeri_v) return false;
			internal::glEnablei = reinterpret_cast<void (*)(GLenum , GLuint )>(internal::get_proc_address("glEnablei"));
			if (!internal::glEnablei) return false;
			internal::glDisablei = reinterpret_cast<void (*)(GLenum , GLuint )>(internal::get_proc_address("glDisablei"));
			if (!internal::glDisablei) return false;
			internal::glIsEnabledi = reinterpret_cast<GLboolean (*)(GLenum , GLuint )>(internal::get_proc_address("glIsEnabledi"));
			if (!internal::glIsEnabledi) return false;
			internal::glBeginTransformFeedback = reinterpret_cast<void (*)(GLenum )>(internal::get_proc_address("glBeginTransformFeedback"));
			if (!internal::glBeginTransformFeedback) return false;
			internal::glEndTransformFeedback = reinterpret_cast<void (*)()>(internal::get_proc_address("glEndTransformFeedback"));
			if (!internal::glEndTransformFeedback) return false;
			internal::glBindBufferRange = reinterpret_cast<void (*)(GLenum , GLuint , GLuint , GLintptr , GLsizeiptr )>(internal::get_proc_address("glBindBufferRange"));
			if (!internal::glBindBufferRange) return false;
			internal::glBindBufferBase = reinterpret_cast<void (*)(GLenum , GLuint , GLuint )>(internal::get_proc_address("glBindBufferBase"));
			if (!internal::glBindBufferBase) return false;
			internal::glTransformFeedbackVaryings = reinterpret_cast<void (*)(GLuint , GLsizei , const GLchar *const*, GLenum )>(internal::get_proc_address("glTransformFeedbackVaryings"));
			if (!internal::glTransformFeedbackVaryings) return false;
			internal::glGetTransformFeedbackVarying = reinterpret_cast<void (*)(GLuint , GLuint , GLsizei , GLsizei *, GLsizei *, GLenum *, GLchar *)>(internal::get_proc_address("glGetTransformFeedbackVarying"));
			if (!internal::glGetTransformFeedbackVarying) return false;
			internal::glClampColor = reinterpret_cast<void (*)(GLenum , GLenum )>(internal::get_proc_address("glClampColor"));
			if (!internal::glClampColor) return false;
			internal::glBeginConditionalRender = reinterpret_cast<void (*)(GLuint , GLenum )>(internal::get_proc_address("glBeginConditionalRender"));
			if (!internal::glBeginConditionalRender) return false;
			internal::glEndConditionalRender = reinterpret_cast<void (*)()>(internal::get_proc_address("glEndConditionalRender"));
			if (!internal::glEndConditionalRender) return false;
			internal::glVertexAttribIPointer = reinterpret_cast<void (*)(GLuint , GLint , GLenum , GLsizei , const void *)>(internal::get_proc_address("glVertexAttribIPointer"));
			if (!internal::glVertexAttribIPointer) return false;
			internal::glGetVertexAttribIiv = reinterpret_cast<void (*)(GLuint , GLenum , GLint *)>(internal::get_proc_address("glGetVertexAttribIiv"));
			if (!internal::glGetVertexAttribIiv) return false;
			internal::glGetVertexAttribIuiv = reinterpret_cast<void (*)(GLuint , GLenum , GLuint *)>(internal::get_proc_address("glGetVertexAttribIuiv"));
			if (!internal::glGetVertexAttribIuiv) return false;
			internal::glVertexAttribI1i = reinterpret_cast<void (*)(GLuint , GLint )>(internal::get_proc_address("glVertexAttribI1i"));
			if (!internal::glVertexAttribI1i) return false;
			internal::glVertexAttribI2i = reinterpret_cast<void (*)(GLuint , GLint , GLint )>(internal::get_proc_address("glVertexAttribI2i"));
			if (!internal::glVertexAttribI2i) return false;
			internal::glVertexAttribI3i = reinterpret_cast<void (*)(GLuint , GLint , GLint , GLint )>(internal::get_proc_address("glVertexAttribI3i"));
			if (!internal::glVertexAttribI3i) return false;
			internal::glVertexAttribI4i = reinterpret_cast<void (*)(GLuint , GLint , GLint , GLint , GLint )>(internal::get_proc_address("glVertexAttribI4i"));
			if (!internal::glVertexAttribI4i) return false;
			internal::glVertexAttribI1ui = reinterpret_cast<void (*)(GLuint , GLuint )>(internal::get_proc_address("glVertexAttribI1ui"));
			if (!internal::glVertexAttribI1ui) return false;
			internal::glVertexAttribI2ui = reinterpret_cast<void (*)(GLuint , GLuint , GLuint )>(internal::get_proc_address("glVertexAttribI2ui"));
			if (!internal::glVertexAttribI2ui) return false;
			internal::glVertexAttribI3ui = reinterpret_cast<void (*)(GLuint , GLuint , GLuint , GLuint )>(internal::get_proc_address("glVertexAttribI3ui"));
			if (!internal::glVertexAttribI3ui) return false;
			internal::glVertexAttribI4ui = reinterpret_cast<void (*)(GLuint , GLuint , GLuint , GLuint , GLuint )>(internal::get_proc_address("glVertexAttribI4ui"));
			if (!internal::glVertexAttribI4ui) return false;
			internal::glVertexAttribI1iv = reinterpret_cast<void (*)(GLuint , const GLint *)>(internal::get_proc_address("glVertexAttribI1iv"));
			if (!internal::glVertexAttribI1iv) return false;
			internal::glVertexAttribI2iv = reinterpret_cast<void (*)(GLuint , const GLint *)>(internal::get_proc_address("glVertexAttribI2iv"));
			if (!internal::glVertexAttribI2iv) return false;
			internal::glVertexAttribI3iv = reinterpret_cast<void (*)(GLuint , const GLint *)>(internal::get_proc_address("glVertexAttribI3iv"));
			if (!internal::glVertexAttribI3iv) return false;
			internal::glVertexAttribI4iv = reinterpret_cast<void (*)(GLuint , const GLint *)>(internal::get_proc_address("glVertexAttribI4iv"));
			if (!internal::glVertexAttribI4iv) return false;
			internal::glVertexAttribI1uiv = reinterpret_cast<void (*)(GLuint , const GLuint *)>(internal::get_proc_address("glVertexAttribI1uiv"));
			if (!internal::glVertexAttribI1uiv) return false;
			internal::glVertexAttribI2uiv = reinterpret_cast<void (*)(GLuint , const GLuint *)>(internal::get_proc_address("glVertexAttribI2uiv"));
			if (!internal::glVertexAttribI2uiv) return false;
			internal::glVertexAttribI3uiv = reinterpret_cast<void (*)(GLuint , const GLuint *)>(internal::get_proc_address("glVertexAttribI3uiv"));
			if (!internal::glVertexAttribI3uiv) return false;
			internal::glVertexAttribI4uiv = reinterpret_cast<void (*)(GLuint , const GLuint *)>(internal::get_proc_address("glVertexAttribI4uiv"));
			if (!internal::glVertexAttribI4uiv) return false;
			internal::glVertexAttribI4bv = reinterpret_cast<void (*)(GLuint , const GLbyte *)>(internal::get_proc_address("glVertexAttribI4bv"));
			if (!internal::glVertexAttribI4bv) return false;
			internal::glVertexAttribI4sv = reinterpret_cast<void (*)(GLuint , const GLshort *)>(internal::get_proc_address("glVertexAttribI4sv"));
			if (!internal::glVertexAttribI4sv) return false;
			internal::glVertexAttribI4ubv = reinterpret_cast<void (*)(GLuint , const GLubyte *)>(internal::get_proc_address("glVertexAttribI4ubv"));
			if (!internal::glVertexAttribI4ubv) return false;
			internal::glVertexAttribI4usv = reinterpret_cast<void (*)(GLuint , const GLushort *)>(internal::get_proc_address("glVertexAttribI4usv"));
			if (!internal::glVertexAttribI4usv) return false;
			internal::glGetUniformuiv = reinterpret_cast<void (*)(GLuint , GLint , GLuint *)>(internal::get_proc_address("glGetUniformuiv"));
			if (!internal::glGetUniformuiv) return false;
			internal::glBindFragDataLocation = reinterpret_cast<void (*)(GLuint , GLuint , const GLchar *)>(internal::get_proc_address("glBindFragDataLocation"));
			if (!internal::glBindFragDataLocation) return false;
			internal::glGetFragDataLocation = reinterpret_cast<GLint (*)(GLuint , const GLchar *)>(internal::get_proc_address("glGetFragDataLocation"));
			if (!internal::glGetFragDataLocation) return false;
			internal::glUniform1ui = reinterpret_cast<void (*)(GLint , GLuint )>(internal::get_proc_address("glUniform1ui"));
			if (!internal::glUniform1ui) return false;
			internal::glUniform2ui = reinterpret_cast<void (*)(GLint , GLuint , GLuint )>(internal::get_proc_address("glUniform2ui"));
			if (!internal::glUniform2ui) return false;
			internal::glUniform3ui = reinterpret_cast<void (*)(GLint , GLuint , GLuint , GLuint )>(internal::get_proc_address("glUniform3ui"));
			if (!internal::glUniform3ui) return false;
			internal::glUniform4ui = reinterpret_cast<void (*)(GLint , GLuint , GLuint , GLuint , GLuint )>(internal::get_proc_address("glUniform4ui"));
			if (!internal::glUniform4ui) return false;
			internal::glUniform1uiv = reinterpret_cast<void (*)(GLint , GLsizei , const GLuint *)>(internal::get_proc_address("glUniform1uiv"));
			if (!internal::glUniform1uiv) return false;
			internal::glUniform2uiv = reinterpret_cast<void (*)(GLint , GLsizei , const GLuint *)>(internal::get_proc_address("glUniform2uiv"));
			if (!internal::glUniform2uiv) return false;
			internal::glUniform3uiv = reinterpret_cast<void (*)(GLint , GLsizei , const GLuint *)>(internal::get_proc_address("glUniform3uiv"));
			if (!internal::glUniform3uiv) return false;
			internal::glUniform4uiv = reinterpret_cast<void (*)(GLint , GLsizei , const GLuint *)>(internal::get_proc_address("glUniform4uiv"));
			if (!internal::glUniform4uiv) return false;
			internal::glTexParameterIiv = reinterpret_cast<void (*)(GLenum , GLenum , const GLint *)>(internal::get_proc_address("glTexParameterIiv"));
			if (!internal::glTexParameterIiv) return false;
			internal::glTexParameterIuiv = reinterpret_cast<void (*)(GLenum , GLenum , const GLuint *)>(internal::get_proc_address("glTexParameterIuiv"));
			if (!internal::glTexParameterIuiv) return false;
			internal::glGetTexParameterIiv = reinterpret_cast<void (*)(GLenum , GLenum , GLint *)>(internal::get_proc_address("glGetTexParameterIiv"));
			if (!internal::glGetTexParameterIiv) return false;
			internal::glGetTexParameterIuiv = reinterpret_cast<void (*)(GLenum , GLenum , GLuint *)>(internal::get_proc_address("glGetTexParameterIuiv"));
			if (!internal::glGetTexParameterIuiv) return false;
			internal::glClearBufferiv = reinterpret_cast<void (*)(GLenum , GLint , const GLint *)>(internal::get_proc_address("glClearBufferiv"));
			if (!internal::glClearBufferiv) return false;
			internal::glClearBufferuiv = reinterpret_cast<void (*)(GLenum , GLint , const GLuint *)>(internal::get_proc_address("glClearBufferuiv"));
			if (!internal::glClearBufferuiv) return false;
			internal::glClearBufferfv = reinterpret_cast<void (*)(GLenum , GLint , const GLfloat *)>(internal::get_proc_address("glClearBufferfv"));
			if (!internal::glClearBufferfv) return false;
			internal::glClearBufferfi = reinterpret_cast<void (*)(GLenum , GLint , GLfloat , GLint )>(internal::get_proc_address("glClearBufferfi"));
			if (!internal::glClearBufferfi) return false;
			internal::glGetStringi = reinterpret_cast<const GLubyte *(*)(GLenum , GLuint )>(internal::get_proc_address("glGetStringi"));
			if (!internal::glGetStringi) return false;
			internal::glIsRenderbuffer = reinterpret_cast<GLboolean (*)(GLuint )>(internal::get_proc_address("glIsRenderbuffer"));
			if (!internal::glIsRenderbuffer) return false;
			internal::glBindRenderbuffer = reinterpret_cast<void (*)(GLenum , GLuint )>(internal::get_proc_address("glBindRenderbuffer"));
			if (!internal::glBindRenderbuffer) return false;
			internal::glDeleteRenderbuffers = reinterpret_cast<void (*)(GLsizei , const GLuint *)>(internal::get_proc_address("glDeleteRenderbuffers"));
			if (!internal::glDeleteRenderbuffers) return false;
			internal::glGenRenderbuffers = reinterpret_cast<void (*)(GLsizei , GLuint *)>(internal::get_proc_address("glGenRenderbuffers"));
			if (!internal::glGenRenderbuffers) return false;
			internal::glRenderbufferStorage = reinterpret_cast<void (*)(GLenum , GLenum , GLsizei , GLsizei )>(internal::get_proc_address("glRenderbufferStorage"));
			if (!internal::glRenderbufferStorage) return false;
			internal::glGetRenderbufferParameteriv = reinterpret_cast<void (*)(GLenum , GLenum , GLint *)>(internal::get_proc_address("glGetRenderbufferParameteriv"));
			if (!internal::glGetRenderbufferParameteriv) return false;
			internal::glIsFramebuffer = reinterpret_cast<GLboolean (*)(GLuint )>(internal::get_proc_address("glIsFramebuffer"));
			if (!internal::glIsFramebuffer) return false;
			internal::glBindFramebuffer = reinterpret_cast<void (*)(GLenum , GLuint )>(internal::get_proc_address("glBindFramebuffer"));
			if (!internal::glBindFramebuffer) return false;
			internal::glDeleteFramebuffers = reinterpret_cast<void (*)(GLsizei , const GLuint *)>(internal::get_proc_address("glDeleteFramebuffers"));
			if (!internal::glDeleteFramebuffers) return false;
			internal::glGenFramebuffers = reinterpret_cast<void (*)(GLsizei , GLuint *)>(internal::get_proc_address("glGenFramebuffers"));
			if (!internal::glGenFramebuffers) return false;
			internal::glCheckFramebufferStatus = reinterpret_cast<GLenum (*)(GLenum )>(internal::get_proc_address("glCheckFramebufferStatus"));
			if (!internal::glCheckFramebufferStatus) return false;
			internal::glFramebufferTexture1D = reinterpret_cast<void (*)(GLenum , GLenum , GLenum , GLuint , GLint )>(internal::get_proc_address("glFramebufferTexture1D"));
			if (!internal::glFramebufferTexture1D) return false;
			internal::glFramebufferTexture2D = reinterpret_cast<void (*)(GLenum , GLenum , GLenum , GLuint , GLint )>(internal::get_proc_address("glFramebufferTexture2D"));
			if (!internal::glFramebufferTexture2D) return false;
			internal::glFramebufferTexture3D = reinterpret_cast<void (*)(GLenum , GLenum , GLenum , GLuint , GLint , GLint )>(internal::get_proc_address("glFramebufferTexture3D"));
			if (!internal::glFramebufferTexture3D) return false;
			internal::glFramebufferRenderbuffer = reinterpret_cast<void (*)(GLenum , GLenum , GLenum , GLuint )>(internal::get_proc_address("glFramebufferRenderbuffer"));
			if (!internal::glFramebufferRenderbuffer) return false;
			internal::glGetFramebufferAttachmentParameteriv = reinterpret_cast<void (*)(GLenum , GLenum , GLenum , GLint *)>(internal::get_proc_address("glGetFramebufferAttachmentParameteriv"));
			if (!internal::glGetFramebufferAttachmentParameteriv) return false;
			internal::glGenerateMipmap = reinterpret_cast<void (*)(GLenum )>(internal::get_proc_address("glGenerateMipmap"));
			if (!internal::glGenerateMipmap) return false;
			internal::glBlitFramebuffer = reinterpret_cast<void (*)(GLint , GLint , GLint , GLint , GLint , GLint , GLint , GLint , GLbitfield , GLenum )>(internal::get_proc_address("glBlitFramebuffer"));
			if (!internal::glBlitFramebuffer) return false;
			internal::glRenderbufferStorageMultisample = reinterpret_cast<void (*)(GLenum , GLsizei , GLenum , GLsizei , GLsizei )>(internal::get_proc_address("glRenderbufferStorageMultisample"));
			if (!internal::glRenderbufferStorageMultisample) return false;
			internal::glFramebufferTextureLayer = reinterpret_cast<void (*)(GLenum , GLenum , GLuint , GLint , GLint )>(internal::get_proc_address("glFramebufferTextureLayer"));
			if (!internal::glFramebufferTextureLayer) return false;
			internal::glMapBufferRange = reinterpret_cast<void *(*)(GLenum , GLintptr , GLsizeiptr , GLbitfield )>(internal::get_proc_address("glMapBufferRange"));
			if (!internal::glMapBufferRange) return false;
			internal::glFlushMappedBufferRange = reinterpret_cast<void (*)(GLenum , GLintptr , GLsizeiptr )>(internal::get_proc_address("glFlushMappedBufferRange"));
			if (!internal::glFlushMappedBufferRange) return false;
			internal::glBindVertexArray = reinterpret_cast<void (*)(GLuint )>(internal::get_proc_address("glBindVertexArray"));
			if (!internal::glBindVertexArray) return false;
			internal::glDeleteVertexArrays = reinterpret_cast<void (*)(GLsizei , const GLuint *)>(internal::get_proc_address("glDeleteVertexArrays"));
			if (!internal::glDeleteVertexArrays) return false;
			internal::glGenVertexArrays = reinterpret_cast<void (*)(GLsizei , GLuint *)>(internal::get_proc_address("glGenVertexArrays"));
			if (!internal::glGenVertexArrays) return false;
			internal::glIsVertexArray = reinterpret_cast<GLboolean (*)(GLuint )>(internal::get_proc_address("glIsVertexArray"));
			if (!internal::glIsVertexArray) return false;

			// OpenGL 3.1

			internal::glDrawArraysInstanced = reinterpret_cast<void (*)(GLenum , GLint , GLsizei , GLsizei )>(internal::get_proc_address("glDrawArraysInstanced"));
			if (!internal::glDrawArraysInstanced) return false;
			internal::glDrawElementsInstanced = reinterpret_cast<void (*)(GLenum , GLsizei , GLenum , const void *, GLsizei )>(internal::get_proc_address("glDrawElementsInstanced"));
			if (!internal::glDrawElementsInstanced) return false;
			internal::glTexBuffer = reinterpret_cast<void (*)(GLenum , GLenum , GLuint )>(internal::get_proc_address("glTexBuffer"));
			if (!internal::glTexBuffer) return false;
			internal::glPrimitiveRestartIndex = reinterpret_cast<void (*)(GLuint )>(internal::get_proc_address("glPrimitiveRestartIndex"));
			if (!internal::glPrimitiveRestartIndex) return false;
			internal::glCopyBufferSubData = reinterpret_cast<void (*)(GLenum , GLenum , GLintptr , GLintptr , GLsizeiptr )>(internal::get_proc_address("glCopyBufferSubData"));
			if (!internal::glCopyBufferSubData) return false;
			internal::glGetUniformIndices = reinterpret_cast<void (*)(GLuint , GLsizei , const GLchar *const*, GLuint *)>(internal::get_proc_address("glGetUniformIndices"));
			if (!internal::glGetUniformIndices) return false;
			internal::glGetActiveUniformsiv = reinterpret_cast<void (*)(GLuint , GLsizei , const GLuint *, GLenum , GLint *)>(internal::get_proc_address("glGetActiveUniformsiv"));
			if (!internal::glGetActiveUniformsiv) return false;
			internal::glGetActiveUniformName = reinterpret_cast<void (*)(GLuint , GLuint , GLsizei , GLsizei *, GLchar *)>(internal::get_proc_address("glGetActiveUniformName"));
			if (!internal::glGetActiveUniformName) return false;
			internal::glGetUniformBlockIndex = reinterpret_cast<GLuint (*)(GLuint , const GLchar *)>(internal::get_proc_address("glGetUniformBlockIndex"));
			if (!internal::glGetUniformBlockIndex) return false;
			internal::glGetActiveUniformBlockiv = reinterpret_cast<void (*)(GLuint , GLuint , GLenum , GLint *)>(internal::get_proc_address("glGetActiveUniformBlockiv"));
			if (!internal::glGetActiveUniformBlockiv) return false;
			internal::glGetActiveUniformBlockName = reinterpret_cast<void (*)(GLuint , GLuint , GLsizei , GLsizei *, GLchar *)>(internal::get_proc_address("glGetActiveUniformBlockName"));
			if (!internal::glGetActiveUniformBlockName) return false;
			internal::glUniformBlockBinding = reinterpret_cast<void (*)(GLuint , GLuint , GLuint )>(internal::get_proc_address("glUniformBlockBinding"));
			if (!internal::glUniformBlockBinding) return false;

			// OpenGL 3.2

			internal::glDrawElementsBaseVertex = reinterpret_cast<void (*)(GLenum , GLsizei , GLenum , const void *, GLint )>(internal::get_proc_address("glDrawElementsBaseVertex"));
			if (!internal::glDrawElementsBaseVertex) return false;
			internal::glDrawRangeElementsBaseVertex = reinterpret_cast<void (*)(GLenum , GLuint , GLuint , GLsizei , GLenum , const void *, GLint )>(internal::get_proc_address("glDrawRangeElementsBaseVertex"));
			if (!internal::glDrawRangeElementsBaseVertex) return false;
			internal::glDrawElementsInstancedBaseVertex = reinterpret_cast<void (*)(GLenum , GLsizei , GLenum , const void *, GLsizei , GLint )>(internal::get_proc_address("glDrawElementsInstancedBaseVertex"));
			if (!internal::glDrawElementsInstancedBaseVertex) return false;
			internal::glMultiDrawElementsBaseVertex = reinterpret_cast<void (*)(GLenum , const GLsizei *, GLenum , const void *const*, GLsizei , const GLint *)>(internal::get_proc_address("glMultiDrawElementsBaseVertex"));
			if (!internal::glMultiDrawElementsBaseVertex) return false;
			internal::glProvokingVertex = reinterpret_cast<void (*)(GLenum )>(internal::get_proc_address("glProvokingVertex"));
			if (!internal::glProvokingVertex) return false;
			internal::glFenceSync = reinterpret_cast<GLsync (*)(GLenum , GLbitfield )>(internal::get_proc_address("glFenceSync"));
			if (!internal::glFenceSync) return false;
			internal::glIsSync = reinterpret_cast<GLboolean (*)(GLsync )>(internal::get_proc_address("glIsSync"));
			if (!internal::glIsSync) return false;
			internal::glDeleteSync = reinterpret_cast<void (*)(GLsync )>(internal::get_proc_address("glDeleteSync"));
			if (!internal::glDeleteSync) return false;
			internal::glClientWaitSync = reinterpret_cast<GLenum (*)(GLsync , GLbitfield , GLuint64 )>(internal::get_proc_address("glClientWaitSync"));
			if (!internal::glClientWaitSync) return false;
			internal::glWaitSync = reinterpret_cast<void (*)(GLsync , GLbitfield , GLuint64 )>(internal::get_proc_address("glWaitSync"));
			if (!internal::glWaitSync) return false;
			internal::glGetInteger64v = reinterpret_cast<void (*)(GLenum , GLint64 *)>(internal::get_proc_address("glGetInteger64v"));
			if (!internal::glGetInteger64v) return false;
			internal::glGetSynciv = reinterpret_cast<void (*)(GLsync , GLenum , GLsizei , GLsizei *, GLint *)>(internal::get_proc_address("glGetSynciv"));
			if (!internal::glGetSynciv) return false;
			internal::glGetInteger64i_v = reinterpret_cast<void (*)(GLenum , GLuint , GLint64 *)>(internal::get_proc_address("glGetInteger64i_v"));
			if (!internal::glGetInteger64i_v) return false;
			internal::glGetBufferParameteri64v = reinterpret_cast<void (*)(GLenum , GLenum , GLint64 *)>(internal::get_proc_address("glGetBufferParameteri64v"));
			if (!internal::glGetBufferParameteri64v) return false;
			internal::glFramebufferTexture = reinterpret_cast<void (*)(GLenum , GLenum , GLuint , GLint )>(internal::get_proc_address("glFramebufferTexture"));
			if (!internal::glFramebufferTexture) return false;
			internal::glTexImage2DMultisample = reinterpret_cast<void (*)(GLenum , GLsizei , GLenum , GLsizei , GLsizei , GLboolean )>(internal::get_proc_address("glTexImage2DMultisample"));
			if (!internal::glTexImage2DMultisample) return false;
			internal::glTexImage3DMultisample = reinterpret_cast<void (*)(GLenum , GLsizei , GLenum , GLsizei , GLsizei , GLsizei , GLboolean )>(internal::get_proc_address("glTexImage3DMultisample"));
			if (!internal::glTexImage3DMultisample) return false;
			internal::glGetMultisamplefv = reinterpret_cast<void (*)(GLenum , GLuint , GLfloat *)>(internal::get_proc_address("glGetMultisamplefv"));
			if (!internal::glGetMultisamplefv) return false;
			internal::glSampleMaski = reinterpret_cast<void (*)(GLuint , GLbitfield )>(internal::get_proc_address("glSampleMaski"));
			if (!internal::glSampleMaski) return false;

			// OpenGL 3.3

			internal::glBindFragDataLocationIndexed = reinterpret_cast<void (*)(GLuint , GLuint , GLuint , const GLchar *)>(internal::get_proc_address("glBindFragDataLocationIndexed"));
			if (!internal::glBindFragDataLocationIndexed) return false;
			internal::glGetFragDataIndex = reinterpret_cast<GLint (*)(GLuint , const GLchar *)>(internal::get_proc_address("glGetFragDataIndex"));
			if (!internal::glGetFragDataIndex) return false;
			internal::glGenSamplers = reinterpret_cast<void (*)(GLsizei , GLuint *)>(internal::get_proc_address("glGenSamplers"));
			if (!internal::glGenSamplers) return false;
			internal::glDeleteSamplers = reinterpret_cast<void (*)(GLsizei , const GLuint *)>(internal::get_proc_address("glDeleteSamplers"));
			if (!internal::glDeleteSamplers) return false;
			internal::glIsSampler = reinterpret_cast<GLboolean (*)(GLuint )>(internal::get_proc_address("glIsSampler"));
			if (!internal::glIsSampler) return false;
			internal::glBindSampler = reinterpret_cast<void (*)(GLuint , GLuint )>(internal::get_proc_address("glBindSampler"));
			if (!internal::glBindSampler) return false;
			internal::glSamplerParameteri = reinterpret_cast<void (*)(GLuint , GLenum , GLint )>(internal::get_proc_address("glSamplerParameteri"));
			if (!internal::glSamplerParameteri) return false;
			internal::glSamplerParameteriv = reinterpret_cast<void (*)(GLuint , GLenum , const GLint *)>(internal::get_proc_address("glSamplerParameteriv"));
			if (!internal::glSamplerParameteriv) return false;
			internal::glSamplerParameterf = reinterpret_cast<void (*)(GLuint , GLenum , GLfloat )>(internal::get_proc_address("glSamplerParameterf"));
			if (!internal::glSamplerParameterf) return false;
			internal::glSamplerParameterfv = reinterpret_cast<void (*)(GLuint , GLenum , const GLfloat *)>(internal::get_proc_address("glSamplerParameterfv"));
			if (!internal::glSamplerParameterfv) return false;
			internal::glSamplerParameterIiv = reinterpret_cast<void (*)(GLuint , GLenum , const GLint *)>(internal::get_proc_address("glSamplerParameterIiv"));
			if (!internal::glSamplerParameterIiv) return false;
			internal::glSamplerParameterIuiv = reinterpret_cast<void (*)(GLuint , GLenum , const GLuint *)>(internal::get_proc_address("glSamplerParameterIuiv"));
			if (!internal::glSamplerParameterIuiv) return false;
			internal::glGetSamplerParameteriv = reinterpret_cast<void (*)(GLuint , GLenum , GLint *)>(internal::get_proc_address("glGetSamplerParameteriv"));
			if (!internal::glGetSamplerParameteriv) return false;
			internal::glGetSamplerParameterIiv = reinterpret_cast<void (*)(GLuint , GLenum , GLint *)>(internal::get_proc_address("glGetSamplerParameterIiv"));
			if (!internal::glGetSamplerParameterIiv) return false;
			internal::glGetSamplerParameterfv = reinterpret_cast<void (*)(GLuint , GLenum , GLfloat *)>(internal::get_proc_address("glGetSamplerParameterfv"));
			if (!internal::glGetSamplerParameterfv) return false;
			internal::glGetSamplerParameterIuiv = reinterpret_cast<void (*)(GLuint , GLenum , GLuint *)>(internal::get_proc_address("glGetSamplerParameterIuiv"));
			if (!internal::glGetSamplerParameterIuiv) return false;
			internal::glQueryCounter = reinterpret_cast<void (*)(GLuint , GLenum )>(internal::get_proc_address("glQueryCounter"));
			if (!internal::glQueryCounter) return false;
			internal::glGetQueryObjecti64v = reinterpret_cast<void (*)(GLuint , GLenum , GLint64 *)>(internal::get_proc_address("glGetQueryObjecti64v"));
			if (!internal::glGetQueryObjecti64v) return false;
			internal::glGetQueryObjectui64v = reinterpret_cast<void (*)(GLuint , GLenum , GLuint64 *)>(internal::get_proc_address("glGetQueryObjectui64v"));
			if (!internal::glGetQueryObjectui64v) return false;
			internal::glVertexAttribDivisor = reinterpret_cast<void (*)(GLuint , GLuint )>(internal::get_proc_address("glVertexAttribDivisor"));
			if (!internal::glVertexAttribDivisor) return false;
			internal::glVertexAttribP1ui = reinterpret_cast<void (*)(GLuint , GLenum , GLboolean , GLuint )>(internal::get_proc_address("glVertexAttribP1ui"));
			if (!internal::glVertexAttribP1ui) return false;
			internal::glVertexAttribP1uiv = reinterpret_cast<void (*)(GLuint , GLenum , GLboolean , const GLuint *)>(internal::get_proc_address("glVertexAttribP1uiv"));
			if (!internal::glVertexAttribP1uiv) return false;
			internal::glVertexAttribP2ui = reinterpret_cast<void (*)(GLuint , GLenum , GLboolean , GLuint )>(internal::get_proc_address("glVertexAttribP2ui"));
			if (!internal::glVertexAttribP2ui) return false;
			internal::glVertexAttribP2uiv = reinterpret_cast<void (*)(GLuint , GLenum , GLboolean , const GLuint *)>(internal::get_proc_address("glVertexAttribP2uiv"));
			if (!internal::glVertexAttribP2uiv) return false;
			internal::glVertexAttribP3ui = reinterpret_cast<void (*)(GLuint , GLenum , GLboolean , GLuint )>(internal::get_proc_address("glVertexAttribP3ui"));
			if (!internal::glVertexAttribP3ui) return false;
			internal::glVertexAttribP3uiv = reinterpret_cast<void (*)(GLuint , GLenum , GLboolean , const GLuint *)>(internal::get_proc_address("glVertexAttribP3uiv"));
			if (!internal::glVertexAttribP3uiv) return false;
			internal::glVertexAttribP4ui = reinterpret_cast<void (*)(GLuint , GLenum , GLboolean , GLuint )>(internal::get_proc_address("glVertexAttribP4ui"));
			if (!internal::glVertexAttribP4ui) return false;
			internal::glVertexAttribP4uiv = reinterpret_cast<void (*)(GLuint , GLenum , GLboolean , const GLuint *)>(internal::get_proc_address("glVertexAttribP4uiv"));
			if (!internal::glVertexAttribP4uiv) return false;

			return true;
		}

		static bool load_ext_GL_ARB_compute_shader()
		{
			internal::glDispatchCompute = reinterpret_cast<void (*)(GLuint , GLuint , GLuint )>(internal::get_proc_address("glDispatchCompute"));
			if (!internal::glDispatchCompute) return false;
			internal::glDispatchComputeIndirect = reinterpret_cast<void (*)(GLintptr )>(internal::get_proc_address("glDispatchComputeIndirect"));
			if (!internal::glDispatchComputeIndirect) return false;

			return true;
		}

		static bool load_ext_GL_ARB_texture_filter_anisotropic()
		{

			return true;
		}

		static std::unordered_set<std::string> extensions;
		bool initialize()
		{
			if (!load_core()) return false;

			GLint num_extensions;
			internal::glGetIntegerv(0x821D, &num_extensions);
			for (GLint i = 0; i < num_extensions; ++i)
				extensions.insert(reinterpret_cast<const char *>(internal::glGetStringi(0x1F03, i)));

			if (extensions.count("GL_ARB_compute_shader") > 0)
				ext_GL_ARB_compute_shader_loaded = load_ext_GL_ARB_compute_shader();
			if (extensions.count("GL_ARB_texture_filter_anisotropic") > 0)
				ext_GL_ARB_texture_filter_anisotropic_loaded = load_ext_GL_ARB_texture_filter_anisotropic();

			return true;
		}

		const char * api(){ return "OpenGL"; }

		int major_version(){ return 3; }

		int minor_version(){ return 3; }

		bool has_extension(const char * name){ return extensions.contains(name); }

		bool ext_ARB_compute_shader(){ return ext_GL_ARB_compute_shader_loaded; }
		bool ext_ARB_texture_filter_anisotropic(){ return ext_GL_ARB_texture_filter_anisotropic_loaded; }

	} // namespace sys

} // namespace gl

