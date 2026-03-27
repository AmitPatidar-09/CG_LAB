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
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    int n;
    cout << "Enter number of circles: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int xc, yc, radius;
        cout << "\nCircle " << i+1 << endl;
        cout << "Enter center (xc yc): ";
        cin >> xc >> yc;
        cout << "Enter radius: ";
        cin >> radius;

        drawCircle(xc, yc, radius);
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Multiple Circles");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

