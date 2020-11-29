#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* circulo;
GameObject* pin;

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
		pin = new GameObject("assets/circulo-rojo.png", renderer);
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
	
	t = 0.2618 * cos(0.7746 * timeCount);
	x = 400 + 250 * sin(t) - 16;
	y = 200 + 250 * cos(t) - 16;

	circulo->update(x,y,32,32);
	pin->update(400-8, 200-8,16,16);

}

void Game::render()
{
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(renderer, 400, 200, x + 16, y + 16);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

	circulo->render();
	pin->render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "simulation cleaned..." << std::endl;
}
