#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>

class Ball
{
public:
    Ball();
    virtual ~Ball();
    void setTexture(sf::Texture &texture);
    sf::Vector2f velocity;
    sf::Sprite sprite;
protected:
};

#endif // BALL_H
