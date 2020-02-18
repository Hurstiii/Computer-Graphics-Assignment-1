#include "Modelling.h"

void setup()
{
	width = 600;
	height = 600;

	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(width, height);
	glutCreateWindow("My Scene");
}

void draw()
{
	glClearColor(1.f, 1.f, 1.f, 1.f); // glClearColor() sets a background color - ..(R, G, B, A) - must come before glClear()!
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear buffers
	glMatrixMode(GL_MODELVIEW); // set for model and viewing operations
	glLoadIdentity(); // reset 
	glEnable(GL_DEPTH_TEST);

	glTranslatef(0.f, 0.f, -200.f); // adjust drawing position from the current position
	glRotatef(160.f, 0.f, 1.f, 0.f); // rotate the whole scene around the y-axis 45 degrees (effectively chaning the camera position/ view point)
	glColor3f(0.f, 0.f, 0.f); // sets drawing color (R, G, B)

	float cubeSize = 50;
	float c_r = cubeSize / 2;

	/*
			   e - - - - - f
			  /|		  /|
			 / |		 / |
			a -|- - - - b  |
			|  |		|  |
			|  g - - - -|- h
			| /			| /
			|/			|/
			c - - - - - d

	*/

	float ax = -c_r;
	float ay = c_r;
	float az = c_r;
	
	float bx = c_r;
	float by = c_r;
	float bz = c_r;

	float cx = -c_r;
	float cy = -c_r;
	float cz = c_r;

	float dx = c_r;
	float dy = -c_r;
	float dz = c_r;

	float ex = -c_r;
	float ey = c_r;
	float ez = -c_r;

	float fx = c_r;
	float fy = c_r;
	float fz = -c_r;

	float gx = -c_r;
	float gy = -c_r;
	float gz = -c_r;

	float hx = c_r;
	float hy = -c_r;
	float hz = -c_r;

	glBegin(GL_LINE_LOOP);
	// front face
	glNormal3f(0, 0, 1);
	// first triangle (b, a, c)
	glVertex3f(bx, by, bz);
	glVertex3f(ax, ay, az);
	glVertex3f(cx, cy, cz);
	glEnd();

	glBegin(GL_LINE_LOOP);
	// second triangle (b, c, d)
	glVertex3f(bx, by, bz);
	glVertex3f(cx, cy, cz);
	glVertex3f(dx, dy, dz);
	glEnd();

	glBegin(GL_LINE_LOOP);
	// right face
	glNormal3f(1, 0, 0);
	// first triangle (b, d, h)
	glVertex3f(bx, by, bz);
	glVertex3f(dx, dy, dz);
	glVertex3f(hx, hy, hz);
	glEnd();

	glBegin(GL_LINE_LOOP);
	//second triangle (b, h, f)
	glVertex3f(bx, by, bz);
	glVertex3f(hx, hy, hz);
	glVertex3f(fx, fy, fz);
	glEnd();

	glBegin(GL_LINE_LOOP);
	// top face
	glNormal3f(0, 1, 0);
	// first triangle (b, f, e)
	glVertex3f(bx, by, bz);
	glVertex3f(fx, fy, fz);
	glVertex3f(ex, ey, ez);
	glEnd();

	glBegin(GL_LINE_LOOP);
	//second triangle (a, b, e)
	glVertex3f(ax, ay, az);
	glVertex3f(bx, by, bz);
	glVertex3f(ex, ey, ez);
	glEnd();

	glBegin(GL_LINE_LOOP);
	// left face
	glNormal3f(-1, 0, 0);
	// first triangle (e, c, a)
	glVertex3f(ex, ey, ez);
	glVertex3f(cx, cy, cz);
	glVertex3f(ax, ay, az);
	glEnd();

	glBegin(GL_LINE_LOOP);
	// second triangle (e, g, c)
	glVertex3f(ex, ey, ez);
	glVertex3f(gx, gy, gz);
	glVertex3f(cx, cy, cz);
	glEnd();

	glBegin(GL_LINE_LOOP);
	// back face
	glNormal3f(0, 0, -1);
	// first triangle (e, h, g)
	glVertex3f(ex, ey, ez);
	glVertex3f(hx, hy, hz);
	glVertex3f(gx, gy, gz);
	glEnd();

	glBegin(GL_LINE_LOOP);
	// second triangle (e, f, h)
	glVertex3f(ex, ey, ez);
	glVertex3f(fx, fy, fz);
	glVertex3f(hx, hy, hz);
	glEnd();

	glBegin(GL_LINE_LOOP);
	// bottom face
	glNormal3f(0, -1, 0);
	// first triangle (g, h, c)
	glVertex3f(gx, gy, gz);
	glVertex3f(hx, hy, hz);
	glVertex3f(cx, cy, cz);
	glEnd();

	glBegin(GL_LINE_LOOP);
	// second triangle (h, d, c)
	glVertex3f(hx, hy, hz);
	glVertex3f(dx, dy, dz);
	glVertex3f(cx, cy, cz);
	glEnd();

	glBegin(GL_TRIANGLES);
	// Draw Tetrahedron inside
	glColor3f(1, 1, 0);
	// fouth triangle (e, h, c)
	glVertex3f(ex, ey, ez);
	glVertex3f(hx, hy, hz);
	glVertex3f(cx, cy, cz);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0, 0, 1);
	// third triangle (b, h, e)
	glVertex3f(bx, by, bz);
	glVertex3f(hx, hy, hz);
	glVertex3f(ex, ey, ez);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0);
	// first triangle/face (b, c, h)
	glVertex3f(bx, by, bz);
	glVertex3f(cx, cy, cz);
	glVertex3f(hx, hy, hz);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0, 1, 0);
	// second triangle (b, e, c)
	glVertex3f(bx, by, bz);
	glVertex3f(ex, ey, ez);
	glVertex3f(cx, cy, cz);
	glEnd();

	checkGLError();
	glutSwapBuffers(); // execute all commands, swap buffers - always at the end
}

void reshape(int _width, int _height)
{
	// update global dimension variables
	width = _width;
	height = _height;
	// calculate new aspect ratio
	GLdouble aspect = static_cast<GLdouble>(width) / static_cast<GLdouble>(height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();     // reset matrix
	gluPerspective(45.0, aspect, 1, 1000);
	glViewport(0, 0, width, height);
	glMatrixMode(GL_MODELVIEW); // return matrix mode to modelling and viewing
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);          // Initialise GL environment
	setup();                        // Call additional initialisation commands
	glutDisplayFunc(draw);          // Register scene to render contents of draw() function
	checkGLError();                 // Check any OpenGL errors in initialisation
	glutReshapeFunc(reshape);
	glutMainLoop();                 // Begin rendering sequence
	return 0;
}

void checkGLError()
{
	int e = 0;                      // Error count
	GLenum error = glGetError();    // Get first glError
	while (GL_NO_ERROR != error)    // Loop until no errors found
	{
		e++;
		printf("GL Error %i: %s\n", e, gluErrorString(error)); // Display error string
		error = glGetError();                                  // Get next glError
	}
}
