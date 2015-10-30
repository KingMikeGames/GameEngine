#pragma once

#include <glm\glm.hpp>

class Camera
{
public:
	Camera(float fov, float aspect, float zNear, float zFar);

	void input(float delta);
	void move(const glm::vec3& direction, float amt);
	void rotateY(float angle);
	void rotateX(float angle);

	glm::mat4 GetViewProjection() const;

	glm::vec3& getPos();
	glm::vec3& getForward();
	glm::vec3& getUp();

	glm::vec3 getLeft() const;
	glm::vec3 getRight() const;

	void setPos(const glm::vec3& pos);
	void setForward(const glm::vec3& forward);
	void SetUp(const glm::vec3& up);
private:
	glm::vec3 m_pos;
	glm::vec3 m_forward;
	glm::vec3 m_up;
	glm::mat4 m_projection;
};

