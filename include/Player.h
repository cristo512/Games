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
    float playerHeight;
    void setTextures(sf::Texture &head_texture, sf::Texture &eye_texture, sf::Texture &pupil_texture);
    sf::Vector2f velocity;
    //sf::Sprite sprite;
    void setLookTexture(sf::Texture &texture);
    void setShoesTexture(sf::Texture &texture);
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
    void draw();
    void spritesSetPosition(float x, float y);
    float playerX;
    float playerY;
    sf::Sprite head;
    sf::Sprite eye;
    sf::Sprite looks;
    sf::Sprite pupil;
    sf::Sprite shoes;
private:
    void moveSprites(float x, float y);
};

#endif // PLAYER_H
