#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdlib.h>
#include "src/tools/Screen.cpp"
#include "src/tools/Mouse.cpp"
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
    newGame.main(argc, argv);

    glutMainLoop();
}