#pragma once
#include "GameObject.h"
class Rect :
    public GameObject
{
public:
	Rect(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
	Rect();
	void Draw();
	void SetColor();
};

