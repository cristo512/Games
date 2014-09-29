#include "drawText.h"
#include "Game.h"

drawText::drawText()
{
    font.loadFromFile("C:\\Windows\\Fonts\\MTCORSVA.ttf");
    textAmount = 0;
}

drawText::~drawText()
{
    //dtor
}

void drawText::addText(std::string str)
{
    text.push_back(sf::Text());
    textAmount++;
    text[textAmount-1].setString(str);
    text[textAmount-1].setFont(font);
    text[textAmount-1].setColor(sf::Color::White);
}

void drawText::setTextSpace(int space)
{
    textSpace = globalGame->scale(100.f);
}

void drawText::setCharakterSize(int size)
{
    for(int i = 0; i < textAmount; i++)
    {
        text[i].setCharacterSize(size);
        text[i].setScale(globalGame->scaling_variable, globalGame->scaling_variable);
    }
}


void drawText::create()
{
    textHeight = textAmount * text[0].getGlobalBounds().height + (textAmount - 1) * textSpace;
    textY = globalGame->average(globalGame->window.getSize().y, textHeight);

    for(int i = 0; i < textAmount; i++)
    {
        text[i].setPosition(globalGame->average(globalGame->window.getSize().x, text[i].getGlobalBounds().width),
                            textY + i * (text[0].getGlobalBounds().height + textSpace));
    }
}
float drawText::getWidth(int tab)
{
    return text[tab].getGlobalBounds().width;
}

float drawText::getHeight(int tab)
{
    return text[tab].getGlobalBounds().height;
}

float drawText::getX(int tab)
{
    return text[tab].getPosition().x;
}
float drawText::getY(int tab)
{
    return text[tab].getPosition().y;
}
void drawText::changePosition(int tab, float x, float y)
{
    text[tab].setPosition(x, y);
}

void drawText::draw()
{
    for(int i = 0; i < textAmount ; i++)
        globalGame->window.draw(text[i]);
}
