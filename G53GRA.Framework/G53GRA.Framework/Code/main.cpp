//
//  main.cpp
//  G53GRA.Framework
//
//  Created by Daniel on 20/02/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "MyScene.h"

int main(int argc, char* argv[])
{
    // seed random numbers
    srand(420);
    
    // Create new instance of MyScene - the OpenGL context on which your coursework is built
    MyScene *scene = NULL;
    scene = new MyScene(argc, argv, "G53GRA", static_cast<const int>(600), static_cast<const int>(400));

    // Begin the main GL loop
    scene->Run();
    
    // On exit, clean up and return success (0x0)
    delete scene;
    
    return 0;
}
