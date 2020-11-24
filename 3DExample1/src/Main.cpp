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

//set up some constants
#define X_CENTRE 0.0      /* centre point of square */
#define Y_CENTRE 0.0

//use to set/track star coordinate for moving/translated star
// Globals for star and helix
GLfloat timer;
Spawner* spawner = new Spawner(X_CENTRE, Y_CENTRE, 70, 40);
PlayerCar* player = new PlayerCar(2, 0, 0, 4, 2);
bool rainbow = false, grid = false;

/* reshape callback function
   executed when window is moved or resized. */
void reshape(int w, int h)
{
	GLfloat aspect = (GLfloat)w / (GLfloat)h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h) /* aspect <= 1 */
		glOrtho(-50.0, 50.0, -50.0 / aspect, 50.0 / aspect, -50.0, 50.0);
	else /* aspect > 1 */
		glOrtho(-50.0*aspect, 50.0*aspect, -50.0, 50.0, -50.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}




//The timer function
//the callback for the timer tick
void TimerFunction(int value)
{
	glClear(GL_COLOR_BUFFER_BIT);
	// Timer code goes here
	timer += 1.0;
	if (timer > 200) { timer = 0; }
	glutPostRedisplay();
	glutTimerFunc(5, TimerFunction, 0);//calls TimerFunction on tick - callback
}
void rightMenu(GLint id)
{
	switch(id)
	{
	case 1:
		rainbow = true;
		break;
	case 2:
		rainbow = false;
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

/* graphics initialisation */ 
void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);     /* window will be cleared to black */
	srand(time(NULL));
    spawner->Spawn(25,3,3);
	glutCreateMenu(rightMenu);
	glutAddMenuEntry("Gamer Mode on", 1);
	glutAddMenuEntry("Gamer Mode off", 2);
	glutAddMenuEntry("Grid toggle", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
}


/* display callback function
   called whenever contents of window need to be re-displayed */
   //this is the all important drawing method - all drawing code goes in here
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);     /* clear window */

	glLoadIdentity();

	// display code goes here (Making shapes etc)
	glPushMatrix();
	spawner->DebugDraw(0.0,1.0,0.0,0.5);
	glPopMatrix();
	spawner->Draw();
	player->Draw();
	glutSwapBuffers();
}


//rename this to main(...) and change example 2 to run this main function
int main(int argc, char** argv)
{
	       /* window management code ... */
   /* initialises GLUT and processes any command line arguments */  
   glutInit(&argc, argv);
   /* use single-buffered window and RGBA colour model */
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   /* window width = 400 pixels, height = 400 pixels */
   /* window width = 640 pixels, height = 480 pixels for a 4:3 ascpect ratio */
   /* window width = 1024 pixels, height = 576 pixels for a 16:9 ascpect ratio */
   glutInitWindowSize (1024, 720);
   /* window upper left corner at (100, 100) */
   glutInitWindowPosition (100, 100);
   /* creates an OpenGL window with command argument in its title bar */
   glutCreateWindow ("Car Game");
   
   init();
   
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   //needed for animation
   glutTimerFunc(5, TimerFunction, 0);
   glutMainLoop();
   return 0;
}

