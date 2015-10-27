#include "renderUtil.h"
#include <GL/glew.h>

void RenderUtil::clearScreen()
{
	// clear colors || clear the depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//TODO: stencil buffer
}

void RenderUtil::initGraphics()
{
	glClearColor(0.23137254902f, 0.61960784313f, 0.69411764705f, 0.0f);

	// set frontface of polygon to clockwise
	//glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	// cull the back face so we don't waste time drawing both
	glEnable(GL_CULL_FACE);

	// draw closer things on top of further things
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_DEPTH_CLAMP);
}