#include "Rectangle.h"

rectangle::rectangle(GLfloat x, GLfloat y, GLfloat width, GLfloat height):_posX(x), _posY(y), _width(width), _height(height) // constructor for 
{
	
}

rectangle::rectangle(GLfloat x, GLfloat y): _posX(x), _posY(y), _width(1), _height(1) // constructor for only x and y
{
	
}

rectangle::rectangle(): _posX(0), _posY(0), _width(1),_height(1) // default constructor
{
}

void rectangle::Draw() // Draw function inside the rectangle class creates a triangle strip with 4 vertices based on the position and size variables.
{
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f((_posX-_width),(_posY-_height));
	glVertex2f((_posX + _width), (_posY - _height));
	glVertex2f((_posX - _width), (_posY + _height));
	glVertex2f((_posX + _width), (_posY + _height));
	glEnd();
	glFlush();
}

int rectangle::getPosX(){	return _posX;}
int rectangle:: getPosY() { return _posY; }
int rectangle::getWidth() { return _width; }
int rectangle::getHeight() { return _height; }


void rectangle::Move(GLfloat x, GLfloat y) { _posX += x; _posY += y; }

void rectangle::Resize(GLfloat width, GLfloat height) { _width = width; _height = height; }




