#include "RenderingEngine.h"
#include "BasicShader.h"

RenderingEngine::RenderingEngine()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	// set frontface of polygon to clockwise
	//glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	// cull the back face so we don't waste time drawing both
	glEnable(GL_CULL_FACE);
	// draw closer things on top of further things
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_DEPTH_CLAMP);
}

RenderingEngine::~RenderingEngine()
{
}

void RenderingEngine::Render(GameObject* object)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	object->Render(BasicShader::getInstance());
}

void RenderingEngine::EnableTexture(bool enabled)
{
	if (enabled)
	{
		glEnable(GL_TEXTURE_2D);
	}
	else
	{
		glDisable(GL_TEXTURE_2D);
	}
}