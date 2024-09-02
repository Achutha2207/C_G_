#include <GL/glut.h>
#include <stdlib.h>

// Global variables
int viewMode = 0; // 0: Perspective, 1: Orthographic, 2: Oblique

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

void setView() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (viewMode == 0) {
        // Perspective view
        gluPerspective(45.0, 1.0, 1.0, 10.0);
    }
    else if (viewMode == 1) {
        // Orthographic view
        glOrtho(-2.0, 2.0, -2.0, 2.0, 1.0, 10.0);
    }
    else if (viewMode == 2) {
        // Oblique view
        glLoadIdentity();  // Reset the modelview matrix

        // Apply transformations directly
        glTranslatef(0.0, 0.0, -2.0);
        glRotatef(45.0, 0.0, 1.0, 0.0);

        // Set up the orthographic projection separately
        glOrtho(-2.0, 2.0, -2.0, 2.0, 1.0, 10.0);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(2.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void drawCube() {
    glBegin(GL_QUADS);

    // Front face
    glColor3f(1.0, 0.0, 0.0); // Red
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);

    // Back face
    glColor3f(0.0, 1.0, 0.0); // Green
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);

    // Top face
    glColor3f(0.0, 0.0, 1.0); // Blue
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);

    // Bottom face
    glColor3f(1.0, 1.0, 0.0); // Yellow
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);

    // Right face
    glColor3f(1.0, 0.0, 1.0); // Magenta
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);

    // Left face
    glColor3f(0.0, 1.0, 1.0); // Cyan
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    setView();
    drawCube();
    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    setView();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case '1':
        viewMode = 0; // Perspective view
        break;
    case '2':
        viewMode = 1; // Orthographic view
        break;
    case '3':
        viewMode = 2; // Oblique view
        break;
    case 27: // ESC key
        exit(0);
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Object Viewer");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}

