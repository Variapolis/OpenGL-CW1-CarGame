#pragma once
#include "Rect.h"
class PlayerCar :
    public Rect
{
public:
	GLfloat _speed;
	PlayerCar(GLfloat speed, GLfloat x, GLfloat y, GLfloat width, GLfloat height);
	PlayerCar(GLfloat speed);
	void CheckCollision(GameObject* obstacle);
	void Rotate();
};

