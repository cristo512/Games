#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "gameState.h"
#include "Menu.h"
#include "Volleyball.h"

class Game
{
public:
    Game();
    ~Game();
	void Run();
	sf::Event event;
    sf::RenderWindow window;
	float scaling_variable;
	float scale_variableX;
	float scale_variableY;
	float scale(float x);
	float average(float x, float y);
	gameState *State;
	float delta;
	sf::Clock clock;
	virtual bool onMouseOver(sf::Sprite &sprite);
	virtual bool onMouseOver(sf::Text &text);
	virtual bool onCollision(sf::Sprite &sprite1, sf::Sprite &sprite2);

protected:
    void setScale_Variable();
};

extern Game* globalGame;

#endif // GAME_H
