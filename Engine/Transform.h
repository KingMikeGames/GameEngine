#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include "Camera.h"

class Transform
{
public:
	Transform();
	~Transform();

	static void setProjection(float _fov, float _width, float _height, float _near, float _far);

	glm::mat4 getTransformation();
	glm::mat4 getProjectedTransformation();
	glm::mat4 initCamera(const glm::vec3& target, const glm::vec3& up);

	static inline Camera& getCamera() { return *s_camera; }
	static void setCamera(Camera& camera);

	void setTranslation(glm::vec3 trans) { m_position = trans; }
	void setRotation(glm::quat rot) { m_rotation = rot; }
	void setScale(glm::vec3 sca) { m_scale = sca; }

	glm::vec3 getPosition() { return m_position; }
	glm::vec3 getScale() { return m_scale; }
	glm::quat getRotation() { return m_rotation; }
	//glm::vec3 getScale() { return scale; }
private:
	static Camera* s_camera;

	static float s_fov;
	static float s_width;
	static float s_height;
	static float s_zNear;
	static float s_zFar;

	glm::vec3 m_position = glm::vec3(0.0f,0.0f,0.0f);
	glm::quat m_rotation = glm::quat(0.0f, 0.0f, 0.0f, 1.0f);
	glm::vec3 m_scale = glm::vec3(1.0f, 1.0f, 1.0f);
};