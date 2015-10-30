#pragma once

#include "camera.h"
class GameObject;

class RenderingEngine
{
public:
	RenderingEngine();

	void Input(float delta);
	void Render(GameObject* object);

	inline Camera& GetMainCamera() { return m_mainCamera; }
	inline void SetMainCamera(const Camera& camera) { m_mainCamera = camera; }

	virtual ~RenderingEngine();
protected:
private:
	RenderingEngine(const RenderingEngine& other) :
	m_mainCamera(glm::radians(70.0f), 16.0/9.0, 0.01f, 1000.0f) {}
	void operator=(const RenderingEngine& other) {}

	Camera m_mainCamera;
};