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

private:
	PIECE p[3][3];
	int filled_places;

	void render_grid();
	void render_pieces();
};

