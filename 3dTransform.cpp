#include <GL/glut.h>

// Translation values
float tx = 1.5f, ty = 1.5f, tz = 0.0f;

// Function to draw a cube
void drawCube()
{
    glutWireCube(1.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Set camera
    gluLookAt(3, 3, 7,  0, 0, 0,  0, 1, 0);

    // 🔵 Draw Original Cube (Blue)
    glColor3f(0.0, 0.0, 1.0);
    drawCube();

    // 🔴 Draw Translated Cube (Red)
    glPushMatrix();
        glTranslatef(tx, ty, tz); // Apply translation
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
    glutCreateWindow("3D Translation of Cube");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
