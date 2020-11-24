#include "PlayerCar.h"

#include <iostream>

PlayerCar::PlayerCar(GLfloat speed, GLfloat x, GLfloat y, GLfloat width, GLfloat height)
: Rect(x, y, width, height), _speed(speed)
{
	
}

PlayerCar::PlayerCar(GLfloat speed) : Rect(), _speed(speed)
{
	
}

void PlayerCar::CheckCollision(GameObject* obstacle)
{
	bool isColliding = false;
	GLfloat xMinCar = _posX - (_width);
	GLfloat yMinCar = _posY - (_height);
	GLfloat xMinObs = obstacle->getPosX() - obstacle->getWidth();
	GLfloat yMinObs = obstacle->getPosY() - obstacle->getHeight();
	GLfloat widthObs= obstacle->getWidth();
	GLfloat heightObs = obstacle->getHeight();
	
	
	if((xMinCar + _width*2)> xMinObs && xMinCar < xMinObs + (widthObs*2))
	{
		if(yMinCar + _height*2 > yMinObs && yMinCar < yMinObs + (heightObs *2))
		{
			HandleCollision(obstacle);
		}
	}
}

void PlayerCar::HandleCollision(GameObject* obstacle)
{
	bool vertical = (_width < _height);
			if (abs((_posX)-obstacle->getPosX()) > abs((_posY)-obstacle->getPosY()))
			{
				if (_posX > obstacle->getPosX()) { _posX += 6; }
				else { _posX -= 6; }
			}
			else
			{
				if (_posY > obstacle->getPosY()) { _posY += 6; }
				else { _posY -= 6; }
			}
	Log("Collided with obstacle.");
	
}
void PlayerCar::Rotate()
{
	GLfloat temp = _width;
	_width = _height;
	_height = temp;
}
