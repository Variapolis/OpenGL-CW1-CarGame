#include <cstdlib>
#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include "freeglut.h"	// OpenGL toolkit - in the local shared folder
#include "Spawner.h"
#include "PlayerCar.h"
#include "ConsoleDebug.h"
#include "EndGate.h"
#include "Boundary.h"

//Constants
#define X_CENTRE 0.0      // Centre
#define Y_CENTRE 0.0
#define START_X -50.0
#define START_Y -20.0
#define END_X 50.0
#define END_Y 38.0
#define PLAYER_WIDTH 4.0
#define PLAYER_HEIGHT 2.0
#define DEFAULT_SIZE 4.0
#define BOUNDARY_WIDTH 54
#define BOUNDARY_HEIGHT 40

//Globals
GLfloat rainbowRed = 0, rainbowGreen = 0.2, rainbowBlue = 0;
Spawner* spawner = new Spawner(X_CENTRE, Y_CENTRE, 50, 20);
EndGate* exitgate = new EndGate(END_X, END_Y, DEFAULT_SIZE, DEFAULT_SIZE/2);
PlayerCar* player = new PlayerCar(2, START_X, START_Y, PLAYER_WIDTH, PLAYER_HEIGHT);
Boundary* border = new Boundary(X_CENTRE, Y_CENTRE, BOUNDARY_WIDTH, BOUNDARY_HEIGHT);
bool rainbowMode = false, grid = false;
bool redCountUp = false;
bool greenCountUp = false;

// Callback function when the window size is changed.
void reshape(int w, int h)
{
	GLfloat aspect = (GLfloat)w / (GLfloat)h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h) // aspect <= 1
		glOrtho(-50.0, 50.0, -50.0 / aspect, 50.0 / aspect, -50.0, 50.0);
	else // aspect > 1
		glOrtho(-50.0*aspect, 50.0*aspect, -50.0, 50.0, -50.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void RateChange(bool &isUp, GLfloat &number, GLfloat rate) //Simple function to make changing the 
{
	if (number > 100) { isUp = true; }
	if (number < 0) { isUp = false; }
	number += rate + (isUp * (-rate * 2));
}


//Timer callback function
void TimerFunction(int value)
{
	glClear(GL_COLOR_BUFFER_BIT);
	RateChange(redCountUp, rainbowRed, 0.2); // Rate change for rainbow "GAMER MODE" colours.
	RateChange(greenCountUp, rainbowGreen, 0.3);
	glutPostRedisplay();
	glutTimerFunc(5, TimerFunction, 0); //calls TimerFunction on tick - callback
}
void rightMenu(GLint id)
{
	switch(id)
	{
	case 1:
		rainbowMode = true;
		break;
	case 2:
		rainbowMode = false;
		break;
	case 3:
		if (grid) { grid = false; }
		else { grid = true; }
		break;
	default: 
		break;
	}
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
		player->Move(0, player->_speed);
		break;
	case 's':
		player->Move(0, -player->_speed);
		break;
	case 'd':
		player->Move(player->_speed, 0);
		break;
	case 'a':
		player->Move(-player->_speed, 0);
		break;
	case 'r':
		player->Rotate();
		break;		
	}
	glutPostRedisplay();
	for(Obstacle* i : spawner->obstacles)
	{
		player->CheckCollision(i);
	}
}

// Graphics initialization function
void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);     // window will be cleared to black
	srand(time(NULL));
    spawner->Spawn(6,3,3);
	player->SetColor(1, 1, 1);
	glutCreateMenu(rightMenu);
	glutAddMenuEntry("Gamer Mode on", 1);
	glutAddMenuEntry("Gamer Mode off", 2);
	glutAddMenuEntry("Grid toggle", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
}


// display callback function called whenever contents of window need to be re-displayed
   //this is the all important drawing method - all drawing code goes in here
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);     /* clear window */

	glLoadIdentity();

	// display code goes here (Making shapes etc)
	glPushMatrix();
	border->Draw(1, 1, 1, 1);
	player->CheckBoundsCollision(border, START_X, START_Y);
	spawner->DebugDraw(0.0,1.0,0.0,0.5);
	glPopMatrix();
	spawner->Draw();
	if (rainbowMode)
	{
		player->SetColor(rainbowRed/100, rainbowGreen/100, 0.5);
	}
	else
	{
		player->SetColor(1, 1, 1);
	}
	player->Draw();
	glPushMatrix();
	exitgate->SetColor(1.0, 0.0, 0.0);
	exitgate->Draw();
	glPopMatrix();
	exitgate->CheckCollision(player,START_X,START_Y);
	glutSwapBuffers();
}


//rename this to main(...) and change example 2 to run this main function
int main(int argc, char** argv)
{
	       /* window management code ... */
   
   glutInit(&argc, argv); // initialises GLUT and processes any command line arguments   
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);	// Double Buffered, RGB colour-space  
   glutInitWindowSize (1024, 720);	// window width = 1024 pixels, height = 576 pixels for a 16:9 ascpect ratio    
   glutInitWindowPosition (600, 100);	// Window upper left corner at (100, 100) in Windows space.
   glutCreateWindow ("Car Game");	// creates an OpenGL window with command argument in its title bar 
   init();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   //needed for animation
   glutTimerFunc(5, TimerFunction, 0);
   glutMainLoop();
   return 0;
}

