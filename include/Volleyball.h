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
    float eye_ball_x;
    float eye_ball_y;
    float eye_ball;
    float ballSIN;
    float ballCOS;
    void setPupils();
    Volleyball();
    virtual ~Volleyball();
    Ball *ball;
    Player *player;
    sf::Sprite Net;
    Background background;
protected:
    float ballMid;
    float playerMid;
    void setTextures();
    void addPlayers();
    void addBalls();
    int playersAmount;
    int ballsAmount;
    void moving();
    void moveBall();
    virtual void draw();
    virtual void checkEvent(sf::Event event);
    virtual void checkActions();
};

#endif // VOLLEYBALL_H
