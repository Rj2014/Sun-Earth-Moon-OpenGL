#include<windows.h>
#include <GL/glut.h>
#include <math.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a,b;
int speed = 0;
const double PI = 3.141592654;
void circle(double r)
{
    float theta;
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<360;i++)
    {
        theta=i*PI/180;// changing degree to radian
        glVertex2f(r*cos(theta),r*sin(theta));
    }
    glEnd();
}
void circle1()
{
    glColor3d(1,0,0);
    circle(.5);
    glColor3d(0,0,0);
    circle(2);
    glColor3d(0,0,0);
    circle(4);
}
void circle2()
{
    glColor3d(0,1,0);
    circle(.2);
}
void circle3()
{
    glColor3d(0,0,1);
    circle(.3);
}
void draw()
{
    glPushMatrix();
    glScaled(0.2,0.2,0);
    glTranslatef(15.0f, 8.0f, 0);
    circle1();
    glPopMatrix();
    glPushMatrix();
    glScaled(0.2,0.2,0);
    glTranslatef(15.0f, 8.0f, 0);
    glRotatef(speed*4,0,0,1);
    glTranslatef(2, 0, 0);
    circle2();
    glPopMatrix();
    glPushMatrix();
    glScaled(0.2,0.2,0);
    glTranslatef(15.0f, 8.0f, 0);
    glRotatef(-speed*6,0,0,1);
    glTranslatef(4, 0, 0);
    circle3();
    glPopMatrix();
}
void display()
{
//to get the assigned window color(by glClearColor) displayed
//specifying that it is the bit values in color buffer that are to be set to the values indicated in glClearColor
    glClear(GL_COLOR_BUFFER_BIT);
    //glLoadIdentity();
    draw();
//GLUT function that instructs the computer that you are done with the current frame and the buffers should be
// swapped so that that frame be displayed and so that you can begin working on the next
    glutSwapBuffers();
}
void frame(int x)
{
    speed=speed+1;
//If your program changes the contents of the window, sometimes you will have to call glutPostRedisplay(),
//which gives glutMainLoop() a nudge to call the registered display callback at its next opportunity
    glutPostRedisplay();
    glutTimerFunc(30,frame,0);
}
void init()
{
    glClearColor(1,1, 1, 1);// Background color for display window
   glMatrixMode(GL_PROJECTION);
    glLoadIdentity();//we assign identity matrix to current matrix
    //glOrtho(0, 7, -1, 4, -1, 1);
    gluOrtho2D(0,7,-1,4);
// model view is used to combine the geometric transformations. Designates 4x4 model view matrix as current matrix.
//Once we are in model view mode, a call to transformation routine generates a matrix that is multiplied by current matrix for that mode.
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv)
{
    int mode=GLUT_RGB|GLUT_DOUBLE;
    glutInitDisplayMode(mode);
//since we are using OpenGL Utility Toolkit, we need to initialize GLUT
    glutInit(&argc, argv);
//specifies the initial pixel width and height of display window. I have set the values equal to my screen resolution
    glutInitWindowSize(1366,768);
//specifies that upper-left corner of display window should be placed
//0 pixels to right of left edge of screen and 0 pixels down from top edge of screen.*/
    glutInitWindowPosition(0,0);
    glutCreateWindow("CG Assignment");
    init();
    glutDisplayFunc(display);//we need to specify what display window is to contain. So the procedure "display" is passed to the function.
    glutTimerFunc(10,frame,0);
    glutMainLoop();//Bringing display window on screen, completing the window processing operations and activating the display windows.
    return 0;
}
