#include<GL/glut.h>
void init(){
	glClearColor(0.0, 0.0,0.0, 1.0); //bg color black
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 500.0, 0.0 , 500.0); // window size 
}
int points[5][2] = {
    {100, 100},
    {200, 100},
    {250, 200},
    {150, 300},
    {100, 200},
    
};
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < 5; i++){
	    glVertex2iv(points[i]);   // pass address of {x, y}
	}
	glVertex2iv(points[0]);
		
	
	
	
	glEnd();
	glFlush();
	
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Drawing lines");

	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}


