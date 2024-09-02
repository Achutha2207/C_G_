#include <GL/glut.h>
#include <cmath>

float angle = 0.0f;           // Rotation angle
float scaleX = 1.0f;          // Scale factor along the X-axis
float scaleY = 1.0f;          // Scale factor along the Y-axis
float transX = 0.0f;          // Translation along the X-axis
float transY = 0.0f;          // Translation along the Y-axis
int startX, startY;           // Initial mouse click position

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);  // Set background color to white
    glColor3f(0.0, 0.0, 0.0);          // Set drawing color to black
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 800.0, 0.0, 600.0); // Set coordinate system
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();  // Save the current transformation matrix

    glTranslatef(transX, transY, 0.0f);  // Apply translation
    glRotatef(angle, 0.0f, 0.0f, 1.0f);  // Apply rotation
    glScalef(scaleX, scaleY, 1.0f);      // Apply scaling

    // Draw a rectangle
    glBegin(GL_POLYGON);
    glVertex2f(-50.0f, -25.0f);
    glVertex2f(50.0f, -25.0f);
    glVertex2f(50.0f, 25.0f);
    glVertex2f(-50.0f, 25.0f);
    glEnd();

    glPopMatrix();  // Restore the previous transformation matrix

    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'r': angle += 10.0f; break;            // Rotate clockwise
    case 'R': angle -= 10.0f; break;            // Rotate counterclockwise
    case 'x': scaleX += 0.1f; break;            // Scale up along X-axis
    case 'X': scaleX -= 0.1f; break;            // Scale down along X-axis
    case 'y': scaleY += 0.1f; break;            // Scale up along Y-axis
    case 'Y': scaleY -= 0.1f; break;            // Scale down along Y-axis
    case 27: exit(0);                           // Escape key to exit
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        startX = x;
        startY = glutGet(GLUT_WINDOW_HEIGHT) - y;
    }
}

void motion(int x, int y) {
    int endX = x;
    int endY = glutGet(GLUT_WINDOW_HEIGHT) - y;

    transX += (endX - startX);
    transY += (endY - startY);

    startX = endX;
    startY = endY;

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Geometric Transformations");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();

    return 0;
}

