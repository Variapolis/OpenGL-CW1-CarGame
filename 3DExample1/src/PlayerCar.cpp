#include "PlayerCar.h"

#include <iostream>

PlayerCar::PlayerCar(GLfloat speed, GLfloat x, GLfloat y, GLfloat width, GLfloat height) : Rect(x, y, width, height), _speed(speed)
{
	
}

PlayerCar::PlayerCar(GLfloat speed) : Rect(), _speed(speed)
{
	
}

void PlayerCar::CheckCollision(GameObject* obstacle)
{
	bool isColliding = false;
	
	if((_posX + _width)> obstacle->getPosX() - obstacle->getWidth() && _posX - _width < obstacle->getPosX() + obstacle->getWidth())
	{
		if(_posY + _height > obstacle->getPosY() - obstacle->getHeight() && _posY - _height < obstacle->getPosY() + obstacle->getHeight())
		{
			std::cout << "collide" << std::endl;
		}
	}
}

void PlayerCar::Rotate()
{
	GLfloat temp = _width;
	_width = _height;
	_height = temp;
}