#pragma once

#include "GameObject.h"

class RenderingEngine
{
public:
	RenderingEngine();
	virtual ~RenderingEngine();

	void Render(GameObject* object);

	static void EnableTexture(bool enabled);
};

