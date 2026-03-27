#include <GL/glut.h> 

void display() {
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(0.7f, 0.4f, 0.2f); 
    glBegin(GL_QUADS);
        glVertex2f(5.0f, 0.0f); 
        glVertex2f(11.0f, 0.0f); 
        glVertex2f(11.0f, 9.0f);  
        glVertex2f(5.0f, 9.0f);   
    glEnd();


    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(5.0f, 9.0f);  
        glVertex2f(11.0f, 9.0f);  
        glVertex2f(8.0f, 11.0f);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(0.8f, 0.9f, 1.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 15.0, 0.0, 12.0); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 480);
    glutCreateWindow("2D House");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
