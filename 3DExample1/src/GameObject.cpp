#include "GameObject.h"

GameObject::GameObject(GLfloat x, GLfloat y, GLfloat width, GLfloat height):_posX(x), _posY(y), _width(width), _height(height) // constructor for 
{
	
}

GameObject::GameObject(GLfloat x, GLfloat y): _posX(x), _posY(y), _width(1), _height(1) // constructor for only x and y
{
	
}

GameObject::GameObject(): _posX(0), _posY(0), _width(0),_height(0) // default constructor
{
}

int GameObject::getPosX(){	return _posX;}
int GameObject::getPosY() { return _posY; }
int GameObject::getWidth() { return _width; }
int GameObject::getHeight() { return _height; }


void GameObject::Move(GLfloat x, GLfloat y) { _posX += x; _posY += y; }

void GameObject::MoveTo(GLfloat x, GLfloat y){ _posX = x; _posY = y; }

void GameObject::Resize(GLfloat width, GLfloat height) { _width = width; _height = height; }
void GameObject::ResizeWidth(GLfloat width) { _width = width; }
void GameObject::ResizeHeight(GLfloat height) {_height = height; }




