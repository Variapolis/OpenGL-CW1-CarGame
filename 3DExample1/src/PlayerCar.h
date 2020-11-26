#pragma once
#include "Rect.h" //Player car used to represent the player, check collisions with the border and obstacles and contain score.
class PlayerCar :
    public Rect
{
	int _score;
	bool _hasWon;
public:
	GLfloat _speed;
	PlayerCar(GLfloat speed, int startScore, GLfloat x, GLfloat y, GLfloat width, GLfloat height);
	PlayerCar(GLfloat speed, int startScore);
	void CheckCollision(GameObject* obstacle, int score);
	void CheckBoundsCollision(GameObject* obstacle, GLfloat startX, GLfloat startY);
	void HandleCollision(GameObject* obstacle);
	void Rotate();
	void AddScore(int score);
	int GetScore();
};

