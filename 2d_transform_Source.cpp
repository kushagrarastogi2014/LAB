#include <GL/glut.h>
#include <cmath>

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);//white background color
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-800, 800,-800,800);
}

void translation()
{
    int x1 = 50, y1 = 200, x2 = 100, y2 = 100, x3 = 200, y3 = 200;
    int tx = 120, ty = 150;
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(x1 + tx, y1 + ty);
    glVertex2i(x2 + tx, y2 + ty);
    glVertex2i(x3 + tx, y3 + ty);
    glEnd();

    glFlush();
}

void scale()
{
    int x1 = 50, y1 = 200, x2 = 100, y2 = 100, x3 = 200, y3 = 200;
    int Sx = 2, Sy = 3;
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(x1 * Sx, y1 * Sy);
    glVertex2i(x2 * Sx, y2 * Sy);
    glVertex2i(x3 * Sx, y3 * Sy);
    glEnd();

    glFlush();
}

void rotation()
{
    int x1 = 50, y1 = 200, x2 = 100, y2 = 100, x3 = 200, y3 = 200;
    float angle = 90;
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
    glVertex2i(x1 * cos(theta) - y1 * sin(theta), x1 * sin(theta) + y1 * cos(theta));
    glVertex2i(x2 * cos(theta) - y2 * sin(theta), x2 * sin(theta) + y2 * cos(theta));
    glVertex2i(x3 * cos(theta) - y3 * sin(theta), x3 * sin(theta) + y3 * cos(theta));
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

    glutDisplayFunc(translation);        
    glutDisplayFunc(scale);
    glutDisplayFunc(rotation);
    glutMainLoop(); // This function does not return. Program ends when user closes the window.
    return 0;
}