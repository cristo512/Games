#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SFML/Graphics.hpp>
class Background
{
public:
    Background();
    virtual ~Background();
    sf::Sprite sprite;
    void setTexture(sf::Texture &texture);
protected:
};

#endif // BACKGROUND_H
