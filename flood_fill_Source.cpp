#include <GL/glut.h>

int ww = 800, wh = 500;
float oldColor[3] = {1.0, 1.0, 1.0};
float newColor[3] = {0.7, 1.0, 0.0};

void setPixel(int pointx, int pointy, float f[3])
{
	glBegin(GL_POINTS);
	glColor3fv(f);
	glVertex2i(pointx, pointy);
	glEnd();
	glFlush();
}
void getPixel(int x, int y, float pixels[3])
{
	glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, pixels);
}

void drawPolygon(int x1, int y1, int x2, int y2)
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x1, y2);
	glEnd();
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(x2, y1);
	glVertex2i(x2, y2);
	glEnd();
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y1);
	glEnd();
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex2i(x1, y2);
	glVertex2i(x2, y2);
	glEnd();
	glFlush();
}

void floodFill4(int x, int y, float oldColor[3], float newColor[3])
{
	float interiorColor[3];
	getPixel(x, y, interiorColor);
	if ( (interiorColor[0] == oldColor[0]) && (interiorColor[1] == oldColor[1]) && (interiorColor[2] == oldColor[2]))
	{
		setPixel(x, y, newColor);
		floodFill4(x + 1, y, oldColor, newColor);
		floodFill4(x - 1, y, oldColor, newColor);
		floodFill4(x, y + 1, oldColor, newColor);
		floodFill4(x, y - 1, oldColor, newColor);
	}
}

void mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		int xi = x;
		int yi = (wh - y);
		floodFill4(xi, yi, oldColor, newColor);
	}
}

void display()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	drawPolygon(150, 250, 200, 300);
	floodFill4(180, 280, oldColor, newColor);
	glFlush();
}

void init()
{
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, (GLdouble)ww, 0.0, (GLdouble)wh);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(ww, wh);
	glutInitWindowPosition(50, 100);
	glutCreateWindow("Flood-Fill-Recursive");
	glutDisplayFunc(display);
	init();
	//glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}