#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* box;
GameObject* box1;
GameObject* box2;
GameObject* box3;

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

		
		box = new GameObject("assets/Crate.png", renderer);
		box1 = new GameObject("assets/Crate.png", renderer);
		box2 = new GameObject("assets/Crate.png", renderer);
		box3 = new GameObject("assets/Crate.png", renderer);


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
	box->update(612-32, 284 + 100 * sin(5 * timeCount) - 32, 64, 64); //VERTICAL
	box1->update(284 + 100 * sin(10 * timeCount)- 32, 100 - 32, 64, 64); //HORIZONTAL
	box2->update(284 + 100 * sin(6 * timeCount) - 32, 456 - 32, 64, 64);
	box3->update(284 + 100 * sin(3 * timeCount) - 32, 300 - 32, 64, 64);
	
}

void Game::render()
{
	SDL_RenderClear(renderer);
	box->render();
	box1->render();
	box2->render();
	box3->render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "simulation cleaned..." << std::endl;
}
