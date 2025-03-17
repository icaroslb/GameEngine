#include "SDL2App.h"
#include "OpenGLApp.h"

#include <iostream>

namespace geb {
	Sdl2App::Sdl2App(Uint32 flags, int major_version, int minor_version)
		: _window(nullptr)
		, _context() {
		int error_id = SDL_Init(flags);
		if (error_id) {
			const char* error = SDL_GetError();
			std::cerr << "Error SDL_Init: " << error_id << " - " << error << std::endl;
		}

		// Activates accelerated visual
		SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

		// Major and Minor version
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major_version);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor_version);

		// Activates double buffer
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	}

	Sdl2App::~Sdl2App() {
		if (_window) {
			SDL_DestroyWindow(_window);
		}

		SDL_Quit();
	}

	void Sdl2App::CreateWindow(const std::string& name, int x, int y, int width, int height, Uint32 flags) {
		_window = SDL_CreateWindow(name.data(), x, y, width, height, flags);
		_context = SDL_GL_CreateContext(_window);

		SDL_GL_SetSwapInterval(1);

		OpenGLApp::init(SDL_GL_GetProcAddress);
	}

	void Sdl2App::SwapWindow() {
		SDL_GL_SwapWindow(_window);
	}
};