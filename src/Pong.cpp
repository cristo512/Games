#include "Pong.h"
#include <cstdlib>
#include <cmath>

void Pong::setInstructions()
{
    instructions.addText("Poruszanie: ");
    instructions.addText("Player 1: W i S");
    instructions.addText("Player 2: Stra³ka w górê i Strza³ka w dó³");
    instructions.addText(" ");
    instructions.addText("Wygrywa ten kto pierwszy zdobêdzie");
    instructions.addText("12 punktów.");
    instructions.addText("Wcisnij Enter aby przejsc dalej");

    instructions.setTextSpace(60);
    instructions.setCharakterSize(90);
    instructions.create();

    instructions.changePosition(6, globalGame->window.getSize().x - instructions.getWidth(6), instructions.getY(6));

    isInstruction = true;
}

void Pong::addPlayers()
{
    player = new squarePlayer [2];

    player[0].shape.setPosition(0, globalGame->average(globalGame->window.getSize().y, player[0].shape.getGlobalBounds().height));
    player[1].shape.setPosition(globalGame->window.getSize().x - player[1].shape.getGlobalBounds().width, globalGame->average(globalGame->window.getSize().y, player[0].shape.getGlobalBounds().height));
    player[0].setKeys(sf::Keyboard::W, sf::Keyboard::S);
    player[1].setKeys(sf::Keyboard::Up, sf::Keyboard::Down);
}

void Pong::addBall()
{
    ball.push_back(ballExample);
    ballSpeed.push_back(1000.f);
    ballDirection.push_back(1);
    ballAmount++;
    ballVelocity.push_back(sf::Vector2f(0 , (rand()%10)-5));
    ballVelocity[ballAmount-1].x = sqrt( pow(ballSpeed[ballAmount-1] * globalGame->timeStep, 2) - pow(ballVelocity[ballAmount-1].y, 2) );
}
void Pong::deleteBall(int tab)
{
    ball.erase(ball.begin()+tab);
    ballAmount--;
    ballDirection.erase(ballDirection.begin()+tab);
    ballVelocity.erase(ballVelocity.begin()+tab);
}

Pong::Pong()
{
    ballExample.setRadius(15);
    ballExample.setPosition(globalGame->average(globalGame->window.getSize().x, ballExample.getGlobalBounds().width),
                            globalGame->average(globalGame->window.getSize().y, ballExample.getGlobalBounds().height));
    ballExample.setFillColor(sf::Color::Yellow);
    ballAmount = 0;
    addPlayers();
    addBall();
    setInstructions();
}

Pong::~Pong()
{
    //dtor
}

void Pong::moveBalls()
{
    for(int i = 0; i < ballAmount; i++)
    {
        if(ball[i].getPosition().y < 0 || ball[i].getPosition().y + ball[i].getGlobalBounds().height > globalGame->window.getSize().y)
            ballVelocity[i].y *= -1;

        for(int x = 0; x < 2; x++)
        {
            if(globalGame->onCollision(player[x].shape.getGlobalBounds(), ball[i].getGlobalBounds()))
            {
                ballMid = ball[i].getPosition().y + (ball[i].getGlobalBounds().height / 2);
                playerMid = player[x].shape.getPosition().y + (player[x].shape.getGlobalBounds().height / 2);
                ballVelocity[i].y = (ballMid - playerMid) / ((player[x].shape.getGlobalBounds().height / 2) / 10);
                if(ballSpeed[i] < 2600.f  && ballSpeed[i] > -2600.f)
                {
                    ballSpeed[i] +=  50 + rand()%50;
                    ballDirection[i] *= -1;
                }
                else
                    ballDirection[i] *= -1;
            }
        }

        ballVelocity[i].x = sqrt( pow(ballSpeed[i] * globalGame->timeStep, 2) - pow(ballVelocity[i].y, 2) ) * ballDirection[i];

        ball[i].move(ballVelocity[i].x, ballVelocity[i].y);
        if(ball[i].getPosition().x + ball[i].getGlobalBounds().width < 0 || ball[i].getPosition().x > globalGame->window.getSize().x)
        {
            deleteBall(i);
            addBall();
        }
    }
}

void Pong::movePlayers()
{
    for(int i = 0; i < 2; i++)
    {
        if(sf::Keyboard::isKeyPressed(player[i].Up) && !sf::Keyboard::isKeyPressed(player[i].Down))
        {
            player[i].moveUp();
            if(player[i].shape.getPosition().y < 0)
                player[i].shape.setPosition(player[i].shape.getPosition().x, 0);
        }
        else if(sf::Keyboard::isKeyPressed(player[i].Down) && !sf::Keyboard::isKeyPressed(player[i].Up))
        {
            player[i].moveDown();
            if(player[i].shape.getPosition().y + player[i].shape.getGlobalBounds().height > globalGame->window.getSize().y)
                player[i].shape.setPosition(player[i].shape.getPosition().x, globalGame->window.getSize().y - player[i].shape.getGlobalBounds().height);
        }
    }
}

void Pong::checkEvent(sf::Event event)
{
    if (event.type == sf::Event::Closed)
        globalGame->window.close();
    if(event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Escape)
        {
            delete globalGame->State;
            globalGame->State = new Menu;
        }
    }
}

void Pong::draw()
{
    globalGame->window.clear();
    if(isInstruction)
        instructions.draw();
    else
    {
        for(int i = 0; i < ballAmount ; i++)
            globalGame->window.draw(ball[i]);
        globalGame->window.draw(player[0].shape);
        globalGame->window.draw(player[1].shape);
    }
    globalGame->window.display();
}

void Pong::checkActions()
{
    if(!isInstruction)
    {
        moveBalls();
        movePlayers();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::K))
            addBall();
    }
    else
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
            isInstruction = false;
    }
}
