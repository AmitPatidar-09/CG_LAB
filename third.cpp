#include<GL/glut.h>
void init(){
	glClearColor(0.0, 0.0,0.0, 1.0); //bg color black
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 500.0, 0.0 , 500.0); // window size 
}
int points[6][2] = {
    {50, 0},
    {100, 50},
    {150, 0},
    {200, 50},
    {250, 0},
    {200, 50}
};
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);
	
	
	for (int i = 0; i < 6; i++){
	    glVertex2iv(points[i]);   // pass address of {x, y}
	}
		
	
	
	
	glEnd();
	glFlush();
	
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Drawing ZigZag lines");

	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}





