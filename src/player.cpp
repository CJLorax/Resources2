#include "player.h"

#include <iostream>

using namespace std;

//Analog joystick dead zone
const int JOYSTICK_DEAD_ZONE = 8000;

float xDir, yDir;

float speed = 500.0f;

float pos_X, pos_Y;


Player::Player(SDL_Renderer *renderer, std::string filePath, float x, float y)
{

	SDL_Surface *surface = IMG_Load(filePath.c_str());

	texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);

	posRect.x = x;

	posRect.y = y;

	posRect.w = 81;

	posRect.h = 103;

	pos_X = x;

	pos_Y = y;


}

void Player::OnControllerAxis(const SDL_ControllerAxisEvent event)
{
	// Axis movements and button presses both sent here as SDL_ControllerAxisEvent structures

	if (event.which == 0)
	{
		if (event.axis == 0)
		{

			if (event.value < -JOYSTICK_DEAD_ZONE)
			{
				xDir = -1.0f;
			}
			else if (event.value > JOYSTICK_DEAD_ZONE)
			{
				xDir = 1.0f;
			}
			else
			{
				xDir = 0.0f;
			}
		}

		if (event.axis == 1)
		{

			if (event.value < -JOYSTICK_DEAD_ZONE)
			{
				yDir = -1.0f;
			}
			else if (event.value > JOYSTICK_DEAD_ZONE)
			{
				yDir = 1.0f;
			}
			else
			{
				yDir = 0.0f;
			}
		}

	}

}

void Player::Update(float ftime) //float delta
{
	pos_X += (speed * xDir) * ftime;
	pos_Y += (speed * yDir) * ftime;
	
	posRect.x = (int)(pos_X + 0.5f);
	
	posRect.y = (int)(pos_Y + 0.5f);

}

void Player::Draw(SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer, texture, NULL, &posRect);

}

Player::~Player()
{
	SDL_DestroyTexture(texture);

}

