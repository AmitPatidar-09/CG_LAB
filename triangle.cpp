#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<float>> temp;
void rotate(vector<vector<float>>& temp) {
    float angle = 30; // degrees
    float rad = angle * M_PI / 180.0;

    vector<vector<float>> rotated;

    for(auto &p : temp) {
        float x = p[0];
        float y = p[1];
        float x_new = x * cos(rad) - y * sin(rad); 
        float y_new = x * sin(rad) + y * cos(rad);
        rotated.push_back({x_new, y_new});
    }

    temp.insert(temp.end(), rotated.begin(), rotated.end());
}
void init(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-300.0, 300.0, -300.0 , 300.0);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 0.0);

    glBegin(GL_TRIANGLES);
   		glVertex2f(temp[0][0],temp[0][1]);
        glVertex2f(temp[1][0],temp[1][1]);
        glVertex2f(temp[2][0],temp[2][1]);
    glEnd();
    
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
   		glVertex2f(temp[3][0],temp[3][1]);
        glVertex2f(temp[4][0],temp[4][1]);
        glVertex2f(temp[5][0],temp[5][1]);
    glEnd();

    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Drawing lines");
	temp.push_back({0, 100});
	temp.push_back({-100, -100});
	temp.push_back({100, -100});
    
	rotate(temp);
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
