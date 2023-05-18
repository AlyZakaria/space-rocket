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

class Mouse {

    public:
        Mouse(){}
        static void MMOUSE(int x, int y) {
            mouseX = x;
            mouseX=0.5+1.0*mouseX * logWidth/ phyWidth;
            mouseY = phyHeight - y;
            mouseY=0.5+1.0* mouseY*logHeight/phyHeight;
            glutPostRedisplay();
        }
        static void passiveMouse (int x,int y){
            mouseX = x;
            mouseX=0.5+1.0*mouseX*logWidth/phyWidth;
            mouseY = phyHeight - y;
            mouseY=0.5+1.0*mouseY*logHeight/phyHeight;
            glutPostRedisplay();

        }
};