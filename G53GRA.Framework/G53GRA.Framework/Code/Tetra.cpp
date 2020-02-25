#include "Tetra.hpp"

Tetra::Tetra()
{
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE);
    
    Vertex a = Vertex(0, 100, 0);
    Vertex b = Vertex(0, 0, 100);
    Vertex c = Vertex(100, 0, 0);
    Vertex d = Vertex(0, 0, -100);
    Vertex e = Vertex(-100, 0, 0);
    Vertex f = Vertex(0, -100, 0);
    
    Triangle tf = Triangle(a, b, c);
    Triangle tl = Triangle(a, e, b);
    Triangle tb = Triangle(a, d, e);
    Triangle tr = Triangle(a, c, d);
    Triangle bf = Triangle(f, c, b);
    Triangle bl = Triangle(f, b, e);
    Triangle bb = Triangle(f, e, d);
    Triangle br = Triangle(f, d, c);
    
    Triangle origTriangles[8] = { tb,bb,tl,bl,tr,br,bf,tf };
    
    int cIndex = 0;
    for (int i = 0; i < 8; i++) {
        Triangle t = origTriangles[i];
        //cout << "**** SPLITTING NEXT TRIANGLE *********\n";
        splitTriangle(t.a, t.b, t.c, tList, cIndex, 1);
    }

    for(int x =0;x<tList.size(); x++)
    {
        RGB temp;
        temp.r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX) ;
        temp.g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX) ;
        temp.b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX) ;
       
        rgb.push_back(temp);
    }
    size(SIZE);
    position(MOVE_X,MOVE_Y,0.f);
    
}

void Tetra::Display()
{
    glTranslatef(pos[0], pos[1], pos[2]);
    
    // Scale object (but not translation) by calling scale after translate
    glScalef(scale[0], scale[1], scale[2]);
    
    // Rotate object in new position, in order y>z>x axes
    glRotatef(rotation[1], 0.0f, 1.0f, 0.0f); // angle ry about (0,1,0)
    glRotatef(rotation[2], 0.0f, 0.0f, 1.0f); // angle rz about (0,0,1)
    glRotatef(rotation[0], 1.0f, 0.0f, 0.0f); // angle rx about (1,0,0)
    
    for (int i = 0; i < tList.size(); i++) {
        Triangle t = tList[i];
        if (!isValidTriangle(t.a, t.b, t.c)) {
            //cout << "*** Skipping an invalid triangle ***\n";
            continue;
        }

        RGB color = rgb.at(i);

        glBegin(GL_TRIANGLES);
        glColor3f(color.r, color.g, color.b);
        glVertex3f(t.a.x, t.a.y, t.a.z);
        glVertex3f(t.b.x, t.b.y, t.b.z);
        glVertex3f(t.c.x, t.c.y, t.c.z);
       
        glEnd();
    }

}

bool Tetra::isValidTriangle(Vertex a, Vertex b, Vertex c) {
    if ((a.x == b.x && a.y == b.y && a.z == b.z) || (a.x == c.x && a.y == c.y && a.z == c.z) || (b.x == c.x && b.y == c.y && b.z == c.z)) {
        return false;
    }
    return true;
}

void Tetra::convertToUnitVector(Vertex &v) {
    // noramlize the vector to be magnitude 1 / a unit vector
    float mag = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
    v.x = v.x / mag;
    v.y = v.y / mag;
    v.z = v.z / mag;
}

void Tetra::adjustForEqualDistToOrigin(Vertex &v) {
    convertToUnitVector(v);
    v.x = v.x * 100;
    v.y = v.y * 100;
    v.z = v.z * 100;
}

void Tetra::splitTriangle(Vertex a, Vertex b, Vertex c, vector<Triangle> &tList, int &cIndex, int cDepth) {
    //cout << "starting split with params :\n";
    //cout << "\tcIndex: " << cIndex << "\n";
    
    // check triangle is a valid traingle with 3 different points
    if (!isValidTriangle(a, b, c)) {
        cout << "**** not a valid triangle ******\n";
        return;
    }
    
    // the new vetices
    Vertex ab = Vertex((a.x + b.x) / 2, (a.y + b.y) / 2, (a.z + b.z) / 2);
    Vertex ac = Vertex((a.x + c.x) / 2, (a.y + c.y) / 2, (a.z + c.z) / 2);
    Vertex bc = Vertex((b.x + c.x) / 2, (b.y + c.y) / 2, (b.z + c.z) / 2);
    
    adjustForEqualDistToOrigin(ab);
    adjustForEqualDistToOrigin(ac);
    adjustForEqualDistToOrigin(bc);
    
    // the 4 new triangles
    Triangle ct = Triangle(ab, bc, ac);
    Triangle tt = Triangle(a, ab, ac);
    Triangle lt = Triangle(b, bc, ab);
    Triangle rt = Triangle(bc, c, ac);
    
    // prevent index out of range exception
    if (cIndex + 4 > NUM_OF_TRIANGLES) {
        cout << "**** returning before out of range exception ****\n";
        return;
    }
    
    // add the final layer of triangles to the list
    if (cDepth == DEPTH) {
        //cout << "reached final layer of split - depth " << cDepth << "\n";
        tList.push_back(tt);
        tList.push_back(ct);
        tList.push_back(lt);
        tList.push_back(rt);
        return;
    }
    
    //cout << "Further splitting the 4 triangles because not at the final layer yet!\n";
    // split the triangles as they aren't the final layer
    splitTriangle(ct.a, ct.b, ct.c, tList, cIndex, cDepth + 1);
    splitTriangle(tt.a, tt.b, tt.c, tList, cIndex, cDepth + 1);
    splitTriangle(lt.a, lt.b, lt.c, tList, cIndex, cDepth + 1);
    splitTriangle(rt.a, rt.b, rt.c, tList, cIndex, cDepth + 1);
}

void Tetra::checkGLError()
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
