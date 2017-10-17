#include <cmath>
#include "SDL.h"
#include "Board.h"
#include "App.h"

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

void Board::render_grid() const
{
	// blue
	SDL_SetRenderDrawColor(App::get_renderer(), 0, 0, 255, 255);

	// horizontal lines
	SDL_RenderDrawLine(App::get_renderer(), 0, square_height, App::SCREEN_WIDTH, square_height);
	SDL_RenderDrawLine(App::get_renderer(), 0, square_height * 2, App::SCREEN_WIDTH, square_height * 2);
	// vertical lines
	SDL_RenderDrawLine(App::get_renderer(), square_width, 0, square_width, App::SCREEN_HEIGHT);
	SDL_RenderDrawLine(App::get_renderer(), square_width * 2, 0, square_width * 2, App::SCREEN_HEIGHT);
}

void Board::render_pieces() const
{
	// red
	SDL_SetRenderDrawColor(App::get_renderer(), 255, 0, 0, 255);
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

void Board::draw_cross(int row, int col) const
{
	SDL_RenderDrawLine(App::get_renderer(), col * square_width, row * square_height, col * square_width + square_width, row * square_height + square_height);
	SDL_RenderDrawLine(App::get_renderer(), col * square_width, row * square_height + square_height, col * square_width + square_width, row * square_height);
}

void Board::draw_circle(int row, int col) const
{
	const int center_x{ col * square_width + (square_width / 2) },
		center_y{ row * square_height + (square_height / 2) },
		radius{ square_width / 2 };

	int end_x{ center_x + radius },
		end_y{ center_y };

	for (double angle{ 0 }; angle < 2 * M_PI; angle += 2 * M_PI / 60)
	{
		const int start_x{ end_x }, start_y{ end_y };
		end_x = radius * cos(angle) + center_x;
		end_y = radius * sin(angle) + center_y;

		SDL_RenderDrawLine(App::get_renderer(), start_x, start_y, end_x, end_y);
	}
}
