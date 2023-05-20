#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

class BackgroundGame : public Quad {

private:
    float r = 0.0, g = 0.0, b = 0.0;
    vector<Circle> circles;
    static BackgroundGame* BackgroundGame_;


protected:
    BackgroundGame(vector<vector<float>> vertices) {
        this->vertices = vertices;
    }


public:
    // BackgroundGame(const BackgroundGame& obj)
    //     = delete;
    static BackgroundGame* getInstance() {
        if (BackgroundGame_ == NULL)
            BackgroundGame_ = new BackgroundGame({ {0, 0}, {1000, 0}, {1000, 1000}, {0, 1000} });
        return BackgroundGame_;
    }
    void draw() {
        Quad::draw();

        for (int i = 0; i < 30; i++) {
            circles.push_back(Circle(rand() % 1000, rand() % 1000, 2, 500));
            circles[i].set_rgb(1.0, 1.0, 1.0);
            circles[i].draw();
        }
    }
};
