#pragma once
#include <GL/glew.h>
#include <string>
namespace Engine{

class GLSLProgram
{
public:
	GLSLProgram();
	~GLSLProgram();

	void loadShader(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilepath);
	void addAttribute(const std::string& attributeName);
	GLint getUniformLocation(const std::string& uniformName);
	void use();
	void unuse();
	void link();


	GLuint getProgramID(){ return _programID; }
			

private:
	GLuint _programID;
	GLuint _vertexShaderID;
	GLuint _fragmentShaderID;
	int _numAttributes;

	void compile(const std::string& filePath, GLuint id);
};

}

