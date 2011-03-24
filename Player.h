#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

class Player
{
	public:
		Player(void);
		~Player(void);
		SDL_Surface* LoadSprite(char* filename);
		bool Draw(SDL_Surface* dest, SDL_Surface* src, int x, int y);
};

#endif;

