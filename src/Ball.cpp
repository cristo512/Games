#include "Ball.h"
#include "Game.h"
#include <cmath>
Ball::Ball()
{
   sprite.setRadius(155);
   speed = 800.f;
   direction = -1;
   velocity = sf::Vector2f(1,-5);
}

Ball::~Ball()
{
    //dtor
}

void Ball::setTexture(sf::Texture &texture)
{
    sprite.setTexture(&texture, false);
    sprite.setScale(globalGame->scaling_variable, globalGame->scaling_variable);
}

void Ball::move()
{
    if(sprite.getPosition().y + sprite.getGlobalBounds().height > globalGame->window.getSize().y)
        velocity.y += Gravity;

    if(sprite.getPosition().x < 0 )
        direction *= -1;
    if(sprite.getPosition().x + sprite.getGlobalBounds().width > globalGame->window.getSize().x )
       direction *= -1;

    if(sprite.getPosition().y < 0 )
        velocity.y *= -1;
    if(sprite.getPosition().y + sprite.getGlobalBounds().height > globalGame->window.getSize().y)
        velocity.y = 0;

    velocity.x = sqrt( pow(speed * globalGame->timeStep, 2) - pow(velocity.y, 2) ) * direction;

    sprite.move(velocity.x, velocity.y);
}
