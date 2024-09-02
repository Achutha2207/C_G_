#include <GL/glut.h>
#include <cmath>
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}
void drawTriangle() {
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.8f, -0.5f);
    glVertex2f(-0.2f, -0.5f);
    glVertex2f(-0.5f, 0.1f);
    glEnd();
}
void drawRectangle() {
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.2f, -0.5f);
    glVertex2f(0.8f, -0.5f);
    glVertex2f(0.8f, 0.1f);
    glVertex2f(0.2f, 0.1f);
    glEnd();
}
void drawHexagon() {
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 6; ++i) {
        glVertex2f(0.3f * cos(i * 2.0f * 3.1415926f / 6.0f),
            0.3f * sin(i * 2.0f * 3.1415926f / 6.0f));
    }
    glEnd();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawTriangle();
    drawRectangle();
    glPushMatrix();
    glTranslatef(0.0f, 0.6f, 0.0f);
    drawHexagon();
    glPopMatrix();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Shapes with GLUT");
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(50, 50);
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

