#pragma once
#include "freeglut.h"

class rectangle
{
	GLfloat _posX, _posY, _width, _height;
public:
	rectangle(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
	rectangle(GLfloat x, GLfloat y);
	rectangle();
	int getPosX(); 	int getPosY();	int getWidth();	int getHeight();
	void Draw();
	void Move(GLfloat x, GLfloat y);
	void Resize(GLfloat width, GLfloat height);
};

