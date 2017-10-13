#include "Board.h"
#include "App.h"
#include "SDL.h"

Board::Board()
{
	filled_places = 0;
	// set all grid squares to empty
	for (int i{ 0 }; i < 3; ++i)
	{
		for (int j{ 0 }; j < 3; ++j)
			p[i][j] = PIECE::PIECE_CLEAR;
	}
}

Board::~Board()
{
}

void Board::render()
{
	this->render_grid();
	this->render_pieces();
}

void Board::place_piece(int row, int col, PIECE piece)
{
	if (filled_places < 9)
	{
		++filled_places;
		p[row][col] = piece;
	}
}

void Board::render_grid()
{
	// blue
	SDL_SetRenderDrawColor(App::get_renderer(), 0x00, 0x00, 0xFF, 0xFF);

	// horizontal lines
	SDL_RenderDrawLine(App::get_renderer(), 0, App::SCREEN_HEIGHT / 3, App::SCREEN_WIDTH, App::SCREEN_HEIGHT / 3);
	SDL_RenderDrawLine(App::get_renderer(), 0, App::SCREEN_HEIGHT / 3 * 2, App::SCREEN_WIDTH, App::SCREEN_HEIGHT / 3 * 2);
	// vertical lines
	SDL_RenderDrawLine(App::get_renderer(), App::SCREEN_WIDTH / 3, 0, App::SCREEN_WIDTH / 3, App::SCREEN_HEIGHT);
	SDL_RenderDrawLine(App::get_renderer(), App::SCREEN_WIDTH / 3 * 2, 0, App::SCREEN_WIDTH / 3 * 2, App::SCREEN_HEIGHT);
}

void Board::render_pieces()
{
}
