#include "Sprite.h"
#include "Vertex.h"
#include <cstddef>

namespace Engine{
	Sprite::Sprite() :_vboID(0)
	{
	}


	Sprite::~Sprite()
	{
	}

	void Sprite::init(GLfloat x, GLfloat y, GLfloat width, GLfloat height)
	{
		Vertex vertexData[6];

		vertexData[0].setPosition(x, y,0);
		vertexData[1].setPosition(x+width, y,0);
		vertexData[2].setPosition(x+width, y+height,0);
		vertexData[3].setPosition(x+width, y+height,0);
		vertexData[4].setPosition(x, y+height,0);
		vertexData[5].setPosition(x, y,0);

		if (_vboID == 0)
		{
			glGenBuffers(1, &_vboID);
		}

		glBindBuffer(GL_ARRAY_BUFFER, _vboID);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
		//glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void Sprite::draw()
	{
		glBindBuffer(GL_ARRAY_BUFFER, _vboID);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glDisableVertexAttribArray(0);
		//glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}
