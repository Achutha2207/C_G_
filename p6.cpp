
#include <GL/glut.h>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

// Global variables to store the color of the triangle
float red = 1.0f, green = 0.0f, blue = 0.0f;

// Function to draw a triangle
void drawTriangle() {
    glBegin(GL_TRIANGLES);
    glColor3f(red, green, blue); // Set the current color
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawTriangle();
    glFlush();
}

// Mouse callback function
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Generate random colors
        red = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        green = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        blue = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);

        // Request a redisplay
        glutPostRedisplay();
    }
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set the background color to black
}

int main(int argc, char** argv) {
    srand(static_cast<unsigned>(time(0))); // Seed the random number generator
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Triangle Color Change");
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}

