#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>
#include<sstream> 
#include "shapes/Triangle.cpp"
#include "shapes/Circle.cpp"
#include "shapes/Quad.cpp"
#include "tools/Text.cpp"
#include "models/Asteroid.cpp"
#include "models/SpaceRocket.cpp"
#include <bits/stdc++.h>

using namespace std;



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
        if (maxi <= Asteroid::Max_Asteroids && !asteroid.get_raduis()) {
            asteroid = Asteroid();
            maxi++;
        }
        else if (maxi > Asteroid::Max_Asteroids) {
            Text text;
            text.setColor(1.0, 1.0, 1.0);
            text.printText("Game Over", 470, 500);
        }
        else {
            asteroid.moving();
            asteroid.draw();
            // shooting
            rocket.shooting(asteroid);
            // score
            Text text;
            text.setColor(1.0, 1.0, 1.0);
            std::stringstream ss;
            ss << "Score: " << asteroidDestroyed;
            text.printText(ss.str().c_str(), 10, 970);
        }


        glutSwapBuffers(); // swap the buffers
        glFlush(); // flush the OpenGL pipeline (usually not necessary)
    }
};

