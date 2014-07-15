#pragma once

#include "SDL_Setup.h"
#include "Image.h"

enum KeyPress
{
	KEY_PRESS_DEFAULT,
	KEY_PRESS_UP,
	KEY_PRESS_DOWN,
	KEY_PRESS_LEFT,
	KEY_PRESS_RIGHT,
	KEY_PRESS_TOTAL
};

class KeyboardEvent
{
public:
	KeyboardEvent(SDL_Setup *passed_setup, Image defaultImage, Image upImage, Image downImage, Image leftImage, Image rightImage);
	KeyboardEvent(SDL_Setup *passed_setup);

	void show();
	~KeyboardEvent(void);

	
	bool loadMedia();
	//de momento solo cambia imagen dependiendo de la tecla, falta por colocar animaciones en vez de imagenes y movimiento.
	void movTeclado();

private:

	
	//The images that correspond to a keypress
Image *gkeyPress[ KEY_PRESS_TOTAL ];
Image *gCurrentSurface;

SDL_Setup *setup;

};

