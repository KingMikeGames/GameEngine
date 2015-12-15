#include "BasicShader.h"



BasicShader::BasicShader()
{
	addVertexShaderFromFile("basicVertex.vs");
	addFragmentShaderFromFile("basicFragment.fs");
	compileShader();

	addUniform("transform");
	addUniform("color");
	//addUniform("sampler2D");
}

static unsigned char whitePixel[] = { 0xFF, 0xFF, 0xFF, 0xFF };

void BasicShader::UpdateUniforms(const Transform& transform, const Material& material, AbstractRenderer* renderingEngine)
{
	static Texture WHITE = Texture(1, 1, whitePixel);

	if (material.texture != NULL)
		material.texture->bind();
	else
		WHITE.bind();

	glm::mat4 worldMatrix = transform.getTransform();
	glm::mat4 projectedMatrix = renderingEngine->GetMainCamera().GetViewProjection() * worldMatrix;

	setUniform("transform", projectedMatrix);
	setUniform("color", material.color);
}