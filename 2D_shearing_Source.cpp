#include <GL/glut.h>
#include <cmath>

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);//white background color
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-800, 800, -800, 800);
}

void shear_x()
{
    int x1 = -100, y1 = 200, x2 = -200, y2 = 100, x3 = -300, y3 = 200;
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);
    glEnd();

    int sx = 2, sy = 2.5; //shearing coefficient

    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(x1 + sx * y1, y1);
    glVertex2i(x2 + sx * y2, y2);
    glVertex2i(x3 + sx * y3, y3);
    glEnd();

    glColor3f(1.0, 0.5, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(x1, y1 + sy * x1);
    glVertex2i(x2, y2 + sy * x2);
    glVertex2i(x3, y3 + sy * x3);
    glEnd();

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // Use single color buffer and no depth buffer.
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50, 100);
    glutCreateWindow("Shearing");
    myInit();

    glutDisplayFunc(shear_x);
    //glutDisplayFunc(shear_y);
    glutMainLoop(); // This function does not return. Program ends when user closes the window.
    return 0;
}