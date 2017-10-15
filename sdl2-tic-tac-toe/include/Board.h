#pragma once

class Board
{
public:
	enum class PIECE
	{
		PIECE_CLEAR,
		PIECE_CROSS,
		PIECE_CIRCLE
	};

	Board();
	~Board();

	void render();
	void place_piece(int row, int col, PIECE piece);
	
	bool square_empty(int row, int col);

private:
	PIECE p[3][3];
	int filled_places;
	int square_width;
	int square_height;

	void render_grid() const;
	void render_pieces() const;
	void draw_cross(int row, int col) const;
	void draw_circle(int row, int col) const;
};

