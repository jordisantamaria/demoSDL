#pragma once

#include <SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class SDL_Setup
{
public:
		SDL_Setup(void);
	~SDL_Setup(void);

	//SDL_Renderer* getRenderer();
	SDL_Event* getMainEvent();
	SDL_Surface* getScreenSurface();

	//carga SDL per crear la screen, el render, etc....
	bool init();

	//actualitza la pantalla per dibuixar de nou les imatges
	void update();

		

private:

	SDL_Renderer* renderer;
	SDL_Event* mainEvent;
	SDL_Window* window;
	SDL_Surface* screenSurface;



};
