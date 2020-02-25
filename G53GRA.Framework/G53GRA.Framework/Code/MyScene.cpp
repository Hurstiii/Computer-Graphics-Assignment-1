#include "MyScene.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();     // reset matrix
//    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearColor(1.f,1.f,1.f,1.f);
    Cube *cube = new Cube();
    addObjectToScene(cube);

//    Tetra *tetra = new Tetra();
//    addObjectToScene(tetra);
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 1000.0);
  
}

void MyScene::addObjectToScene(DisplayableObject *obj)
{
    objects.push_back(obj);
    AddObjectToScene(obj);
}

void checkGLError()
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
