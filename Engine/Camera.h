#pragma once

#include <glm\glm.hpp>

class Camera
{
public:
	Camera(glm::vec3 pos = glm::vec3(0, 0, 0), glm::vec3 forward = glm::vec3(0, 0, -1), glm::vec3 up = glm::vec3(0, 1, 0));
	~Camera();

	void input();
	void move(const glm::vec3& direction, float amt);
	void rotateY(float angle);
	void rotateX(float angle);

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
};

