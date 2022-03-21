#define GL_SILENCE_DEPRECATION
#include <iostream>
#include <GL/glut.h>
#include<cmath>
using namespace std;

void dda(int x1, int y1, int x2, int y2) {

    float dy, dx, step, x, y, k, Xin, Yin;
    dx = x2 - x1;
    dy = y2 - y1;
    if (abs(dx) > abs(dy))
    {
        step = abs(dx);
    }
    else {
        step = abs(dy);
    }
    Xin = dx / step;
    Yin = dy / step;

    x = x1;
    y = y1;
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    for (k = 1; k <= step; ++k) {
        x = x + Xin;
        y = y + Yin;

        glPointSize(2);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();

    }

    glFlush();

}

void plot(int x, int y) {
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2i(x, y + 50);
    glEnd();
}

void circle(int r) {
    int x = 0, y = r;
    float p = 5 / 4.0 - r;

    plot(x, y);
    while (x < y) {

        if (p < 0) {
            ++x;
            p = p + 2 * x + 3;
        }
        else {
            ++x;
            --y;
            p = p + 2 * x - 2 * y + 5;
        }
        plot(x, y);
        plot(y, x);
        plot(y, -x);
        plot(x, -y);
        plot(-x, -y);
        plot(-y, -x);
        plot(-y, x);
        plot(-x, y);
    }

}

void init(void)
{
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    circle(20);
    dda(0, 30, 0, -30);
    dda(0, 10, 20, 10);
    dda(0, 10, -20, 10);
    dda(-20, 10, -30, 0);
    dda(20, 10, 30, 0);
    dda(0, -30, -20, -50);
    dda(0, -30, 20, -50);
    glFlush();
}

int main(int argv, char** argc) {
    glutInit(&argv, argc);
    glutInitWindowSize(640, 640);
    glutCreateWindow("DRAW");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
