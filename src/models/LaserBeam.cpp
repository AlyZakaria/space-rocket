
class LaserBeam {
private:
    float x;
    float y;
    float bodyWidth;
    float bodyHeight;
    vector<vector<float>> color = { {1,0,0} , {0,1,0} , {0,0,1} };
    Quad laser;
public:
    static int iterator;
    LaserBeam() {}
    LaserBeam(float x, float y, float bodyWidth, float bodyHeight) : x(x), y(y), bodyWidth(bodyWidth), bodyHeight(bodyHeight) {
        laser = Quad({ {x - (bodyWidth / 2), y + (bodyHeight / 2)}, {x + (bodyWidth / 2), y + (bodyHeight / 2)},
                    {x + (bodyWidth / 2), logHeight} , {x - (bodyWidth / 2), logHeight} });

    };
    void draw() {
        laser.set_rgb(color[iterator][0], color[iterator][1], color[iterator][2]);
        laser.draw();
    }
    vector<float> get_rgb() { return { color[iterator][0], color[iterator][1], color[iterator][2] }; };

};
int LaserBeam::iterator = 0;