#include <GL/glut.h>
float balloonX = 0.0f;  // Balloon x-coordinate
float balloonY = 0.0f;
float balloonColorR = 1.0f;  // Balloon color (red component)
float balloonColorG = 0.0f;  // Balloon color (green component)
float balloonColorB = 0.0f;  // Balloon color (blue component)

void drawBalloon()
{   
    // Set balloon color
    glColor3f(balloonColorR, balloonColorG, balloonColorB);

    // Balloon body
    glutSolidSphere(0.1f, 20, 20);
    glutSolidSphere(0.1f, 20, 20);
    
    
    // Balloon basket
    glColor3f(0.6f, 0.3f, 0.0f);
    glPushMatrix();
    glTranslatef(0.0f, -0.15f, 0.0f);
    glutSolidCube(0.1f);
    glPopMatrix();
}

void drawCloud(float x, float y)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    // Draw cloud
    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_POLYGON);
    glVertex2f(0.1f, 0.05f);
    glVertex2f(0.15f, 0.1f);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(0.25f, 0.05f);
    glVertex2f(0.2f, 0.0f);
    glVertex2f(0.15f, 0.0f);
    glEnd();
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    // Draw sky blue background
    glClearColor(0.529f, 0.808f, 0.922f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw cloud structures in the background
    drawCloud(-0.7f, 0.7f);
    drawCloud(-0.4f, 0.8f);
    drawCloud(0.1f, 0.6f);
    drawCloud(-0.4f, 0.7f);
    drawCloud(0.7f, 0.8f);

    // Draw the moving balloon
    glPushMatrix();
    glTranslatef(balloonX, balloonY, 0.0f);
    drawBalloon();
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

void handleKeypress(unsigned char key, int x, int y)
{
    // Move the balloon based on number keys
    switch (key) {
        case '8':
            balloonY += 0.05f;
            break;
        case '4':
            balloonX -= 0.05f;
            break;
        case '2':
            balloonY -= 0.05f;
            break;
        case '6':
            balloonX += 0.05f;
            break;
        case 'r':
            balloonColorR = 1.0f;
            balloonColorG = 0.0f;
            balloonColorB = 0.0f;
            break;
        case 'g':
            balloonColorR = 0.0f;
            balloonColorG = 1.0f;
            balloonColorB = 0.0f;
            break;
        case 'b':
            balloonColorR = 0.0f;
            balloonColorG = 0.0f;
            balloonColorB = 1.0f;
            break;
        case 'q':
            exit(0);
            break;
    }
      glutPostRedisplay();
  }

int main(int argc, char** argv)

{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Sky with Balloon");
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    glutMainLoop();

    return 0;
}



