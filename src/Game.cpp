#include "Game.h"
#include <algorithm>

Game* globalGame;

float Game::scale(float x)
{
	return x * scaling_variable;
}

float Game::average(float x, float y)
{
    return (x - y) / 2.f;
}

void Game::loadTextures()
{
    headTexture.loadFromFile("./data/Player/Head.png");
    eyeTexture.loadFromFile("./data/Player/Eye.png");
    pupilTexture.loadFromFile("./data/Player/Pupil.png");
    looksTexture_1.loadFromFile("./data/Player_1/Looks.png");
    shoesTexture_1.loadFromFile("./data/Player_1/Shoes.png");
    looksTexture_2.loadFromFile("./data/Player_2/Looks.png");
    shoesTexture_2.loadFromFile("./data/Player_2/Shoes.png");
    ballTexture.loadFromFile("./data/Ball.png");
    bgTexture.loadFromFile("./data/Background.png");
    netTexture.loadFromFile("./data/Net.png");
}

Game::Game()
{
    loadTextures();

    sf::VideoMode videoMode;
    videoMode.getFullscreenModes();
    window.create(sf::VideoMode::getDesktopMode(), "Gra", sf::Style::Fullscreen);

    setScale_Variable();
    globalGame = this;
	delta = 0.0f;
	lastUpdateTime = clock.getElapsedTime().asSeconds();
	accumulator = 0.0f;
	clock.restart();

    window.setFramerateLimit(400);
    State = new Menu;
}

void Game::setScale_Variable()
{
	if(window.getSize().x / 1920.f <= window.getSize().y / 1080.f)
        scaling_variable = window.getSize().x / 1920.f;
    else
        scaling_variable = window.getSize().y / 1080.f;
}

Game::~Game()
{
    //dtor
}


bool Game::onMouseOver(sf::FloatRect rect)
{
    return rect.contains(State->mouse.getPosition().x,State->mouse.getPosition().y);
}

bool Game::onCollision(sf::FloatRect rect1, sf::FloatRect rect2)
{
    return rect1.intersects(rect2);
}

float Game::clamp(const float &what, const float& a, const float& b)
{
	return std::min(b, std::max(what, a));
}

bool Game::checkIfReleased()
{
    for(sf::Keyboard::Key key = sf::Keyboard::A; key < sf::Keyboard::KeyCount ;  key = (sf::Keyboard::Key)(((int)key)+1))
    {
        if( isKeyReleased[key] && !sf::Keyboard::isKeyPressed(key))
            isKeyReleased[key] = false;
        else if(!isKeyReleased[key] && !sf::Keyboard::isKeyPressed(key))
            isKeyReleased[key] = true;
        else if( sf::Keyboard::isKeyPressed(key))
            isKeyReleased[key] = false;
    }
}

void Game::Run()
{
    while(window.isOpen())
    {
        delta = clock.getElapsedTime().asSeconds();
        clock.restart();
        delta = std::max(0.f, delta);
        accumulator += delta;
        accumulator = clamp(accumulator, 0, maxAccumulatedTime);
        checkIfReleased();
        while(window.pollEvent(event))
            State->checkEvent(event);
        while(accumulator > timeStep)
        {
            State->checkActions();
            accumulator -= timeStep;
        }
        State->draw();
    }
}
