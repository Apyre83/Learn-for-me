#include "learn-for-me.h"


bool checkOverlap(const sf::Rect<float>& playerRect, const std::vector<sf::Rect<float>>& objectRects) {
    for (const auto& objectRect : objectRects) {
        if (playerRect.findIntersection(objectRect)) {
            return true;
        }
    }
    return false;
}


void Player::update(sf::Vector2u mapSize, float dt, std::vector<Student> &students, std::vector<Desk> &desks) {
	(void) mapSize;
    float newX = x, newY = y;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        newX -= speed * dt * TIME_FACTOR;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        newX += speed * dt * TIME_FACTOR;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        newY -= speed * dt * TIME_FACTOR;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        newY += speed * dt * TIME_FACTOR;
    }

    std::vector<sf::Rect<float>> studentRects, deskRects;
    for (const auto& student : students) {
        studentRects.push_back({{student.getX() * 1.0f, student.getY() * 1.0f}, {student.getSize() * 1.0f, student.getSize() * 1.0f}});
    }
    for (const auto& desk : desks) {
        deskRects.push_back({{desk.getX() * 1.0f, desk.getY() * 1.0f}, {desk.getSize() * 1.0f, desk.getSize() * 1.0f}});
    }

    sf::Rect<float> playerRect({newX, newY}, {size * 1.0f, size * 1.0f});
    
    bool overlap = checkOverlap(playerRect, studentRects) || checkOverlap(playerRect, deskRects);

    if (!overlap) {
        x = newX;
        y = newY;
        isMoving = true;
    } else {
        // Si collision, vérifiez séparément pour les mouvements en X et Y
        playerRect.left = newX;
        playerRect.top = y;

        overlap = checkOverlap(playerRect, studentRects) || checkOverlap(playerRect, deskRects);

        if (!overlap) {
            x = newX;
            isMoving = true;
        }

        playerRect.left = x;
        playerRect.top = newY;

        overlap = checkOverlap(playerRect, studentRects) || checkOverlap(playerRect, deskRects);

        if (!overlap) {
            y = newY;
            isMoving = true;
        }
    }
}

