#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
// #include "../models/LaserBeam.cpp"

using namespace std;

class Keyboard {
public:
    Keyboard() {}
    static void keyPress(unsigned char key, int x, int y) {
        if (key == 32)
            LaserBeam::iterator = (LaserBeam::iterator + 1) % 3;
        glutPostRedisplay();
    }
    static void specialKeyPress(int key, int x, int y) {
        if (key == GLUT_KEY_F1 && (timer <= 0 || gameOver)) {
            timer = 20;
            maxi = 0;
            asteroidDestroyed = 0;
            gameOver = false;
        }
        glutPostRedisplay();
    }
};