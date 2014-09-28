#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include "gameState.h"

class Menu : public gameState
{
public:
    Menu();
    ~Menu();
protected:
    int textAmount;
    sf::Text *text;
    sf::Font font;
    bool mouseCollision();
    void setPositions();
    float textSpace;
    float textHeight;
    float textY;
    virtual void draw();
    virtual void checkEvent(sf::Event event);
    virtual void checkActions();
};

#endif // MENU_H
