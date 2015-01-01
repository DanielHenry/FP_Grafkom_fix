#include<GL/freeglut.h>

void init ( GLvoid )     // Create Some Everyday Functions
{

  glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
   glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

/*void gambar_bola()
{
          
}*/

void gambar_meja_tenis()
{
    glColor3f(0, 0, 1);
    glPushMatrix();
    //glScaled(2, 0.1, 1);
    //glutSolidCube(0.8);
    glPopMatrix();

    //net
    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslated(0, 0.045, 0.41);
    //glScaled(0.05, 0.3, 0.05);
    //glutSolidCube(0.5);
    glPopMatrix();

    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslated(0, 0.045, -0.41);
    //glScaled(0.05, 0.3, 0.05);
    //glutSolidCube(0.5);
    glPopMatrix();

    glColor3f(1, 1, 1);
    glPushMatrix();
    glTranslated(0, 0.045, 0);
    //glScaled(0.05, 0.3, 1.6);
    //glutSolidCube(0.5);
    glPopMatrix();

    //garis meja
    glColor3f(1, 1, 1);
    glPushMatrix();
    glTranslated(0, 0.04, 0);
    //glScaled(1.9, 0.01, 0.01);
    //glutSolidCube(0.8);
    glPopMatrix();

    glColor3f(1, 1, 1);
    glPushMatrix();
    glTranslated(0, 0.04, 0.38);
    //glScaled(1.9, 0.01, 0.01);
    //glutSolidCube(0.8);
    glPopMatrix();

    glColor3f(1, 1, 1);
    glPushMatrix();
    glTranslated(0, 0.04, -0.38);
    //glScaled(1.9, 0.01, 0.01);
    //glutSolidCube(0.8);
    glPopMatrix();

    glColor3f(1, 1, 1);
    glPushMatrix();
    glTranslated(0.755, 0.04, 0);
    //glScaled(0.01, 0.01, 0.95);
    //glutSolidCube(0.8);
    glPopMatrix();

    glColor3f(1, 1, 1);
    glPushMatrix();
    glTranslated(-0.755, 0.04, 0);
    //glScaled(0.01, 0.01, 0.95);
    //glutSolidCube(0.8);
    glPopMatrix();

    //kaki meja
    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslated(0.5, -0.18, 0.2);
    //glScaled(0.05, 0.7, 0.05);
    //glutSolidCube(0.5);
    glPopMatrix();

    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslated(-0.5, -0.18, 0.2);
    //glScaled(0.05, 0.7, 0.05);
    //glutSolidCube(0.5);
    glPopMatrix();

    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslated(-0.5, -0.18, -0.2);
    //glScaled(0.05, 0.7, 0.05);
    //glutSolidCube(0.5);
    glPopMatrix();

    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslated(0.5, -0.18, -0.2);
    //glScaled(0.05, 0.7, 0.05);
    //glutSolidCube(0.5);
    glPopMatrix();

    //tambahan kaki meja
    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslated(0.5, -0.18, 0);
    //glScaled(0.05, 0.05, 0.8);
    //glutSolidCube(0.5);
    glPopMatrix();

    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslated(-0.5, -0.18, 0);
    //glScaled(0.05, 0.05, 0.8);
    //glutSolidCube(0.5);
    glPopMatrix(); 
}

/*void gambar_bat()
{
     
}*/

void display ( void )   // Create The Display Function
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
   glLoadIdentity();									// Reset The Current Modelview Matrix
   glPushMatrix();
   
   gambar_meja_tenis();
   glLoadIdentity();
    
   glPopMatrix();

   glutSwapBuffers ( );
  // Swap The Buffers To Not Be Left With A Clear Screen
}

void reshape ( int w, int h )   // Create The Reshape Function (the viewport)
{
  glViewport     ( 0, 0, w, h );
  glMatrixMode   ( GL_PROJECTION );  // Select The Projection Matrix
  glLoadIdentity ( );                // Reset The Projection Matrix
  if ( h==0 )  // Calculate The Aspect Ratio Of The Window
     gluPerspective ( 80, ( float ) w, 1.0, 5000.0 );
  else
     gluPerspective ( 80, ( float ) w / ( float ) h, 1.0, 5000.0 );
  glMatrixMode   ( GL_MODELVIEW );  // Select The Model View Matrix
  glLoadIdentity ( );    // Reset The Model View Matrix
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
  switch ( key ) {
    case 27:        // When Escape Is Pressed...
      exit ( 0 );   // Exit The Program
      break;        // Ready For Next Case
    default:        // Now Wrap It Up
      break;
  }
}

void arrow_keys ( int a_keys, int x, int y )  // Create Special Function (required for arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     // When Up Arrow Is Pressed...
      glutFullScreen ( ); // Go Into Full Screen Mode
      break;
    case GLUT_KEY_DOWN:               // When Down Arrow Is Pressed...
      glutReshapeWindow ( 500, 500 ); // Go Into A 500 By 500 Window
      break;
    default:
      break;
  }
}

int main ( int argc, char** argv )   // Create Main Function For Bringing It All Together
{
  glutInit            ( &argc, argv ); // Erm Just Write It =)
  init ();
  glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE); // Display Mode
  glutInitWindowSize  ( 500, 500 ); // If glutFullScreen wasn't called this is the window size
  glutCreateWindow    ( "FP Grafkom" ); // Window Title (argv[0] for current directory as title)
  glutFullScreen      ( );          // Put Into Full Screen
  glutDisplayFunc     ( display );  // Matching Earlier Functions To Their Counterparts
  glutReshapeFunc     ( reshape );
  glutKeyboardFunc    ( keyboard );
  glutSpecialFunc     ( arrow_keys );
  glutIdleFunc			 ( display );
  glutMainLoop        ( );          // Initialize The Main Loop
  return 0;
}

