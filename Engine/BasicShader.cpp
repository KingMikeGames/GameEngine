#include "BasicShader.h"



BasicShader::BasicShader()
{

	addVertexShaderFromFile("basicVertex.vs");
	addFragmentShaderFromFile("basicFragment.fs");

	addUniform("transform");

}


BasicShader::~BasicShader()
{
}

static unsigned char whitePixel[] = { 0xFF, 0xFF, 0xFF, 0xFF };

void BasicShader::updateUniforms(const glm::mat4& worldMatrix, const glm::mat4& projectedMatrix)
{
	setUniform("transform", projectedMatrix);
}