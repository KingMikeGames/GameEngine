#pragma once

#include "camera.h"
class GameObject;


/*
This is the abstract renderer currently set up to use opengl
This draws all things in the engine
*/
class RenderingEngine
{
public:
	/*
	initliazes camera and initializes opengl
	*/
	RenderingEngine();

	/*
	mouse and keyboard inputs
	@param delta time between frames
	*/
	void Input(float delta);

	/*
	render the game object
	@param object gameObject to render
	*/
	void Render(GameObject* object);

	/*
	returns the scene's main camera
	*/
	inline Camera& GetMainCamera() { return m_mainCamera; }

	/*
	sets the main camera
	@param camera the main camera
	*/
	inline void SetMainCamera(const Camera& camera) { m_mainCamera = camera; }

	virtual ~RenderingEngine();
protected:
private:

	RenderingEngine(const RenderingEngine& other) :
	m_mainCamera(glm::radians(70.0f), 16.0/9.0, 0.01f, 1000.0f) {}

	void operator=(const RenderingEngine& other) {}

	/*
	The camera currently viewing the rendered
	*/
	Camera m_mainCamera;
};