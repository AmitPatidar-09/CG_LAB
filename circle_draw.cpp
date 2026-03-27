#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

vector<pair<int,int>> points;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glPointSize(1.0);

    glBegin(GL_POINTS);
    for(auto &p : points)
        glVertex2i(p.first, p.second);
    glEnd();
	glFlush();
}

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200.0, 200.0, -200.0, 200.0);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    int radius;
    cout << "Enter Radius Of the circle : ";
    cin >> radius;

    int x = 0;
    int y = radius;
    int dp = 1 - radius;

    while(x <= y)
    {
        points.push_back({ x,  y});
        points.push_back({ y,  x});
        points.push_back({-x,  y});
        points.push_back({-y,  x});
        points.push_back({-x, -y});
        points.push_back({-y, -x});
        points.push_back({ x, -y});
        points.push_back({ y, -x});

        x++;

        if(dp < 0)
            dp = dp + 2*x + 1;
        else
        {
            y--;
            dp = dp + 2*(x - y) + 1;
        }
    }

   	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Circle Draw");

    init();
    glutDisplayFunc(display);
    glutMainLoop();


    return 0;
}

