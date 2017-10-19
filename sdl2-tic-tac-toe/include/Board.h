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

	void render();
	void place_piece(int row, int col, PIECE piece);
	void reset();

	inline bool is_draw(){ return filled_squares == 9 && !is_won(); }
	bool is_won();
	
	inline bool square_empty(int row, int col) const { return p[row][col] == PIECE::PIECE_CLEAR; }

private:
	PIECE p[3][3];
	int filled_squares;
	int square_width;
	int square_height;

	void render_grid() const;
	void render_pieces() const;
	void draw_cross(int row, int col) const;
	void draw_circle(int row, int col) const;
};

