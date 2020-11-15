/*
* 5CCGD003W - Tutorial 6-PART1 - example code
* program draws a star and animates it
*/
// Code created by Dr Anastassia Angelopoulou 


#include "include\freeglut.h"	// OpenGL toolkit - in the local shared folder
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
#include <math.h>


//set up some constants
#define X_CENTRE 0.0      /* centre point of square */
#define Y_CENTRE 0.0
#define LENGTH   1.0      /* lengths of sides of square */
#define PI 3.14159265

//use to set/track star coordinate for moving/translated star
// Globals for star and helix
GLfloat starX = -50.0;
GLfloat starY = 0.0;
GLfloat angle = 0.0;   //rotation angle for star

	  
//forward declaration - best in the header
void drawStar(GLfloat radius, GLfloat x, GLfloat y);
void spinStar(bool xaxis, bool yaxis, bool zaxis,
	GLfloat rotation, GLfloat radius, GLfloat xpos, GLfloat ypos, bool multiplyMatrix);

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


/* display callback function
   called whenever contents of window need to be re-displayed */
//this is the all important drawing method - all drawing code goes in here
void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);     /* clear window */

   glLoadIdentity();

   /*SpinStar function with different parameters*/
   spinStar(true, false, false, angle, 40.0, 0.0, 0.0, false);

   glutSwapBuffers();
}

//Draws a 5 pointed star using lines
void drawStar(GLfloat radius, GLfloat x, GLfloat y)
{
	//x1,y1 is the first coordinate at 72 degrees from the unit circle
	//glColor3f(red, green, blue);
	GLfloat x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;

	x1 = x + cos(72 * PI / 180) * radius;
	y1 = y + sin(72 * PI / 180) * radius;
	x2 = x + cos(144 * PI / 180) * radius;
	y2 = y + sin(144 * PI / 180) * radius;
	x3 = x + cos(216 * PI / 180) * radius;
	y3 = y + sin(216 * PI / 180) * radius;
	x4 = x + cos(288 * PI / 180) * radius;
	y4 = y + sin(288 * PI / 180) * radius;
	x5 = x + radius;
	y5 = y;

	//Change the width of the line. You can have a thicker line.
	glLineWidth(2.0);

	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x3, y3);
	glVertex2f(x1, y1);
	glVertex2f(x4, y4);
	glVertex2f(x2, y2);
	glVertex2f(x4, y4);
	glVertex2f(x2, y2);
	glVertex2f(x5, y5);
	glVertex2f(x3, y3);
	glVertex2f(x5, y5);
	glEnd();

	glFlush();
}

/*this function spins (rotates) a 2D star around any axis
the multiplyMatrix value sets whether or not the matrix should be cleared before rotation
or multiplied */
void spinStar(bool xaxis, bool yaxis, bool zaxis,
	GLfloat rotation, GLfloat radius, GLfloat xpos, GLfloat ypos, bool multiplyMatrix)
{
	GLfloat x, y, z;
	x = 0.0;
	y = 0.0;
	z = 0.0;

	glColor3f(0.0, 1.0, 0.0);

	//this function spins the stars about a chosen axis or axes
	//note that you could say set the value = 0.5 if you wish
	if (xaxis)x = 2.5;
	if (yaxis)y = 1.0;
	if (zaxis)z = 1.0;
	
	//this clears the matrix otherwise remove to spin one star around the other
	if (!multiplyMatrix)
	{
		glLoadIdentity();
	}
	glRotatef(rotation, x, y, z);
	drawStar(radius, xpos, ypos);

	glFlush();
}

//The timer function
//the callback for the timer tick
void TimerFunction(int value)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//the angle by which the star is rotated
	angle = angle + 1.0;
	if (angle>360)
		angle = 0;

	glutPostRedisplay();
	glutTimerFunc(5, TimerFunction, 0);//calls TimerFunction on tick - callback
}

/* graphics initialisation */ 
void init(void)
{
   /*glClearColor (0.0, 0.0, 0.0, 0.0);   /* window will be cleared to black */
    glClearColor (0.0, 0.0, 0.0, 0.0);     /* window will be cleared to red */
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
   glutInitWindowSize (500, 500);
   /* window upper left corner at (100, 100) */
   glutInitWindowPosition (100, 100);
   /* creates an OpenGL window with command argument in its title bar */
   glutCreateWindow ("Example 6 -3D Rotation Animation");
   
   init();
   
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   
   //needed for animation
   glutTimerFunc(5, TimerFunction, 0);
   glutMainLoop();
   return 0;
}

