/*
* 5CCGD003W - Tutorial 4
* This tutorial introduces different even-driven programming examples that can be used for the cw
*/
// Code by Dr Anastassia Angelopoulou 


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

// Use the STL extension of C++
using namespace std;

//Initialise constants for position, window size and colour
GLint xRaster = 25, x = 30;
GLint k;
GLint i = 0;

//GLsizei wh = 500, ww = 500;

GLfloat red = 1.0, green = 1.0, blue = 1.0;

// Add your Globals here


//specify the position of the asterisks
GLint dataPosition[5] = { 450, 300, 200, 350, 150 };

//specify the colours for the asterisks
GLfloat Colors[15] =
{ 1.0, 0.0, 0.0,
	0.0, 1.0, 0.0,
	0.0, 0.0, 1.0,
	1.0, 1.0, 0.0,
	1.0, 0.5, 1.0,
};


// Routine to draw a bitmap character string.
void writeBitmapString(void* font, char* string)
{
	char* c;
	for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}

// reshape callback function executed when window is moved or resized. 
void reshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, w, h);
	glLoadIdentity();
	gluOrtho2D(0, (GLdouble)w, 0, (GLdouble)h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


// reshape callback function executed when window is moved or resized. 
/*void reshape(GLsizei w, GLsizei h)
{
	// Prevent a divide by zero
	if (h == 0)
		h = 1;

	glMatrixMode(GL_PROJECTION);

	// Set Viewport to window dimensions
	glViewport(0, 0, w, h);

	// Reset coordinate system
	glLoadIdentity();

	// Establish clipping volume (left, right, bottom, top, near, far)
	// Set the aspect ratio of the clipping area to match the viewport
	if (w <= h)
		glOrtho(0.0f, ww, 0.0f, wh*h / w, 1.0, -1.0);
	else
		glOrtho(0.0f, ww*w / h, 0.0f, wh, 1.0, -1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}*/



/* display callback function
   called whenever contents of window need to be re-displayed */
   //this is the all important drawing method - all drawing code goes in here

void display()
{
	// Clear the window with current clearing colour
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);        /* white drawing objects */


//Plot the data as polyline
	glBegin(GL_LINE_STRIP);
	for (k = 0; k < 5; k++)
	{
		glVertex2i(x + k * 100, dataPosition[k] + 5);
	}
	glEnd();


	//Plot data as asterisks on screen
	for (k = 0; k < 5; k++)
	{
		glColor3f(Colors[3 * i], Colors[3 * i + 1], Colors[3 * i + 2]);
		glRasterPos2i(xRaster + k * 100, dataPosition[k]);
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '*');
		i++;
	}


	//Plot and position text on screen
	glColor3f(1.0, 0.0, 0.0);
	glRasterPos2f(10, 70);
	writeBitmapString(GLUT_BITMAP_HELVETICA_18, "Red");

	glColor3f(0.0, 1.0, 0.0);
	glRasterPos2f(110, 70);
	writeBitmapString(GLUT_BITMAP_HELVETICA_18, "Green");

	glColor3f(0.0, 0.0, 1.0);
	glRasterPos2f(220, 70);
	writeBitmapString(GLUT_BITMAP_HELVETICA_18, "Blue");

	glColor3f(1.0, 1.0, 0.0);
	glRasterPos2f(320, 70);
	writeBitmapString(GLUT_BITMAP_HELVETICA_18, "Yellow");

	glColor3f(1.0, 0.0, 1.0);
	glRasterPos2f(430, 70);
	writeBitmapString(GLUT_BITMAP_HELVETICA_18, "Purple");

	glutSwapBuffers();
}


void init(void)
{
	glClearColor(0.9, 0.8, 0.5, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

//rename this to main(...) and change example 2 to run this main function
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Tutorial 4");
	glutDisplayFunc(display);

	init();

	//keyboard interaction


	//Mouse interaction


	glutReshapeFunc(reshape);

	glutMainLoop();
	return 0;
}

