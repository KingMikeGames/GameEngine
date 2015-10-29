#pragma once

#include "Shader.h"
#include <glm\glm.hpp>
#include "Util.h"

class BasicShader : public Shader
{
public:

	static BasicShader* getInstance()
	{
		static BasicShader instance;
		return &instance;
	}

	virtual void updateUniforms(const glm::mat4& worldMatrix, const glm::mat4& projectedMatrix, Material& material) override;

protected:
private:
	BasicShader();

	BasicShader(BasicShader const&) {}
	void operator=(BasicShader const&) {}

};

