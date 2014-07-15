/*
Cosas por hacer:

Hacer SDL_SETUP y imageManager singletone para que solo pueda haber una sola instancia
falta optimizar la imagen, NIVEL 5, necessito singletone plz...
*/




//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

#include "SDL_Setup.h"
#include "Image.h"
#include "imageManager.h"
#include "KeyboardEvent.h"



int main( int argc, char* args[] )
{
	//Start up SDL and create window
		SDL_Setup* setup = new SDL_Setup();
		Image* HelloWord = new Image("hello_world.bmp", 10, 100, 100, 100);
		KeyboardEvent *teclado = new KeyboardEvent(setup);

	if(!setup->init())
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		HelloWord->loadMedia();
		teclado->loadMedia();

		//Event handler
		
			bool quit = false;

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( setup->getMainEvent() ) != 0 )
				{
					//User requests quit
					if( setup->getMainEvent()->type == SDL_QUIT )
					{
						quit = true;
					}
				}
				teclado->movTeclado();
				teclado->show();

			//Apply the image
				HelloWord->show(setup->getScreenSurface());
			
			
			setup->update();

			}
	}



	return 0;
}