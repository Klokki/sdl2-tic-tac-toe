#include <iostream>
#include "Game.h"
#include "App.h"

void Game::update(SDL_Event *e)
{
	if (e->type == SDL_MOUSEBUTTONDOWN && board.is_playable())
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		const int row{ y / (App::SCREEN_HEIGHT / 3) }, col{ x / (App::SCREEN_WIDTH / 3) };

		if (board.square_empty(row, col))
		{
			if (is_cross)
				board.place_piece(row, col, Board::PIECE::PIECE_CROSS);
			else
				board.place_piece(row, col, Board::PIECE::PIECE_CIRCLE);

			is_cross = !is_cross;
		}
	}
	else if (board.is_draw())
		texture = TEXTURE::TEXTURE_DRAW;
	else if (!board.is_playable() && !is_cross)
		texture = TEXTURE::TEXTURE_CROSS;
	else if (!board.is_playable())
		texture = TEXTURE::TEXTURE_CIRCLE;
}

void Game::render()
{
	SDL_SetRenderDrawColor(App::get_renderer(), 255, 255, 255, 255);
	SDL_RenderClear(App::get_renderer());

	board.render();
	SDL_RenderCopy(App::get_renderer(), App::get_texture(texture), NULL, &App::get_rect());

	SDL_RenderPresent(App::get_renderer());
}