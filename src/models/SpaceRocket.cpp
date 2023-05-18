#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#include "../shapes/Triangle.cpp"
#include "../shapes/Circle.cpp"
#include "../shapes/Quad.cpp"
#include "LaserBeam.cpp"
using namespace std;


class SpaceRocket {

    private:
        float rocketX = 250.0;
        float rocketY = 250.0;
        float bodyWidth = 25.0;
        float bodyHeight = 50.0;
        Quad body;
        vector<Triangle> triangles;
        LaserBeam laserBeam;
public:
        SpaceRocket(float rocketX, float rocketY) {
            this->rocketX = rocketX;
            this->rocketY = rocketY;
            body = Quad({       {rocketX -( bodyWidth / 2), rocketY - (bodyHeight / 2)},
                                {rocketX +( bodyWidth / 2), rocketY - (bodyHeight / 2)},
                                {rocketX +( bodyWidth / 2), rocketY + (bodyHeight / 2)},
                                {rocketX -( bodyWidth / 2), rocketY + (bodyHeight / 2)} });
            triangles = {
                        Triangle({{rocketX - (bodyWidth / 2), rocketY + (bodyHeight / 2)}, {rocketX + (bodyWidth / 2), rocketY + (bodyHeight / 2)}, {rocketX , rocketY + bodyHeight}}) ,
                        Triangle({{rocketX - (bodyWidth / 2), rocketY - (bodyHeight / 2)}, {rocketX - (bodyWidth / 2), rocketY}, {rocketX - bodyWidth, rocketY - (bodyHeight / 2)}}) ,
                        Triangle({{rocketX + (bodyWidth / 2), rocketY - (bodyHeight / 2)}, {rocketX + (bodyWidth / 2), rocketY}, {rocketX + bodyWidth, rocketY - (bodyHeight / 2)}}),
                        Triangle({{rocketX - (bodyWidth/2), rocketY - (bodyHeight / 2)}, {rocketX- (bodyWidth / 10), rocketY - bodyHeight + 20}, {rocketX - (bodyWidth / 10), rocketY - (bodyHeight / 2) }}),
                        Triangle({{rocketX + (bodyWidth / 2), rocketY - (bodyHeight / 2)}, {rocketX + (bodyWidth / 10), rocketY - bodyHeight + 20}, {rocketX + (bodyWidth / 10), rocketY - (bodyHeight / 2)}}) };
            laserBeam = LaserBeam(rocketX, rocketY, bodyWidth, bodyHeight);
        }
        void draw() {
            laserBeam.draw();
            body.set_rgb(0.0/255, 188.0/255.0, 255.0/255.0);
            body.draw();
            for (auto i = triangles.begin(); i != triangles.end(); ++i) {
                auto final = triangles.end() - 2;
                // for the fires && setting the color to yellow
                if (i == triangles.begin())
                    i->set_rgb(255.0/255.0, 188.0/255.0, 0.0/255.0);
                else if (i == final || i == final + 1)
                    i->set_rgb(255, 215, 0.0);
                else
                    i->set_rgb(255.0/255.0, 188.0/255.0, 0.0/255.0);
                    i->draw();
            }
        }

};