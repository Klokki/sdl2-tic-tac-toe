#pragma once
#include "SDL.h"
#include "Game.h"

class App
{
public:
	// screen dimension constants
	static constexpr int SCREEN_WIDTH{ 600 }, SCREEN_HEIGHT{ 600 };

	App();
	~App();

	// getters
	static SDL_Window *get_window()		{ return s_window; }
	static SDL_Renderer *get_renderer() { return s_renderer; }

private:
	bool init_SDL();
	// contains main game loop
	void run();

	static SDL_Window *s_window;
	static SDL_Renderer *s_renderer;
	SDL_Event e;
};