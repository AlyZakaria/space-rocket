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

using namespace std;


class SpaceRocket {

    private:
        float rocketX = 250.0;
        float rocketY = 250.0;
        float bodyWidth = 50.0;
        float bodyHeight = 100.0;
        Quad body;
        vector<Triangle> triangles;
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
                        Triangle({{rocketX + (bodyWidth/2), rocketY - (bodyHeight / 2)}, {rocketX+(bodyWidth / 10), rocketY - bodyHeight + 20}, {rocketX + (bodyWidth / 10), rocketY - (bodyHeight / 2)}}) };
        }
        void draw() {
            body.set_rgb(0.0, 0.0, 1);
            body.draw();
            for (auto i = triangles.begin(); i != triangles.end(); ++i) {
                auto final = triangles.end() - 2;
                // for the fires && setting the color to yellow
                if (i == final || i == final + 1) 
                    i->set_rgb(255, 215, 0.0);
                
                i->draw();
            }
        }

};