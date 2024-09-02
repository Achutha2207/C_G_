#include <GL/glut.h>

void init() {
    glClearColor(0.7, 0.9, 1.0, 1.0); // Light blue background color
    glEnable(GL_DEPTH_TEST); // Enable depth testing for 3D
}

void drawGround() {
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.8, 0.2); // Green ground color
    glVertex3f(-5.0, 0.0, -5.0);
    glVertex3f(-5.0, 0.0, 5.0);
    glVertex3f(5.0, 0.0, 5.0);
    glVertex3f(5.0, 0.0, -5.0);
    glEnd();
}

void drawTree() {
    glColor3f(0.8, 0.5, 0.2); // Brown trunk color
    glPushMatrix();
    glTranslatef(-1.5, 0.0, -1.5);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(1.0); // Trunk

    glColor3f(0.0, 0.6, 0.1); // Green leaf color
    glTranslatef(0.0, 0.8, 0.0);
    glutSolidSphere(0.8, 10, 10); // Leaves
    glPopMatrix();
}

void drawSun() {
    glColor3f(1.0, 1.0, 0.0); // Yellow sun color
    glPushMatrix();
    glTranslatef(3.0, 3.0, -3.0);
    glutSolidSphere(1.0, 20, 20); // Sun
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Set up the camera
    gluLookAt(3.0, 3.0, 5.0,  // eye position
        0.0, 0.0, 0.0,  // look-at position
        0.0, 1.0, 0.0); // up direction

    drawGround();
    drawTree();
    glPushMatrix();
    glTranslatef(2.0, 0.0, 2.0);
    drawTree();
    glPopMatrix();
    drawSun();

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (double)width / height, 1.0, 20.0); // perspective parameters
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Scenery");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}


