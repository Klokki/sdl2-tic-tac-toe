#pragma once
#include "SDL.h"
#include "Board.h"

class Game
{
public:
	Game();
	~Game();

	void update(SDL_Event *e);
	void render();

private:
	Board board;
};