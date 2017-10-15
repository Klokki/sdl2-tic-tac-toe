#include <iostream>
#include "App.h"

// initialize static members
SDL_Window* App::s_window{ nullptr };
SDL_Renderer* App::s_renderer{ nullptr };

App::App()
{
	if (init_SDL())
	{
		running = true;
		this->run();
	}
	else
		SDL_Quit();
}

App::~App()
{
	if (s_renderer != nullptr)
	{
		SDL_DestroyRenderer(s_renderer);
		s_renderer = nullptr;
	}

	if (s_window != nullptr)
	{
		SDL_DestroyWindow(s_window);
		s_window = nullptr;
	}

	SDL_Quit();
}

bool App::init_SDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "SDL_Init error: " << SDL_GetError() << std::endl;
		return false;
	}

	s_window = SDL_CreateWindow("Tic Tac Toe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!s_window)
	{
		std::cerr << "SDL_CreateWindow error: " << SDL_GetError() << std::endl;
		return false;
	}

	s_renderer = SDL_CreateRenderer(s_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!s_renderer)
	{
		std::cerr << "SDL_CreateRenderer error: " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}

void App::run()
{
	Game game;

	// game loop
	while (running)
	{
		this->handle_quit();
		game.update(&e);
		game.render();
	}
}

void App::handle_quit()
{
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			running = false;

		// Q quits the game
		if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
			case(SDLK_q):
				running = false;
				break;
			default:
				break;
			}
		}
	}
}
