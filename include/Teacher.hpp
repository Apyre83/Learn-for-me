#ifndef LEARN_FOR_ME_TEACHER_HPP
#define LEARN_FOR_ME_TEACHER_HPP


#include "learn-for-me.h"

class Teacher {
public:
	Teacher(int nbCellX, int nbCellY, const int size, int sizeCellX, int sizeCellY, sf::Texture &texture): nbCellX(nbCellX), nbCellY(nbCellY), size(size) {
		shape.setSize(sf::Vector2f(size, size));
		shape.setTexture(&texture);
		x = nbCellX * sizeCellX + (sizeCellX - size) / 2;
		y = nbCellY * sizeCellY + (sizeCellY - size) / 2;
	}
	~Teacher() = default;


	void move();
	void draw(sf::RenderWindow& window) {
		shape.setPosition({x, y});
		window.draw(shape);
	}
	
private:
	float               x = 0;
	float               y = 0;
	int					nbCellX;
	int					nbCellY;
	float               speed = 10.0f;
	unsigned int        size;

	bool                isMoving = false;

	sf::RectangleShape  shape;
};



#endif //LEARN_FOR_ME_TEACHER_HPP
