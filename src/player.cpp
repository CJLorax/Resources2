#include "player.h"


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

void Player::Update(float delta)
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

