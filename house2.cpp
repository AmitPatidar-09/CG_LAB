#include <GL/glut.h>
#include <cmath>

// Draw house outline
void drawHouse(float x, float y) {
    glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x + 120, y);
        glVertex2f(x + 120, y + 100);
        glVertex2f(x, y + 100);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(x - 10, y + 100);
        glVertex2f(x + 130, y + 100);
        glVertex2f(x + 60, y + 170);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(x + 45, y);
        glVertex2f(x + 75, y);
        glVertex2f(x + 75, y + 60);
        glVertex2f(x + 45, y + 60);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(x + 15, y + 50);
        glVertex2f(x + 40, y + 50);
        glVertex2f(x + 40, y + 75);
        glVertex2f(x + 15, y + 75);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(x + 80, y + 50);
        glVertex2f(x + 105, y + 50);
        glVertex2f(x + 105, y + 75);
        glVertex2f(x + 80, y + 75);
    glEnd();
}

// Draw Sun outline
void drawSun() {
    float cx = 500, cy = 500, r = 40;

    glBegin(GL_LINE_LOOP);
    for(int i=0;i<100;i++){
        float theta=2*3.1416*i/100;
        glVertex2f(cx+r*cos(theta), cy+r*sin(theta));
    }
    glEnd();

    glBegin(GL_LINES);
    for(int i=0;i<12;i++){
        float theta=2*3.1416*i/12;
        glVertex2f(cx, cy);
        glVertex2f(cx+70*cos(theta), cy+70*sin(theta));
    }
    glEnd();
}

// Draw Fence
void drawFence() {
    for(int x=50;x<=550;x+=25){
        glBegin(GL_LINE_LOOP);
            glVertex2f(x, 120);
            glVertex2f(x+12, 120);
            glVertex2f(x+12, 180);
            glVertex2f(x, 180);
        glEnd();
    }
    glBegin(GL_LINES);
        glVertex2f(40,140); glVertex2f(560,140);
        glVertex2f(40,155); glVertex2f(560,155);
        glVertex2f(40,165); glVertex2f(560,165);
    glEnd();
}

// Display
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawHouse(80,200);
    drawHouse(250,200);
    drawHouse(420,200);

    drawSun();
    drawFence();

    glFlush();
}

// Initialize OpenGL
void init(){
    glClearColor(0,0,0,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,600,0,600);
}

// Main function
int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitWindowSize(600,600);
    glutCreateWindow("Wireframe Houses");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

