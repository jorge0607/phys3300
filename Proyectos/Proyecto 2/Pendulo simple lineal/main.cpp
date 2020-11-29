#include "Game.h"

int main(int argc, char*args[])
{
	const float FPS = 60.0f;
	const float frameDelay = 1000 / FPS;

	Uint32 frameStart;
	Uint32 frameEnd;
	float frameTime = 0.0f;
	

	Game* game = nullptr;
	game = new Game();

	game->init("New Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update(frameTime / 1000.0f);
		game->render();

		frameEnd = SDL_GetTicks();

		frameTime = frameEnd - frameStart;

		if (frameTime < frameDelay)
		{
			SDL_Delay(frameDelay - frameTime);
		}

		frameTime = SDL_GetTicks() - frameStart;
	}

	game->clean();

	return 0;
}