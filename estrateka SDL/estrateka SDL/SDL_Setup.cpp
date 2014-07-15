#include "SDL_Setup.h"


SDL_Setup::SDL_Setup(void)
{
	window = NULL;
	renderer = NULL;
	mainEvent = NULL;

	screenSurface = NULL;

	mainEvent = new SDL_Event();
}

bool SDL_Setup::init()
{

	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		window = SDL_CreateWindow( "Shakugan no Shana Final Battle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface( window );
		}
	}

	return success;
}

//actualitza la pantalla per dibuixar de nou les imatges
	void SDL_Setup::update()
	{
		//Update the surface, para mostrar los surface creados en pantalla ^^
			SDL_UpdateWindowSurface( window );
	}


	SDL_Surface* SDL_Setup::getScreenSurface()
	{
		return screenSurface;
	}
	SDL_Event* SDL_Setup::getMainEvent()
	{
		return mainEvent;
	}


SDL_Setup::~SDL_Setup(void)
{
	//Destroy window
    SDL_DestroyWindow( window );
	window = NULL;
	SDL_FreeSurface( screenSurface );
	screenSurface =NULL;
	

    //Quit SDL subsystems
    SDL_Quit();
}
