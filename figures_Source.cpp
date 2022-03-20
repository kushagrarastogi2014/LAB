#include<gl/glut.h>
#include<math.h>
void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-1000.0, 1000.0, -1000.0, 1000.0);
}
void display()
{
	float pi = 3.1428, x, y, xpos, ypos, yend, theta, r=100;
	glColor3f(1.0, 0.0, 0.0);
	for (int i = 0; i < 720; i++)
	{
		if (i == 540)
		{
			glBegin(GL_LINES);
			glVertex2i(x, y);
			glVertex2i(x, y - 500);
			yend = y - 500;
			glEnd();
			xpos = x;
			ypos = y;
		}
		theta = i * pi / 360;
		x = r * cos(theta);
		y = r * sin(theta);
		glBegin(GL_POINTS);
			glVertex2i(x, y);
		glEnd();
	}
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(xpos, ypos - 200);
	glVertex2i(xpos - 200, ypos - 400);
	glVertex2i(xpos, ypos - 200);
	glVertex2i(xpos + 200, ypos - 400);
	glVertex2i(xpos, ypos - 500);
	glVertex2i(xpos - 170, ypos - 700);
	glVertex2i(xpos, ypos - 500);
	glVertex2i(xpos + 170, ypos - 700);
	glEnd();
	glFlush();
}
int main(int argc,char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(50,100);
	glutCreateWindow("Man");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}