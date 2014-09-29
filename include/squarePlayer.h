#ifndef SQUAREPLAYER_H
#define SQUAREPLAYER_H
#include <SFML/Graphics.hpp>

class squarePlayer
{
public:
    squarePlayer();
    virtual ~squarePlayer();
    sf::RectangleShape shape;
    sf::Keyboard::Key Up;
    sf::Keyboard::Key Down;
    void setKeys(sf::Keyboard::Key Up, sf::Keyboard::Key Down);
    void moveUp();
    void moveDown();
    float speed;
    int points;
private:
};

#endif // SQUAREPLAYER_H
