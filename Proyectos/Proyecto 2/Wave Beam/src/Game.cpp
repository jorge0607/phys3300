#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* circulo;


Game::~Game()
{

}

Game::Game()
{

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	{
		int flags = 0;
		if (fullscreen)
		{
			flags = SDL_WINDOW_FULLSCREEN;
		}

		if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
		{
			std::cout << "SDL Initialized!" << std::endl;
			window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

			if (window)
			{
				std::cout << "Window created!" << std::endl;
			}

			renderer = SDL_CreateRenderer(window, -1, 0);

			if (renderer)
			{
				std::cout << "Renderer created!" << std::endl;
			}

			isRunning = true;
		}
		else {
			std::cout << "Couldn't initiate SDL..." << std::endl;
			isRunning = false;
		}

		circulo = new GameObject("assets/circulo-rojo.png", renderer);

	}
}


void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;

	}
}

void Game::update(float dt)
{
	timeCount += dt;
	float x = -50 + 300 * timeCount; 
	float y = 284 + 100 * sin(15 * timeCount) - 16;

	if (x > 900) {
		x = -50;
		timeCount = 0.0f;
	}

	circulo ->update(x, y, 32, 32);
}

void Game::render()
{
	SDL_RenderClear(renderer);
	circulo->render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "simulation cleaned..." << std::endl;
}
