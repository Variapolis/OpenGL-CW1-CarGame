#pragma once
#include "GameObject.h"
class Boundary :
    public GameObject
{
public:

	Boundary(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
	void Draw(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
};

