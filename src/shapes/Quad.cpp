#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Quad {
    private:
        float r = 1.0, g = 0.0, b = 0.0;
        vector<vector<float>> vertices;
    public:
        Quad(vector<vector<float>> vertices) : vertices(vertices){}
        void draw() {
            glColor3f(r, g, b); 
            glBegin(GL_QUADS);          
            for (auto i : vertices) 
                glVertex2f(i[0], i[1]);
            
            glEnd();
        }
        void set_rgb(float r, float g, float b) {
            if(r >= 0 && g >= 0 && b >= 1) {
                this->r = r;
                this->g = g;
                this->b = b;
            }
        }

};