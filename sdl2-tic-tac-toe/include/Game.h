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
	TEXTURE texture;

	// whether the cross (X) is playing or not
	bool is_cross{ true };
	// whether text should be drawn or not
	bool render_text{ false };
};