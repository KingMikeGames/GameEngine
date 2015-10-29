#pragma once

#include "gameObject.h"

class RenderingEngine
{
public:
	RenderingEngine();

	void Render(GameObject* object);

	virtual ~RenderingEngine();
protected:
private:
	RenderingEngine(const RenderingEngine& other) {}
	void operator=(const RenderingEngine& other) {}
};