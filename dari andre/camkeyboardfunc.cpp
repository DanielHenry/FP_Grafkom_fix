// camera points
float angle = 0.0;
float Lx = 0.0;
float Lz = -1.0;
float Ex = 0.0;
float Ez = 1.0;

gluLookAt(Ex, 0.0f, Ez, Ex+Lx, 0.0f, Ez+Lz, 0.0, 1.0, 0.0); // taruh di display()

void keypressed(unsigned char key, int x, int y){
	
	float fraction = 0.1f;

	switch (key)
	{
	case 'a':
		angle -= 0.01f;
		Lx = sin(angle);
		Lz = -cos(angle);
		break;
	case 'd':
		angle += 0.01f;
		Lx = sin(angle);
		Lz = -cos(angle);
		break;
	case 'w':
		Ex += Lx * fraction;
		Ez += Lz * fraction;
		break;
	case 's':
		Ex -= Lx * fraction;
		Ez -= Lz * fraction;
		break;
	default:
		break;
	}
}

/* hasilnya kamera berputar tok, belum maju mundur */
