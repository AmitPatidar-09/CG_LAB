#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

vector<pair<int,int>> points;

void drawCircle(int xc, int yc, int radius)
{
    int x = 0;
    int y = radius;
    int dp = 1 - radius;

    while(x <= y)
    {
        points.push_back({ xc + x, yc + y });
        points.push_back({ xc + y, yc + x });
        points.push_back({ xc - x, yc + y });
        points.push_back({ xc - y, yc + x });
        points.push_back({ xc - x, yc - y });
        points.push_back({ xc - y, yc - x });
        points.push_back({ xc + x, yc - y });
        points.push_back({ xc + y, yc - x });

        x++;
        if(dp < 0)
            dp = dp + 2*x + 1;
        else
        {
            y--;
            dp = dp + 2*(x - y) + 1;
        }
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0); // White color
    glPointSize(2.0);

    glBegin(GL_POINTS);
    for(auto &p : points)
        glVertex2i(p.first, p.second);
    glEnd();

    glFlush();
}

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400.0, 400.0, -300.0, 300.0);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    int radius = 50;   // Ring radius
    int gapX = 120;    // Horizontal gap between rings
    int gapY = 60;     // Vertical offset for bottom row

    // Top row rings
    drawCircle(-2*gapX, 0, radius);  // Left
    drawCircle(0, 0, radius);        // Middle
    drawCircle(2*gapX, 0, radius);   // Right

    // Bottom row rings
    drawCircle(-gapX, -gapY, radius);  // Left
    drawCircle(gapX, -gapY, radius);   // Right

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Olympic Rings in White");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

