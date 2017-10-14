#include "Board.h"
#include "App.h"
#include "SDL.h"

Board::Board() :
	square_height(App::SCREEN_HEIGHT / 3),
	square_width(App::SCREEN_WIDTH / 3),
	filled_places(0)
{
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

bool Board::square_empty(int row, int col)
{
	return p[row][col] == PIECE::PIECE_CLEAR;
}

void Board::render_grid()
{
	// blue
	SDL_SetRenderDrawColor(App::get_renderer(), 0x00, 0x00, 0xFF, 0xFF);

	// horizontal lines
	SDL_RenderDrawLine(App::get_renderer(), 0, square_height, App::SCREEN_WIDTH, square_height);
	SDL_RenderDrawLine(App::get_renderer(), 0, square_height * 2, App::SCREEN_WIDTH, square_height * 2);
	// vertical lines
	SDL_RenderDrawLine(App::get_renderer(), square_width, 0, square_width, App::SCREEN_HEIGHT);
	SDL_RenderDrawLine(App::get_renderer(), square_width * 2, 0, square_width * 2, App::SCREEN_HEIGHT);
}

void Board::render_pieces()
{
	// red
	SDL_SetRenderDrawColor(App::get_renderer(), 0xFF, 0x00, 0x00, 0xFF);
	for (int i{ 0 }; i < 3; ++i)
	{
		for (int j{ 0 }; j < 3; ++j)
		{
			switch (p[i][j])
			{
			case(PIECE::PIECE_CROSS):
				draw_cross(i, j);
				break;
			case(PIECE::PIECE_CIRCLE):
				draw_circle(i, j);
				break;
			default:
				break;
			}
		}
	}
}

void Board::draw_cross(int row, int col)
{
	SDL_RenderDrawLine(App::get_renderer(), col * square_width, row * square_height, col * square_width + square_width, row * square_height + square_height);
	SDL_RenderDrawLine(App::get_renderer(), col * square_width, row * square_height + square_height, col * square_width + square_width, row * square_height);
}

void Board::draw_circle(int row, int col)
{
	
}
