#ifndef PLAYER_H
#define PLAYER_H
class Player;
#include <SFML/Graphics.hpp>
#include "Game.h"

class Player
{
public:
    Player();
    virtual ~Player();
    float moveSpeed;
    float jumpSpeed;
    void setTexture(sf::Texture &texture);
    sf::Vector2f velocity;
    sf::Sprite sprite;
    std::string name;
    void move();
    void back();
    void fall();
    bool jumpingAvailable = true;
    const float Gravity = 1.0f;
    sf::Keyboard::Key Left;
    sf::Keyboard::Key Up;
    sf::Keyboard::Key Right;
    void setKeys(sf::Keyboard::Key Left, sf::Keyboard::Key Up, sf::Keyboard::Key Right);
};

#endif // PLAYER_H
