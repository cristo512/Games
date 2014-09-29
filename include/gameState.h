#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>

class gameState
{
public:
    gameState();
    virtual ~gameState();
	virtual void checkEvent(sf::Event event) = 0;
	virtual void draw() = 0;
    sf::Mouse mouse;
    virtual void checkActions() = 0;
};

#endif // GAMESTATE_H
