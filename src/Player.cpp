#include "Player.h"

Player::Player()
{
    velocity.x = 0;
    velocity.y = 0;
    isReverse = false;
}

Player::~Player()
{
}

void Player::horizontalReflection()
{
    head.setScale(-head.getScale().x, head.getScale().y);
    eye.setScale(-eye.getScale().x, eye.getScale().y);
    pupil.setScale(-pupil.getScale().x, pupil.getScale().y);
    looks.setScale(-looks.getScale().x, looks.getScale().y);
    shoes1.setScale(-shoes1.getScale().x, shoes1.getScale().y);
    shoes2.setScale(-shoes2.getScale().x, shoes2.getScale().y);
    isReverse = true;
}

void Player::setReversedPosition(float x, float y)
{
    playerX = x;
    playerY = y;
    head.setPosition(x, y);
    shoes1.setPosition(x - (head.getGlobalBounds().width * 2.5f) / 10.f, y + (head.getGlobalBounds().height * 19) / 20 );
    shoes2.setPosition(x - (head.getGlobalBounds().width * 5.5f) / 10.f, y + (head.getGlobalBounds().height * 75) / 80 );
    eye.setPosition(x - (head.getGlobalBounds().width * 9) / 10 + eye.getGlobalBounds().width,
                    y + head.getGlobalBounds().height / 4);
    looks.setPosition(x - head.getGlobalBounds().width + looks.getGlobalBounds().width - head.getGlobalBounds().width / 200 ,
                      y - head.getGlobalBounds().height / 100);
}

void Player::setPlayerHeight()
{
    playerHeight = (shoes1.getPosition().y + shoes1.getGlobalBounds().height - head.getPosition().y);
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
    pupilDistance = (eye.getGlobalBounds().width - pupil.getGlobalBounds().width) / 2;
}

void Player::setLookTexture(sf::Texture &texture)
{
    looks.setTexture(texture);
    looks.setScale(globalGame->scaling_variable, globalGame->scaling_variable);
    looks.setPosition(0,0);
}
void Player::setShoesTexture(sf::Texture &texture)
{
    shoes1.setTexture(texture);
    shoes1.setScale(globalGame->scaling_variable, globalGame->scaling_variable);
    shoes1.setPosition(0,0);
    shoes2.setTexture(texture);
    shoes2.setScale(globalGame->scaling_variable, globalGame->scaling_variable);
    shoes2.setPosition(0,0);
}

void Player::setKeys(sf::Keyboard::Key Left, sf::Keyboard::Key Up, sf::Keyboard::Key Right)
{
    this -> Right = Right;
    this -> Up = Up;
    this -> Left = Left;
}

void Player::setSpritesPosition(float x, float y)
{
    playerX = x;
    playerY = y;
    head.setPosition(x, y);
    shoes1.setPosition(x + (head.getGlobalBounds().width * 2.5f) / 10.f, y + (head.getGlobalBounds().height * 19) / 20 );
    shoes2.setPosition(x + (head.getGlobalBounds().width * 5.5f) / 10.f, y + (head.getGlobalBounds().height * 75) / 80 );
    eye.setPosition(x + (head.getGlobalBounds().width * 9) / 10 - eye.getGlobalBounds().width,
                    y + head.getGlobalBounds().height / 4);
    looks.setPosition(x + head.getGlobalBounds().width - looks.getGlobalBounds().width + head.getGlobalBounds().width / 200 ,
                      y - head.getGlobalBounds().height / 100);
}

void Player::moveSprites(float x, float y)
{
    head.move(velocity.x * x, velocity.y * y);
    eye.move(velocity.x * x, velocity.y * y);
    pupil.move(velocity.x * x, velocity.y * y);
    looks.move(velocity.x * x, velocity.y * y);
    shoes1.move(velocity.x * x, velocity.y * y);
    shoes2.move(velocity.x * x, velocity.y * y);
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
        if(isReverse)
            setReversedPosition(playerX, (globalGame->window.getSize().y * 19.f) / 20 - playerHeight);
        else
            setSpritesPosition(playerX, (globalGame->window.getSize().y * 19.f) / 20 - playerHeight);
        velocity.y = 0;
        jumpingAvailable = true;
    }

    moveSprites(1.f, 1.f);


    if ( playerX < 0)
    {
        if(isReverse)
             setReversedPosition(0, playerY);
        else
             setSpritesPosition(0, playerY);
    }
    if ( playerX > globalGame->window.getSize().x)
    {
        if(isReverse)
            setReversedPosition(globalGame->window.getSize().x, playerY);
        else
            setSpritesPosition(globalGame->window.getSize().x, playerY);
    }
}

void Player::setPupil(float ballSIN, float ballCOS)
{
    pupil.setPosition( eye.getPosition().x + pupilDistance + (pupilDistance * ballSIN),
                        eye.getPosition().y + pupilDistance + (pupilDistance * ballCOS) * -1);
    if(isReverse)
    {
        pupil.setPosition( eye.getPosition().x - pupilDistance - (pupilDistance * ballSIN),
                            eye.getPosition().y + pupilDistance + (pupilDistance * ballCOS) * -1);
    }
}

void Player::draw()
{
    globalGame->window.draw(shoes2);
    globalGame->window.draw(shoes1);
    globalGame->window.draw(head);
    globalGame->window.draw(eye);
    globalGame->window.draw(pupil);
    globalGame->window.draw(looks);
}
