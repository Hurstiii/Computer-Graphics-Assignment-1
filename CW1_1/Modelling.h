#pragma once
#ifndef ___Modelling__
#define ___Modelling__
#ifdef __APPLE__ // if OS X
#include <glut/glut.h> // include freeglut libraries
#else // if Windows
#include <gl/glut.h> // include freeglut libraries
#endif

#include <stdio.h>

void setup();
void draw();
int main(int argc, char **argv);
void checkGLError();                        // Prints any OpenGL errors to console

#endif
#include <stdio.h>
int width;
int height;
void setup();
void draw();
int main(int argc, char **argv);
void checkGLError(); // Prints any OpenGL errors to console

