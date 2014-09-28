#ifndef VOLLEYBALL_H
#define VOLLEYBALL_H

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "gameState.h"
#include "Player.h"
#include "Ball.h"
#include "Background.h"
#include <iostream>

class Volleyball : public gameState
{
public:
    Volleyball();
    virtual ~Volleyball();
    Ball *ball;
    Player *player;
    sf::Sprite Net;
    Background background;
protected:
    sf::Texture playerStay;
    sf::Texture ballTexture;
    sf::Texture bgTexture;
    sf::Texture netTexture;
    void addPlayers();
    void addBalls();
    int playersAmount;
    int ballsAmount;
    void moving();
    virtual void draw();
    virtual void checkEvent(sf::Event event);
    virtual void checkActions();
};

#endif // VOLLEYBALL_H
