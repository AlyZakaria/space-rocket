#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include "shapes/Triangle.cpp"
#include "shapes/Circle.cpp"
#include "shapes/Quad.cpp"
#include "models/Asteroid.cpp"
#include "models/SpaceRocket.cpp"
using namespace std;

int maxi = 0;


class Game {

public:
    SpaceRocket rocket;
    Asteroid asteroid;
    Game() {
        glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);// color & number of buffers
        glutInitWindowSize(phyWidth, phyHeight);
        glutInitWindowPosition(300, 0);
        glutCreateWindow("Space Rocket");
    }
    void init(float r, float g, float b) {
        glClearColor(r, g, b, 0);// background color
        glMatrixMode(GL_PROJECTION); // 2d
        gluOrtho2D(0.0, 1000.0, 0.0, 1000.0); // range of x and y axis
    }
    void main(int argc, char** argv) {
        glutPassiveMotionFunc(SpaceRocket::moving);
        Asteroid::Timer(10);
    }

    void display() {
        glClear(GL_COLOR_BUFFER_BIT); // clear the buffers

        rocket = SpaceRocket(mouseX, mouseY);
        rocket.draw();
        if (maxi == 0) {
            asteroid = Asteroid();
            maxi++;
        }
        asteroid.moving();
        // shooting
        rocket.shooting(asteroid);
        asteroid.draw();

        glutSwapBuffers(); // swap the buffers
        glFlush(); // flush the OpenGL pipeline (usually not necessary)
    }
};

