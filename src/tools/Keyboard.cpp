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
            LaserBeam::iterator = (LaserBeam::iterator+1) % 3;
        
        glutPostRedisplay();
    }
};