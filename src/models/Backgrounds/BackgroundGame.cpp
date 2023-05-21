
// make the background a singleton class
// To ensure random circles are generated only once
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

    static BackgroundGame* getInstance() {
        if (BackgroundGame_ == NULL)
            BackgroundGame_ = new BackgroundGame({ {0, 0}, {1000, 0}, {1000, 1000}, {0, 1000} });
        return BackgroundGame_;
    }
    void draw() {
        // call the parent method to draw the background
        Quad::draw();
        for (int i = 0; i < 30; i++) {
            // generate random circles
            circles.push_back(Circle(rand() % 1000, rand() % 1000, 2, 500));
            circles[i].set_rgb(1.0, 1.0, 1.0);
            circles[i].draw();
        }
    }
};
