#include "Camera.h"
#include "Input.h"
#include "Time.h"
#include "Window.h"
#include <glm\gtx\quaternion.hpp>
bool mouseLocked = false;

Camera::Camera(glm::vec3 pos, glm::vec3 forward, glm::vec3 up) :
	m_pos(pos),
	m_forward(forward),
	m_up(up)
{

}

Camera::~Camera()
{
}

void Camera::input()
{
	float sensitivity = 0.005f;
	float moveAmount = float(5.0f * Time::getDelta());
	float rotationAmount = (float)(Time::getDelta());

	if (Input::getKey(KEY::KEY_ESCAPE))
	{
		Input::setCursor(true);
		mouseLocked = false;
	}

	if (mouseLocked)
	{
		glm::vec2 centerPosition = glm::vec2((float)Window::getWidth() / 2.0f, (float)Window::getHeight() / 2.0f);
		glm::vec2 deltaPos = Input::getMousePosition() - centerPosition;

		bool rotX = deltaPos.x != 0;
		bool rotY = deltaPos.y != 0;

		if (rotX)
		{
			rotateX(deltaPos.x * sensitivity);
		}
		if (rotY)
		{
			rotateY(deltaPos.y * sensitivity);
		}

		if (rotY || rotX)
		{
			Input::setMousePosition(centerPosition);
		}
	}

	if (Input::getMouseDown(MOUSE::LEFT_MOUSE))
	{
		glm::vec2 centerPosition = glm::vec2((float)Window::getWidth() / 2.0f, (float)Window::getHeight() / 2.0f);
		Input::setMousePosition(centerPosition);
		Input::setCursor(false);
		mouseLocked = true;
	}

	if (Input::getKey(KEY::KEY_W))
	{
		move(getForward(), moveAmount);
	}
	if (Input::getKey(KEY::KEY_S))
	{
		move(getForward(), -moveAmount);
	}
	if (Input::getKey(KEY::KEY_A))
	{
		move(getLeft(), -moveAmount);
	}
	if (Input::getKey(KEY::KEY_D))
	{
		move(getRight(), -moveAmount);
	}

}

void Camera::move(const glm::vec3 & direction, float amt)
{
	m_pos += (direction * amt);
}

void Camera::rotateY(float angle)
{
	glm::vec3 hAxis = glm::normalize(glm::cross(glm::vec3(0, 1, 0),m_forward));

	m_forward = glm::normalize(glm::rotate(glm::angleAxis(angle, hAxis), m_forward));
	m_up = glm::normalize(glm::cross(m_forward, hAxis));
}

void Camera::rotateX(float angle)
{
	glm::vec3 hAxis = glm::normalize(glm::cross(glm::vec3(0, 1, 0), m_forward));

	m_forward = glm::normalize(glm::rotate(glm::angleAxis(-angle, m_up), m_forward));
	m_up = glm::normalize(glm::cross(m_forward, hAxis));
}

glm::vec3 & Camera::getPos()
{
	return m_pos;
}

glm::vec3 & Camera::getForward()
{
	return m_forward;
}

glm::vec3 & Camera::getUp()
{
	return m_up;
}

glm::vec3 Camera::getLeft() const
{
	return glm::normalize(glm::cross(m_forward,m_up));
}

glm::vec3 Camera::getRight() const
{
	return glm::normalize(glm::cross(m_up, m_forward));
}

void Camera::setPos(const glm::vec3 & pos)
{
	m_pos = pos;
}

void Camera::setForward(const glm::vec3 & forward)
{
	m_forward = forward;
}

void Camera::SetUp(const glm::vec3 & up)
{
	m_up = up;
}
