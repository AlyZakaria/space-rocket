
class Text {
private:

    float r = 1.0;
    float g = 1.0;
    float b = 1.0;
public:
    void printText(string text, int x, int y) {
        glRasterPos2d(x, y);
        for (int i = 0; i < text.size(); i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
    void setColor(float r, float g, float b) {
        glColor3f(r, g, b);
    }

};