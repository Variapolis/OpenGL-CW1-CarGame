#include "Obstacle.h"

Obstacle::Obstacle(GLfloat x, GLfloat y, GLfloat width, GLfloat height) :GameObject(x,y,width,height)
{
}

void Obstacle::Draw() // Draw function inside the rectangle class creates a triangle strip with 4 vertices based on the position and size variables.
{
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f((_posX - _width), (_posY - _height));
	glVertex2f((_posX + _width), (_posY - _height));
	glVertex2f((_posX - _width), (_posY + _height));
	glVertex2f((_posX + _width), (_posY + _height));
	glEnd();
	glFlush();
}

void Obstacle::SetColor()
{
	
}