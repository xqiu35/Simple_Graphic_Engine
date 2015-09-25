#pragma once
#include <GL/glew.h>
namespace Engine{
	class Cube
	{
	public:
		Cube();
		~Cube();

		void init(GLfloat length);
		void draw();

	private:
		GLuint _vboID;
		GLuint _colorBuffer;
	};
}

