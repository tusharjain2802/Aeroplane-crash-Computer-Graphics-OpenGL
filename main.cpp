#include <stdio.h>
#include <GL/glut.h>
#include <cmath>
GLfloat a = 0, c = 0, e = 0;

void blast();
void display2();

GLfloat R = 1.0, G = 0.0, B = 0.0;
void hill()
{
    glColor3f(0, 0.4, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(400.0, 450.0);
    glVertex2f(335.0, 80.0);
    glVertex2f(400.0, 50.0);
    glEnd();
    glColor3f (0.0117, 0.7137, 0.0392);
    glBegin(GL_TRIANGLES);
    glVertex2f(400.0, 450.0);
    glVertex2f(400.0, 50.0);
    glVertex2f(475.0, 50.0);
    glEnd();


}
void mountain(){
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.8);
    glVertex2i(-60, 310);
    glVertex2i(110, 325);
    glVertex2i(30, 366);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.8);
    glVertex2i(40, 310);
    glVertex2i(230, 325);
    glVertex2i(150, 366);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.8);
    glVertex2i(140, 310);
    glVertex2i(350, 325);
    glVertex2i(270, 366);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.8);
    glVertex2i(240, 313);
    glVertex2i(470, 325);
    glVertex2i(390, 366);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.8);
    glVertex2i(440, 313);
    glVertex2i(570, 325);
    glVertex2i(490, 346);
    glEnd();
}

void trees(){
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.3, 0.0);
    glVertex2i(312, 310);
    glVertex2i(312, 333);
    glVertex2i(309, 333);
    glVertex2i(309, 310);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2i(290, 330);
    glVertex2i(330, 330);
    glVertex2i(310, 380);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.3, 0.0);
    glVertex2i(212, 310);
    glVertex2i(212, 333);
    glVertex2i(209, 333);
    glVertex2i(209, 310);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2i(190, 330);
    glVertex2i(230, 330);
    glVertex2i(210, 380);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.3, 0.0);
    glVertex2i(112, 310);
    glVertex2i(112, 333);
    glVertex2i(109, 333);
    glVertex2i(109, 310);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2i(90, 330);
    glVertex2i(130, 330);
    glVertex2i(110, 380);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.3, 0.0);
    glVertex2i(12, 310);
    glVertex2i(12, 333);
    glVertex2i(9, 333);
    glVertex2i(9, 310);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2i(-10, 330);
    glVertex2i(30, 330);
    glVertex2i(10, 380);
    glEnd();
}

void color(int id)
{
    switch (id)
    {
    case 1:
        R = 1.0, G = 0.0, B = 0.0;
        glutPostRedisplay();
        break;
    case 2:
        R = 0.0, G = 1.0, B = 1.0;
        glutPostRedisplay();
        break;
    case 3:
        R = 1.0, G = 0.0, B = 1.0;
        glutPostRedisplay();
        break;
    }
}
int pntX1, pntY1;
void update(int value)
{
    a += 20.0; // Plane position takeoff on x axis
    c += 15;   // take off at certain angle on y axis
    glutPostRedisplay();
    glutTimerFunc(150, update, 0); // delay
}
void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2f(x + pntX1, y + pntY1);
    glEnd();
}

void bresenham_circle(int r)
{
    glColor3f(1, 1, 0.34);
    pntX1 = 100;
    pntY1 = 450;
    int x = 0;
    int y = r;
    float d = 3 - 2 * r;
    plot(x, y);

    while (y > x)
    {
        if (d < 0)
        {
            d += 4 * x + 6;
            x++;
        }
        else
        {
            d += 4 * (x - y) + 10;
            y--;
            x++;
        }
        plot(x, y);
        plot(x, -y);
        plot(-x, y);
        plot(-x, -y);
        plot(y, x);
        plot(-y, x);
        plot(y, -x);
        plot(-y, -x);
    }
}
void midPointCircleAlgo(int r)
{
    glColor3f(1, 0.858, 0.345);
    int x = 0;
    int y = r;
    pntX1 = 100;
    pntY1 = 450;
    float d = 5 / 4 - r;
    plot(x, y);

    while (y > x)
    {
        if (d < 0)
        {
            d += 2 * x + 3;
            x++;
        }
        else
        {
            d += 2 * (x - y) + 5;
            y--;
            x++;
        }
        plot(x, y);
        plot(x, -y);
        plot(-x, y);
        plot(-x, -y);
        plot(y, x);
        plot(-y, x);
        plot(y, -x);
        plot(-y, -x);
    }
}
void fillCircle(int xc, int yc, int radius)
{
    float xb1 = xc, yb11 = yc, xb2, yb2;
    float angle;

    glColor3f(1, 0.858, 0.345);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xb1, yb11);
    for (angle = 1.0f; angle < 361.0f; angle += 0.2)
    {
        xb2 = xb1 + cos(angle) * radius;
        yb2 = yb11 + sin(angle) * radius;
        glVertex2f(xb2, yb2);
    }
    glEnd();
}
void drawSunRays(int xc, int yc, int numRays, int rayLength)
{
    float angleIncrement = 360.0f / numRays; // Angle between each ray in degrees
    float angle = 0.0f;                      // Initial angle in degrees

    glBegin(GL_LINES);
    glColor3f(1, 0.858, 0.345);
    for (int i = 0; i < numRays; i++)
    {
        float startX = xc + rayLength * cos(angle * M_PI / 180.0f);      // Calculate start point x-coordinate
        float startY = yc + rayLength * sin(angle * M_PI / 180.0f);      // Calculate start point y-coordinate
        float endX = xc + rayLength * 1.5f * cos(angle * M_PI / 180.0f); // Calculate end point x-coordinate
        float endY = yc + rayLength * 1.5f * sin(angle * M_PI / 180.0f); // Calculate end point y-coordinate

        glVertex2f(startX, startY); // Set start point
        glVertex2f(endX, endY);     // Set end point

        angle += angleIncrement; // Increment angle for the next ray
    }
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    // glColor3f(1, 0.858, 0.345);
    midPointCircleAlgo(20);
    bresenham_circle(25);
    drawSunRays(pntX1, pntY1, 30, 26);
    fillCircle(pntX1, pntY1, 20);
    mountain();
    trees();

    glFlush();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0); // green ground

    glVertex2i(0, 300);

    glVertex2i(645, 310);

    glVertex2i(940, 0);

    glVertex2i(0, 0);
    glEnd();
    glFlush();
    glPushMatrix();
    glTranslatef(a, c, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON); // rectangular body
    glVertex2f(0.0, 30.0);
    glVertex2f(0.0, 55.0);
    glVertex2f(135.0, 55.0);
    glVertex2f(135.0, 30.0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(a, c, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON); // upper triangle construction plane
    glVertex2f(135.0, 55.0);
    glVertex2f(150.0, 50.0);
    glVertex2f(155.0, 45.0);
    glVertex2f(160.0, 40.0);
    glVertex2f(135.0, 40.0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(a, c, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP); // outline of upper triangle plane
    glVertex2f(135.0, 55.0);
    glVertex2f(150.0, 50.0);
    glVertex2f(155.0, 45.0);
    glVertex2f(160.0, 40.0);
    glVertex2f(135.0, 40.0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(a, c, 0.0);
    glColor3f(R, G, B);
    glBegin(GL_POLYGON); // lower triangle
    glVertex2f(135.0, 40.0);
    glVertex2f(160.0, 40.0);
    glVertex2f(160.0, 37.0);
    glVertex2f(145.0, 30.0);
    glVertex2f(135.0, 30.0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(a, c, 0.0);
    glColor3f(R, G, B);
    glBegin(GL_POLYGON); // back wing
    glVertex2f(0.0, 55.0);
    glVertex2f(0.0, 80.0);
    glVertex2f(10.0, 80.0);
    glVertex2f(40.0, 55.0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(a, c, 0.0);
    glColor3f(R, G, B);
    glBegin(GL_POLYGON); // left side wing
    glVertex2f(65.0, 55.0);
    glVertex2f(50.0, 70.0);
    glVertex2f(75.0, 70.0);
    glVertex2f(90.0, 55.0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(a, c, 0.0);
    glColor3f(R, G, B);
    glBegin(GL_POLYGON); // rightside wing
    glVertex2f(70.0, 40.0);
    glVertex2f(100.0, 40.0);
    glVertex2f(80.0, 15.0);
    glVertex2f(50.0, 15.0);
    glEnd();
    glPopMatrix();
    if (a > 500.0) // window position during take off
    {
        a = 0.0;
    }
    if (c > 300) // timer to jump to 2nd display
    {
        display2();
        e += 20;     // plane takeoff on x in 2nd display
        if (e > 250) // timer to call blast function
        {
            blast();
            e = 250;
        }
    }
    glFlush();
}

void blast(void) // blast polygon construction
{
    glPushMatrix();
    glTranslatef(-10.0, -60.0, 0.0);
    glColor3f(R, G, B);
    glBegin(GL_POLYGON);
    glVertex2f(404.4, 320.0);
    glVertex2f(384.0, 285.0);
    glVertex2f(368.0, 344.5);
    glVertex2f(344.0, 355.0);
    glVertex2f(347.2, 414.5);
    glVertex2f(332.8, 442.5);
    glVertex2f(347.2, 477.5);
    glVertex2f(352.0, 530.0);
    glVertex2f(379.2, 519.5);
    glVertex2f(396.8, 565.0);
    glVertex2f(416.0, 530.0);
    glVertex2f(440.0, 547.5);
    glVertex2f(452.8, 512.5);
    glVertex2f(472.0, 512.5);
    glVertex2f(475.2, 470.5);
    glVertex2f(488.0, 442.5);
    glVertex2f(488.0, 404.0);
    glVertex2f(470.0, 372.5);
    glVertex2f(475.2, 337.5);
    glVertex2f(464.0, 306.0);
    glVertex2f(444.8, 320.0);
    glVertex2f(425.6, 285.0);
    glVertex2f(404.8, 320.0);
    glEnd();
    glPopMatrix();
}
void display2()
{
    glClear(GL_COLOR_BUFFER_BIT);
    midPointCircleAlgo(20);
    bresenham_circle(25);
    drawSunRays(pntX1, pntY1, 30, 26);
    fillCircle(pntX1, pntY1, 20);
    mountain();
    trees();
    glFlush();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0); // green ground
    glVertex2i(0, 300);
    glVertex2i(645, 310);
    glVertex2i(940, 0);
    glVertex2i(0, 0);
    glEnd();
    glFlush();

    hill();
    glPushMatrix();
    glTranslatef(e, 300.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 30.0);
    glVertex2f(0.0, 55.0);
    glVertex2f(135.0, 55.0);
    glVertex2f(135.0, 30.0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(e, 300.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(135.0, 55.0);
    glVertex2f(150.0, 50.0);
    glVertex2f(155.0, 45.0);
    glVertex2f(160.0, 40.0);
    glVertex2f(135.0, 40.0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(e, 300.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(135.0, 55.0);
    glVertex2f(150.0, 50.0);
    glVertex2f(155.0, 45.0);
    glVertex2f(160.0, 40.0);
    glVertex2f(135.0, 40.0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(e, 300.0, 0.0);
    glColor3f(R, G, B);
    glBegin(GL_POLYGON);
    glVertex2f(135.0, 40.0);
    glVertex2f(160.0, 40.0);
    glVertex2f(160.0, 37.0);
    glVertex2f(145.0, 30.0);
    glVertex2f(135.0, 30.0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(e, 300.0, 0.0);
    glColor3f(R, G, B);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 55.0);
    glVertex2f(0.0, 80.0);
    glVertex2f(10.0, 80.0);
    glVertex2f(40.0, 55.0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(e, 300.0, 0.0);
    glColor3f(R, G, B);
    glBegin(GL_POLYGON);
    glVertex2f(65.0, 55.0);
    glVertex2f(50.0, 70.0);
    glVertex2f(75.0, 70.0);
    glVertex2f(90.0, 55.0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(e, 300.0, 0.0);
    glColor3f(R, G, B);
    glBegin(GL_POLYGON);
    glVertex2f(70.0, 40.0);
    glVertex2f(100.0, 40.0);
    glVertex2f(80.0, 15.0);
    glVertex2f(50.0, 15.0);
    glEnd();
    glPopMatrix();
}
void myinit()
{
    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}
int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Plane Crash Animation");
    glutDisplayFunc(display);
    glutCreateMenu(color);
    glutAddMenuEntry("Red", 1);
    glutAddMenuEntry("Cyan", 2);
    glutAddMenuEntry("Purple", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    myinit();
    glutTimerFunc(100, update, 0);
    glutMainLoop();
}
