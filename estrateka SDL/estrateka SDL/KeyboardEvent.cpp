#include "KeyboardEvent.h"


KeyboardEvent::KeyboardEvent(SDL_Setup *passed_setup, Image defaultImage, Image upImage, Image downImage, Image leftImage, Image rightImage)
{
	setup = passed_setup;
	gCurrentSurface = NULL;

}

KeyboardEvent::KeyboardEvent(SDL_Setup *passed_setup)
{
	setup = passed_setup;
	gCurrentSurface = new Image("press.bmp");
	gCurrentSurface->loadMedia();
}

bool KeyboardEvent::loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load default surface
	gkeyPress[ KEY_PRESS_DEFAULT ] = new Image("press.bmp");
	if( gkeyPress[ KEY_PRESS_DEFAULT ]->loadMedia() == false )
	{
		printf( "Failed to load default image!\n" );
		success = false;
	}

	//Load up surface
	gkeyPress[ KEY_PRESS_UP ] = new Image("up.bmp");
	if( gkeyPress[ KEY_PRESS_UP ]->loadMedia() == false )
	{
		printf( "Failed to load up image!\n" );
		success = false;
	}

	//Load down surface
	gkeyPress[ KEY_PRESS_DOWN ] = new Image("down.bmp");
	if( gkeyPress[ KEY_PRESS_DOWN ]->loadMedia() == false )
	{
		printf( "Failed to load down image!\n" );
		success = false;
	}

	//Load left surface
	gkeyPress[ KEY_PRESS_LEFT ] = new Image("left.bmp");
	if( gkeyPress[ KEY_PRESS_LEFT ]->loadMedia() == false )
	{
		printf( "Failed to load left image!\n" );
		success = false;
	}

	//Load right surface
	gkeyPress[ KEY_PRESS_RIGHT ] = new Image("right.bmp");
	if( gkeyPress[ KEY_PRESS_RIGHT ]->loadMedia() == false )
	{
		printf( "Failed to load right image!\n" );
		success = false;
	}

	return success;
}
void KeyboardEvent::movTeclado()
{

	//si es un evento keydown
	if( setup->getMainEvent()->type == SDL_KEYDOWN )
	{
		//un segundi switch para detecar que tecla es
		switch (setup->getMainEvent()->key.keysym.sym)
		{
		case SDLK_UP:
			//gCurrentSurface = gkeyPress[KEY_PRESS_UP];
			gCurrentSurface->setImage(gkeyPress[KEY_PRESS_UP]->getImagen());
			break;
		case SDLK_DOWN:
			//gCurrentSurface = gkeyPress[KEY_PRESS_DOWN];
			gCurrentSurface->setImage(gkeyPress[KEY_PRESS_DOWN]->getImagen());
			break;
		case SDLK_LEFT:
			//gCurrentSurface = gkeyPress[KEY_PRESS_LEFT];
			gCurrentSurface->setImage(gkeyPress[KEY_PRESS_LEFT]->getImagen());
			break;
		case SDLK_RIGHT:		
			//gCurrentSurface = gkeyPress[KEY_PRESS_RIGHT];
			gCurrentSurface->setImage(gkeyPress[KEY_PRESS_RIGHT]->getImagen());
			break;

		default:
			//gCurrentSurface = gkeyPress[KEY_PRESS_DEFAULT];
			
			break;
		}
	}
	if( setup->getMainEvent()->type == SDL_KEYUP)
	{
		gCurrentSurface->setImage(gkeyPress[KEY_PRESS_DEFAULT]->getImagen());
	}
}
void KeyboardEvent::show()
{
	SDL_BlitSurface(gCurrentSurface->getImagen(), NULL, setup->getScreenSurface(), NULL );
}

KeyboardEvent::~KeyboardEvent(void)
{
}
