#include "Ball.h"
#include "Game.h"

Ball::Ball()
{
    //ctor
}

Ball::~Ball()
{
    //dtor
}

void Ball::setTexture(sf::Texture &texture)
{
    sprite.setTexture(texture);
    sprite.setScale(globalGame->scaling_variable, globalGame->scaling_variable);
}
