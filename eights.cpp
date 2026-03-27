#include<GL/glut.h>
void init(){
	glClearColor(0.0 , 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); 
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}
int out[5][2] = {
	{100,100},
	{100,300},
	{250,450},
	{400,300},
	{400,100}
};
int win1[4][2] = {
	{150,250},
	{150,300},
	{200,300},
	{200,250}
};
int win2[4][2] = {
	{300,250},
	{300,300},
	{350,300},
	{350,250}
};

int door[4][2] = {
	{220,100},
	{220,200},
	{280,200},
	{280,100}
};
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);
	
	for(int i = 0; i < 5; i++){
		glVertex2iv(out[i]);
	}
	glVertex2iv(out[0]); 
	
	glEnd(); 
	glFlush();
	glBegin(GL_LINE_STRIP);
	for(int i = 0; i < 4; i++){
		glVertex2iv(win1[i]);
	}
	glVertex2iv(win1[0]);	
	glEnd();
	glFlush();
	
	
	glBegin(GL_LINE_STRIP);
	for(int i = 0; i < 4; i++){
		glVertex2iv(win2[i]);
	}
	glVertex2iv(win2[0]);	
	glEnd();
	glFlush();
	
	glBegin(GL_LINE_STRIP);
	for(int i = 0; i < 4; i++){
		glVertex2iv(door[i]);
	}
	glVertex2iv(door[0]);	
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
