#pragma once
#include <GL/glew.h>

namespace Engine{
struct Position
{
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

struct Vertex
{
	Position position;
	void setPosition(const GLfloat& x, const GLfloat& y, const GLfloat& z)
	{
		position.x = x;
		position.y = y;
		position.z = z;
	}
};
}
