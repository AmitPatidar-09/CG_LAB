#include<GL/glut.h>
void init(){
	glClearColor(0.0 , 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

int star[10][2] = {
    {250, 400},  // top
    {280, 300},
    {380, 300},
    {300, 240},
    {330, 140},
    {250, 200},
    {170, 140},
    {200, 240},
    {120, 300},
    {220, 300}
};

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);
	
	for(int i = 0; i < 10; i++){
		glVertex2iv(star[i]);
	}
	glVertex2f(250,400);
	
	glEnd();
	glFlush();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Drawing A Star");

	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
