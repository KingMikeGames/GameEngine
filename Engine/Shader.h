#pragma once

#include <unordered_map>
#include <string>
#include <glm\glm.hpp>
#include "Material.h"

class Shader
{
public:
	Shader();
	~Shader();
	void addUniform(const std::string& uniform);
	void addVertexShaderFromFile(const std::string& text);
	void addGeometryShaderFromFile(const std::string& text);
	void addFragmentShaderFromFile(const std::string& text);
	void addVertexShader(const std::string& text);
	void addGeometryShader(const std::string& text);
	void addFragmentShader(const std::string& text);
	void setUniformi(const std::string& name, int value);
	void setUniformf(const std::string& name, float value);
	void setUniform(const std::string& name, const glm::vec3& value);
	void setUniform(const std::string& name, const glm::mat4& value);
	void compileShader();
	void bind();

	virtual void updateUniforms(const glm::mat4& worldMatrix, const glm::mat4& projectedMatrix, Material& material);

private:
	void addProgram(const std::string& text, int type);

	int m_program;
	std::unordered_map<std::string, int> m_uniforms;
};