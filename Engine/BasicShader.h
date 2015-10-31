#pragma once

#include "Shader.h"
#include <glm\glm.hpp>
#include "Util.h"

/*
Just a basic unlit shader program to be used as default shader
*/

class BasicShader : public Shader
{
public:
	// Gets the instance of the shader
	static BasicShader* getInstance()
	{
		static BasicShader instance;
		return &instance;
	}

	/*
	Updates uniforms using objects transform and material
	takes rendering engine so it can get the mainCamera's view
	@param transform the objects transform
	@param material the objects material
	@param renderingEngine
	*/
	virtual void UpdateUniforms(const Transform& transform, const Material& material, RenderingEngine* renderingEngine);

protected:
private:
	BasicShader();

	BasicShader(BasicShader const&) {}
	void operator=(BasicShader const&) {}

};

