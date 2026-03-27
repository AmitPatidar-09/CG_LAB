#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

int n;               // number of sides
float vertices[100][2];  // store vertices (max 100 sides)
float cx = 250, cy = 250, r = 100; // center and radius

void init() {
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1); // white color

    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < n; i++) {
        glVertex2fv(vertices[i]);
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    printf("Enter the number of sides of the polygon: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        float angle = 2.0 * 3.14159 * i / n;
        vertices[i][0] = cx + r * cos(angle);
        vertices[i][1] = cy + r * sin(angle);
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Dynamic Polygon");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

