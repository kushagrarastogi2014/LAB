#include <GL/glut.h>
#include <cmath>

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);//white background color
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-800, 800, -800, 800);
}

void scale_pivot()
{
    int x1 = 50, y1 = 200, x2 = 100, y2 = 100, x3 = 200, y3 = 200;
    int Sx = 2, Sy = 3;
    int xp = 400, yp = 300; //pivot point
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2i((x1 - xp) * Sx + xp, (y1 - yp) * Sy + yp);
    glVertex2i((x2 - xp) * Sx + xp, (y2 - yp) * Sy + yp);
    glVertex2i((x3 - xp) * Sx + xp, (y3 - yp) * Sy + yp);
    glEnd();

    glFlush();
}

void rotation_pivot()
{
    int x1 = 50, y1 = 200, x2 = 100, y2 = 100, x3 = 200, y3 = 200;
    int xp = 50, yp = 200; //pivot point
    float angle = 180;
    float pi = 3.1428;
    float theta = angle * pi / 180;
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2i((x1 - xp) * cos(theta) - (y1 - yp) * sin(theta) + xp, (x1 - xp) * sin(theta) + (y1 - yp) * cos(theta) + yp);
    glVertex2i((x2 - xp) * cos(theta) - (y2 - yp) * sin(theta) + xp, (x2 - xp) * sin(theta) + (y2 - yp) * cos(theta) + yp);
    glVertex2i((x3 - xp) * cos(theta) - (y3 - yp) * sin(theta) + xp, (x3 - xp) * sin(theta) + (y3 - yp) * cos(theta) + yp);
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

    glutDisplayFunc(scale_pivot); 
    //glutDisplayFunc(rotation_pivot);
    glutMainLoop(); // This function does not return. Program ends when user closes the window.
    return 0;
}