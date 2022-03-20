#include <iostream>
#include <GL/glut.h>
using namespace std;

int xcenter, ycenter, r;

void plot_point(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(xcenter + x, ycenter + y);
	glVertex2i(xcenter + x, ycenter - y);
	glVertex2i(xcenter + y, ycenter + x);
	glVertex2i(xcenter + y, ycenter - x);
	glVertex2i(xcenter - x, ycenter - y);
	glVertex2i(xcenter - y, ycenter - x);
	glVertex2i(xcenter - x, ycenter + y);
	glVertex2i(xcenter - y, ycenter + x);
	glEnd();
}

void midPointCircleAlgo()
{
	int x = 0;
	int y = r;
	float decision = 5 / 4 - r;

	while (y >= x)
	{
		plotpoint(x, y); 
		if (decision < 0)
		{
			x++;
			decision += 2 * x + 3;
		}
		else
		{
			y--;
			x++;
			decision += 2 * (x - y) + 5;
		}
	}
}

void display(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 400.0, 0.0, 200.0); 

	midPointCircleAlgo();

	glFlush();
}

int main(int argc, char** argv)
{
	cout << "Enter the coordinates of the center:\n" << endl;

	cout << "X-coordinate : "; 
	cin >> xcenter;
	cout << "Y-coordinate : "; 
	cin >> ycenter;
	cout << "Enter radius : "; 
	cin >> r;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 400);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Mid-point circle drawing algo");
	glutDisplayFunc(display);
	glutMainLoop();
}