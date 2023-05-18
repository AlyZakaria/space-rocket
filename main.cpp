#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdlib.h>
#include "src/shapes/Triangle.cpp"
#include "src/shapes/Circle.cpp"
#include "src/shapes/Quad.cpp"
using namespace std;

int phyWidth = 500.0;
int phyHeight = 500.0;
int logWidth = 500;
int logHeight = 500;
int centerX = logWidth /2;
int centerY = logHeight /2;
int alphaX = 0;
int alphaY = 0;

int mouseX = 250;
int mouseY = 250;

void init(float r, float g, float b){
    glClearColor(r,g,b,0);// background color
    glMatrixMode(GL_PROJECTION); // 2d
    gluOrtho2D(0.0,500.0, 0.0, 500.0); // range of x and y axis

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // clear the buffers

    // for testing
    // draw triangle
    Triangle t1 = Triangle({ {100, 100} , {200,100}  , {150,200}});
    t1.draw();
    // draw circle
    Circle c1 = Circle(300.0, 300.0, 50, 1000);
    c1.set_rgb(0.0, 1.0, 0.0);
    c1.draw();
    // draw quad
    Quad q1 = Quad({ {400, 100} , {490, 100} , {490, 200} , {400, 200} });
    q1.set_rgb(0.0, 1.0, 0.0);
    q1.draw();

    
    glutSwapBuffers(); // swap the buffers
    glFlush(); // flush the OpenGL pipeline (usually not necessary)
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);// color & number of buffers
    glutInitWindowSize(phyWidth, phyHeight);
    glutInitWindowPosition(500,100);
    glutCreateWindow("Space Rocket");


    init(0.0, 0.0, 0.0);
    glutDisplayFunc(display);
    glutMainLoop();
}