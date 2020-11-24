#pragma once
#include "GameObject.h"
class Rect :
    public GameObject
{
	GLfloat _red, _green, _blue;
public:
	Rect(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
	Rect(GLfloat x, GLfloat y);
	Rect();
	void Draw();
	void SetColor(GLfloat red, GLfloat green, GLfloat blue);
};

