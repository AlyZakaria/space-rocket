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

class Triangle {
    private:
        float r = 0.0, g = 1.0, b = 0.0;
        vector<vector<float>> vertices;
public:
        Triangle(vector<vector<float>> vertices) : vertices(vertices){}
        void draw() {
            glColor3f(r, g, b); 
            glBegin(GL_TRIANGLES);          
                for (auto i : vertices) 
                    glVertex2f(i[0], i[1]);
            glEnd();
        }
        void set_rgb(float r, float g, float b) {
            if(r >= 0 && g >= 0 && b >= 0) {
                this->r = r;
                this->g = g;
                this->b = b;
            }
        }

};
