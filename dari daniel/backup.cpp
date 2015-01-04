#include<GL/freeglut.h>

GLfloat x_ball_pos = 2.0f;
GLfloat y_ball_pos = 0.25f;
GLfloat z_ball_pos;
bool apakah_bola_bergerak_ke_kiri = true;
bool apakah_bola_bergerak_ke_bawah = true;

bool is_left_button_pressing = false;

int x_pixel_global, y_pixel_global;
int x_pixel_before, y_pixel_before;
bool is_camera_move = false;
GLfloat x_eye_pos_before = 0.0f;
GLfloat y_eye_pos_before = 0.0f;
GLfloat x_focus_pos_before = 0.0f;
GLfloat y_focus_pos_before = 0.0f;
GLfloat x_up_pos_before = 0.0f;
GLfloat y_up_pos_before = 1.0f;

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

void gambarMejaTanpaKaki()
{
    glColor3f(0, 1, 0); 
    glBegin(GL_QUADS);   //sisi belakang
      glVertex3f(-2, -0.125, -1);
      glVertex3f(-2,  0.125, -1);
      glVertex3f( 2,  0.125, -1);
      glVertex3f( 2, -0.125, -1);
    glEnd();
    
    glColor3f(0, 1, 0);
    glBegin(GL_QUADS); //sisi kiri
      glVertex3f(-2, -0.125, -1);
      glVertex3f(-2,  0.125, -1);
      glVertex3f(-2,  0.125,  1);
      glVertex3f(-2, -0.125,  1);
    glEnd();
    
    glColor3f(0, 1, 0);
    glBegin(GL_QUADS); //sisi depan
      glVertex3f(-2, -0.125,  1);
      glVertex3f(-2,  0.125,  1);
      glVertex3f( 2,  0.125,  1);
      glVertex3f( 2, -0.125,  1);
    glEnd();
    
    glColor3f(0, 1, 0);
    glBegin(GL_QUADS); //sisi kanan
      glVertex3f( 2, -0.125, -1);
      glVertex3f( 2,  0.125, -1);
      glVertex3f( 2,  0.125,  1);
      glVertex3f( 2, -0.125,  1);
    glEnd();
    
    glColor3f(0, 1, 0);
    glBegin(GL_QUADS); //sisi atas
      glVertex3f( 2,  0.125,  1);
      glVertex3f( 2,  0.125, -1);
      glVertex3f(-2,  0.125, -1);
      glVertex3f(-2,  0.125,  1);
    glEnd();
    
    glColor3f(0, 1, 0);
    glBegin(GL_QUADS); //sisi bawah
      glVertex3f( 2, -0.125,  1);
      glVertex3f( 2, -0.125, -1);
      glVertex3f(-2, -0.125, -1);
      glVertex3f(-2, -0.125,  1);
    glEnd();           
}

void gambarNet()
{
    glColor3f(1, 1, 1); 
    glBegin(GL_QUADS);   //sisi belakang
      glVertex3f(-0.02, -0.075, -1);
      glVertex3f(-0.02,  0.075, -1);
      glVertex3f( 0.02,  0.075, -1);
      glVertex3f( 0.02, -0.075, -1);
    glEnd();
    
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS); //sisi kiri
      glVertex3f(-0.02, -0.075, -1);
      glVertex3f(-0.02,  0.075, -1);
      glVertex3f(-0.02,  0.075,  1);
      glVertex3f(-0.02, -0.075,  1);
    glEnd();
    
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS); //sisi depan
      glVertex3f(-0.02, -0.075,  1);
      glVertex3f(-0.02,  0.075,  1);
      glVertex3f( 0.02,  0.075,  1);
      glVertex3f( 0.02, -0.075,  1);
    glEnd();
    
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS); //sisi kanan
      glVertex3f( 0.02, -0.075, -1);
      glVertex3f( 0.02,  0.075, -1);
      glVertex3f( 0.02,  0.075,  1);
      glVertex3f( 0.02, -0.075,  1);
    glEnd();
    
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS); //sisi atas
      glVertex3f( 0.02,  0.075,  1);
      glVertex3f( 0.02,  0.075, -1);
      glVertex3f(-0.02,  0.075, -1);
      glVertex3f(-0.02,  0.075,  1);
    glEnd();
    
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS); //sisi bawah
      glVertex3f( 0.02, -0.075,  1);
      glVertex3f( 0.02, -0.075, -1);
      glVertex3f(-0.02, -0.075, -1);
      glVertex3f(-0.02, -0.075,  1);
    glEnd(); 
}

void gambarKakiMeja()
{
          
}

void gambarMejaTenis()
{
    gambarMejaTanpaKaki();
    glTranslatef(0, 0.2, 0);
    gambarNet(); 
}

void gambarBolaPimpong()
{
    glColor3f(1, 1, 0); 
    glutSolidSphere(0.1, 16, 16); 
}

void gambarBat()
{
     
}

void pindahMata()
{
     if (is_camera_move==true)
     {
         int x_pixel_move = x_pixel_global - x_pixel_before;
         int y_pixel_move = y_pixel_global - y_pixel_before;
         
         GLfloat x_eye_pos = x_eye_pos_before + ((GLfloat)x_pixel_move*0.0001f);
         GLfloat y_eye_pos = y_eye_pos_before - ((GLfloat)y_pixel_move*0.0001f);
         GLfloat x_focus_pos = x_eye_pos;
         GLfloat y_focus_pos = y_eye_pos;
         GLfloat x_up_pos = x_eye_pos;
         GLfloat y_up_pos = y_eye_pos + 1.0f;
         
         glMatrixMode(GL_PROJECTION);
         glLoadIdentity();                      
         gluLookAt(x_eye_pos, y_eye_pos, 0.0f, x_focus_pos, y_focus_pos, -1.0f, x_up_pos, y_up_pos, 0.0f);
         glMatrixMode(GL_MODELVIEW);
         glLoadIdentity();
         
         x_pixel_before = x_pixel_global;
         y_pixel_before = y_pixel_global;
         
         x_eye_pos_before = x_eye_pos;
         y_eye_pos_before = y_eye_pos;
     }                            
     return;     
}

void display ( void )   // Create The Display Function
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
   glLoadIdentity();									// Reset The Current Modelview Matrix
   glPushMatrix();
   
   glTranslatef(0, -1, -4);
   gambarMejaTenis();
   glLoadIdentity();
   glTranslatef(x_ball_pos, y_ball_pos, -4);
   //glTranslatef(1, y_ball_pos, -4);
   gambarBolaPimpong();
   glLoadIdentity(); 
    
   glPopMatrix();
   
   //deteksi x
   if (x_ball_pos<(-2.0f))
   {
       apakah_bola_bergerak_ke_kiri = false;
       x_ball_pos+=0.01f;                       
   }
   else if (x_ball_pos>2.0f)
   {
       apakah_bola_bergerak_ke_kiri = true;
       x_ball_pos-=0.01f;                       
   }
   else if (apakah_bola_bergerak_ke_kiri==true) x_ball_pos-=0.01f;
   else x_ball_pos+=0.01f;
   
   //deteksi y
   if (y_ball_pos<(-0.775))
   {
       apakah_bola_bergerak_ke_bawah = false;
       y_ball_pos+=0.007f;                           
   }
   else if (y_ball_pos>0.25)
   {
       apakah_bola_bergerak_ke_bawah = true;
       y_ball_pos-=0.004f;      
   }
   else if (apakah_bola_bergerak_ke_bawah==true) y_ball_pos-=0.004f;
   else y_ball_pos+=0.007f;
   
   //pindahkan mata jika layar di-klik kiri dan digeser
   pindahMata();

   // Swap The Buffers To Not Be Left With A Clear Screen
   glutSwapBuffers ( );
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

/*void mouse(int button, int state, int x_pixel, int y_pixel)
{
     if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
     {
         if (is_camera_move==false)
         {
             is_camera_move = true;
             x_pixel_before = x_pixel;
             y_pixel_before = y_pixel;                         
         }
         else
         {   
             int x_pixel_move = x_pixel - x_pixel_before;
             int y_pixel_move = y_pixel - y_pixel_before;
             
             GLfloat x_eye_pos = x_eye_pos_before + ((GLfloat)x_pixel_move*0.01f);
             GLfloat y_eye_pos = y_eye_pos_before - ((GLfloat)y_pixel_move*0.01f);
             GLfloat x_focus_pos = x_eye_pos;
             GLfloat y_focus_pos = y_eye_pos;
             GLfloat x_up_pos = x_eye_pos;
             GLfloat y_up_pos = y_eye_pos + 1.0f;
             
             glMatrixMode(GL_PROJECTION);
             glLoadIdentity();                      
             gluLookAt(x_eye_pos, y_eye_pos, 0.0f, x_focus_pos, y_focus_pos, -1.0f, x_up_pos, y_up_pos, 0.0f);
             
             x_pixel_before = x_pixel;
             y_pixel_before = y_pixel;
             
             x_eye_pos_before = x_eye_pos;
             y_eye_pos_before = y_eye_pos;
         }                            
     }
     else if (button==GLUT_LEFT_BUTTON && state==GLUT_UP) is_camera_move = false;
     return;
}

void movedMouse(int button, int state, int x_pixel, int y_pixel)
{
     if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
     {
         if (is_camera_move==false)
         {
             is_camera_move = true;
             x_pixel_before = x_pixel;
             y_pixel_before = y_pixel;                         
         }
         else
         {   
             int x_pixel_move = x_pixel - x_pixel_before;
             int y_pixel_move = y_pixel - y_pixel_before;
             
             GLfloat x_eye_pos = x_eye_pos_before + ((GLfloat)x_pixel_move*0.01f);
             GLfloat y_eye_pos = y_eye_pos_before - ((GLfloat)y_pixel_move*0.01f);
             GLfloat x_focus_pos = x_eye_pos;
             GLfloat y_focus_pos = y_eye_pos;
             GLfloat x_up_pos = x_eye_pos;
             GLfloat y_up_pos = y_eye_pos + 1.0f;
             
             glMatrixMode(GL_PROJECTION);
             glLoadIdentity();                      
             gluLookAt(x_eye_pos, y_eye_pos, 0.0f, x_focus_pos, y_focus_pos, -1.0f, x_up_pos, y_up_pos, 0.0f);
             
             x_pixel_before = x_pixel;
             y_pixel_before = y_pixel;
             
             x_eye_pos_before = x_eye_pos;
             y_eye_pos_before = y_eye_pos;
         }                            
     }
     else if (button==GLUT_LEFT_BUTTON && state==GLUT_UP) is_camera_move = false;
     return;
}*/

void mouse(int button, int state, int x_pixel, int y_pixel)
{
     if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
     {
          is_camera_move = true;
          x_pixel_before = x_pixel;
          y_pixel_before = y_pixel;                                                
     }
     else if (button==GLUT_LEFT_BUTTON && state==GLUT_UP) is_camera_move = false;
     return;
}

void movedMouse(int x_pixel, int y_pixel)
{
     if (is_camera_move==true)
     {
         x_pixel_global = x_pixel;
         y_pixel_global = y_pixel;
     }                            
     return;
}

int main ()  
{
  init ();
  glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE); // Display Mode
  glutInitWindowSize  ( 500, 500 ); // If glutFullScreen wasn't called this is the window size
  glutCreateWindow    ( "FP Grafkom F kelompok ADD" ); 
  glutFullScreen      ( );          
  glutDisplayFunc     ( display );  
  glutReshapeFunc     ( reshape );
  glutKeyboardFunc    ( keyboard );
  glutMouseFunc       ( mouse );
  glutMotionFunc      ( movedMouse );
  glutSpecialFunc     ( arrow_keys );
  glutIdleFunc			 ( display );
  glutMainLoop        ( );          // Initialize The Main Loop
  return 0;
}

