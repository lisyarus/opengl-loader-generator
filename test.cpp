#include "gl.hpp"
#include <iostream>

#include <SDL2/SDL.h>

int main(int argc, char ** argv)
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, gl::sys::major_version());
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, gl::sys::minor_version());
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	auto window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL | SDL_WINDOW_MAXIMIZED | SDL_WINDOW_HIDDEN);

	auto gl_context = SDL_GL_CreateContext(window);

	if (!gl::sys::initialize())
	{
		std::cout << "Failed to load OpenGL functions\n";
		return 1;
	}

	int major, minor;
	gl::GetIntegerv(gl::MAJOR_VERSION, &major);
	gl::GetIntegerv(gl::MINOR_VERSION, &minor);

	std::cout << "Loaded OpenGL " << major << "." << minor << "\n";
	std::cout << "Vendor: " << (const char *)gl::GetString(gl::VENDOR) << "\n";
	std::cout << "Renderer: " << (const char *)gl::GetString(gl::RENDERER) << "\n";
	std::cout << "GL_ARB_compute_shader: " << gl::sys::ext_ARB_compute_shader() << "\n";
	std::cout << "GL_ARB_texture_filter_anisotropic: " << gl::sys::ext_ARB_texture_filter_anisotropic() << "\n";
}
