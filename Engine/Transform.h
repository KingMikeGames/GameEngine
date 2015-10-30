#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include "Camera.h"

class Transform
{
public:
	Transform(glm::vec3 pos = glm::vec3(0, 0, 0), glm::quat rot = glm::quat(0, 0, 0, 0), glm::vec3 scale = glm::vec3(0,0,0));

	glm::mat4 getTransformation() const;

	void setTranslation(glm::vec3 trans) { m_position = trans; }
	void setRotation(glm::quat rot) { m_rotation = rot; }
	void setScale(glm::vec3 sca) { m_scale = sca; }

	glm::vec3 getPosition() { return m_position; }
	glm::vec3 getScale() { return m_scale; }
	glm::quat getRotation() { return m_rotation; }
	//glm::vec3 getScale() { return scale; }
private:
	glm::vec3 m_position = glm::vec3(0.0f,0.0f,0.0f);
	glm::quat m_rotation = glm::quat(0.0f, 0.0f, 0.0f, 1.0f);
	glm::vec3 m_scale = glm::vec3(1.0f, 1.0f, 1.0f);
};