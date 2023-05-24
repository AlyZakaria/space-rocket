#include <program.h>

using namespace std;

class BackgroundEndGame : public Background {
private:
    vector<stringstream> texts;
    Text message;
    float x = 400.0, y = 700.0;
    Quad quad;
public:
    BackgroundEndGame(vector<stringstream>& texts) {
        // draw background
        quad = Quad({ {0, 0}, {0, logHeight}, {logWidth, logHeight}, {logWidth, 0} });
        quad.draw_gradient({ {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0} });
        for (auto& text : texts) {
            message.setColor(1.0, 1.0, 1.0);
            if (text.str() == "Your Score is ") text << asteroidDestroyed;
            message.printText(text.str(), x, y);
            y -= 100;
        }
    }

};