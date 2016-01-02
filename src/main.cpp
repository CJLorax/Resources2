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

#include "player.h"

using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;



//Game Controller 1 handler
SDL_Joystick* gGameController = NULL;

int main(int argc, char ** argv) {

	//File paths for Windows, Mac, and Linux
	//File paths for Windows, Mac, and Linux
#if defined (_WIN32) ||  (_WIN64)

	cout << "This is Windows" << endl;

	string s_cwd(getcwd(NULL, 0));

	string s_cwd_images = s_cwd + "\\Resources2\\images\\";


#endif

#if defined (__APPLE__)

	cout << "This is Apple" << endl;

	string s_cwd(getcwd(NULL, 0));

	string s_cwd_images = s_cwd + "/Resources2/images/";

#endif

#if defined (__linux__)

	cout << "This is Linux" << endl;

	string s_cwd(getcwd(NULL, 0));

	string s_cwd_images = s_cwd + "/Resources2/images/";


#endif

	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The renderer we'll be using
	SDL_Renderer *renderer = NULL;

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

	//Load joystick
	gGameController = SDL_JoystickOpen(0);

	// create player
	Player player1 = Player(renderer, s_cwd_images + "player.png", 300.0f, 300.0f);


	while (1) {
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				break;
			}
		}
		else if (e.type == SDL_JOYAXISMOTION)
		{

			//Motion on controller 0
			if (e.jaxis.which == 0)
			{
				player1.Input(e);
			}

		}



		player1.Update();


		SDL_RenderClear(renderer);

		//SDL_RenderCopy(renderer, texture, NULL, &posRect);

		player1.Draw(renderer);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	//Close game controller
	SDL_JoystickClose(gGameController);
	gGameController = NULL;

	SDL_Quit();


	return 0;
}
