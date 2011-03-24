#include "Player.h"
#include "Game.h"

Player::Player(void)
{
}


Player::~Player(void)
{
}


SDL_Surface* Player::LoadSprite(char* filename)
{
	SDL_Surface* temp = NULL;
	SDL_Surface* optimized = NULL;
	 
	if((temp = IMG_Load(filename)) != NULL)
	{
		optimized = SDL_DisplayFormatAlpha(temp);
		SDL_FreeSurface(temp);
		return optimized;
	}
}

bool Player::Draw(SDL_Surface* dest, SDL_Surface* src, int x, int y)
{
	if(dest == NULL || src == NULL)
	{
		return false;
	}
	
	SDL_Rect  destR;
	destR.x = x;
	destR.y = y;
	SDL_BlitSurface(src, NULL, dest, &destR);
	SDL_UpdateRect(src, 0,0,0,0);
	return true;
}