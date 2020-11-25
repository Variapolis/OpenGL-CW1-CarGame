#include "PlayerCar.h"

#include <iostream>

PlayerCar::PlayerCar(GLfloat speed, int startScore, GLfloat x, GLfloat y, GLfloat width, GLfloat height)
: Rect(x, y, width, height), _speed(speed), _score(startScore)
{
	_hasWon = false;
}

PlayerCar::PlayerCar(GLfloat speed, int startScore) : Rect(), _speed(speed), _score(startScore)
{
	_hasWon = false;
}

void PlayerCar::CheckCollision(GameObject* obstacle, int score)
{
	bool isColliding = false;
	GLfloat xMinCar = _posX - (_width);
	GLfloat yMinCar = _posY - (_height);
	GLfloat xMinObs = obstacle->getPosX() - obstacle->getWidth();
	GLfloat yMinObs = obstacle->getPosY() - obstacle->getHeight();
	GLfloat widthObs= obstacle->getWidth();
	GLfloat heightObs = obstacle->getHeight();
	if ((xMinCar + _width * 2) > xMinObs && xMinCar < xMinObs + (widthObs * 2))
	{
		if (yMinCar + _height * 2 > yMinObs && yMinCar < yMinObs + (heightObs * 2))
		{
			HandleCollision(obstacle);
			AddScore(-score);
			LogIntValue("Player crashed and lost: ", score, " points!");
			LogIntValue("Current score: ", GetScore(), " Points");
		}
	}
}

void PlayerCar::CheckBoundsCollision(GameObject* obstacle, GLfloat startX, GLfloat startY)
{
	bool isColliding = false;
	GLfloat xMinCar = _posX - (_width);
	GLfloat yMinCar = _posY - (_height);
	GLfloat xMinObs = obstacle->getPosX() - obstacle->getWidth();
	GLfloat yMinObs = obstacle->getPosY() - obstacle->getHeight();
	GLfloat widthObs = obstacle->getWidth();
	GLfloat heightObs = obstacle->getHeight();
	if (xMinCar < xMinObs || xMinCar + _width * 2 > xMinObs + widthObs*2 || yMinCar < yMinObs || yMinCar + _height * 2 > yMinObs + (heightObs * 2))
	{
		LogIntValue("xMinCar", xMinCar);
		LogIntValue("xMinObs", xMinObs);
		MoveTo(startX, startY);
		Log("Player has been returned within bounds.");
	}
}

void PlayerCar::HandleCollision(GameObject* obstacle)
{
	bool vertical = (_width < _height);
	if (abs((_posX)-obstacle->getPosX()) > abs((_posY)-obstacle->getPosY()))
	{
		if (_posX > obstacle->getPosX()) { _posX += 6; }
		else { _posX -= 6; }
	}
	else
	{
		if (_posY > obstacle->getPosY()) { _posY += 6; }
		else { _posY -= 6; }
	}
	
	Log("Collided with obstacle.");
	
}


void PlayerCar::Rotate()
{
	GLfloat temp = _width;
	_width = _height;
	_height = temp;
}

void PlayerCar::AddScore(int score)
{
	_score += score;
}

int PlayerCar::GetScore(){	return _score; }
