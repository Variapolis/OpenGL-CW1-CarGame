#include "EndGate.h"


EndGate::EndGate(GLfloat x, GLfloat y, GLfloat width, GLfloat height) :Rect(x, y, width, height)
{
}


bool EndGate::CheckCollision(PlayerCar* player, int score,GLfloat startX, GLfloat startY)
{
	bool isColliding = false;
	GLfloat xMinCar = _posX - (_width);
	GLfloat yMinCar = _posY - (_height);
	GLfloat xMinObs = player->getPosX() - player->getWidth();
	GLfloat yMinObs = player->getPosY() - player->getHeight();
	GLfloat widthObs = player->getWidth();
	GLfloat heightObs = player->getHeight();


	if ((xMinCar + _width * 2) > xMinObs && xMinCar < xMinObs + (widthObs * 2))
	{
		if (yMinCar + _height * 2 > yMinObs && yMinCar < yMinObs + (heightObs * 2))
		{
			player->MoveTo(startX,startY);
			Log("Player reached End Gate.");
			player->AddScore(score);
			LogIntValue("Player won and gained: ", score, " points!");
			LogIntValue("Current score: ", player->GetScore(), " Points");
			return true;
		}
	}
	return false;
}