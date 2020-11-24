#include "Rect.h"

Rect::Rect(GLfloat x, GLfloat y, GLfloat width, GLfloat height) :GameObject(x, y, width, height)
{
	GLfloat red = 1, green = 1, blue = 1;
}

Rect::Rect(GLfloat x, GLfloat y) : GameObject(x, y)
{
	GLfloat _red = 1, _green = 1, _blue = 1;
}

Rect::Rect():GameObject()
{
	GLfloat _red = 1, _green = 1, _blue = 1;
}

void Rect::Draw() // Draw function inside the rectangle class creates a triangle strip with 4 vertices based on the position and size variables.
{
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(_red, _green, _blue);
	glVertex2f((_posX - _width), (_posY - _height));
	glVertex2f((_posX + _width), (_posY - _height));
	glVertex2f((_posX + _width), (_posY + _height));
	glVertex2f((_posX - _width), (_posY + _height));
	glEnd();
	glFlush();
	glPopMatrix();
}

void Rect::SetColor(GLfloat red, GLfloat green, GLfloat blue)
{
	_red = red;
	_green = green;
	_blue = blue;
}