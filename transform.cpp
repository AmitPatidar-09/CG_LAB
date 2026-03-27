#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<float>> temp;

void init(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100.0, 100.0, -100.0 , 100.0);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);

    // original line
    glBegin(GL_LINES);
    glVertex2f(temp[0][0], temp[0][1]);
    glVertex2f(temp[1][0], temp[1][1]);
    glEnd();
	
	glColor3f(1.0, 0.0, 1.0);

    // rotated line
    glBegin(GL_LINES);
    glVertex2f(temp[0][0], temp[0][1]);
    glVertex2f(temp[2][0], temp[2][1]);
    glEnd();
    
    

  glColor3f(1.0, 1.0, 0.0);

    glBegin(GL_LINES);
    glVertex2f(temp[0][0] + 3, temp[0][1] + 2);
    glVertex2f(temp[2][0] + 3, temp[2][1] + 2);
    glEnd();


    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Drawing lines");

    // original line
    temp.push_back({0,0});
    temp.push_back({0,50});

    float x = temp[1][0], y = temp[1][1];

    float angle = 30;
    float rad = angle * M_PI / 180.0;

    float px = temp[0][0];
    float py = temp[0][1];

    float dx = x - px;
    float dy = y - py;

    float x_new = px + dx * cos(rad) - dy * sin(rad);
    float y_new = py + dx * sin(rad) + dy * cos(rad);

    temp.push_back({x_new, y_new});

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
