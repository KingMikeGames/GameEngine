#pragma once

#include "Transform.h"
#include "Shader.h"

class GameComponent
{
public:
	virtual void Input(const Transform& transform) {}
	virtual void Update(const Transform& transform) {}
	virtual void Render(const Transform& transform, Shader* shader) {}
};
