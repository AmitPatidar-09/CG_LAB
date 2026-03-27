#include <GL/glut.h>
#include <cmath>

// DDA Line Drawing Algorithm
void drawLineDDA(int x0, int y0, int x1, int y1)
{
    int dx = x1 - x0;
    int dy = y1 - y0;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    float x = x0;
    float y = y0;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++)
    {
        glVertex2i(round(x), round(y));
        x += xInc;
        y += yInc;
    }
    glEnd();
}

// Draw H
void drawH(int x, int y)
{
    drawLineDDA(x, y, x, y + 80);
    drawLineDDA(x + 30, y, x + 30, y + 80);
    drawLineDDA(x, y + 40, x + 30, y + 40);
}

// Draw E
void drawE(int x, int y)
{
    drawLineDDA(x, y, x, y + 80);
    drawLineDDA(x, y + 80, x + 30, y + 80);
    drawLineDDA(x, y + 40, x + 25, y + 40);
    drawLineDDA(x, y, x + 30, y);
}

// Draw L
void drawL(int x, int y)
{
    drawLineDDA(x, y, x, y + 80);
    drawLineDDA(x, y, x + 30, y);
}

// Draw O
void drawO(int x, int y)
{
    drawLineDDA(x, y, x, y + 80);
    drawLineDDA(x, y + 80, x + 30, y + 80);
    drawLineDDA(x + 30, y + 80, x + 30, y);
    drawLineDDA(x + 30, y, x, y);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glPointSize(2);

    int startX = 50;
    int startY = 200;
    int gap = 50;   					// To have a space between each letter for clearity.
    									// Y same axis pe hi rhega.

    drawH(startX, startY);
    drawE(startX + gap, startY);
    drawL(startX + 2 * gap, startY);
    drawL(startX + 3 * gap, startY);
    drawO(startX + 4 * gap, startY);

    glFlush();
}

void init()
{
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("HELLO using DDA");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

