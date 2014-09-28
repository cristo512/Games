#include "Player.h"

Player::Player()
{
    velocity.x = 0;
    velocity.y = 0;
}

Player::~Player()
{
}

void Player::setTexture(sf::Texture &texture)
{
    sprite.setTexture(texture);
    sprite.setScale(globalGame->scaling_variable, globalGame->scaling_variable);
}

void Player::setKeys(sf::Keyboard::Key Left, sf::Keyboard::Key Up, sf::Keyboard::Key Right)
{
    this -> Right = Right;
    this -> Up = Up;
    this -> Left = Left;
}

void Player::back()
{
    sprite.move(-velocity.x, 0);
}

void Player::move()
{
    if( sprite.getPosition().y < (globalGame->window.getSize().y / 2))
        jumpingAvailable = false;

    if(sprite.getPosition().y + sprite.getGlobalBounds().height < globalGame->window.getSize().y
       || velocity.y < 0 )
        velocity.y += Gravity;
    else
    {
        sprite.setPosition(sprite.getPosition().x, globalGame->window.getSize().y - sprite.getGlobalBounds().height);
        velocity.y = 0;
        jumpingAvailable = true;
    }

    sprite.move(velocity.x, velocity.y);


    if ( sprite.getPosition().x < 0)
        sprite.setPosition(0, sprite.getPosition().y);
    if ( sprite.getPosition().x > globalGame->window.getSize().x)
        sprite.setPosition(globalGame->window.getSize().x, sprite.getPosition().y);
}
