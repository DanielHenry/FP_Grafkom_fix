
//penjelasannya menggunakan suara!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include <stdio.h>

#include <GL\freeglut.h>

#include <math.h>
#include <stdlib.h>

#ifndef M_PI
#    define M_PI 3.14159265358979323846
#endif

// Constants
#define ROTATE 1
#define TRANSLATE 2
#define RADIUS 100
#define SPEED 1.0
#define SIZE 200
#define STEP 0.1

// Transformation variables 
int xangle = 20;
int yangle = 30;
int zangle = 0;
int xpos = 0;
int ypos = 0;
int zpos = 0;
int mode = ROTATE;

// Ball variables
float Px;
float Py;
float Pz;
float Vx;
float Vy;
float Vz;
float Radius;
float Red;
float Green;
float Blue;
float X[SIZE + 1][SIZE + 1];
float Y[SIZE + 1][SIZE + 1];
float Z[SIZE + 1][SIZE + 1];
//float Gravity = 0;
//float Bounce = -1;

// Bat variable
float Bx;
float By;
float Bz;
float Bradius;
float bred;
float bgreen;
float bblue;
float BX[SIZE + 1], BY[SIZE + 1];

float Ka = 0.2;
float Kd = 0.4;
float Ks = 0.4;
float Kp = 0.5;

void init_material(float Ka, float Kd, float Ks, float Kp, float Mr, float Mg, float Mb)
{
	// Material variables
	float ambient[] = { Ka * Mr, Ka * Mg, Ka * Mb, 1.0 };
	float diffuse[] = { Kd * Mr, Kd * Mg, Kd * Mb, 1.0 };
	float specular[] = { Ks * Mr, Ks * Mg, Ks * Mb, 1.0 };

	// Initialize material
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, Kp);
}

void init_light(int light_source, float Lx, float Ly, float Lz,
	float Lr, float Lg, float Lb)
{
	// Light variables
	float light_position[] = { Lx, Ly, Lz, 0.0 };
	float light_color[] = { Lr, Lg, Lb, 1.0 };

	// Initialize light source
	glEnable(GL_LIGHTING);
	glEnable(light_source);
	glLightfv(light_source, GL_POSITION, light_position);
	glLightfv(light_source, GL_AMBIENT, light_color);
	glLightfv(light_source, GL_DIFFUSE, light_color);
	glLightfv(light_source, GL_SPECULAR, light_color);
	glLightf(light_source, GL_CONSTANT_ATTENUATION, 1.0);
	glLightf(light_source, GL_LINEAR_ATTENUATION, 0.0);
	glLightf(light_source, GL_QUADRATIC_ATTENUATION, 0.0);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_FALSE);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
}

float myrand(float min, float max)
{
	return rand() * (max - min) / RAND_MAX + min;
}

void init_balls()
{
	// Initialize balls with random positions and colors
		// Calculate random positions
	Px = RADIUS/2;
	Py = 0;
	Pz = 0;
	Vx = myrand(-SPEED, SPEED);
	Vy = myrand(-SPEED, SPEED);
	Vz = myrand(-SPEED, SPEED);
	Radius = 10;

	// Genterate random colors
	Red = myrand(0, 1);
	Green = myrand(0, 1);
	Blue = myrand(0, 1);

	// Initialize ball surface
	for (int i = 0; i <= SIZE; i++)
	{
		float angle1 = 2 * i * M_PI / SIZE;
		for (int j = 0; j <= SIZE; j++)
		{
			float angle2 = j * M_PI / SIZE;
			X[i][j] = cos(angle1) * sin(angle2);
			Y[i][j] = sin(angle1) * sin(angle2);
			Z[i][j] = cos(angle2);
		}
	}
	return;
}

void init_bat(){
	Bx = -RADIUS / 2;
	By = 0;
	Bz = 0;
	Bradius = 25;

	bred = myrand(0, 1);
	bgreen = myrand(0, 1);
	bblue = myrand(0, 1);

	for (int i = 0; i < SIZE; i++)
	{
		float angle1 = 2 * (float)i * M_PI / SIZE;
		BX[i] = cosf(angle1);
		BY[i] = sinf(angle1);
	}
	return;
}

void setup()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-RADIUS, RADIUS, -RADIUS, RADIUS, -RADIUS, RADIUS);
	glEnable(GL_DEPTH_TEST);

	glShadeModel(GL_SMOOTH);
	init_light(GL_LIGHT0, 0, 1, 1, 1, 1, 1);
	init_light(GL_LIGHT1, 1, 0, 1, 1, 1, 1);
	init_light(GL_LIGHT2, 1, 1, 0, 1, 1, 1);

	init_balls();
	init_bat();
}

void draw_ball(float centerX, float centerY,
	float centerZ, float radius)
{
	// Draw the surface
	int i, j;
	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
		{
			glBegin(GL_POLYGON);
			glNormal3f(X[i][j], Y[i][j], Z[i][j]);
			glVertex3f(centerX + radius*X[i][j],
				centerY + radius*Y[i][j], centerZ + radius*Z[i][j]);

			glNormal3f(X[i][j + 1], Y[i][j + 1], Z[i][j + 1]);
			glVertex3f(centerX + radius*X[i][j + 1],
				centerY + radius*Y[i][j + 1], centerZ + radius*Z[i][j + 1]);

			glNormal3f(X[i + 1][j + 1], Y[i + 1][j + 1], Z[i + 1][j + 1]);
			glVertex3f(centerX + radius*X[i + 1][j + 1],
				centerY + radius*Y[i + 1][j + 1], centerZ + radius*Z[i + 1][j + 1]);

			glNormal3f(X[i + 1][j], Y[i + 1][j], Z[i + 1][j]);
			glVertex3f(centerX + radius*X[i + 1][j],
				centerY + radius*Y[i + 1][j], centerZ + radius*Z[i + 1][j]);
			glEnd();
		}
}

void draw_bat(float centerX, float centerY, float centerZ, float radius, float thickness){
	glBegin(GL_POLYGON);
	for (int i = 0; i < SIZE; i++){
		glNormal3f(BX[i], BY[i], 0);
		glVertex3f(centerX + BX[i] * Bradius, centerY + BY[i] * Bradius, centerZ);
	}
	for (int i = 0; i < SIZE; i++){
		glNormal3f(BX[i], BY[i], thickness);
		glVertex3f(centerX + BX[i] * Bradius, centerY + BY[i] * Bradius, centerZ + thickness);
	}
	glEnd();
	return;
}

void draw_stick(){
	glColor3f(bred,bgreen,bblue);
	glBegin(GL_POLYGON);
	glVertex3f(Bx - 4.0, By, Bz);
	glNormal3f(Bx + 4.0, By, Bz);
	glVertex3f(Bx + 4.0, By, Bz);
	glNormal3f(Bx + 4.0, By - 40, Bz);
	glVertex3f(Bx + 4.0, By - 40, Bz);
	glNormal3f(Bx - 4.0, By - 40, Bz);
	glVertex3f(Bx - 4.0, By - 40, Bz);
	glNormal3f(Bx - 4.0, By, Bz + 10);
	glVertex3f(Bx - 4.0, By, Bz + 10);
	glNormal3f(Bx + 4.0, By, Bz + 10);
	glVertex3f(Bx + 4.0, By, Bz + 10);
	glNormal3f(Bx + 4.0, By - 40, Bz + 10);
	glVertex3f(Bx + 4.0, By - 40, Bz + 10);
	glNormal3f(Bx + 4.0, By - 40, Bz + 10);
	glVertex3f(Bx - 4.0, By - 40, Bz + 10);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	init_material(Ka, Kd, Ks, 100 * Kp, Red, Green, Blue);

	glTranslatef(xpos / 500.0, ypos / 500.0, zpos / 500.0);
	glRotatef(xangle, 1.0, 0.0, 0.0);
	glRotatef(yangle, 0.0, 1.0, 0.0);
	glRotatef(zangle, 0.0, 0.0, 1.0);

	draw_ball(Px, Py, Pz, Radius);

	init_material(Ka, Kd, Ks, 100 * Kp, bred, bgreen, bblue);

	draw_bat(Bx, By, Bz, Bradius, 10);

	draw_stick();

	glFlush();
	glutSwapBuffers();
}

int main(int argc, char *argv[])
{
	// Create OpenGL window
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(250, 250);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Bouncing Balls");
	setup();

	glutDisplayFunc(display);

	glutMainLoop();

	return 0;
}
