#pragma once

#include <glm\glm.hpp>

/*
Camera is matrix which edits the view of openGL
*/

class Camera
{
public:

	/*
	sets up the perspective matrix
	@param fov The angle in which the camera sees
	@param aspect the width of the window divided by the height
	@param zNear minimum distance you can see
	@param zFar maximum distance you can see
	*/
	Camera(float fov, float aspect, float zNear, float zFar);

	/*
	moves the camera around
	@param delta deltaTime (time between frames)
	*/
	void input(float delta);

	/*
	moves the camera around
	*/
	void move(const glm::vec3& direction, float amt);

	/*
	rotate the camera around Y axis
	*/
	void rotateY(float angle);

	/*
	rotate the camera around X axis
	*/
	void rotateX(float angle);

	/*
	The Matrix that you pass to shader that moves objects based on camera location
	also has view in perspective
	*/
	glm::mat4 GetViewProjection() const;

	/*
	gets the position of the camera
	*/
	glm::vec3& getPosition();

	/*
	gets the forward vector of the camera
	*/
	glm::vec3& getForward();

	/*
	gets the up vector of the camera
	*/
	glm::vec3& getUp();

	/*
	gets the Left vector of the camera
	*/
	glm::vec3 getLeft() const;

	/*
	gets the right vector of the camera
	*/
	glm::vec3 getRight() const;

	/*
	sets the position of the camera
	*/
	void setPosition(const glm::vec3& pos);

	/*
	sets the forward vector of the camera
	changes the direction the camera is facing
	*/
	void setForward(const glm::vec3& forward);

	/*
	sets the upvector of the camera
	*/
	void SetUp(const glm::vec3& up);
private:
	glm::vec3 m_pos;
	glm::vec3 m_forward;
	glm::vec3 m_up;
	glm::mat4 m_projection;
};

