#include <GL/glut.h>
#include <cmath>
#include <cstdlib>

const double TWO_PI = 6.2831853;
GLsizei winwidth = 400, winheight = 400;

class ScreenPt {
public:
    GLint x, y;
};

ScreenPt hexVertex[6];
GLint hexRadius = 120;

void updateHexVertices(GLsizei width, GLsizei height) {
    ScreenPt center;
    center.x = width / 2;
    center.y = height / 2;

    for (int k = 0; k < 6; ++k) {
        double theta = TWO_PI * k / 6;
        hexVertex[k].x = center.x + hexRadius * cos(theta);
        hexVertex[k].y = center.y + hexRadius * sin(theta);
    }
}

void init() {
    glClearColor(1.0, 0.0, 1.0, 0.0); // Set the background color to purple
    glColor3f(1.0, 1.0, 0.0); // Set the drawing color to yellow
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, winwidth, 0.0, winheight);

    updateHexVertices(winwidth, winheight);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
    for (int k = 0; k < 6; ++k) {
        glVertex2i(hexVertex[k].x, hexVertex[k].y);
    }
    glEnd();

    glFlush();
}

void reshape(int newWidth, int newHeight) {
    glViewport(0, 0, (GLsizei)newWidth, (GLsizei)newHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)newWidth, 0.0, (GLdouble)newHeight);

    updateHexVertices(newWidth, newHeight);

    display();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winwidth, winheight);
    glutCreateWindow("Hexagon Reshape Example");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}


