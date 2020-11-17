#include "Rectangle.h"

rectangle::rectangle(GLfloat x, GLfloat y, GLfloat width, GLfloat height):_posX(x), _posY(y), _width(width), _height(height)
{
	
}

rectangle::rectangle(GLfloat x, GLfloat y): _posX(x), _posY(y), _width(1), _height(1)
{
	
}

rectangle::rectangle(): _posX(0), _posY(0), _width(1),_height(1)
{
}

void rectangle::Draw()
{
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f((_posX-_width),(_posY-_height));
	glVertex2f((_posX + _width), (_posY - _height));
	glVertex2f((_posX - _width), (_posY + _height));
	glVertex2f((_posX + _width), (_posY + _height));
	glEnd();
	glFlush();
}
