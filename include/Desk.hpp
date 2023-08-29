#ifndef LEARN_FOR_ME_DESK_HPP
#define LEARN_FOR_ME_DESK_HPP


#include "learn-for-me.h"

class Desk {

public:
	Desk(int nbCellX, int nbCellY, const int size, int sizeCellX, int sizeCellY): nbCellX(nbCellX), nbCellY(nbCellY), size(size) {
		shape.setSize(sf::Vector2f(size, size));
		shape.setFillColor(sf::Color::Blue);
		x = nbCellX * sizeCellX + (sizeCellX - size) / 2;
		y = nbCellY * sizeCellY + (sizeCellY - size) / 2;
	}
	~Desk() = default;

	void move();
	void draw(sf::RenderWindow& window) {
		shape.setPosition({x, y});
		window.draw(shape);

		if (student != nullptr) {
			student->draw(window);
		}
	}

	float getX() const { return x; }
	float getY() const { return y; }
	unsigned int getSize() const { return size; }

	void setX(float x) { this->x = x; }
	void setY(float y) { this->y = y; }

	void	setStudent(Student *student) {
		this->student = student;
		this->student->setX(x);
		this->student->setY(y + size);

	}


private:
    float               x;
    float               y;
	int					nbCellX;
	int					nbCellY;
    float               speed = 0.5f;
    unsigned int        size;

    sf::RectangleShape  shape;

	Student				*student = nullptr;
};


#endif //LEARN_FOR_ME_DESK_HPP
