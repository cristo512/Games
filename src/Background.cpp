#include "Background.h"
#include "Game.h"

Background::Background()
{
    sprite.setPosition(0, 0);
}

Background::~Background()
{
    //dtor
}

void Background::setTexture(sf::Texture &texture)
{
    sprite.setTexture(texture);
    sprite.setScale(globalGame->scaling_variable, globalGame->scaling_variable);
}
