#include "Volleyball.h"
#include <cmath>
void Volleyball::addPlayers()
{
    playersAmount = 2;
    player = new Player [playersAmount];
    player[0].setLookTexture(globalGame->looksTexture_1);
    player[0].setShoesTexture(globalGame->shoesTexture_1);
    player[1].setLookTexture(globalGame->looksTexture_2);
    player[1].setShoesTexture(globalGame->shoesTexture_2);
    for (int i = 0; i < playersAmount ; i++)
    {
        player[i].moveSpeed = 800.f;
        player[i].jumpSpeed = 1000.f;
            player[i].setTextures(globalGame->headTexture, globalGame->eyeTexture, globalGame->pupilTexture);
        player[i].setSpritesPosition(0,0);
        player[i].setPlayerHeight();
    }
    player[0].setKeys(sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::D);
    player[0].setSpritesPosition(globalGame->window.getSize().x / 5, globalGame->window.getSize().y - player[0].playerHeight);

    player[1].setKeys(sf::Keyboard::Left, sf::Keyboard::Up, sf::Keyboard::Right);
    player[1].setReversedPosition((4 * globalGame->window.getSize().x) / 5, globalGame->window.getSize().y - player[1].playerHeight);
    player[1].horizontalReflection();
}
void Volleyball::addBalls()
{
    ballsAmount = 1;
    ball = new Ball [ballsAmount];

    for (int i = 0; i < playersAmount ; i++)
    {
        ball[i].setTexture(globalGame->ballTexture);
    }
    ball[0].sprite.setPosition(globalGame->average(globalGame->window.getSize().x,
                                ball[0].sprite.getGlobalBounds().width),globalGame->window.getSize().y / 10);
}

void Volleyball::setTextures()
{
    Net.setTexture(globalGame->netTexture);
    Net.scale(globalGame->scaling_variable, globalGame->scaling_variable);
    background.setTexture(globalGame->bgTexture);
    Net.setPosition(globalGame->average(globalGame->window.getSize().x, Net.getGlobalBounds().width),
                    globalGame->window.getSize().y - Net.getGlobalBounds().height);
}

Volleyball::Volleyball()
{
    setTextures();
    addPlayers();
    addBalls();
}

Volleyball::~Volleyball()
{
    //dtor
}

void Volleyball::setPupils()
{
    eye_ball_x = fabs( (player[0].eye.getPosition().x + player[0].eye.getGlobalBounds().width) / 2 - (ball[0].sprite.getPosition().x + ball[0].sprite.getGlobalBounds().width) /2 );
    eye_ball_y = fabs( (player[0].eye.getPosition().y + player[0].eye.getGlobalBounds().height) / 2 - (ball[0].sprite.getPosition().y + ball[0].sprite.getGlobalBounds().height) /2 );
    eye_ball = sqrt((pow(eye_ball_x, 2) + pow(eye_ball_y, 2)));
    ballSIN =  eye_ball_x / eye_ball;
    ballCOS = eye_ball_y / eye_ball;
    player[0].setPupil(ballSIN, ballCOS);

    eye_ball_x = fabs( (player[1].eye.getPosition().x - player[1].eye.getGlobalBounds().width) / 2 - (ball[0].sprite.getPosition().x + ball[0].sprite.getGlobalBounds().width) /2 );
    eye_ball_y = fabs( (player[1].eye.getPosition().y - player[1].eye.getGlobalBounds().height) / 2 - (ball[0].sprite.getPosition().y + ball[0].sprite.getGlobalBounds().height) /2 );
    eye_ball = sqrt((pow(eye_ball_x, 2) + pow(eye_ball_y, 2)));
    ballSIN =  eye_ball_x / eye_ball;
    ballCOS = eye_ball_y / eye_ball;
    player[1].setPupil(ballSIN, ballCOS);
}
void Volleyball::moveBall()
{
    for(int x = 0; x < 2; x++)
    {
        if(globalGame->onCollision(player[x].head.getGlobalBounds(), ball[0].sprite.getGlobalBounds()))
        {
            ballMid = ball[0].sprite.getPosition().y + (ball[0].sprite.getGlobalBounds().height / 2);
            playerMid = player[x].head.getPosition().y + (player[x].head.getGlobalBounds().height / 2);
            ball[0].velocity.y -= 15;
        }
    }
    ball[0].move();
}

void Volleyball::moving()
{
    for(int i = 0; i < playersAmount; i++)
    {
        if(sf::Keyboard::isKeyPressed(player[i].Left) && sf::Keyboard::isKeyPressed(player[i].Right))
            player[i].velocity.x = 0;
        else if(sf::Keyboard::isKeyPressed(player[i].Left))
        {
            player[i].velocity.x = -player[i].moveSpeed * globalGame->timeStep;
        }

        else if(sf::Keyboard::isKeyPressed(player[i].Right))
        {
            player[i].velocity.x = player[i].moveSpeed * globalGame->timeStep;
        }

        if(!sf::Keyboard::isKeyPressed(player[i].Left) && !sf::Keyboard::isKeyPressed(player[i].Right))
            player[i].velocity.x = 0;

        if(sf::Keyboard::isKeyPressed(player[i].Up) && player[i].jumpingAvailable)
            player[i].velocity.y = -player[i].jumpSpeed * globalGame->timeStep;

        player[i].move();
        if(globalGame->onCollision(player[i].head.getGlobalBounds(), Net.getGlobalBounds()))
            player[i].back();
    }
}

void Volleyball::checkEvent(sf::Event event)
{
    if(event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Escape)
        {
            delete globalGame->State;
            globalGame->State = new Menu;
        }
    }
}
void Volleyball::draw()
{
    globalGame->window.clear();
    globalGame->window.draw(background.sprite);
    player[0].draw();
    player[1].draw();
    globalGame->window.draw(ball[0].sprite);
    globalGame->window.draw(Net);
    globalGame->window.display();
}
void Volleyball::checkActions()
{
    moving();
    moveBall();
    setPupils();
}
