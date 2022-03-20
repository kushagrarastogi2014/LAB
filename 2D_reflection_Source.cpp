#include <GL/glut.h>
#include <cmath>

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);//white background color
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-800, 800, -800, 800);
}

void reflection_about_line()
{
    int x1 = -100, y1 = 200, x2 = -200, y2 = 100, x3 = -300, y3 = 200;
    glClear(GL_COLOR_BUFFER_BIT);
    
    int a = 1, b = -1, c = 50;   //reflection about x-y+50=0

    //line 
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(-500, -500+c);
    glVertex2i(500, 500+c);
    glEnd();

    //original figure
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);
    glEnd();

    //reflected figure
    glColor3f(0.0, 0.0, 1.0);
    int xnew1 = x1 - (2 * a * (x1 - y1 + c)) / (a * a + b * b);
    int ynew1 = y1 - (2 * b * (x1 - y1 + c)) / (a * a + b * b);
    int xnew2 = x2 - (2 * a * (x2 - y2 + c)) / (a * a + b * b);
    int ynew2 = y2 - (2 * b * (x2 - y2 + c)) / (a * a + b * b);
    int xnew3 = x3 - (2 * a * (x3 - y3 + c)) / (a * a + b * b);
    int ynew3 = y3 - (2 * b * (x3 - y3 + c)) / (a * a + b * b);

    glBegin(GL_TRIANGLES);
    glVertex2i(xnew1, ynew1);
    glVertex2i(xnew2, ynew2);
    glVertex2i(xnew3, ynew3);
    glEnd();

    glFlush();
}

void reflection_axis()
{
    int x1 = 50, y1 = 200, x2 = 100, y2 = 100, x3 = 200, y3 = 200;
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(800, 0);
    glVertex2i(-800, 0);
    glVertex2i(0, 800);
    glVertex2i(0, -800);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(x1, -y1);
    glVertex2i(x2, -y2);
    glVertex2i(x3, -y3);
    glEnd();

    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(-x1, y1);
    glVertex2i(-x2, y2);
    glVertex2i(-x3, y3);
    glEnd();

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // Use single color buffer and no depth buffer.
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50, 100);
    glutCreateWindow("2D-Transformations");
    myInit();

    glutDisplayFunc(reflection_about_line);
    //glutDisplayFunc(reflection_axis);
    glutMainLoop(); // This function does not return. Program ends when user closes the window.
    return 0;
}