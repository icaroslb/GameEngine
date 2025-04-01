#ifndef GRAPHIC_SDL3_APP_H
#define GRAPHIC_SDL3_APP_H

#include <string>
#include <memory>
#include <SDL3/SDL.h>

namespace sge {

	class Sdl3App {
	public:
		Sdl3App(Uint32 flags, int major_version, int minor_version);
		~Sdl3App();

		Sdl3App(const Sdl3App&) = delete;
		Sdl3App& operator=(const Sdl3App&) = delete;

		/**
		* CreateWindow
		* Create a SDL Window
		* @param name: Window name
		* @param width: Window width
		* @param height: Window height
		* @param flags: Window flags
		*/
		void CreateWindow(const std::string& name, int width, int height, Uint32 flags);

		/**
		* SwapWindow
		* Update the window render
		*/
		void SwapWindow();

	private:
		SDL_Window* _window;
		SDL_GLContext _context;
	};

};

#endif // GRAPHIC_SDL2_APP_H
