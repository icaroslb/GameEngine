#include "Sdl3App.h"
#include "OpenGLApp.h"

#include <iostream>

namespace sge {
	Sdl3App::Sdl3App(Uint32 flags, int major_version, int minor_version)
		: _window(nullptr)
		, _context() {
		
		if (!SDL_Init(flags)) {
			const char* error = SDL_GetError();
			std::cerr << "Error SDL_Init: " << error << std::endl;
		}

		// Activates accelerated visual
		if (!SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1)) {
			const char* error = SDL_GetError();
			std::cerr << "Warning SDL_GL_ACCELERATED_VISUAL: " << error << std::endl;
		}

		// Major and Minor version
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major_version);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor_version);

		// Activates double buffer
		if (!SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1)) {
			const char* error = SDL_GetError();
			std::cerr << "Warning SDL_GL_DOUBLEBUFFER: " << error << std::endl;
		}
	}

	Sdl3App::~Sdl3App() {
		if (_window) {
			SDL_GL_DestroyContext(_context);
			SDL_DestroyWindow(_window);
		}

		SDL_Quit();
	}

	void Sdl3App::CreateWindow(const std::string& name, int width, int height, Uint32 flags) {
		_window = SDL_CreateWindow(name.data(), width, height, flags);
		_context = SDL_GL_CreateContext(_window);

		if (!_window) {
			const char* error = SDL_GetError();
			std::cerr << "Warning SDL_CreateWindow: " << error << std::endl;
		}

		if (!_context) {
			const char* error = SDL_GetError();
			std::cerr << "Warning SDL_GL_CreateContext: " << error << std::endl;
		}

		SDL_GL_SetSwapInterval(1);

		OpenGLApp::init((ProcAddress)SDL_GL_GetProcAddress);
	}

	void Sdl3App::SwapWindow() {
		if (!SDL_GL_SwapWindow(_window)) {
			const char* error = SDL_GetError();
			std::cerr << "Warning SDL_GL_SwapWindow: " << error << std::endl;
		}
	}
};