
// Project Name : IntelliQube

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>      // handle the window-managing operations
#else
#include <GL/glew.h>
#include <GL/freeglut.h>    // handle the window-managing operations
#endif
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
GLint win_width = 600,
win_hight = 600;

//check the solution of each stage
bool L1 = false;
bool L2 = false;
bool L3 = false;
bool L4 = false;
bool L5 = false;
bool L6 = false;
//level 2
int level2Games = 1;
int skipLevel2 = 1;
//level 3
bool transitionToScene2 = false;
//level 4
int page = 0;
int KeyboardMove = 0;
//Prize Page
GLuint myTexture;
char image1Path[] = "C:\\Users\\083T\\Documents\\GitHubProject\\ProjectIntelliQube\\ThePrize.bmp";
// basic
int flag = 0;
int moveLevel = 0;
int CountmoveLevel = 0;
int skip = 1;
int CountSkip = 0;
int startGame = 0;
int IQ = 0;
string CountIQ;
float scale = 0.0; //control scale +,-
int gap = 300; //func "MyTimer"
int counter = 0; //func "MyTimer"
int timeControl = 0; //func "MyTimer"
int next1 = 0; //game page transition
int keyMouse1 = 0; //key mouse
GLdouble PI = 3.14159265359;

// -------------------------[ Build Fanction ]-------------------------

//Font Type:
//GLUT_BITMAP_HELVETICA_18
//GLUT_BITMAP_TIMES_ROMAN_24
//GLUT_BITMAP_9_BY_15

//track cursor coordinates x,y
void mouseTracking(int x, int y) {
    cout << "X: " << x << " ,Y: " << y << endl;
}

//calculating time
void MyTimer(int extra)
{
    if (timeControl == 0) { //on
        counter = extra + 1;
    }
    if (timeControl == 1) { //stop
        counter = extra + 0;
    }
    if (timeControl == 2) { //start zero
        counter = 0;
    }
    glutPostRedisplay();
    glutTimerFunc(gap, MyTimer, counter);
}

//draw filled circle
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

//draw hollow circle
void drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int lineAmount = 100; //# of triangles used to draw circle
    GLfloat twicePi = 2.0f * PI;
    glBegin(GL_LINE_LOOP);
    for (i = 0; i <= lineAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / lineAmount)),
            y + (radius * sin(i * twicePi / lineAmount))
        );
    }
    glEnd();
}

// -------------------------[ Basic Designs Of The Game ]-------------------------

//background intro
void background1()
{
    //background 
    glBegin(GL_QUADS);
    glColor3f(0.996f, 0.97265625f, 0.89453125f);
    glVertex2f(1.0f, 0.88f);
    glVertex2f(-1.0f, 0.88f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glEnd();
    //three circles
    glColor3f(1.f, 0.0f, 0.f);
    drawFilledCircle(-0.9, 0.94, 0.025);
    glColor3f(0.f, 1.0f, 0.f);
    drawFilledCircle(-0.8, 0.94, 0.025);
    glColor3f(0.2f, 0.5f, 0.9f);
    drawFilledCircle(-0.7, 0.94, 0.025);
}

//background level game
void background2()
{
    //background
    glBegin(GL_QUADS);
    glColor3f(0.996f, 0.97265625f, 0.89453125f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glEnd();
    //the top bar
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(1.0f, 0.95f);
    glVertex2f(-1.0f, 0.95f);
    glVertex2f(-1.0f, 0.8f);
    glVertex2f(1.0f, 0.8f);
    glEnd();
    //frame top bar
    glBegin(GL_LINES);
    glLineWidth(0.1);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(1.0f, 0.95f);
    glVertex2f(-1.0f, 0.95f);
    glVertex2f(-1.0f, 0.8f);
    glVertex2f(1.0f, 0.8f);
    glEnd();
    //skip level icon
    glBegin(GL_QUADS);
    glLineWidth(0.1);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(0.915f, 0.905f);
    glVertex2f(0.9f, 0.905f);
    glVertex2f(0.9f, 0.845f);
    glVertex2f(0.915f, 0.845f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glLineWidth(0.1);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(0.84f, 0.845f);
    glVertex2f(0.895f, 0.875f);
    glVertex2f(0.84f, 0.905f);
    glEnd();
    //text "Skip Level"
    char text1[] = "Skip Level";
    glColor3f(0.3, 0.3, 0.3);
    glRasterPos2f(0.58, 0.85999);
    for (GLint i = 0; i <= strlen(text1); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text1[i]);
    }
}

//background of IQ results
void background3()
{
    //frame 1
    glLineWidth(2.0f);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.45f, 0.45f, 0.45f);
    glVertex2f(0.8f, 0.4f);
    glVertex2f(0.8f, 0.7f);
    glVertex2f(0.5f, 0.7f);
    glEnd();
    //frame 2
    glBegin(GL_LINE_STRIP);
    glColor3f(0.45f, 0.45f, 0.45f);
    glVertex2f(-0.5f, 0.7f);
    glVertex2f(-0.8f, 0.7f);
    glVertex2f(-0.8f, 0.4f);
    glEnd();
    //frame 3
    glBegin(GL_LINE_STRIP);
    glColor3f(0.45f, 0.45f, 0.45f);
    glVertex2f(-0.8f, -0.5f);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(-0.5f, -0.8f);
    glEnd();
    //frame 4
    glBegin(GL_LINE_STRIP);
    glColor3f(0.45f, 0.45f, 0.45f);
    glVertex2f(0.5f, -0.8f);
    glVertex2f(0.8f, -0.8f);
    glVertex2f(0.8f, -0.5f);
    glEnd();
    //button box
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.6f, 0.5f);
    glVertex2f(0.28f, -0.72f);
    glVertex2f(-0.28f, -0.72f);
    glVertex2f(-0.28f, -0.85f);
    glVertex2f(0.28f, -0.85f);
    glEnd();
}

// ---------------------------------------------------------------[ Introduction 1 ]---------------------------------------------------------------
void Page1()
{
    //cube
    glBegin(GL_QUADS); //up
    glColor3f(0.515625f, 0.703125f, 0.875f);
    glVertex2f(0.0f, 0.25f);
    glVertex2f(-0.2f, 0.15f);
    glVertex2f(0.0f, 0.05f);
    glVertex2f(0.2f, 0.15f);
    glEnd();
    glBegin(GL_QUADS); //left
    glColor3f(0.996f, 0.54296f, 0.54296f);
    glVertex2f(-0.2f, 0.15f);
    glVertex2f(-0.2f, -0.05f);
    glVertex2f(0.0f, -0.15f);
    glVertex2f(0.0f, 0.05f);
    glEnd();
    glBegin(GL_QUADS); //right
    glColor3f(0.996f, 0.84765f, 0.39843f);
    glVertex2f(0.0f, 0.05f);
    glVertex2f(0.0f, -0.15f);
    glVertex2f(0.2f, -0.05f);
    glVertex2f(0.2f, 0.15f);
    glEnd();
    //line cube
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.2f, 0.15f); //left
    glVertex2f(0.0f, 0.05f);
    glVertex2f(0.0f, 0.05f); //right
    glVertex2f(0.2f, 0.15f);
    glVertex2f(0.0f, 0.05f); //mid
    glVertex2f(0.0f, -0.15f);
    glEnd();
}

void textPage1()
{
    //text
    char text1[] = "IntelliQube";
    glColor3f(0.36, 0.36, 0.36);
    glRasterPos2f(-0.18, -0.29);
    for (GLint i = 0; i <= strlen(text1); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text1[i]);
    }
}

// --> Introduction 1 - Move the cube
void Introduction()
{
    //hide the cube
    glPushMatrix();
    glScalef(0.0, .0, 0.0);
    Page1();
    glPopMatrix();
    //show the cube
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(0.0, 0.04, 0.0);
    glScalef(scale, scale, 0.0);
    Page1();
    if (scale < 1.0) {
        scale = scale + 0.0005;
    }
    glPopMatrix();
    //show name of the game
    if (scale >= 1.0) {
        glPushMatrix();
        glTranslatef(0.0, 0.06, 0.0);
        textPage1();
        glPopMatrix();
    }
}

// ---------------------------------------------------------------[ Introduction 2 ]---------------------------------------------------------------
void Page2() //game definition
{
    keyMouse1 = 1;
    background1();

    //text box
    glBegin(GL_QUADS);
    glLineWidth(0.1);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.8f, 0.45f);
    glVertex2f(-0.8f, 0.45f);
    glVertex2f(-0.8f, -0.55f);
    glVertex2f(0.8f, -0.55f);
    glEnd();
    //next box
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.2f, -0.65f);
    glVertex2f(-0.2f, -0.65f);
    glVertex2f(-0.2f, -0.76f);
    glVertex2f(0.2f, -0.76f);
    glEnd();
    //next frame
    glBegin(GL_LINE_LOOP);
    glLineWidth(0.1);
    glColor3f(0.85f, 0.85f, 0.85f);
    glVertex2f(0.2f, -0.65f);
    glVertex2f(-0.2f, -0.65f);
    glVertex2f(-0.2f, -0.76f);
    glVertex2f(0.2f, -0.76f);
    glEnd();
    //text "Next"
    char text7[] = "Next";
    glColor3f(0.45, 0.45, 0.45);
    glRasterPos2f(-0.071, -0.72);
    for (GLint i = 0; i <= strlen(text7); i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text7[i]);
    }

    //text "Welcome"
    char text2[] = "Welcome to IntelliQube !";
    glColor3f(0.3, 0.3, 0.3);
    glRasterPos2f(-0.4, 0.62);
    for (GLint i = 0; i <= strlen(text2); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text2[i]);
    }
    //text intro project
    char text3[] = "The IntelliQube is a puzzle game";
    char text4[] = "that contains six different levels of ";
    char text5[] = "difficulty to determine the player's";
    char text6[] = "intelligence quotient(IQ) level.";
    glColor3f(0.45, 0.45, 0.45);
    glRasterPos2f(-0.53, 0.20);
    for (GLint i = 0; i <= strlen(text3); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text3[i]);
    }
    glColor3f(0.45, 0.45, 0.45);
    glRasterPos2f(-0.56, 0.03);
    for (GLint i = 0; i <= strlen(text4); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text4[i]);
    }
    glColor3f(0.45, 0.45, 0.45);
    glRasterPos2f(-0.56, -0.13);
    for (GLint i = 0; i <= strlen(text5); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text5[i]);
    }
    glColor3f(0.45, 0.45, 0.45);
    glRasterPos2f(-0.51, -0.31);
    for (GLint i = 0; i <= strlen(text6); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text6[i]);
    }
}

// ---------------------------------------------------------------[ Introduction 3 ]---------------------------------------------------------------
void Page3() //game rules
{
    keyMouse1 = 2;
    background1();

    //text box
    glBegin(GL_QUADS);
    glLineWidth(0.2);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.83f, 0.62f);
    glVertex2f(-0.83f, 0.62f);
    glVertex2f(-0.83f, -0.69f);
    glVertex2f(0.83f, -0.69f);
    glEnd();
    //next box
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.2f, -0.73f);
    glVertex2f(-0.2f, -0.73f);
    glVertex2f(-0.2f, -0.84f);
    glVertex2f(0.2f, -0.84f);
    glEnd();
    //next frame
    glBegin(GL_LINE_LOOP);
    glLineWidth(0.1);
    glColor3f(0.85f, 0.85f, 0.85f);
    glVertex2f(0.2f, -0.73f);
    glVertex2f(-0.2f, -0.73f);
    glVertex2f(-0.2f, -0.84f);
    glVertex2f(0.2f, -0.84f);
    glEnd();
    //text "Next"
    char text8[] = "Next";
    glColor3f(0.45, 0.45, 0.45);
    glRasterPos2f(-0.071, -0.8);
    for (GLint i = 0; i <= strlen(text8); i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text8[i]);
    }

    //text "Rules"
    char text7[] = "Game Rules";
    glColor3f(0.3, 0.3, 0.3);
    glRasterPos2f(-0.19, 0.69);
    for (GLint i = 0; i <= strlen(text7); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text7[i]);
    }
    //text game rules
    char text3[] = "# This game will have six levels, and you";
    char text4[] = "  must solve them within three minutes.";
    char text5[] = "# If you complete a certain level, you will";
    char text6[] = "  automatically move to the next level, and";
    char text9[] = "  if you do not know the solution for specific";
    char text10[] = "  level, you can skip it 'YOU CAN'T BACK'.";
    char text11[] = "# If you finish all the levels within the";
    char text12[] = "  specified time, your result will appear";
    char text13[] = "  immediately, If all the answers are correct";
    char text14[] = "  you will get the prize. Otherwise, the";
    char text15[] = "  game will end and an incomplete result";
    char text16[] = "  will appear. You can replay the game.";
    glColor3f(0.3, 0.3, 0.3);
    glRasterPos2f(-0.75, 0.5);
    for (GLint i = 0; i <= strlen(text3); i++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text3[i]);
    }
    glColor3f(0.3, 0.3, 0.3);
    glRasterPos2f(-0.75, 0.4);
    for (GLint i = 0; i <= strlen(text4); i++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text4[i]);
    }
    glColor3f(0.3, 0.3, 0.3);
    glRasterPos2f(-0.75, 0.3);
    for (GLint i = 0; i <= strlen(text5); i++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text5[i]);
    }
    glColor3f(0.3, 0.3, 0.3);
    glRasterPos2f(-0.75, 0.2);
    for (GLint i = 0; i <= strlen(text6); i++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text6[i]);
    }
    glColor3f(0.3, 0.3, 0.3);
    glRasterPos2f(-0.75, 0.1);
    for (GLint i = 0; i <= strlen(text9); i++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text9[i]);
    }
    glColor3f(0.3, 0.3, 0.3);
    glRasterPos2f(-0.75, 0.0);
    for (GLint i = 0; i <= strlen(text10); i++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text10[i]);
    }
    glColor3f(0.3, 0.3, 0.3);
    glRasterPos2f(-0.75, -0.1);
    for (GLint i = 0; i <= strlen(text11); i++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text11[i]);
    }
    glColor3f(0.3, 0.3, 0.3);
    glRasterPos2f(-0.75, -0.2);
    for (GLint i = 0; i <= strlen(text12); i++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text12[i]);
    }
    glColor3f(0.3, 0.3, 0.3);
    glRasterPos2f(-0.75, -0.3);
    for (GLint i = 0; i <= strlen(text13); i++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text13[i]);
    }
    glColor3f(0.3, 0.3, 0.3);
    glRasterPos2f(-0.75, -0.4);
    for (GLint i = 0; i <= strlen(text14); i++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text14[i]);
    }
    glColor3f(0.3, 0.3, 0.3);
    glRasterPos2f(-0.74, -0.5);
    for (GLint i = 0; i <= strlen(text15); i++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text15[i]);
    }
    glColor3f(0.3, 0.3, 0.3);
    glRasterPos2f(-0.75, -0.6);
    for (GLint i = 0; i <= strlen(text16); i++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text16[i]);
    }
}

// ---------------------------------------------------------------[ Start Window ]---------------------------------------------------------------
void Page4()
{
    keyMouse1 = 3;
    background1();

    //frame
    glLineWidth(3.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.4, 0.4, 0.4);
    glVertex2f(-0.86f, -0.35f);
    glVertex2f(0.86f, -0.35f);
    glVertex2f(0.86f, 0.6f);
    glVertex2f(-0.86f, 0.6f);
    glEnd();
    //circle start
    glColor3f(1.0, 1.0, 1.0);
    drawFilledCircle(0.0, 0.1, 0.14);
    //triangle start
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.3, 1.3);
    glVertex2f(-0.05, 0.18);
    glVertex2f(-0.05, 0.03);
    glVertex2f(0.1, 0.10);
    glEnd();
    //cloud circles
    glColor3f(0.537254902, 0.8117647059, 0.9411764706);
    drawFilledCircle(0.0, -0.3, 0.12);

    drawFilledCircle(0.2, -0.3, 0.12);
    drawFilledCircle(0.4, -0.3, 0.12);
    drawFilledCircle(0.5, -0.35, 0.12);

    drawFilledCircle(-0.2, -0.3, 0.12);
    drawFilledCircle(-0.4, -0.3, 0.12);
    drawFilledCircle(-0.5, -0.35, 0.12);

    glColor3f(0.537254902, 0.8117647059, 0.9411764706);
    drawFilledCircle(0.0, -0.4, 0.12);

    drawFilledCircle(0.2, -0.4, 0.12);
    drawFilledCircle(0.4, -0.4, 0.12);

    drawFilledCircle(-0.2, -0.4, 0.12);
    drawFilledCircle(-0.4, -0.4, 0.12);

    //text - project name
    char text12[] = "IntelliQube";
    glColor3f(0.36, 0.36, 0.36);
    glRasterPos2f(-0.181, 0.388);
    for (GLint i = 0; i <= strlen(text12); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text12[i]);
    }
    //text
    char text13[] = "START";
    glColor3f(0.5, 0.5, 0.5);
    glRasterPos2f(-0.11, -0.12);
    for (GLint i = 0; i <= strlen(text13); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text13[i]);
    }
    char text14[] = "<<<< GOOD LUCK >>>>";
    glColor3f(0.4, 0.4, 0.4);
    glRasterPos2f(-0.4, -0.38);
    for (GLint i = 0; i <= strlen(text14); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text14[i]);
    }
    char text15[] = "ARE YOU READY!!!";
    glColor3f(0.4, 0.4, 0.4);
    glRasterPos2f(-0.3, -0.7);
    for (GLint i = 0; i <= strlen(text15); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text15[i]);
    }
}




// ---------------------------------------------------------------[ Transition Function ]---------------------------------------------------------------

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

// ---------------------------------------------------------------[ Mouse ]
static void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_UP) {
            // --------------> page 2 - game definition
            if (keyMouse1 == 1) {
                if (x >= 199 && x <= 299 && y >= 413 && y <= 438 && counter == 0) {
                    next1 = 2;
                }
            }
            // --------------> page 3 - game rules
            if (keyMouse1 == 2) {
                if (x >= 204 && x <= 295 && y >= 434 && y <= 455 && counter == 0) {
                    next1 = 3;
                }
            }
            // --------------> page 4 - start window
            if (keyMouse1 == 3) {
                if (x >= 227 && x <= 274 && y >= 204 && y <= 250) {
                    next1 = 4;
                    startGame = 1;
                    moveLevel = 1;
                    timeControl = 0;
                }
            }


        }
    }

    if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_UP) {

        }
    }
}

static void motion(int x, int y) {}

// ---------------------------------------------------------------[ Keyboard ]
static void key(unsigned char keyPressed, int x, int y) //key handling
{
   
}

static void play(void)
{
    glutPostRedisplay();
}

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



// ---------------------------------------------------------------[ Display Function ]---------------------------------------------------------------

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //-------------------[ Page 1 ]
    if (counter <= 10 && next1 == 0) {
        Introduction();
        if (counter == 10) {
            next1 = 1;
            keyMouse1 = 1;
        }
    }
    //-------------------[ Page 2 ]
    if (next1 == 1) {
        Page2();
        timeControl = 2;
    }
    //-------------------[ Page 3 ]
    if (next1 == 2) {
        Page3();
    }
    //-------------------[ Page 4 ]
    if (startGame == 0 && next1 == 3) {
        Page4();
    }
   
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); // Specify the display Mode ? RGB, RGBA or color
    glutInitWindowSize(500, 500); // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow("IntelliQube"); // Create a window with the given title
    init();

    glutIdleFunc(play);
    glutDisplayFunc(display);
    glutReshapeFunc(reshapeFunc);
    //glutPassiveMotionFunc(mouseTracking); // ÊÊÈÚ ÇÍÏÇËíÇÊ ÇáÝÇÑÉ
    glutTimerFunc(gap, MyTimer, counter); //timer
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(key);
    glutSpecialFunc(special);

    glutMainLoop(); // Enter the infinitely event-processing loop

    return 0;
}

