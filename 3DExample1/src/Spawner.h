#pragma once
#include "GameObject.h"
#include "Obstacle.h"
#include <vector>

class Spawner : public GameObject
{
public:
	std::vector<Obstacle*> obstacles;
	Spawner(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
	Spawner();
	void DebugDraw(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
	void Draw();
	int GetRandBounds(int upper);
	void Spawn(int amount, GLfloat width, GLfloat height);
	void Spawn(GLfloat width, GLfloat height);
	bool CheckSpawn(GameObject* obstacle, GLfloat posX, GLfloat posY, GLfloat width, GLfloat height);
};

