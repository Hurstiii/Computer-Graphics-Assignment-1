//
//  Cube.hpp
//  G53GRA.Framework
//
//  Created by Daniel on 20/02/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef Cube_hpp
#define Cube_hpp

#include <stdio.h>
#include "../Framework/Interface/DisplayableObject.h"
class Cube : public DisplayableObject
{
public:
    Cube();
    ~Cube() {};
    void Display();
private:
    void checkGLError();
};

#endif /* Cube_hpp */
