#include "squarePlayer.h"
#include "Game.h"

squarePlayer::squarePlayer()
{
    shape.setSize(sf::Vector2f(30, 300));
    shape.setFillColor(sf::Color::White);
    speed = 800.f;
    points = 0;
}

squarePlayer::~squarePlayer()
{
    //dtor
}

void squarePlayer::setKeys(sf::Keyboard::Key Up, sf::Keyboard::Key Down)
{
    this->Up = Up;
    this->Down = Down;
}


void squarePlayer::moveUp()
{
    shape.move(0, -speed * globalGame->timeStep);
}

void squarePlayer::moveDown()
{
    shape.move(0, speed * globalGame->timeStep);
}
