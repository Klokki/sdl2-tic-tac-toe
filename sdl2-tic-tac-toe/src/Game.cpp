#include "Game.h"
#include "App.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::update(SDL_Event *e)
{
}

void Game::render()
{
	SDL_SetRenderDrawColor(App::get_renderer(), 255, 255, 255, 255);
	SDL_RenderClear(App::get_renderer());

	board.render();

	SDL_RenderPresent(App::get_renderer());
}