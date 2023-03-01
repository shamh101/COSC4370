/*******************************************************
 * Homework 2: OpenGL                                  *
 *-----------------------------------------------------*
 * First, you should fill in problem1(), problem2(),   *
 * and problem3() as instructed in the written part of *
 * the problem set.  Then, express your creativity     *
 * with problem4()!                                    *
 *                                                     *
 * Note: you will only need to add/modify code where   *
 * it says "TODO".                                     *
 *                                                     *
 * The left mouse button rotates, the right mouse      *
 * button zooms, and the keyboard controls which       *
 * problem to display.                                 *
 *                                                     *
 * For Linux/OS X:                                     *
 * To compile your program, just type "make" at the    *
 * command line.  Typing "make clean" will remove all  *
 * computer-generated files.  Run by typing "./hw2"    *
 *                                                     *
 * For Visual Studio:                                  *
 * You can create a project with this main.cpp and     *
 * build and run the executable as you normally would. *
 *******************************************************/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#include "./freeglut-3.2.1/include/GL/freeglut.h"

using namespace std;

bool leftDown = false, rightDown = false;
int lastPos[2];
float cameraPos[4] = {0,1,4,1};
int windowWidth = 640, windowHeight = 480;
double yRot = 0;
int curProblem = 4; // TODO: change this number to try different examples

float specular[] = { 1.0, 1.0, 1.0, 1.0 };
float shininess[] = { 50.0 };

void problem1() {

  float cx = 0;
  float cy = 0;
  float px = 2.0;
  float py = 2.0;
  float theta = 36;
  float xf = 0;
   float yf = 0;

        // actual calculations..
int i = 1;
  
  while (i <= 10) {

  xf = (cx + ((float)(px - cx) * cos(theta)) - ((float)(py - cy) *  sin(theta)));
  yf = (cy + ((float)(px - cx) * sin(theta)) +((float)(py - cy) * cos(theta)));

  
  
 // glRotatef(36, 0.0, 0.0, 0.0);
cout << xf << endl;

    
    glPushMatrix();
    glRotatef(theta, 0.0, 0.0, 1.0);
     glutSolidTeapot(0.25);
    glPopMatrix();
    
    glTranslatef(xf, yf, 0.0);
    
    i = i + 1;
    theta = theta + 36.0;
   // px = xf;
   // py = yf;
  }
    
//glTranslatef(2.0, 0.0, 0.0);
//glutSolidTeapot(0.25);


  
    // TODO: Your code here!
}

void problem2() {

  int i = 0;
while (i < 15){

 glutSolidCube(0.25);

  int build = 0;
  
   glPushMatrix();
  while (build < i){

   
    glTranslatef(0.0, 0.25, 0.0);

  glutSolidCube(0.25);
   
    build ++;
  }
   glPopMatrix();

  glTranslatef(0.25, 0.0, 0.0);

  i++;
}


  
// glutSolidCube(0.25);

 // glTranslatef(0.25, 0.0, 0.0);

 // glutSolidCube(0.25);
  
 // glTranslatef(0.0, 0.25, 0.0);

 // glutSolidCube(0.25);
    // TODO: Your code here!
}

void problem3() {

  int i = 6;

  while(i > 0){
    glTranslatef(0.25, 0.0, 0.0);
    
    int j = 0;
    glPushMatrix();
    
    while(j < i){

      glutSolidTeapot(0.25);
  glTranslatef(0.50, 0.0, 0.0);
      j++;
    }  
    
  glPopMatrix();

glTranslatef(0.0, -0.50, 0.0);
    i--;
  }
  
  
    // TODO: Your code here!
}

void problem4() {

  
  
    // TODO: Your code here!
}

void display() {
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glBegin(GL_LINES);
		glColor3f(1,0,0); glVertex3f(0,0,0); glVertex3f(1,0,0); // x axis
		glColor3f(0,1,0); glVertex3f(0,0,0); glVertex3f(0,1,0); // y axis
		glColor3f(0,0,1); glVertex3f(0,0,0); glVertex3f(0,0,1); // z axis
	glEnd(/*GL_LINES*/);

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glEnable(GL_LIGHT0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0,0,windowWidth,windowHeight);

	float ratio = (float)windowWidth / (float)windowHeight;
	gluPerspective(50, ratio, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cameraPos[0], cameraPos[1], cameraPos[2], 0, 0, 0, 0, 1, 0);

	glLightfv(GL_LIGHT0, GL_POSITION, cameraPos);

	glRotatef(yRot,0,1,0);

	if (curProblem == 1) problem1();
	if (curProblem == 2) problem2();
	if (curProblem == 3) problem3();
	if (curProblem == 4) problem4();

	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) leftDown = (state == GLUT_DOWN);
	else if (button == GLUT_RIGHT_BUTTON) rightDown = (state == GLUT_DOWN);

	lastPos[0] = x;
	lastPos[1] = y;
}

void mouseMoved(int x, int y) {
	if (leftDown) yRot += (x - lastPos[0])*.1;
	if (rightDown) {
		for (int i = 0; i < 3; i++)
			cameraPos[i] *= pow(1.1,(y-lastPos[1])*.1);
	}


	lastPos[0] = x;
	lastPos[1] = y;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	curProblem = key-'0';
    if (key == 'q' || key == 'Q' || key == 27){
        exit(0);
    }
	glutPostRedisplay();
}

void reshape(int width, int height) {
	windowWidth = width;
	windowHeight = height;
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("HW2");

	glutDisplayFunc(display);
	glutMotionFunc(mouseMoved);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}
