//
//  Tetra.hpp
//  G53GRA.Framework
//
//  Created by Daniel on 20/02/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef Tetra_hpp
#define Tetra_hpp

#define MOVE_X 0.f
#define MOVE_Y 0.f
#define SIZE 1.f


#include <stdio.h>
#include <vector>
#include <cmath>
#include <iostream>
#include "../Framework/Interface/DisplayableObject.h"
#include "Vertex.h"
#include "Triangle.h"
#include <vector>
using namespace std;

class Tetra : public DisplayableObject
{
public:
    Tetra();
    ~Tetra() {};
    void Display();
    
private:
    vector<Triangle> tList;
    const int DEPTH = 5; // dont do 0
    const int NUM_OF_TRIANGLES = pow(4, DEPTH) * 8;
    
    struct RGB
    {
        float r;
        float g;
        float b;
    };
    vector<RGB>rgb;
    bool isValidTriangle(Vertex a, Vertex b, Vertex c);
    void convertToUnitVector(Vertex &v);
    void adjustForEqualDistToOrigin(Vertex &v);
    void splitTriangle(Vertex a, Vertex b, Vertex c, vector<Triangle> &tList, int &cIndex, int cDepth);
    void checkGLError();    
    
};
#endif /* Tetra_hpp */
