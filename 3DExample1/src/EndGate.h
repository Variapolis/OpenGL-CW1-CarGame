#pragma once
#include "Rect.h"
class EndGate :
    public Rect
{
public:
	EndGate(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
	void CheckCollision(GameObject* player, GLfloat startX, GLfloat startY);
};

