#pragma once
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

#include <string>


class Player {

public:

	SDL_Texture *texture;
	SDL_Rect posRect;

	Player(SDL_Renderer *renderer, std::string filePath, float x, float y);

	void Input(SDL_Event e);

	void Update(float ftime); //

	void Draw(SDL_Renderer *renderer);

	~Player();



};