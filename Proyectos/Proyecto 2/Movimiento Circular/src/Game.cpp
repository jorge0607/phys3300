#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* circulo_centro;
GameObject* circulo1;
GameObject* circulo2;
GameObject* circulo3;


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

		circulo_centro = new GameObject("assets/circulo-rojo.png", renderer);
		circulo1 = new GameObject("assets/circulo-rojo.png",renderer);
		circulo2 = new GameObject("assets/circulo-rojo.png", renderer);
		circulo3 = new GameObject("assets/circulo-rojo.png", renderer);

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
	float x1 = 400 - 16;
	float y1 = 320 - 16;
	float x = 400 + 250 * cos(0.8 * timeCount) - 16;
	float y = 320 + 250 * sin(0.8 * timeCount) - 16; 
	

	circulo1->update(x, y, 32, 32);
	circulo2->update(400 + 100 * cos(4 * timeCount) - 16, 320 + 100 * sin(4 * timeCount) - 16, 32, 32);
	circulo3->update(400 + 150 * cos(2 * timeCount) - 16, 320 + 150 * sin(2 * timeCount) - 16, 32, 32);
    circulo_centro->update(x1, y1, 32, 32);
	std::cout << (x - x1) * (x-x1) + (y-y1)*(y-y1) << std::endl;

}

void Game::render()
{
	SDL_RenderClear(renderer);
	circulo1->render();
	circulo2->render();
	circulo3->render();
	circulo_centro->render();
   SDL_RenderPresent(renderer);
}
	


void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "simulation cleaned..." << std::endl;
}
