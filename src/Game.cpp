#include "Game.h"

Game* globalGame;

float Game::scale(float x)
{
	return x * scaling_variable;
}

float Game::average(float x, float y)
{
    return (x - y) / 2.f;
}

Game::Game()
{
    sf::VideoMode videoMode;
    videoMode.getFullscreenModes();
    window.create(sf::VideoMode::getDesktopMode(), "Gra", sf::Style::Fullscreen);
    //window.setFramerateLimit(60);

    setScale_Variable();
    globalGame = this;
    clock.restart();

    State = new Volleyball;
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


bool Game::onMouseOver(sf::Sprite &sprite)
{
    sf::FloatRect rect = sprite.getGlobalBounds();
    return rect.contains(State->mouse.getPosition().x,State->mouse.getPosition().y);
}

bool Game::onMouseOver(sf::Text &text)
{
    sf::FloatRect rect = text.getGlobalBounds();
    return rect.contains(State->mouse.getPosition().x,State->mouse.getPosition().y);
}

bool Game::onCollision(sf::Sprite &sprite1, sf::Sprite &sprite2)
{
    sf::FloatRect rect1 = sprite1.getGlobalBounds();
    sf::FloatRect rect2 = sprite2.getGlobalBounds();
    return rect1.intersects(rect2);
}

void Game::Run()
{
    while(window.isOpen())
    {
        do{
            delta = clock.getElapsedTime().asSeconds();
        }while(delta < 0.016f);
        if(delta > 0.016f)
            delta = 0.016f;
        clock.restart();
        State->draw();
        while(window.pollEvent(event))
            State->checkEvent(event);
        State->checkActions();
    }
}
