#include "Triangle.h"

Triangle::Triangle() : a(Vertex()), b(Vertex()), c(Vertex())
{
}

Triangle::Triangle(Vertex a, Vertex b, Vertex c) : a(Vertex()), b(Vertex()), c(Vertex())
{
	this->a = a;
	this->b = b;
	this->c = c;
}
