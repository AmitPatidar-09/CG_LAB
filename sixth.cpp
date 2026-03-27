#include <GL/glut.h>

#define MAX_POINTS 100

int points[MAX_POINTS][2];
int pointCount = 0;

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();  
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);  
    glColor3f(1.0, 1.0, 1.0);     
     glPointSize(10.0);
    if (pointCount > 0) {
        glBegin(GL_POINTS);
        for (int i = 0; i < pointCount; i++) {
            glVertex2iv(points[i]);
        }
        glEnd();
    }

    glFlush();  
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (pointCount < MAX_POINTS) {
            points[pointCount][0] = x;
            points[pointCount][1] = 500 - y;  
            pointCount++;
            glutPostRedisplay();
        }
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Using Mouse Functions");

    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();

    return 0;
}

