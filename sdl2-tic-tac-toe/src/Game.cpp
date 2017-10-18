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
	if (e->type == SDL_MOUSEBUTTONDOWN && board.is_playable())
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		const int row{ y / (App::SCREEN_HEIGHT / 3) }, col{ x / (App::SCREEN_WIDTH / 3) };

		if (board.square_empty(row, col))
		{
			if(is_cross)
				board.place_piece(row, col, Board::PIECE::PIECE_CROSS);
			else
				board.place_piece(row, col, Board::PIECE::PIECE_CIRCLE);

			is_cross = !is_cross;
		}
	}
}

void Game::render()
{
	SDL_SetRenderDrawColor(App::get_renderer(), 255, 255, 255, 255);
	SDL_RenderClear(App::get_renderer());

	board.render();

	SDL_RenderPresent(App::get_renderer());
}