#pragma once

#include "Shader.h"
#include <glm\glm.hpp>

class BasicShader : public Shader
{
public:
	BasicShader();
	~BasicShader();

	static BasicShader* getInstance()
	{
		static BasicShader instance;
		return &instance;
	}

	virtual void updateUniforms(const glm::mat4& worldMatrix, const glm::mat4& projectedMatrix) override;

protected:
private:
	BasicShader(BasicShader const&) {}
	void operator=(BasicShader const&) {}

};

