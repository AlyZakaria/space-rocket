
class Quad {
protected:
    float r = 0.0, g = 0.0, b = 1.0;
    vector<vector<float>> vertices;
public:
    Quad() {}
    Quad(vector<vector<float>> vertices) : vertices(vertices) {}
    void draw() {
        glColor3f(this->r, this->g, this->b);
        glBegin(GL_QUADS);
        for (auto i : vertices)
            glVertex2i(i[0], i[1]);
        glEnd();
    }
    void draw_gradient(vector<vector<float>> gradient) {
        glBegin(GL_QUADS);
        for (int i = 0; i < 4; i++) {
            glColor3f(gradient[i][0], gradient[i][1], gradient[i][2]);
            glVertex2i(vertices[i][0], vertices[i][1]);
        }
        glEnd();
    }
    void set_rgb(float r, float g, float b) {
        if (r >= 0 && g >= 0 && b >= 0) {
            this->r = r;
            this->g = g;
            this->b = b;
        }
    }


};