
class Keyboard {
public:
    Keyboard() {}
    static void keyPress(unsigned char key, int x, int y) {
        // speasebar to change the color of the laser beam
        if (key == 32)
            LaserBeam::iterator = (LaserBeam::iterator + 1) % 3;
        glutPostRedisplay();
    }
    static void specialKeyPress(int key, int x, int y) {
        // check if the game is over or timeout has occured 
        // so you can restart the game
        if (key == GLUT_KEY_F1 && (timer <= 0 || gameOver)) {
            timer = 20;
            noAsteroid = 0;
            asteroidDestroyed = 0;
            gameOver = false;
        }
        glutPostRedisplay();
    }
};