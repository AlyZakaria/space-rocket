#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cstring>

using namespace std;

class Text {
private:

    float r = 1.0;
    float g = 1.0;
    float b = 1.0;
public:
    void printText(string text, int x, int y) {
        // for (auto i : text) cout << i << " ";
        glRasterPos2d(x, y);
        // int size = strlen(text);
        for (int i = 0; i < text.size(); i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
    void setColor(float r, float g, float b) {
        glColor3f(r, g, b);
    }

};