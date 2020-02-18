#pragma once
#ifndef ___SubSurfacing__
#define ___SubSurfacing__
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
#include "Triangle.h"
#include "Vertex.h"
#include <vector>
#include <stdio.h>
#include <math.h>

using namespace std;
using namespace System;
using namespace System::Collections;

const int DEPTH = 5; // dont do 0
const int NUM_OF_TRIANGLES = pow(4, DEPTH) * 8;
int width;
int height;
void adjustForEqualDistToOrigin(Vertex &v);
void convertToUnitVector(Vertex &v);
bool isValidTriangle(Vertex a, Vertex b, Vertex c);
void splitTriangle(Vertex, Vertex, Vertex, vector<Triangle> &tList, int &cIndex, int cDepth);
void setup();
void draw();
int main(int argc, char **argv);
void checkGLError(); // Prints any OpenGL errors to console

