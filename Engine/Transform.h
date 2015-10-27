#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
class Transform
{
public:
	Transform();
	~Transform();

	static void setProjection(float _fov, float _width, float _height, float _near, float _far);

	glm::mat4 getTransformation();
	glm::mat4 getProjectedTransformation();

	void setTranslation(glm::vec3 trans) { translation = trans; }
	void setRotation(glm::quat rot) { rotation = rot; }
	void setScale(glm::vec3 sca) { scale = sca; }

	glm::vec3 getScale() { return scale; }
	glm::quat getRotation() { return rotation; }
	//glm::vec3 getScale() { return scale; }
private:
	glm::vec3 translation = glm::vec3(0.0f,0.0f,0.0f);
	glm::quat rotation = glm::quat(0.0f, 0.0f, 0.0f, 1.0f);
	glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);
};