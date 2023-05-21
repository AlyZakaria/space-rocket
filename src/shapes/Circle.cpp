
class Circle {
protected:
    float cx, cy;
    float raduis;
    float r = 1.0, g = 0.0, b = 0.0;
    int num_segments = 500;

public:
    Circle() {}
    Circle(float cx, float cy) {
        this->cx = cx;
        this->cy = cy;
    }
    Circle(float cx, float cy, float raduis, int num_segements) {
        this->cx = cx;
        this->cy = cy;
        this->num_segments = num_segements;
        this->raduis = raduis;
    }
    void draw() {
        glColor3f(r, g, b);
        glBegin(GL_POLYGON);
        for (int i = 0; i < num_segments; i++) {
            float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle
            float x = raduis * cosf(theta);//calculate the x component
            float y = raduis * sinf(theta);//calculate the y component
            glVertex2f(x + cx, y + cy);//output vertex
        }
        glEnd();
    }

    void set_rgb(float r, float g, float b) {
        if (r >= 0.0 && g >= 0.0 && b >= 0) {
            this->r = r;
            this->g = g;
            this->b = b;
        }
    }
    void set_Center(float x, float y) {
        if (x >= 0 && y >= 0) {
            this->cx = x;
            this->cy = y;
        }
    }
    void set_raduis(float raduis) {
        if (raduis >= 0) this->raduis = raduis;
    }
    void set_num_segments(int num_segments) {
        if (num_segments >= 0) this->num_segments = num_segments;
    }
    int get_raduis() { return this->raduis; }

};