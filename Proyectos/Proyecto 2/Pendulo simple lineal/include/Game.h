#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update(float dt = 0.0f);
	void render();
	void clean();

	bool running() { return isRunning; }

private:

	bool isRunning;
	int count = 0;
	float timeCount = 0.0f;
	float t, x, y;
	SDL_Window* window;
	SDL_Renderer* renderer;



};
#endif

