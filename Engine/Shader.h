#pragma once

#include <unordered_map>
#include <string>
#include <glm/glm.hpp>

class Shader
{
public:
	Shader();
	~Shader();
	void addUniform(const std::string& uniform);
	void addVertexShaderFromFile(const std::string& text);
	void addGeometryShaderFromFile(const std::string& text);
	void addFragmentShaderFromFile(const std::string& text);
	void setUniformi(const std::string& name, int value);
	void setUniformf(const std::string& name, float value);
	void setUniform(const std::string& name, const glm::vec3& value);
	void setUniform(const std::string& name, const glm::mat4& value);
	void compileShader();
	void bind();
private:
	void addProgram(const std::string& text, int type);

	int m_program;
	std::unordered_map<std::string, int> m_uniforms;
};