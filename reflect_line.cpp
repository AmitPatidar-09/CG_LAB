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
    
    glBegin(GL_LINES);
    glVertex2f(temp[0][0], temp[0][1]);
    glVertex2f(temp[1][0], temp[1][1]);
    glEnd();
   
 	glColor3f(1.0, 1.0, 1.0);
    
    glBegin(GL_LINES);
    glVertex2f(-temp[0][0], temp[0][1]);
    glVertex2f(-temp[1][0], temp[1][1]);
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
    temp.push_back({50,50});


    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
