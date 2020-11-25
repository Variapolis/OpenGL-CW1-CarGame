#pragma once
#include "Rect.h"
#include "PlayerCar.h"
class EndGate :
    public Rect
{
public:
	EndGate(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
	bool CheckCollision(PlayerCar* player, int score, GLfloat startX, GLfloat startY);
};

