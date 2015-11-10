#pragma once
#pragma once

#include "camera.h"
#include "Window.h"
class GameObject;

/*
* This is the current renderer that uses OpenGL and is totally not abstract at all
*/
class AbstractRenderer
{
public:
	/*
	* Sets up the camera and initializes OpenGL
	*/
	AbstractRenderer() :
		m_mainCamera(glm::radians(70.0f), Window::GetAspect(), 0.01f, 1000.0f)
	{}

	/*
	* Handles all keyboard and mouse events
	* @param delta Time between frames
	*/
	virtual void Input(float delta) = 0;

	/*
	* Renders a GameObject
	* @param object GameObject to render
	*/
	virtual void Render(GameObject* object) = 0;

	/*
	* Returns the main camera in the scene
	* @return The main camera
	*/
	virtual inline Camera& GetMainCamera() = 0;

	/*
	* Sets the main camera in the scene
	* @param camera The new main camera
	*/
	virtual inline void SetMainCamera(const Camera& camera) = 0;
protected:
	/* The camera currently viewing the rendered scene */
	Camera m_mainCamera;

};