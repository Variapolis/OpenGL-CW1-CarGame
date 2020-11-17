#pragma once
#include "freeglut.h"

class rectangle
{
	GLfloat _posX, _posY, _width, _height;
public:
	rectangle(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
	rectangle(GLfloat x, GLfloat y);
	rectangle();
	void Draw();
};

