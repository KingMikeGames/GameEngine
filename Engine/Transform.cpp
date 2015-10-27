#include "Transform.h"
#include "Util.h"
#include <math.h>
#include <glm\gtx\transform.hpp>
#include <iostream>
static float zNear, zFar, width, height, fov;

Transform::Transform()
{

}

Transform::~Transform()
{

}

void Transform::setProjection(float _fov, float _width, float _height, float _near, float _far)
{
	fov = _fov;
	width = _width;
	height = _height;
	zNear = _near;
	zFar = _far;
}

glm::mat4 Transform::getTransformation()
{
	glm::mat4 translationMatrix = glm::translate(glm::mat4(), translation);
	glm::mat4 rotationMatrix = glm::mat4_cast(rotation);
	glm::mat4 scaleMatrix = glm::scale(glm::mat4(), scale);
	return translationMatrix * rotationMatrix * scaleMatrix;
}

glm::mat4 Transform::getProjectedTransformation()
{
	
	std::cout << zFar << std::endl;
	return glm::perspective(fov, width / height, zNear, zFar) * getTransformation();

}