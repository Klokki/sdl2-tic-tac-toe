#pragma once
#include "SDL.h"

class Game
{
public:
	Game();
	~Game();

	void update(SDL_Event *e);
	void render();
};