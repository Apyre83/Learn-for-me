#ifndef LEARN_FOR_ME_PLAYER_HPP
#define LEARN_FOR_ME_PLAYER_HPP

#include "learn-for-me.h"

class Player {
public:
    Player(const int size_ = 10) : size(size_) {
        shape.setSize(sf::Vector2f(size, size));
        shape.setFillColor(sf::Color(255, 128, 0, 255));
    }
    ~Player() = default;


    void move();
    void draw(sf::RenderWindow& window) {
        shape.setPosition({x, y});
        window.draw(shape);
    }
    void update(sf::Vector2u mapSize, int cellSizeX, int cellSizeY, int cellOffsetX, int cellOffsetY);

private:
    float               x = 0;
    float               y = 0;
    float               speed = 0.5f;
    unsigned int        size;

    bool                isMoving = false;

    sf::RectangleShape  shape;
};


#endif //LEARN_FOR_ME_PLAYER_HPP
