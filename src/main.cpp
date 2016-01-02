#if defined (_WIN32) ||  (_WIN64)

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_net.h>

#endif


#if defined (__APPLE__)

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_net/SDL_net.h>

#endif


#if defined (__linux__)

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_net.h"

#endif

#if defined (_WIN32) ||  (_WIN64)
#include <direct.h>
#define getcwd _getcwd
#endif

#if defined (__linux__)
#include <unistd.h>
#endif

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

int main(int argc, char ** argv) {

	//File paths for Windows, Mac, and Linux
	//File paths for Windows, Mac, and Linux
#if defined (_WIN32) ||  (_WIN64)

	cout << "This is Windows" << endl;

	string s_cwd(getcwd(NULL, 0));

	string s_cwd_images = s_cwd + "\\Resources\\images\\";


#endif

#if defined (__APPLE__)

	cout << "This is Apple" << endl;

	cout << "This is Apple" << endl;

	cout << "This is Apple" << endl;

	string s_cwd(getcwd(NULL, 0));

	string s_cwd_images = s_cwd + "/Resources2/images/";

#endif

#if defined (__linux__)

	cout << "This is Linux" << endl;

	cout << "This is Linux" << endl;

	cout << "This is Linux" << endl;

	string s_cwd(getcwd(NULL, 0));

	string s_cwd_images = s_cwd + "/Resources2/images/";


#endif

	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The renderer we'll be using
	SDL_Renderer *renderer = NULL;

	//The surface contained by the window
	//SDL_Surface* screenSurface = NULL;

	//Initialize all the SDL includes - SDL, images, mixer, ttf, net
	SDL_Init(SDL_INIT_EVERYTHING);

	//Create window
	window = SDL_CreateWindow("SDL Window",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);

	//Create Renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


	//create texture

	//string tempStr = s_cwd_images + "player.png";//tempStr.c_str()

	SDL_Surface *surface = IMG_Load((s_cwd_images + "player.png").c_str());

    /*
	if( surface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", tempStr.c_str(), IMG_GetError() );
    }
     */

	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);

	SDL_Rect posRect;

	posRect.x = 10;

	posRect.y = 10;

	posRect.w = 81;

	posRect.h = 103;


	while (1) {
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				break;
			}
		}

		SDL_RenderClear(renderer);

		SDL_RenderCopy(renderer, texture, NULL, &posRect);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();


	return 0;
}
