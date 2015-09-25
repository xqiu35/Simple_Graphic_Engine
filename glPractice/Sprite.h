#pragma once
#include <GL/glew.h>
#include "Vertex.h"

namespace Engine{
class Sprite
{
public:
	Sprite();
	~Sprite();

	void init(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
	void draw();

private:
	GLuint _vboID;
};
}


