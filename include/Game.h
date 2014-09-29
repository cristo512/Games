#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "gameState.h"
#include "Menu.h"
#include "Volleyball.h"
#include "Pong.h"

class Game
{
public:
    Game();
    ~Game();
	void Run();
	sf::Event event;
	bool isKeyReleased[sf::Keyboard::KeyCount];
	bool checkIfReleased();
    sf::RenderWindow window;
	float scaling_variable;
	float scale_variableX;
	float scale_variableY;
	float scale(float x);
	float average(float x, float y);
	gameState *State;
	float clamp(const float &what, const float& a, const float& b);
	float delta;
	float lastUpdateTime;
	float accumulator;
	const float timeStep = 0.016;
	const float maxAccumulatedTime = 1.0;
	sf::Clock clock;
    sf::Texture headTexture;
    sf::Texture pupilTexture;
    sf::Texture eyeTexture;
    sf::Texture shoesTexture_1;
    sf::Texture shoesTexture_2;
    sf::Texture looksTexture_1;
    sf::Texture looksTexture_2;
    sf::Texture ballTexture;
    sf::Texture bgTexture;
    sf::Texture netTexture;
    bool onMouseOver(sf::FloatRect rect);
	bool onCollision(sf::FloatRect rect1, sf::FloatRect rect2);

protected:
    void loadTextures();
    void setScale_Variable();
};

extern Game* globalGame;

#endif // GAME_H
