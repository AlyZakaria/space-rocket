#include <program.h>
#include <tools.h>
#include <shapes.h>
#include "src/Game.cpp"
#include "src/tools/Keyboard.cpp"


using namespace std;


Game newGame = Game();

void display() {
    newGame.display();
}


int main(int argc, char** argv) {

    newGame.init(0.0, 0.0, 0.0);
    glutDisplayFunc(display);
    glutKeyboardFunc(Keyboard::keyPress);
    glutSpecialFunc(Keyboard::specialKeyPress);
    newGame.main(argc, argv);

    glutMainLoop();
}