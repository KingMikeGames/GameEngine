#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include "Camera.h"
/*
The position rotation and scale of an object
*/
class Transform
{
public:

	/*
	creates a transform
	@param pos vec3 position relative to parent
	@param rot local rotation relative to parent
	@param scale local scale relative to parent
	*/
	Transform(glm::vec3 pos = glm::vec3(0, 0, 0), glm::quat rot = glm::quat(0, 0, 0, 0), glm::vec3 scale = glm::vec3(1,1,1));

	/*
	returns the object's transform
	*/
	glm::mat4 getTransform() const;

	/*
	set position of object
	@param position new position of object
	*/
	void setPosition(glm::vec3 pos) { m_position = pos; }

	/*
	set position of object
	@param rot new rotation of object
	*/
	void setRotation(glm::quat rot) { m_rotation = rot; }

	/*
	set position of object
	@param scale new rotation of object
	*/
	void setScale(glm::vec3 sca) { m_scale = sca; }

	/*
	return object position
	*/
	glm::vec3 getPosition() { return m_position; }
	/*
	return object scale
	*/
	glm::vec3 getScale() { return m_scale; }
	/*
	return object rotation
	*/
	glm::quat getRotation() { return m_rotation; }
private:
	glm::vec3 m_position = glm::vec3(0.0f,0.0f,0.0f);
	glm::quat m_rotation = glm::quat(0.0f, 0.0f, 0.0f, 1.0f);
	glm::vec3 m_scale = glm::vec3(1.0f, 1.0f, 1.0f);
};