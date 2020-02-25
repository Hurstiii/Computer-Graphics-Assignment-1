//
//  Cube.cpp
//  G53GRA.Framework
//
//  Created by Daniel on 20/02/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Cube.hpp"


Cube::Cube()
{
    position(10000, 0, 0);
}

void Cube::Display()
{
    
    
    
//    glClearColor(1.f, 1.f, 1.f, 1.f); // glClearColor() sets a background color - ..(R, G, B, A) - must come before glClear()!
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear buffers
    glMatrixMode(GL_MODELVIEW); // set for model and viewing operations
    glLoadIdentity(); // reset
    glEnable(GL_DEPTH_TEST);
//
    glTranslatef(0, 0.f,-100.f); // adjust drawing position from the current position
    glRotatef(160.f, 0.f, 1.f, 0.f); // rotate the whole scene around the y-axis 45 degrees (effectively chaning the camera position/ view point)
    glColor3f(0.f, 0.f, 0.f); // sets drawing color (R, G, B)

    float cubeSize = 50;
    float c_r = cubeSize / 2;
    
    /*
     e - - - - - f
     /|          /|
     / |         / |
     a -|- - - - b  |
     |  |        |  |
     |  g - - - -|- h
     | /            | /
     |/            |/
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
//    glEnable(GL_LIGHTING);
    // Revert changes between most recent glPushMatrix and here
//    glPopMatrix();
     checkGLError();
//    glutSwapBuffers(); // execute all commands, swap buffers - always at the end
}

void Cube::checkGLError()
{
    int errorNum = 0;                      // Error count
    GLenum error = glGetError();           // Get first glError
    while (GL_NO_ERROR != errorNum)        // Loop until no errors found
    {
        errorNum++;
        printf("GL Error %i: %s\n", errorNum, gluErrorString(error)); // Display error string
        error = glGetError();                                  // Get next glError
    }
}
