#ifdef __APPLE__
/* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>      // handle the window-managing operations
#else
#include <GL/glew.h>
#include <GL/freeglut.h>    // handle the window-managing operations
#endif
#include <stdlib.h>
#include <iostream>
//#include <conio.h>

using namespace std;

GLint win_width = 500,
win_hight = 500;
float transValue;
float scaleValue;
GLdouble PI = 3.14159265359;

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius) {
	int i;
	int triangleAmount = 20; //# of triangles used to draw circle
	GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x + (radius * cos(i * twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();
}

void ObjAllTank()
{
	//figure frame
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.86f, 0.87f);
	glVertex2f(-0.92f, 0.87f);
	glVertex2f(-0.92f, -0.81f);
	glVertex2f(0.86f, -0.81f);
	glEnd();
	//tap
	glBegin(GL_QUADS); //1
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.86f, 0.75f);
	glVertex2f(0.54f, 0.75f);
	glVertex2f(0.54f, 0.72f);
	glVertex2f(0.86f, 0.72f);
	glEnd();
	glBegin(GL_QUADS); //2
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.58f, 0.72f);
	glVertex2f(0.54f, 0.72f);
	glVertex2f(0.54f, 0.69f);
	glVertex2f(0.58f, 0.69f);
	glEnd();
	glBegin(GL_QUADS); //3
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.59f, 0.69f);
	glVertex2f(0.53f, 0.69f);
	glVertex2f(0.53f, 0.68f);
	glVertex2f(0.59f, 0.68f);
	glEnd();
	glBegin(GL_QUADS); //4
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.63f, 0.77f);
	glVertex2f(0.61f, 0.77f);
	glVertex2f(0.59f, 0.75f);
	glVertex2f(0.65f, 0.75f);
	glEnd();
	glBegin(GL_QUADS); //5
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.63f, 0.79f);
	glVertex2f(0.61f, 0.79f);
	glVertex2f(0.61f, 0.77f);
	glVertex2f(0.63f, 0.77f);
	glEnd();
	glBegin(GL_QUADS); //6
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.626f, 0.8f);
	glVertex2f(0.614f, 0.8f);
	glVertex2f(0.614f, 0.79f);
	glVertex2f(0.626f, 0.79f);
	glEnd();
	glBegin(GL_QUADS); //7
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.66f, 0.81f);
	glVertex2f(0.58f, 0.81f);
	glVertex2f(0.58f, 0.8f);
	glVertex2f(0.66f, 0.8f);
	glEnd();
	//drop
	glColor3f(0.0f, 0.0f, 1.0f);
	drawFilledCircle(0.56, 0.63, 0.02);
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.56f, 0.67f);
	glVertex2f(0.58f, 0.64f);
	glVertex2f(0.54f, 0.64f);
	glEnd();
	//water
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.65f, 0.43f);
	glVertex2f(0.45f, 0.43f);
	glVertex2f(0.45f, 0.4f);
	glVertex2f(0.65f, 0.4f);
	glEnd();
	//tank&pipe line 1
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.45f, 0.6f);
	glVertex2f(0.45f, 0.46f);
	glVertex2f(0.35f, 0.46f);
	glVertex2f(0.35f, 0.36f);
	glVertex2f(0.3f, 0.36f);
	glVertex2f(0.3f, 0.5f);
	glEnd();
	//tank&pipe line 2
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.65f, 0.6f);
	glVertex2f(0.65f, 0.4f);
	glVertex2f(0.45f, 0.4f);
	glVertex2f(0.45f, 0.43f);
	glVertex2f(0.38f, 0.43f);
	glVertex2f(0.38f, 0.33f);
	glVertex2f(0.3f, 0.33f);
	glVertex2f(0.3f, 0.3f);
	glVertex2f(0.22f, 0.3f);
	glVertex2f(0.22f, 0.26f);
	glVertex2f(0.45f, 0.26f);
	glVertex2f(0.45f, 0.3f);
	glEnd();
	//tank&pipe line 3
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.1f, 0.5f);
	glVertex2f(0.1f, 0.4f);
	glVertex2f(0.05f, 0.4f);
	glVertex2f(0.05f, 0.47f);
	glVertex2f(-0.05f, 0.47f);
	glVertex2f(-0.05f, 0.55f);
	glEnd();
	//tank&pipe line 4
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.1f, 0.4f);
	glVertex2f(0.1f, 0.37f);
	glVertex2f(0.02f, 0.37f);
	glVertex2f(0.02f, 0.44f);
	glVertex2f(-0.05f, 0.44f);
	glVertex2f(-0.05f, 0.47f);
	glEnd();
	//tank&pipe line 5
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.1f, 0.37f);
	glVertex2f(0.1f, 0.3f);
	glVertex2f(0.19f, 0.3f);
	glVertex2f(0.19f, 0.26f);
	glVertex2f(-0.14f, 0.26f);
	glVertex2f(-0.14f, 0.35f);
	glVertex2f(-0.05f, 0.35f);
	glVertex2f(-0.05f, 0.44f);
	glEnd();
	//tank&pipe line 6
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.25f, 0.55f);
	glVertex2f(-0.25f, 0.41f);
	glVertex2f(-0.33f, 0.41f);
	glVertex2f(-0.33f, 0.31f);
	glVertex2f(-0.45f, 0.31f);
	glVertex2f(-0.45f, 0.45f);
	glEnd();
	//tank&pipe line 7
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.65f, 0.45f);
	glVertex2f(-0.65f, 0.25f);
	glVertex2f(-0.45f, 0.25f);
	glVertex2f(-0.45f, 0.28f);
	glVertex2f(-0.3f, 0.28f);
	glVertex2f(-0.3f, 0.38f);
	glVertex2f(-0.25f, 0.38f);
	glVertex2f(-0.25f, 0.35f);
	glVertex2f(-0.17f, 0.35f);
	glVertex2f(-0.17f, 0.23f);
	glVertex2f(0.45f, 0.23f);
	glVertex2f(0.45f, 0.16f);
	glVertex2f(0.37f, 0.16f);
	glVertex2f(0.37f, -0.04f);
	glVertex2f(0.3f, -0.04f);
	glVertex2f(0.3f, 0.1f);
	glEnd();
	//tank&pipe line 8
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.65f, 0.35f);
	glVertex2f(-0.78f, 0.35f);
	glVertex2f(-0.78f, -0.02f);
	glVertex2f(-0.7f, -0.02f);
	glVertex2f(-0.7f, 0.05f);
	glEnd();
	//tank&pipe line 9
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.65f, 0.3f);
	glVertex2f(0.65f, 0.1f);
	glVertex2f(0.45f, 0.1f);
	glVertex2f(0.45f, 0.13f);
	glVertex2f(0.4f, 0.13f);
	glVertex2f(0.4f, -0.15f);
	glVertex2f(0.45f, -0.15f);
	glEnd();
	//tank&pipe line 10
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.1f, 0.1f);
	glVertex2f(0.1f, 0.04f);
	glVertex2f(0.06f, 0.04f);
	glVertex2f(0.06f, 0.07f);
	glVertex2f(-0.1f, 0.07f);
	glVertex2f(-0.1f, 0.2f);
	glEnd();
	//tank&pipe line 11
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.3f, 0.2f);
	glVertex2f(-0.3f, 0.05f);
	glVertex2f(-0.4f, 0.05f);
	glVertex2f(-0.4f, -0.08f);
	glVertex2f(-0.5f, -0.08f);
	glVertex2f(-0.5f, 0.05f);
	glEnd();
	//tank&pipe line 12
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.45f, -0.18f);
	glVertex2f(0.37f, -0.18f);
	glVertex2f(0.37f, -0.07f);
	glVertex2f(0.3f, -0.07f);
	glVertex2f(0.3f, -0.1f);
	glVertex2f(0.1f, -0.1f);
	glVertex2f(0.1f, 0.01f);
	glVertex2f(0.03f, 0.01f);
	glVertex2f(0.03f, 0.04f);
	glVertex2f(-0.1f, 0.04f);
	glVertex2f(-0.1f, 0.0f);
	glVertex2f(-0.3f, 0.0f);
	glVertex2f(-0.3f, 0.02f);
	glVertex2f(-0.37f, 0.02f);
	glVertex2f(-0.37f, -0.11f);
	glVertex2f(-0.5f, -0.11f);
	glVertex2f(-0.5f, -0.15f);
	glVertex2f(-0.7f, -0.15f);
	glVertex2f(-0.7f, -0.05f);
	glVertex2f(-0.78f, -0.05f);
	glVertex2f(-0.78f, -0.44f);
	glVertex2f(-0.7f, -0.44f);
	glVertex2f(-0.7f, -0.3f);
	glEnd();
	//tank&pipe line 13
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.65f, 0.21f);
	glVertex2f(0.75f, 0.21f);
	glVertex2f(0.75f, -0.61f);
	glVertex2f(0.65f, -0.61f);
	glEnd();
	//tank&pipe line 14
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.65f, 0.18f);
	glVertex2f(0.72f, 0.18f);
	glVertex2f(0.72f, -0.24f);
	glVertex2f(0.65f, -0.24f);
	glVertex2f(0.65f, -0.1f);
	glEnd();
	//tank&pipe line 15
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.45f, -0.1f);
	glVertex2f(0.45f, -0.3f);
	glVertex2f(0.53f, -0.3f);
	glVertex2f(0.53f, -0.36f);
	glEnd();
	//tank&pipe line 16
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.57f, -0.36f);
	glVertex2f(0.57f, -0.3f);
	glVertex2f(0.65f, -0.3f);
	glVertex2f(0.65f, -0.27f);
	glVertex2f(0.72f, -0.27f);
	glVertex2f(0.72f, -0.58f);
	glVertex2f(0.65f, -0.58f);
	glEnd();
	//tank&pipe line 17
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.45f, -0.45f);
	glVertex2f(0.45f, -0.47f);
	glVertex2f(0.37f, -0.47f);
	glVertex2f(0.37f, -0.33f);
	glVertex2f(0.2f, -0.33f);
	glVertex2f(0.2f, -0.25f);
	glEnd();
	//tank&pipe line 18
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, -0.25f);
	glVertex2f(0.0f, -0.38f);
	glVertex2f(-0.05f, -0.38f);
	glVertex2f(-0.05f, -0.33f);
	glVertex2f(-0.15f, -0.33f);
	glVertex2f(-0.15f, -0.2f);
	glEnd();
	//tank&pipe line 19
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.35f, -0.2f);
	glVertex2f(-0.35f, -0.23f);
	glVertex2f(-0.45f, -0.23f);
	glVertex2f(-0.45f, -0.32f);
	glVertex2f(-0.5f, -0.32f);
	glVertex2f(-0.5f, -0.3f);
	glEnd();
	//tank&pipe line 20
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.65f, -0.45f);
	glVertex2f(0.65f, -0.65f);
	glVertex2f(0.45f, -0.65f);
	glVertex2f(0.45f, -0.5f);
	glVertex2f(0.34f, -0.5f);
	glVertex2f(0.34f, -0.36f);
	glVertex2f(0.2f, -0.36f);
	glVertex2f(0.2f, -0.45f);
	glVertex2f(0.0f, -0.45f);
	glVertex2f(0.0f, -0.41f);
	glVertex2f(-0.08f, -0.41f);
	glVertex2f(-0.08f, -0.36f);
	glVertex2f(-0.15f, -0.36f);
	glVertex2f(-0.15f, -0.4f);
	glVertex2f(-0.35f, -0.4f);
	glVertex2f(-0.35f, -0.26f);
	glVertex2f(-0.42f, -0.26f);
	glVertex2f(-0.42f, -0.35f);
	glVertex2f(-0.5f, -0.35f);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(-0.58f, -0.5f);
	glVertex2f(-0.58f, -0.58f);
	glVertex2f(-0.27f, -0.58f);
	glVertex2f(-0.27f, -0.4f);
	glEnd();
	//tank&pipe line 21
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.53f, -0.65f);
	glVertex2f(0.53f, -0.72f);
	glVertex2f(0.33f, -0.72f);
	glVertex2f(0.33f, -0.58f);
	glVertex2f(0.12f, -0.58f);
	glVertex2f(0.12f, -0.45f);
	glEnd();
	//tank&pipe line 22
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.09f, -0.45f);
	glVertex2f(0.09f, -0.58f);
	glVertex2f(-0.24f, -0.58f);
	glVertex2f(-0.24f, -0.4f);
	glEnd();
	//tank&pipe line 23
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.65f, 0.38f);
	glVertex2f(-0.81f, 0.38f);
	glVertex2f(-0.81f, -0.47f);
	glVertex2f(-0.7f, -0.47f);
	glVertex2f(-0.7f, -0.5f);
	glVertex2f(-0.61f, -0.5f);
	glVertex2f(-0.61f, -0.61f);
	glVertex2f(0.3f, -0.61f);
	glVertex2f(0.3f, -0.75f);
	glVertex2f(0.56f, -0.75f);
	glVertex2f(0.56f, -0.65f);
	glEnd();
	//number
	char line1[] = "1";
	char line2[] = "2";
	char line3[] = "3";
	char line4[] = "4";
	char line5[] = "5";
	char line6[] = "6";
	char line7[] = "7";
	char line8[] = "8";
	char line9[] = "9";
	char line10[] = "10";
	char line11[] = "11";
	char line12[] = "12";
	char line13[] = "13";
	//number text
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2f(0.53, 0.48);
	for (GLint i = 0; i <= strlen(line1); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, line1[i]);
	}
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2f(0.18, 0.37);
	for (GLint i = 0; i <= strlen(line2); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, line2[i]);
	}
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2f(-0.17, 0.42);
	for (GLint i = 0; i <= strlen(line3); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, line3[i]);
	}
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2f(-0.57, 0.32);
	for (GLint i = 0; i <= strlen(line4); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, line4[i]);
	}
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2f(-0.62, -0.08);
	for (GLint i = 0; i <= strlen(line5); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, line5[i]);
	}
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2f(-0.22, 0.07);
	for (GLint i = 0; i <= strlen(line6); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, line6[i]);
	}
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2f(0.18, -0.03);
	for (GLint i = 0; i <= strlen(line7); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, line7[i]);
	}
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2f(0.53, 0.17);
	for (GLint i = 0; i <= strlen(line8); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, line8[i]);
	}
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2f(0.53, -0.23);
	for (GLint i = 0; i <= strlen(line9); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, line9[i]);
	}
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2f(0.51, -0.58);
	for (GLint i = 0; i <= strlen(line10); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, line10[i]);
	}
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2f(0.06, -0.38);
	for (GLint i = 0; i <= strlen(line11); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, line11[i]);
	}
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2f(-0.29, -0.33);
	for (GLint i = 0; i <= strlen(line12); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, line12[i]);
	}
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2f(-0.64, -0.43);
	for (GLint i = 0; i <= strlen(line13); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, line13[i]);
	}
}

static void special(int key, int x, int y)
{
	//handle special keys
	switch (key) {
	case GLUT_KEY_HOME:
		break;
	case GLUT_KEY_LEFT:
		break;
	case GLUT_KEY_RIGHT:
		break;
	case GLUT_KEY_UP:
		break;
	case GLUT_KEY_DOWN:
		break;
	default:
		break;
	}
}


static void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_UP) {
			
		}
	}

	if (button == GLUT_RIGHT_BUTTON) {
		if (state == GLUT_UP) {
			
		}
	}
}

static void motion(int x, int y)
{}

static void play(void)
{
	glutPostRedisplay();
}

static void key(unsigned char keyPressed, int x, int y) {} // key handling

void init() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-1, 1, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

void reshapeFunc(GLint new_width, GLint new_hight)
{
	glViewport(0, 0, new_width, new_hight);
	win_width = new_width;
	win_hight = new_hight;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	ObjAllTank();
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); // Initialize GLUT
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); // Specify the display Mode ? RGB, RGBA or color 	//  Index, single or double Buffer
	glutInitWindowSize(500, 500); // Set the window's initial width & height
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutCreateWindow("Level 5 (Which tank will fill up first?)"); // Create a window with the given title
	init();

	glutIdleFunc(play);
	glutDisplayFunc(display);
	glutReshapeFunc(reshapeFunc);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutKeyboardFunc(key);
	glutSpecialFunc(special);

	glutMainLoop(); // Enter the infinitely event-processing loop

	return 0;
}

