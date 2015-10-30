#pragma once

#include "Transform.h"
#include "Shader.h"

class RenderingEngine;
class Shader;

class GameComponent
{
public:
	virtual ~GameComponent() {}

	virtual void Input(const Transform& transform, float delta) {}
	virtual void Update(const Transform& transform, float delta) {}
	virtual void Render(const Transform& transform, Shader* shader, RenderingEngine* renderingEngine) {}
};
