#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;


class Asteroid : public Circle {
protected:
    float radius = 10.0;
    vector<vector<float>> rgb = { {1.0,0.0,0.0} , {0.0,1.0,0.0} , {0.0,0.0,1.0} };
    float iterator = 0;
    float sqDelta = 0; // Responsible of the square’s mouvment
    bool sqUp = true;
public:
    static const int Max_Asteroids = 25;
    Asteroid() {
        // get random center
        this->cx = float(rand() % int(logWidth));
        this->cy = logHeight;
        // get random color (red , green, blue)
        iterator = rand() % 3;
        this->r = rgb[iterator][0];
        this->g = rgb[iterator][1];
        this->b = rgb[iterator][2];
        this->set_rgb(r, g, b);
        this->set_raduis(radius);
    }
    void moving() {
        cy -= sqDelta;
        float maxY = floor(mouseY); // asteroid Maximum Travelling
        if ((floor(cy) <= maxY && mouseX - 20 < cx && mouseX + 20 > cx) || cy < 0) sqUp = !sqUp;
        if (sqUp) sqDelta += 0.5;
        else {
            this->set_raduis(0.0);
        }
    }
    static void Timer(int value) {
        glutTimerFunc(10, Timer, value);
        if (timer > 0)
            glutPostRedisplay();
        else return;
    }
    float getX() { return this->cx; }
    float getY() { return this->cy; }
    vector<float> get_rgb() { return { this->r, this->g, this->b }; }
};