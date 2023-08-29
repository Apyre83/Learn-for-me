
#ifndef LEARN_FOR_ME_STUDENT_HPP
#define LEARN_FOR_ME_STUDENT_HPP


#include "learn-for-me.h"

class Student {
public:
	Student(int nbCellX, int nbCellY, const int size, int sizeCellX, int sizeCellY, sf::Texture &texture): nbCellX(nbCellX), nbCellY(nbCellY), size(size) {
		shape.setSize(sf::Vector2f(size, size));
		shape.setTexture(&texture);
		x = nbCellX * sizeCellX + (sizeCellX - size) / 2;
		y = nbCellY * sizeCellY + (sizeCellY - size) / 2;
	}
	~Student() = default;

	void move();
	void draw(sf::RenderWindow& window) {
		shape.setPosition({x, y});
		window.draw(shape);
	}
	void update(sf::Vector2u mapSize, float dt);

	float getX() const { return x; }
	float getY() const { return y; }
	unsigned int getSize() const { return size; }

	void setX(float x) { this->x = x; }
	void setY(float y) { this->y = y; }
	
private:
    float               x;
    float               y;
	int					nbCellX;
	int					nbCellY;
    float               speed = 0.5f;
    unsigned int        size;

    sf::RectangleShape  shape;
};


#endif //LEARN_FOR_ME_STUDENT_HPP

