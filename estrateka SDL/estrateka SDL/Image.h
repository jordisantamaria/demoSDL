#pragma once

#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>

class Image
{
public:
	Image(std::string passed_nomFitxer, int x, int y, int w, int h);
	Image(std::string passed_nomFitxer);
	Image(void);
	~Image(void);

	bool loadMedia();

	void show(SDL_Surface* screenSurface);

SDL_Surface* getImagen();
void setImage(SDL_Surface* imagen);

private:

	SDL_Surface* imagen;
	std::string nomFitxer;
	SDL_Rect RectPos;
};

