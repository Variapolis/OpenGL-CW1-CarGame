#pragma once
#include "freeglut.h"

class GameObject
{
protected:
	GLfloat _posX, _posY, _width, _height;
public:
	GameObject(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
	GameObject(GLfloat x, GLfloat y);
	GameObject();
	int getPosX(); 	int getPosY();	int getWidth();	int getHeight();
	void Draw();
	void Move(GLfloat x, GLfloat y);
	void MoveTo(GLfloat x, GLfloat y);
	void Resize(GLfloat width, GLfloat height);
	void ResizeWidth(GLfloat width);
	void ResizeHeight(GLfloat height);
};

