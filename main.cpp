#include<GL/freeglut.h>

void inisiasi()
{
     glClearColor(1.0, 1.0, 1.0, 0.0);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0, 640.0, 0.0, 480.0);     
}

void menggambar()
{
     glClear(GL_COLOR_BUFFER_BIT);
     
     glColor3f(0.0, 0.0, 0.0);
     glBegin(GL_LINE_STRIP);
       glColor3f(0.0, 0.0, 0.0);
       glVertex2i(100,50);
       glVertex2i(100,130);
       glVertex2i(150,130);
     glEnd();
     
     glFlush();  
}

int main ()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,150);
    glutCreateWindow("coba cg1");
    glutDisplayFunc(menggambar);
    inisiasi();
    
    glutMainLoop();
    return 0;    
}
