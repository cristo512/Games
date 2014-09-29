#ifndef DRAWTEXT_H
#define DRAWTEXT_H
#include <SFML/Graphics.hpp>
#include <vector>

class drawText
{
public:
    drawText();
    virtual ~drawText();

    sf::Font font;
    std::vector<sf::Text> text;
    int textAmount;
    float textSpace;
    float textHeight;
    float textY;
    void changePosition(int tab, float x, float y);
    float getWidth(int tab);
    float getHeight(int tab);
    float getX(int tab);
    float getY(int tab);
    void setPositions();
    void addText(std::string str);
    void setTextSpace(int space);
    void setCharakterSize(int size);
    void create();
    void draw();
};

#endif // DRAWTEXT_H
