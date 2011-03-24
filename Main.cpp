#include "Game.h"

int main(int argc, char* argv[]) 
{
	Game game;

	game.Init(false);

	while(game.Running())
	{
		game.HandleEvent(&game);
		game.Update();
		SDL_FillRect(game.GetScreen(), NULL, 0x000000);
		game.Draw();
	}
	
	game.Clean();
	return 0;
}