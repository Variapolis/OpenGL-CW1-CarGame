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
// Checks collision by comparing the aMin x/y and bMin x/y against each other in a AABB format.
{
	bool isColliding = false;
	GLfloat xMinCar = _posX - (_width);
	GLfloat yMinCar = _posY - (_height);
	GLfloat xMinObs = obstacle->getPosX() - obstacle->getWidth();
	GLfloat yMinObs = obstacle->getPosY() - obstacle->getHeight();
	GLfloat widthObs= obstacle->getWidth();
	GLfloat heightObs = obstacle->getHeight();
	//Essentially checks if the player is inside the range of the obstacle on TWO axes. If it is not within range on both axes, it is not colliding.
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
// Checks collision by comparing the aMin x/y and bMin x/y against each other in a REVERSED AABB format.
{
	bool isColliding = false;
	GLfloat xMinCar = _posX - (_width);
	GLfloat yMinCar = _posY - (_height);
	GLfloat xMinObs = obstacle->getPosX() - obstacle->getWidth();
	GLfloat yMinObs = obstacle->getPosY() - obstacle->getHeight();
	GLfloat widthObs = obstacle->getWidth();
	GLfloat heightObs = obstacle->getHeight();
	if (xMinCar < xMinObs || xMinCar + _width * 2 > xMinObs + widthObs*2 || yMinCar < yMinObs || yMinCar + _height * 2 > yMinObs + (heightObs * 2))
		//Essentially checks if the player is outside the range of the border on ANY axis. If it is not within range on atleast one axis, it is colliding.
	{
		LogIntValue("xMinCar", xMinCar);
		LogIntValue("xMinObs", xMinObs);
		MoveTo(startX, startY);
		Log("Player has been returned within bounds.");
	}
}

void PlayerCar::HandleCollision(GameObject* obstacle) // Handles the collision, essentially determines whether the object is above or below, then left or right.
{
	bool vertical = (_width < _height); // Top/Side determinant is not flawless and some slipping can be seen.
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


void PlayerCar::Rotate() //Swaps the width and height values to "rotate" by 90 degrees.
{
	GLfloat temp = _width;
	_width = _height;
	_height = temp;
}

void PlayerCar::AddScore(int score) // Adds an amount to the private _score variable.
{
	_score += score;
}

int PlayerCar::GetScore(){	return _score; } // Gets player's score
