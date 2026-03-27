#include <GL/glut.h>

float angle = 45.0f; // rotation angle

// Function to draw cube
void drawCube()
{
    glutWireCube(2);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Camera
    gluLookAt(4, 4, 6,  0, 0, 0,  0, 1, 0);

    // 🔵 Original Cube
    glColor3f(0.0, 0.0, 1.0);
    drawCube();

    // 🔴 Rotated Cube (about X-axis)
    glPushMatrix();
        glRotatef(angle, 1.0f, 0.0f, 0.0f); // rotate about X-axis
        glColor3f(1.0, 0.0, 0.0);
        drawCube();
    glPopMatrix();

    glutSwapBuffers();
}

void init()
{
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1.0, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("3D Rotation about X-axis");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
