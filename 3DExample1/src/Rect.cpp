#include "Rect.h"

Rect::Rect(GLfloat x, GLfloat y, GLfloat width, GLfloat height) :GameObject(x, y, width, height)
{
}

Rect::Rect(GLfloat x, GLfloat y) : GameObject(x, y)
{
}

Rect::Rect():GameObject()
{
}

void Rect::Draw() // Draw function inside the rectangle class creates a triangle strip with 4 vertices based on the position and size variables.
{
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f((_posX - _width), (_posY - _height));
	glVertex2f((_posX + _width), (_posY - _height));
	glVertex2f((_posX - _width), (_posY + _height));
	glVertex2f((_posX + _width), (_posY + _height));
	glEnd();
	glFlush();
}

void Rect::SetColor()
{

}