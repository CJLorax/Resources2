#include "player.h"

#include <iostream>

using namespace std;





//Analog joystick dead zone
const int JOYSTICK_DEAD_ZONE = 500;


Player::Player(SDL_Renderer *renderer, std::string filePath, float x, float y)
{

	SDL_Surface *surface = IMG_Load(filePath.c_str());

	texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);

	posRect.x = x;

	posRect.y = y;

	posRect.w = 81;

	posRect.h = 103;



}

void Player::Input(SDL_Event e)
{
	//X axis motion
	if (e.jaxis.axis == 0)
	{
		//Left of dead zone
		if (e.jaxis.value < -JOYSTICK_DEAD_ZONE)
		{
			//xDir = -1;
			cout << "X = -1" << endl;
		}
		//Right of dead zone
		else if (e.jaxis.value > JOYSTICK_DEAD_ZONE)
		{
			//xDir = 1;
			cout << "X = 1" << endl;
		}
		else
		{
			//xDir = 0;
			cout << "X = 0" << endl;
		}
	}

	//Y axis motion
	if (e.jaxis.axis == 1)
	{
		//Below of dead zone
		if (e.jaxis.value < -JOYSTICK_DEAD_ZONE)
		{
			//yDir = -1;
			cout << "Y = -1" << endl;
		}
		//Above of dead zone
		else if (e.jaxis.value > JOYSTICK_DEAD_ZONE)
		{
			//yDir = 1;
			cout << "Y = 1" << endl;
		}
		else
		{
			//yDir = 0;
			cout << "Y = 0" << endl;
		}
	}

}

void Player::Update() //float delta
{


}

void Player::Draw(SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer, texture, NULL, &posRect);

}

Player::~Player()
{
	SDL_DestroyTexture(texture);


}

