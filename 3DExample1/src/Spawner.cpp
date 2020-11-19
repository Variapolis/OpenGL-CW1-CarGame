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

void Spawner::Draw()
{
	for(int i = 0; i < obstacles.size(); i++)
	{
		glPushMatrix();
		obstacles[i]->Draw();
		glPopMatrix();
	}
}

int Spawner::GetRandBounds(int upper) // Generates a number within the range of the bounds of the spawner.
{
	int bound = (rand() % (upper*2)) - upper;
	return bound;
}

void Spawner::Spawn(int amount, GLfloat width, GLfloat height)
{
	for (int i = 0; i < amount; i++) // Loop spawns the specified amount of Obstacle class instances at specified size.
	{
		obstacles.push_back(new Obstacle(GetRandBounds(_width), GetRandBounds(_height), width, height));
	}
}

void Spawner::Spawn(GLfloat width, GLfloat height) // Spawns a single obstacle at the 
{
	obstacles.push_back(new Obstacle(GetRandBounds(_width), GetRandBounds(_height), width, height));
}


void Spawner::Spawn() // Spawns a single Obstacle class.
{
		obstacles.push_back(new Obstacle(GetRandBounds(_width), GetRandBounds(_height)));
}

