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
    static void Timeout(int value) {
        glutTimerFunc(1000, Timeout, value);
        timer--;
        glutPostRedisplay();
    }
    void main(int argc, char** argv) {
        if (timer <= 0) return;
        Asteroid::Timer(10);
        Game::Timeout(0);
        glutPassiveMotionFunc(SpaceRocket::moving);

    }

    void display() {
        glClear(GL_COLOR_BUFFER_BIT); // clear the buffers

        rocket = SpaceRocket(mouseX, mouseY);
        rocket.draw();
        if (maxi <= Asteroid::Max_Asteroids && !asteroid.get_raduis() && timer > 0) {
            asteroid = Asteroid();
            maxi++;
        }
        else if (maxi > Asteroid::Max_Asteroids) {
            Text text;
            text.setColor(1.0, 1.0, 1.0);
            text.printText("Game Over", 400, 700);
            std::stringstream ss;
            ss << "Your Score is   " << asteroidDestroyed;
            text.printText(ss.str().c_str(), 400, 600);
            text.printText("Press F1 to play Again", 400, 500);
            gameOver = true;
        }
        else if (timer < 0) {
            Text text;
            text.setColor(1.0, 1.0, 1.0);
            text.printText("Time Out", 400, 700);
            std::stringstream ss;
            ss << "Your Score is   " << asteroidDestroyed;
            text.printText(ss.str().c_str(), 400, 600);
            text.printText("Press F1 to play Again", 400, 500);
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

            // Timer
            Text timeText;
            std::stringstream newS;
            newS << "Time: " << timer;
            timeText.printText(newS.str().c_str(), 915, 970);
        }


        glutSwapBuffers(); // swap the buffers
        glFlush(); // flush the OpenGL pipeline (usually not necessary)
    }
};

