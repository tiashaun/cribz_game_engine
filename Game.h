#ifndef _GAME_H_
#define _GAME_H_
#include "SDL/SDL.h"
#include "Player.h"

class Game
{
	public:
		Game(){}
		~Game(){}
		void Init(bool fullscreen);
		void HandleEvent(Game* game);
		void Draw();
		void Update();
		void Clean();
		SDL_Surface* GetScreen(){return screen;}
		void Quit(){isRunning = false;}
		bool Running(){return isRunning;}

	private:
		int PlayerX;
		int PlayerY;
		int PlayerX_level;
		int PlayerY_level;
		int PlayerHealth;
		int PlayerLifes;
		bool isRunning;
		bool isFullscreen;
		SDL_Surface* screen;
		SDL_Surface* playerSprite;
		SDL_Surface* background;
		Player* player;
};

#endif