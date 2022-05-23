#include <windows.h>
#include <GL/glut.h>
#include <math.h>

int i, putar = 0, a = 0, b = 0, c = 0, d = 0;
int gerak = 9.0;

void myInit(void){
    glLineWidth(3.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300.0,300.0,-300.0,300.0);

}

void myDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT);

    //glClearColor(1-(putar*0.05),(putar*0.0125),(putar*0.025)
    if(putar%2==1)glClearColor(0,0,1,1);
    else glClearColor(0.5,0,1,1);

    //persegi panjang
    if(putar%2==0){
        glColor3f(1,0,1);
    }else{
        glColor3f(0,1,1);
    }
    glPushMatrix();
    glRotated(a+=10,0,0,1);
    glBegin(GL_POLYGON);
    glVertex2f(-40,10);
    glVertex2f(-40,-10);
    glVertex2f(40,-10);
    glVertex2f(40,10);
    glEnd();
    glPopMatrix();

    //persegi panjang
    if(putar%2==0){
        glColor3f(1,0.5,0);
    }else{
        glColor3f(1,1,1);
    }
    glPushMatrix();
    glRotated(b-=10,0,0,1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-40,10);
    glVertex2f(-40,-10);
    glVertex2f(40,-10);
    glVertex2f(40,10);
    glEnd();
    glPopMatrix();

    //persegi
    glPushMatrix();
    glRotated(c+=10,0,0,1);
    if(putar%2==0){
        glColor3f(1,0,0);
    }else{
        glColor3f(0,1,0);
        glScalef(0.5,0.5,1);
    }
    glRectf(100,50,150,100);
    glPopMatrix();

    //segitiga
    glPushMatrix();
    glRotated(d-=10,0,0,1);
    if(putar%2==0){
        glTranslatef(-200,0,0);
        glScalef(0.5,0.5,1);
        glColor3f(0,1,0);
    }else{
        glTranslatef(-150,0,0);
        glColor3f(1,0,0);
    }
    glBegin(GL_TRIANGLES);
        glVertex2f(50,100);
        glVertex2f(-50,100);
        glVertex2f(0,0);
    glEnd();
    glPopMatrix();

    putar++;
    glFlush();
}

void timer(int value){
    gerak -=2.5;
    glutPostRedisplay();
    glutTimerFunc(500,timer,0);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(300,100);
    glutCreateWindow("Gruda Sakti Krida Prastya - 672019252");
    glutDisplayFunc(myDisplay);
    myInit();
    timer(0);
    glutMainLoop();
    return 0;
}
