#pragma once

#include "camera.h"
class GameObject;

/* 
* This is the current renderer that uses OpenGL and is totally not abstract at all
*/
class RenderingEngine
{
public:
	/*
	* Sets up the camera and initializes OpenGL
	*/
	RenderingEngine();

	/*
	* Handles all keyboard and mouse events
	* @param delta Time between frames
	*/
	void Input(float delta);

	/*
	* Renders a GameObject
	* @param object GameObject to render
	*/
	void Render(GameObject* object);

	/*
	* Returns the main camera in the scene
	* @return The main camera
	*/
	inline Camera& GetMainCamera() { return m_mainCamera; }

	/*
	* Sets the main camera in the scene
	* @param camera The new main camera
	*/
	inline void SetMainCamera(const Camera& camera) { m_mainCamera = camera; }

	virtual ~RenderingEngine();
protected:
private:
	RenderingEngine(const RenderingEngine& other) :
	m_mainCamera(glm::radians(70.0f), 16.0/9.0, 0.01f, 1000.0f) {}
	void operator=(const RenderingEngine& other) {}

	/* The camera currently viewing the rendered scene */
	Camera m_mainCamera;
};