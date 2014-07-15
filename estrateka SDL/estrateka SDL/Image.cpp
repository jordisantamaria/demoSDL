#include "Image.h"


Image::Image(std::string passed_nomFitxer, int x, int y, int w, int h)
{
	imagen = NULL;

	nomFitxer = passed_nomFitxer;
	RectPos.x = x;
	RectPos.y = y;
	RectPos.w = w;
	RectPos.h = h;
}

Image::Image(void)
{
	imagen = NULL;
}
Image::Image(std::string passed_nomFitxer)
{
	imagen = NULL;

	nomFitxer = passed_nomFitxer;
}
bool Image::loadMedia()
{
	Image *temp;

	//Loading success flag
	bool success = true;

	//Load splash image
	imagen = SDL_LoadBMP( nomFitxer.c_str() );
	if( imagen == NULL )
	{
	std::cout << "No se puede abrir " << nomFitxer << SDL_GetError() << std::endl;
		success = false;
	}
	return success;
}

SDL_Surface* Image::getImagen()
{
	return imagen;
}
void Image::setImage(SDL_Surface* imagen)
{
	this->imagen = imagen;
}

void Image::show(SDL_Surface* screenSurface)
{
	SDL_BlitScaled( imagen, NULL, screenSurface, &RectPos ); 
	//SDL_BlitSurface( imagen, NULL, screenSurface, &RectPos );
}
Image::~Image(void)
{
		//Deallocate surface
	SDL_FreeSurface( imagen );
	imagen = NULL;
}
