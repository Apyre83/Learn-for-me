#ifndef LEARN_FOR_ME_PLAYER_HPP
#define LEARN_FOR_ME_PLAYER_HPP

#include "learn-for-me.h"

class Player {
public:
    Player(const int size_, sf::Texture &texture) : size(size_) {
        shape.setSize(sf::Vector2f(size, size));
		shape.setTexture(&texture);
    }
    ~Player() = default;


    void move();
    void draw(sf::RenderWindow& window) {
        shape.setPosition({x, y});
        window.draw(shape);
    }
    void update(sf::Vector2u mapSize, float dt, std::vector<Student> &students, std::vector<Desk> &desks);

private:
    float               x = 0;
    float               y = 0;
    float               speed = 10.0f;
    unsigned int        size;

    bool                isMoving = false;

    sf::RectangleShape  shape;
};


#endif //LEARN_FOR_ME_PLAYER_HPP
