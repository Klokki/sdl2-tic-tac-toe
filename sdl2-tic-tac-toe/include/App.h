#pragma once
#include <string>
#include "SDL.h"
#include "Game.h"
#include "Texture.h"

class App
{
public:
	// screen dimension constants
	static constexpr int SCREEN_WIDTH{ 600 }, SCREEN_HEIGHT{ 600 };

	App();
	~App();

	// getters
	static inline SDL_Window *get_window()		{ return s_window; }
	static inline SDL_Renderer *get_renderer()	{ return s_renderer; }
	static SDL_Texture *get_texture(TEXTURE texture);

private:
	bool init_SDL();
	bool init_TTF();

	void close_SDL();
	void close_TTF();

	// contains main game loop
	void run();
	void handle_quit();

	bool running;

	static SDL_Window *s_window;
	static SDL_Renderer *s_renderer;

	TTF_Font* font;
	// TODO: replace this mess with some other solution
	// because this is just dumb and uses almost 100 MB of memory
	SDL_Surface* draw_surface{ nullptr };
	SDL_Surface* cross_surface{ nullptr };
	SDL_Surface* circle_surface{ nullptr };
	static SDL_Texture* s_draw;
	static SDL_Texture* s_cross;
	static SDL_Texture* s_circle;

	SDL_Event e;
	Game game;
};