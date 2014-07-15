#pragma once

#include "SDL_Setup.h"

class Button
{
public:
	Button(void);
	~Button(void);
	
	bool loadMedia();

	void show(SDL_Surface* screenSurface);

SDL_Surface* getImagen();

private:

	SDL_Surface* imagen;
};

