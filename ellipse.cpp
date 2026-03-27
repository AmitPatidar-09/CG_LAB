#include <GL/glut.h>
#include <math.h>

int xc = 300, yc = 300;   // Center of ellipse
int a = 150;              // X radius
int b = 100;              // Y radius

void plotPoints(int x, int y) {
    glBegin(GL_POINTS);
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);
    glEnd();
}

void midpointEllipse() {

    float dx, dy, d1, d2, x, y;
    x = 0;
    y = b;

    // Decision parameter for region 1
    d1 = (b * b) - (a * a * b) + (0.25 * a * a);
    dx = 2 * b * b * x;
    dy = 2 * a * a * y;

    // -------- Region 1 --------
    while (dx < dy) {
        plotPoints(x, y);

        if (d1 < 0) {
            x++;
            dx = dx + (2 * b * b);
            d1 = d1 + dx + (b * b);
        }
        else {
            x++;
            y--;
            dx = dx + (2 * b * b);
            dy = dy - (2 * a * a);
            d1 = d1 + dx - dy + (b * b);
        }
    }

    // Decision parameter for region 2
    d2 = ((b * b) * ((x + 0.5) * (x + 0.5))) +
         ((a * a) * ((y - 1) * (y - 1))) -
         (a * a * b * b);

    // -------- Region 2 --------
    while (y >= 0) {
        plotPoints(x, y);

        if (d2 > 0) {
            y--;
            dy = dy - (2 * a * a);
            d2 = d2 + (a * a) - dy;
        }
        else {
            y--;
            x++;
            dx = dx + (2 * b * b);
            dy = dy - (2 * a * a);
            d2 = d2 + dx - dy + (a * a);
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);

    midpointEllipse();

    glFlush();
}

void init() {
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 600, 0, 600);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Midpoint Ellipse Algorithm");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

