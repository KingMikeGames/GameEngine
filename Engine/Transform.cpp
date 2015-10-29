#include "Transform.h"
#include "Util.h"
#include <math.h>
#include <glm\gtx\transform.hpp>
#include <iostream>


Camera* Transform::s_camera = &Camera();
float Transform::s_zFar = 0;
float Transform::s_zNear = 0;
float Transform::s_fov = 0;
float Transform::s_width = 0;
float Transform::s_height = 0;

Transform::Transform()
{

}

Transform::~Transform()
{

}

void Transform::setProjection(float _fov, float _width, float _height, float _near, float _far)
{
	s_fov = _fov;
	s_width = _width;
	s_height = _height;
	s_zNear = _near;
	s_zFar = _far;
}

glm::mat4 Transform::getTransformation() const
{
	glm::mat4 translationMatrix = glm::translate(glm::mat4(), m_position);
	glm::mat4 rotationMatrix = glm::mat4_cast(glm::normalize(m_rotation));
	glm::mat4 scaleMatrix = glm::scale(glm::mat4(), m_scale);
	return translationMatrix * rotationMatrix * scaleMatrix;
}

glm::mat4 Transform::getProjectedTransformation() const
{

	glm::mat4 cameraMatrix = initCamera(s_camera->getPos() + s_camera->getForward(), s_camera->getUp());

	return glm::perspective(s_fov, s_width / s_height, s_zNear, s_zFar) * cameraMatrix * getTransformation();
}

glm::mat4 Transform::initCamera(const glm::vec3 & target, const glm::vec3 & up) const
{
	return glm::lookAt(s_camera->getPos(), target, up);
}

void Transform::setCamera(Camera & camera)
{
	Transform::s_camera = &camera;
}
