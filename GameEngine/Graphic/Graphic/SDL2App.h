#ifndef GRAPHIC_SDL2_APP_H
#define GRAPHIC_SDL2_APP_H

#include <string>
#include <memory>
#include <SDL2/SDL.h>

namespace geb {

	class Sdl2App {
	public:
		Sdl2App(Uint32 flags, int major_version, int minor_version);
		~Sdl2App();

		Sdl2App(const Sdl2App&) = delete;
		Sdl2App& operator=(const Sdl2App&) = delete;

		/**
		* CreateWindow
		* Create a SDL Window
		* @param name: Window name
		* @param x: Window X position
		* @param y: Window Y position
		* @param width: Window width
		* @param height: Window height
		* @param flags: Window flags
		*/
		void CreateWindow(const std::string& name, int x, int y, int width, int height, Uint32 flags);

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
