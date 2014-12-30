#include <stdio.h>
#include <GL/glut.h>

// obyek yang akan digambar
void draw(){
    //meja
    glColor3f(0, 0, 1);
    glPushMatrix();
    glScaled(2, 0.1, 1);
    glutSolidCube(0.8);
    glPopMatrix();

    //net
    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslated(0, 0.045, 0.41);
    glScaled(0.05, 0.3, 0.05);
    glutSolidCube(0.5);
    glPopMatrix();

    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslated(0, 0.045, -0.41);
    glScaled(0.05, 0.3, 0.05);
    glutSolidCube(0.5);
    glPopMatrix();

    glColor3f(1, 1, 1);
    glPushMatrix();
    glTranslated(0, 0.045, 0);
    glScaled(0.05, 0.3, 1.6);
    glutSolidCube(0.5);
    glPopMatrix();

    //garis meja
    glColor3f(1, 1, 1);
    glPushMatrix();
    glTranslated(0, 0.04, 0);
    glScaled(1.9, 0.01, 0.01);
    glutSolidCube(0.8);
    glPopMatrix();

    glColor3f(1, 1, 1);
    glPushMatrix();
    glTranslated(0, 0.04, 0.38);
    glScaled(1.9, 0.01, 0.01);
    glutSolidCube(0.8);
    glPopMatrix();

    glColor3f(1, 1, 1);
    glPushMatrix();
    glTranslated(0, 0.04, -0.38);
    glScaled(1.9, 0.01, 0.01);
    glutSolidCube(0.8);
    glPopMatrix();

    glColor3f(1, 1, 1);
    glPushMatrix();
    glTranslated(0.755, 0.04, 0);
    glScaled(0.01, 0.01, 0.95);
    glutSolidCube(0.8);
    glPopMatrix();

    glColor3f(1, 1, 1);
    glPushMatrix();
    glTranslated(-0.755, 0.04, 0);
    glScaled(0.01, 0.01, 0.95);
    glutSolidCube(0.8);
    glPopMatrix();

    //kaki meja
    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslated(0.5, -0.18, 0.2);
    glScaled(0.05, 0.7, 0.05);
    glutSolidCube(0.5);
    glPopMatrix();

    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslated(-0.5, -0.18, 0.2);
    glScaled(0.05, 0.7, 0.05);
    glutSolidCube(0.5);
    glPopMatrix();

    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslated(-0.5, -0.18, -0.2);
    glScaled(0.05, 0.7, 0.05);
    glutSolidCube(0.5);
    glPopMatrix();

    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslated(0.5, -0.18, -0.2);
    glScaled(0.05, 0.7, 0.05);
    glutSolidCube(0.5);
    glPopMatrix();

    //tambahan kaki meja
    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslated(0.5, -0.18, 0);
    glScaled(0.05, 0.05, 0.8);
    glutSolidCube(0.5);
    glPopMatrix();

    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslated(-0.5, -0.18, 0);
    glScaled(0.05, 0.05, 0.8);
    glutSolidCube(0.5);
    glPopMatrix();

    glFlush();
}


// Ini cuma buat ngeliat dari sudut yang lain
void rotate1(double angle){
    glMatrixMode(GL_MODELVIEW);
    glRotated(angle, 1, 0, 0);
}

void rotate2(double angle){
    glMatrixMode(GL_MODELVIEW);
    glRotated(angle, 0, 1, 0);
}


// Ini juga cuma buat ngeliat dari sudut yang lain
void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state==GLUT_DOWN){
        rotate1(-10.0);
    }
    else if(button == GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
        rotate2(-10.0);
    }

    glFlush();
    glutPostRedisplay();
}

void render(){
    glClearColor(0, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    draw();

    glutSwapBuffers();
}

int main(int argc,char*argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutCreateWindow("Meja");
    glutReshapeWindow(500,500);
    glutDisplayFunc(render);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
