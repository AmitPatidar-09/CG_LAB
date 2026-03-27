#include <GL/glut.h>
#include <cmath>

void drawDottedLine(int x0, int y0, int x1, int y1)
{
    int dx = x1 - x0;
    int dy = y1 - y0;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xInc = dx / (float) steps;
    float yInc = dy / (float) steps;

    float x = x0;
    float y = y0;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++)
    {
        int pattern = i % 9;

        // DASH (4 points) + DOT (1 point)   // Dash is been created by joining four dotes. Then Sking the 5th dot.
        
        if (pattern < 4 || pattern == 6)
        {
            glVertex2i(round(x), round(y));
        }
        x += xInc;
        y += yInc;
    }
    glEnd();
}
// _._._._._._._._._._._

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0); // white line
    glPointSize(3.0);

    drawDottedLine(50, 50, 450, 450);

    glFlush();
}

void init()
{
    glClearColor(0, 0, 0, 1); // black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Dotted Line - OpenGL");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

