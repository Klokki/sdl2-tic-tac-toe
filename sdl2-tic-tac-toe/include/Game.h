#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "Board.h"
#include "Texture.h"

class Game
{
public:
	Game();

	void update(SDL_Event *e);
	void render();

private:
	Board board;
	SDL_Rect message_rect;
	TEXTURE texture{ TEXTURE::TEXTURE_BLANK };
	bool is_cross{ true };
};