#pragma once
#include "Rect.h"
#include "PlayerCar.h"
class EndGate :
    public Rect //Endgate class used to regenerate a new level when player passes through.
{
public:
	EndGate(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
	bool CheckCollision(PlayerCar* player, int score, GLfloat startX, GLfloat startY);
};

