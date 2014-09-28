#include "Volleyball.h"

void Volleyball::addPlayers()
{
    playersAmount = 1;
    player = new Player [playersAmount];
    for (int i = 0; i < playersAmount ; i++)
    {
        player[i].moveSpeed = 800.f;
        player[i].jumpSpeed = 1000.f;
        player[i].setTextures(globalGame->headTexture, globalGame->eyeTexture, globalGame->pupilTexture);
    }
    player[0].setLookTexture(globalGame->looksTexture_1);
    player[0].setShoesTexture(globalGame->shoesTexture_1);
    player[0].setKeys(sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::D);
    //player[0].spritesSetPosition(globalGame->window.getSize().x / 5, globalGame->window.getSize().y - player[0].playerHeight);
    //player[1].setKeys(sf::Keyboard::Left, sf::Keyboard::Up, sf::Keyboard::Right);
    //player[1].sprite.setScale(-player[1].sprite.getScale().x, player[1].sprite.getScale().y);
    //player[1].sprite.setPosition((4 * globalGame->window.getSize().x) / 5, globalGame->window.getSize().y - player[1].sprite.getGlobalBounds().height);
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
        if(globalGame->onCollision(player[i].head, Net))
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
    globalGame->window.draw(ball[0].sprite);
    globalGame->window.draw(Net);
    globalGame->window.display();
}
void Volleyball::checkActions()
{
    moving();
}
