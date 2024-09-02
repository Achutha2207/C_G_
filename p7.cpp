#include <GL/glut.h>

// Initial size of the square
float size = 0.5f;

// Function to draw a square
void drawSquare(float centerX, float centerY, float size) {
    float halfSize = size / 2.0f;
    glBegin(GL_QUADS);
    glVertex2f(centerX - halfSize, centerY - halfSize);
    glVertex2f(centerX + halfSize, centerY - halfSize);
    glVertex2f(centerX + halfSize, centerY + halfSize);
    glVertex2f(centerX - halfSize, centerY + halfSize);
    glEnd();
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawSquare(0.0f, 0.0f, size);
    glFlush();
}

// Keyboard callback function
void keyboard(unsigned char key, int x, int y) {
    if (key == 'i' || key == 'I') {
        size += 0.1f; // Increase size
    }
    else if (key == 'd' || key == 'D') {
        size -= 0.1f; // Decrease size
    }
    glutPostRedisplay(); // Request a redraw
}

// Mouse callback function
void mouse(int button, int state, int x, int y) {
    if (state == GLUT_DOWN) {
        if (button == GLUT_LEFT_BUTTON) {
            size += 0.1f; // Increase size
        }
        else if (button == GLUT_RIGHT_BUTTON) {
            size -= 0.1f; // Decrease size
        }
        glutPostRedisplay(); // Request a redraw
    }
}

// Initialization function
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
    glColor3f(0.0, 0.0, 0.0); // Black drawing color
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Define the viewing area
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Resize Square");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}


