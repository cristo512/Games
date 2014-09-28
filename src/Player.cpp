#include "Player.h"

Player::Player()
{
    velocity.x = 0;
    velocity.y = 0;
}

Player::~Player()
{
}

void Player::setTextures(sf::Texture &head_texture, sf::Texture &eye_texture, sf::Texture &pupil_texture)
{
    head.setTexture(head_texture);
    eye.setTexture(eye_texture);
    pupil.setTexture(pupil_texture);
    head.setScale(globalGame->scaling_variable, globalGame->scaling_variable);
    eye.setScale(globalGame->scaling_variable, globalGame->scaling_variable);
    pupil.setScale(globalGame->scaling_variable, globalGame->scaling_variable);
    head.setPosition(0,0);
    eye.setPosition(0,0);
    pupil.setPosition(0,0);
    playerHeight = head.getGlobalBounds().height;
}

void Player::setLookTexture(sf::Texture &texture)
{
    looks.setTexture(texture);
    looks.setScale(globalGame->scaling_variable, globalGame->scaling_variable);
    looks.setPosition(0,0);
}
void Player::setShoesTexture(sf::Texture &texture)
{
    shoes.setTexture(texture);
    shoes.setScale(globalGame->scaling_variable, globalGame->scaling_variable);
    shoes.setPosition(0,0);
}

void Player::setKeys(sf::Keyboard::Key Left, sf::Keyboard::Key Up, sf::Keyboard::Key Right)
{
    this -> Right = Right;
    this -> Up = Up;
    this -> Left = Left;
}

void Player::spritesSetPosition(float x, float y)
{
    playerX = x;
    playerY = y;
    head.setPosition(x, y);
    shoes.setPosition(x + (head.getGlobalBounds().width * 3.f) / 10, y + head.getGlobalBounds().height / 8);
    eye.setPosition(x + (head.getGlobalBounds().width * 9) / 10 - eye.getGlobalBounds().width,
                    y + head.getGlobalBounds().height / 4);
    pupil.setPosition(eye.getPosition().x - pupil.getGlobalBounds().width - eye.getGlobalBounds().width / 5,
                      eye.getPosition().y + eye.getGlobalBounds().width / 4);
    looks.setPosition(x + head.getGlobalBounds().width - looks.getGlobalBounds().width, y);
    playerHeight = (shoes.getPosition().y + shoes.getGlobalBounds().height - y) * -1;
}

void Player::moveSprites(float x, float y)
{
    head.move(velocity.x * x, velocity.y * y);
    eye.move(velocity.x * x, velocity.y * y);
    pupil.move(velocity.x * x, velocity.y * y);
    looks.move(velocity.x * x, velocity.y * y);
    shoes.move(velocity.x * x, velocity.y * y);
    playerX += velocity.x * x;
    playerY += velocity.y * y;
}
void Player::back()
{
    moveSprites(-1.f, 0);
}
void Player::move()
{
    if( head.getPosition().y < (globalGame->window.getSize().y / 2) || globalGame->isKeyReleased[Up])
        jumpingAvailable = false;

    if(head.getPosition().y + playerHeight < (globalGame->window.getSize().y * 19.f) / 20
       || velocity.y < 0 )
        velocity.y += Gravity;
    else
    {
        spritesSetPosition(playerX, (globalGame->window.getSize().y * 19.f) / 20 - playerHeight);
        velocity.y = 0;
        jumpingAvailable = true;
    }

    moveSprites(1.f, 1.f);


    if ( playerX < 0)
        spritesSetPosition(0, playerY);
    if ( playerX > globalGame->window.getSize().x)
        spritesSetPosition(globalGame->window.getSize().x, playerY);
}

void Player::draw()
{
    globalGame->window.draw(shoes);
    globalGame->window.draw(head);
    globalGame->window.draw(eye);
    globalGame->window.draw(pupil);
    globalGame->window.draw(looks);
}
