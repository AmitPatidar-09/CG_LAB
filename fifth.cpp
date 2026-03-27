#include<GL/glut.h>
void init(){
	glClearColor(0.0, 0.0,0.0, 1.0); //bg color black
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 500.0, 0.0 , 500.0); // window size 
}
	int points[3][2] = {
	    {50, 100},
	    {65, 150},
	    {100, 200}
	};
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	
	
	for (int i = 0; i < 3; i++){
	    glVertex2iv(points[i]);   // pass address of {x, y}
	}
		
	
	
	
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








//G8OoPB
