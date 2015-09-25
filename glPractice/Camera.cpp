#include "Camera.h"
namespace Engine{

	Camera::Camera() :
	cameraPosition(glm::vec3(0, 0, 1)),
	cameraTarget(glm::vec3(0, 0, 0)),
	cameraUpDirection(glm::vec3(0, 1, 0))
	{
		_model = glm::mat4(1.0f);
		_viewMatrix = glm::lookAt(cameraPosition, cameraTarget, cameraUpDirection);
		_projectionMatrix = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
		_mvp = _projectionMatrix * _viewMatrix * _model;
	}

Camera::~Camera()
{
}

void Camera::init(GLint CameraMatrixUniformLocation)
{
	_matrixID = CameraMatrixUniformLocation;
}

void Camera::update()
{
	_model = glm::mat4(1.0f);
	_viewMatrix = glm::lookAt(cameraPosition, cameraTarget, cameraUpDirection);
	_projectionMatrix = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	_mvp = _projectionMatrix * _viewMatrix * _model;
	glUniformMatrix4fv(_matrixID, 1, GL_FALSE, &_mvp[0][0]);
}

}
