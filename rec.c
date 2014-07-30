#include <GL/glut.h>
#include <math.h>
const float cPSIZE = 0.05;
void putpix(float x, float y)
{
glBegin(GL_POLYGON);
	glVertex2f(x-cPSIZE/2, y-cPSIZE/2); //Top left
	glVertex2f(x-cPSIZE/2, y+cPSIZE/2); //Bottom left
	glVertex2f(x+cPSIZE/2, y+cPSIZE/2); //Bottom right
	glVertex2f(x+cPSIZE/2, y-cPSIZE/2);	//Top right
glEnd();
}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	int i;
	float radius = 1;
	for (i = 0; i < 30; i++)
	{
		putpix(cos(i)*cPSIZE*radius, sin(i) * cPSIZE*radius);
		radius += 0.1;
	}
	
	glFlush();

	return;
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);

	/* Default view so can be ignored */
	/*
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	*/	
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("This started as recursion research.");
	glutDisplayFunc(display);
	init();
	glutMainLoop();

	return 0;
}
