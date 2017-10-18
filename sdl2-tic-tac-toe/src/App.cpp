#include <iostream>
#include "App.h"

// initialize static members
SDL_Window* App::s_window{ nullptr };
SDL_Renderer* App::s_renderer{ nullptr };
SDL_Texture* App::s_draw{ nullptr };
SDL_Texture* App::s_cross{ nullptr };
SDL_Texture* App::s_circle{ nullptr };

App::App()
{
	if (init_SDL() && init_TTF())
	{
		running = true;
		this->run();
	}
}

App::~App()
{
	this->close_SDL();
	this->close_TTF();

	SDL_Quit();
	TTF_Quit();
}

SDL_Texture* App::get_texture(TEXTURE texture)
{
	switch (texture)
	{
	case(TEXTURE::TEXTURE_DRAW):
		return s_draw;
		break;
	case(TEXTURE::TEXTURE_CROSS):
		return s_cross;
		break;
	case(TEXTURE::TEXTURE_CIRCLE):
		return s_circle;
		break;
	default:
		break;
	}
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

bool App::init_TTF()
{
	if (TTF_Init() < 0)
	{
		std::cerr << "TTF_Init error: " << TTF_GetError() << std::endl;
		return false;
	}

	font = TTF_OpenFont("font/PT_Serif-Web-Regular.ttf", 52);
	if (!font)
	{
		std::cerr << "TTF_OpenFont error: " << TTF_GetError() << std::endl;
		return false;
	}

	draw_surface = TTF_RenderText_Blended(font, "Draw", SDL_Color{ 0, 0, 0 });
	cross_surface = TTF_RenderText_Blended(font, "X Wins!", SDL_Color{ 0, 0, 0 });
	circle_surface = TTF_RenderText_Blended(font, "O Wins!", SDL_Color{ 0, 0, 0 });
	if (!draw_surface || !cross_surface || !circle_surface)
	{
		std::cerr << "TTF_RenderText_Solid error: " << TTF_GetError() << std::endl;
		return false;
	}

	s_draw = SDL_CreateTextureFromSurface(App::get_renderer(), draw_surface);
	s_cross = SDL_CreateTextureFromSurface(App::get_renderer(), cross_surface);
	s_circle = SDL_CreateTextureFromSurface(App::get_renderer(), circle_surface);
	if (!s_draw || !s_cross || !s_circle)
	{
		std::cerr << "SDL_CreateTextureFromSurface error: " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}

void App::close_SDL()
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
}

void App::close_TTF()
{
	if (font != nullptr)
	{
		TTF_CloseFont(font);
		font = nullptr;
	}

	// TODO: seriously fix this
	// this is legit disgusting
	if (draw_surface != nullptr)
	{
		SDL_FreeSurface(draw_surface);
		draw_surface = nullptr;
	}

	if (cross_surface != nullptr)
	{
		SDL_FreeSurface(cross_surface);
		cross_surface = nullptr;
	}

	if (circle_surface != nullptr)
	{
		SDL_FreeSurface(circle_surface);
		circle_surface = nullptr;
	}

	if (s_draw != nullptr)
	{
		SDL_DestroyTexture(s_draw);
		s_draw = nullptr;
	}

	if (s_cross != nullptr)
	{
		SDL_DestroyTexture(s_cross);
		s_cross = nullptr;
	}

	if (s_circle != nullptr)
	{
		SDL_DestroyTexture(s_circle);
		s_circle = nullptr;
	}
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
