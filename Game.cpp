#include "Game.h"
#include "CribzDebug.h"

void Game::Init(bool fullscreen)
{
	PlayerX = 0;
	PlayerY = 0;
	PlayerX_level = 0;
	PlayerY_level = 0;
	PlayerHealth = 100;
	PlayerLifes = 3;

	int flags = 0;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_WM_SetCaption("Game Engine", "Game Engine");

	if(fullscreen)
	{
		flags = SDL_FULLSCREEN;
	}

	screen = SDL_SetVideoMode(650, 350, 32, SDL_DOUBLEBUF | flags);
	isFullscreen = fullscreen;
	isRunning = true;
	CribzDebug::PrintToConsole("Game Init Successful");
}


void Game::HandleEvent(Game* game)
{
	SDL_Event event;

	if(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT:
				game->Quit();
			break;

			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						game->Quit();
					break;

					case SDLK_LEFT:
                        PlayerX_level = -3;
						//PlayerX -= 3;
						CribzDebug::PrintToConsole("Moving Left");
						CribzDebug::PrintToConsole("X is now: ", PlayerX);
                    break;

                    case SDLK_RIGHT:
						PlayerX_level = 3;
                        //PlayerX += 3;
						CribzDebug::PrintToConsole("Moving Right");
						CribzDebug::PrintToConsole("X is now: ", PlayerX);
                    break;

                    case SDLK_UP:
                        PlayerY_level = -3;
						//PlayerY -= 3;
						CribzDebug::PrintToConsole("Moving Up");
						CribzDebug::PrintToConsole("Y is now: ", PlayerY);
                    break;

                    case SDLK_DOWN:
						PlayerY_level = 3;
                        //PlayerY +=  3;
						CribzDebug::PrintToConsole("Moving Down");
						CribzDebug::PrintToConsole("Y is now: ", PlayerY);
                    break;

					default:
					break;
				}
			break;

			case SDL_KEYUP:
                switch( event.key.keysym.sym )
				{
                    case SDLK_LEFT:
                        if(PlayerX_level < 0)
                            PlayerX_level = 0;
                    break;

                    case SDLK_RIGHT:
                        if(PlayerX_level > 0)
                            PlayerX_level = 0;
                    break;

                    case SDLK_UP:
                        if(PlayerY_level < 0)
                            PlayerY_level = 0;
                    break;

                    case SDLK_DOWN:
                        if(PlayerY_level > 0)
                            PlayerY_level = 0;
                    break;

                    default:
                    break;
                }
			break;
		}

		PlayerX += PlayerX_level;
		PlayerY += PlayerY_level;
	}
}


void Game::Draw()
{
	CribzDebug::PrintToConsole("Blanking Screen");
	//SDL_FillRect(screen, NULL, 0x000000);
	//SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
	background = player->LoadSprite("bg.png");
	player->Draw(GetScreen(), background, 0, 0);
	playerSprite = player->LoadSprite("player.png");
	player->Draw(GetScreen(), playerSprite, PlayerX, PlayerY);
	SDL_Flip(screen);
	//CribzDebug::PrintToConsole("Game Drawing");
}


void Game::Update()
{
	//CribzDebug::PrintToConsole("Game Updating");
}


void Game::Clean()
{
	//CribzDebug::PrintToConsole("Game Clean");
}