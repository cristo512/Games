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
    float speed;
    void move();
    const float Gravity = 1.0f;
    int direction;
    sf::CircleShape sprite;
protected:
};

#endif // BALL_H
