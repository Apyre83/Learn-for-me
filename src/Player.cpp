#include "learn-for-me.h"

void    Player::update(sf::Vector2u mapSize, int cellSizeX, int cellSizeY, int cellOffsetX, int cellOffsetY) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && x > speed) {
        x -= speed;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && x < mapSize.x - speed - size) {
        x += speed;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && y > speed) {
        y -= speed;
        isMoving = true;

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && y < mapSize.y - speed - size) {
        y += speed;
        isMoving = true;
    }

    if (!isMoving) /* Go to the closest cell */
    {
        int xCell = std::round(static_cast<float>(x) / cellSizeX);
        int yCell = std::round(static_cast<float>(y) / cellSizeY);

        xCell = std::max(0, std::min(static_cast<int>(mapSize.x / cellSizeX) - 1, xCell));
        yCell = std::max(0, std::min(static_cast<int>(mapSize.y / cellSizeY) - 1, yCell));

        x = xCell * cellSizeX + cellOffsetX * 1.0f + cellSizeX / 2 - size / 2;
        y = yCell * cellSizeY + cellOffsetY * 1.0f + cellSizeY / 2 - size / 2;

        std::cout << "xCell: " << xCell << " " << "yCell: " << yCell << std::endl;
    }
    else
    {
        isMoving = false;
    }
}