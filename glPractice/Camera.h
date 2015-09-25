#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <GL/glew.h>
#include <string>

namespace Engine{
class Camera
{
public:
	Camera();
	~Camera();

	glm::vec3 cameraPosition;
	glm::vec3 cameraTarget;
	glm::vec3 cameraUpDirection;

	void init(GLint CameraMatrixUniformLocation);
	void update();

	// Setters
	void setModelMatrix(glm::mat4 CameraMatrix){ _model = CameraMatrix; }
	void setProjectionMatrix(GLfloat HorizontalFieldOfView, GLfloat ScreenRatio, GLfloat RangeNear, GLfloat RangeFar){ _projectionMatrix = glm::perspective(HorizontalFieldOfView, ScreenRatio, RangeNear, RangeFar);}




private:

	GLint _matrixID;
	glm::mat4 _model;
	glm::mat4 _viewMatrix;
	glm::mat4 _projectionMatrix;
	glm::mat4 _mvp;

};
}

