#include<SDL.h>
#include<iostream>
//using namespace std;
// Delaring gloabal variable
const int screen_width = 640;
const int screen_height = 480;
// declaring key components and initializing them 
SDL_Window* gwindow = NULL;
SDL_Surface* gscreensurface = NULL;
SDL_Surface* ghelloworld = NULL;
bool init() {
	// initializing of window and getting surface
	//intialization flag 
	bool success = true;
	// initialize sdl
	// When there's an error, SDL_Init returns -1
	if (SDL_Init(SDL_INIT_VIDEO)<0)
	{
		std::cout << "Sdl failed to initialize! sdl Get error/n" << SDL_GetError()<<std::endl;
		success = false;
	}
	else
	{
		//create window 
		gwindow = SDL_CreateWindow("Window with image", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
		if (gwindow == NULL)
		{
			std::cout << "Window could not created! Getlasterror/n" << SDL_GetError()<<std::endl;
			success = false;
		}
		else
		{
			gscreensurface = SDL_GetWindowSurface(gwindow);
		}
	}
	return success;
}
bool loadmedia() {
	//loading image onto the grabbed surface
	//load success flag
	bool success = true;
	//loading splash image 
	
	ghelloworld = SDL_LoadBMP("02_getting_an_image_on_the_screen/hello_world.bmp");
	// there should not be any space in address. 02_getting_an_image_on_the_screen/hello_world.bmp
	 
	if (ghelloworld == NULL)
	{
		std::cout << "Unable to load image % s!SDL Error : % s\n02_getting_an_image_on_the_screen / hello_world.bmp" << SDL_GetError;
		success = false;
	}
	return success;
}
void close() {
	//dealloacte surface
	SDL_FreeSurface(ghelloworld);
	ghelloworld = NULL;
	// destroy window
	SDL_DestroyWindow(gwindow);
	gwindow = NULL;
	// quit sdl subsystem
	SDL_QUIT;
}

int main(int argc, char* args[]) {
	//start sdl and create window
	if (!init())
	{
		std::cout << "Failed to initialize init()";
	}
	else
	{
		//load media 
		if (!loadmedia())
		{
			std::cout << "Failed to load media ";
		}
		else
		{
			//apply image
			SDL_BlitSurface(ghelloworld, NULL, gscreensurface, NULL);
			// update the surface 
			SDL_UpdateWindowSurface(gwindow);
			// main loop
			bool quit = false;
			// event handler
			SDL_Event e;
			while (!quit)
			{
				// handle events on queue
				while (SDL_PollEvent(&e)!=0)
				{	
					// logging user input
					if (e.type == SDL_KEYDOWN)
					{	
						std::cout << "key pressed";
					}
					// user request quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}
			}
			
		
			
		}
	}
	close();
	
	return 0 ; 
}