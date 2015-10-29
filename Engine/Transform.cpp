#include "Transform.h"
#include "Util.h"
#include <math.h>
#include <glm\gtx\transform.hpp>
#include <iostream>


Camera* Transform::m_camera = &Camera();
float Transform::m_zFar = 0;
float Transform::m_zNear = 0;
float Transform::m_fov = 0;
float Transform::m_width = 0;
float Transform::m_height = 0;

Transform::Transform()
{

}

Transform::~Transform()
{

}

void Transform::setProjection(float _fov, float _width, float _height, float _near, float _far)
{
	m_fov = _fov;
	m_width = _width;
	m_height = _height;
	m_zNear = _near;
	m_zFar = _far;
}

glm::mat4 Transform::getTransformation()
{
	glm::mat4 translationMatrix = glm::translate(glm::mat4(), translation);
	glm::mat4 rotationMatrix = glm::mat4_cast(glm::normalize(rotation));
	glm::mat4 scaleMatrix = glm::scale(glm::mat4(), scale);
	return translationMatrix * rotationMatrix * scaleMatrix;
}

glm::mat4 Transform::getProjectedTransformation()
{

	glm::mat4 cameraMatrix = initCamera(m_camera->getPos() + m_camera->getForward(), m_camera->getUp());

	return glm::perspective(m_fov, m_width / m_height, m_zNear, m_zFar) * cameraMatrix * getTransformation();
}

glm::mat4 Transform::initCamera(const glm::vec3 & target, const glm::vec3 & up)
{
	return glm::lookAt(m_camera->getPos(), target, up);
}

Camera & Transform::getCamera()
{
	return *m_camera;
}

void Transform::setCamera(Camera & camera)
{
	Transform::m_camera = &camera;
}
