#pragma once
#include "GameObject.h"
class Obstacle :  public GameObject
{
public:
	Obstacle(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
	void Draw();
	void SetColor();
};

