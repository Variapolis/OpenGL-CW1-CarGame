#include "Boundary.h"

#include "EndGate.h"

Boundary::Boundary(GLfloat x, GLfloat y, GLfloat width, GLfloat height) :GameObject(x, y, width, height)
{
	
}

void Boundary::Draw(GLfloat r, GLfloat g, GLfloat b, GLfloat a) // Draw function inside the rectangle class creates a triangle strip with 4 vertices based on the position and size variables.
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
