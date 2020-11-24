#include "Spawner.h"

Spawner::Spawner(GLfloat x, GLfloat y, GLfloat width, GLfloat height):GameObject(x,y,width,height)
{
}

Spawner::Spawner():GameObject()
{
}

void Spawner::DebugDraw(GLfloat r, GLfloat g, GLfloat b, GLfloat a) // Draw function inside the rectangle class creates a triangle strip with 4 vertices based on the position and size variables.
{
	glPushAttrib(GL_CURRENT_BIT);
	glBegin(GL_LINE_LOOP);
	glColor4f(r, g, b, a);
	glVertex2f((_posX - _width), (_posY - _height));
	glVertex2f((_posX + _width), (_posY - _height));
	glVertex2f((_posX + _width), (_posY + _height));
	glVertex2f((_posX - _width), (_posY + _height));
	glEnd();
	glPopAttrib();
	glFlush();
}

void Spawner::Draw() // Draws all of the spawned obstacles.
{
	for(int i = 0; i < obstacles.size(); i++)
	{
		glPushAttrib(GL_CURRENT_BIT);
		glPushMatrix();
		obstacles[i]->Draw();
		glPopMatrix();
		glPopAttrib();
		glColor3f(1, 1, 1);
	}
}

int Spawner::GetRandBounds(int upper) // Generates a number within the range of the bounds of the spawner.
{
	int bound = (rand() % (upper*2)) - upper;
	return bound;
}

void Spawner::Spawn(int amount, GLfloat width, GLfloat height)
{
	int count = 0;
	while(count != amount){
	bool isBlocked = false;
	GLfloat spawnX = GetRandBounds(_width);
	GLfloat spawnY = GetRandBounds(_height);
		for (int i = 0; i < amount; i++) // Loop spawns the specified amount of Obstacle class instances at specified size.
		{
			if (!(obstacles.empty()))
			{
				for (auto i : obstacles)
				{
					if (CheckSpawn(i, spawnX, spawnY, width, height)) { isBlocked = true; break; }
				}
			}
			if (!isBlocked) { obstacles.push_back(new Obstacle(spawnX, spawnY, width, height)); count++; }
			obstacles.back()->SetColor((GLfloat)rand() * (1.0) / (GLfloat)RAND_MAX, (GLfloat)rand() * (1.0 - 0.5) / (GLfloat)RAND_MAX, (GLfloat)rand() * (1.0 - 0.5) / (GLfloat)RAND_MAX);
		}	
	}
}

void Spawner::Spawn(GLfloat width, GLfloat height) // Spawns a single obstacle at the specified size.
{
	bool isBlocked = true;
	bool hasSpawned = false;
	GLfloat spawnX = GetRandBounds(_width);
	GLfloat spawnY = GetRandBounds(_height);
	while (!hasSpawned)
	{
		if (!(obstacles.empty()))
		{
			for (int i = 0; i < obstacles.size(); i++)
			{
				isBlocked = CheckSpawn(obstacles[i], spawnX, spawnY, width, height);
				if (isBlocked) { break; }
			}
		}
		if (!isBlocked) { obstacles.push_back(new Obstacle(spawnX, spawnY, width, height)); hasSpawned = true; }
		obstacles.back()->SetColor((GLfloat)rand() * (1.0) / (GLfloat)RAND_MAX + 0.1, (GLfloat)rand() * (1.0 - 0.5) / (GLfloat)RAND_MAX, (GLfloat)rand() * (1.0 - 0.5) / (GLfloat)RAND_MAX);

	}
}

bool Spawner::CheckSpawn(GameObject* obstacle, GLfloat posX, GLfloat posY, GLfloat width, GLfloat height)
{
	bool isColliding = false;
	GLfloat xMinNew = posX - (width);
	GLfloat yMinNew = posY - (height);
	GLfloat xMinObs = obstacle->getPosX() - obstacle->getWidth();
	GLfloat yMinObs = obstacle->getPosY() - obstacle->getHeight();
	GLfloat widthObs = obstacle->getWidth();
	GLfloat heightObs = obstacle->getHeight();


	if (((xMinNew + width * 2) > xMinObs && xMinNew < xMinObs + (widthObs * 2)))
	{
		if ((yMinNew + height * 2 > yMinObs && yMinNew < yMinObs + (heightObs * 2)))
		{
			return true; // true means collision
		}
	}
	return false;
}
