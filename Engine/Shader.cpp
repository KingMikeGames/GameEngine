#include "Shader.h"
#include <cassert>
#include <memory>
#include <fstream>
#include <iostream>
#include <GL/glew.h>

#include "util.h"


Shader::Shader()
{
	m_program = glCreateProgram();

	if (m_program == 0)
	{
		fprintf(stderr, "Error creating shader program\n");
		exit(1);
	}
}

Shader::~Shader()
{

}

void Shader::bind()
{
	glUseProgram(m_program);
}

void Shader::addUniform(const std::string& uniform)
{
	int location = glGetUniformLocation(m_program, uniform.c_str());

	assert(location != INVALID_VALUE);

	m_uniforms.emplace(uniform, location);
}

void Shader::addVertexShaderFromFile(const std::string& text)
{
	addProgram(text, GL_VERTEX_SHADER);
}

void Shader::addGeometryShaderFromFile(const std::string& text)
{
	addProgram(text, GL_GEOMETRY_SHADER);
}

void Shader::addFragmentShaderFromFile(const std::string& text)
{
	addProgram(text, GL_FRAGMENT_SHADER);
}

void Shader::setUniformi(const std::string& name, int value)
{
	glUniform1i(m_uniforms.at(name), value);
}

void Shader::setUniformf(const std::string& name, float value)
{
	glUniform1f(m_uniforms.at(name), value);
}

void Shader::setUniform(const std::string& name, const glm::vec3& value)
{
	glUniform3f(m_uniforms.at(name), value.x, value.y, value.z);
}

void Shader::setUniform(const std::string& name, const glm::mat4& value)
{
	glUniformMatrix4fv(m_uniforms.at(name), 1, false, &(value[0][0]));
}

void Shader::addProgram(const std::string& text, int type)
{
	int shader = glCreateShader(type);

	if (shader == 0)
	{
		fprintf(stderr, "Error creating shader type %d\n", type);
		exit(1);
	}

	const GLchar* p[1];
	p[0] = text.c_str();
	GLint lengths[1];
	lengths[0] = text.length();

	glShaderSource(shader, 1, p, lengths);
	glCompileShader(shader);

	GLint success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		GLchar InfoLog[1024];

		glGetShaderInfoLog(shader, 1024, NULL, InfoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", shader, InfoLog);

		exit(1);
	}

	glAttachShader(m_program, shader);
}

void Shader::compileShader()
{
	glLinkProgram(m_program);

	int success = 0;
	glGetProgramiv(m_program, GL_LINK_STATUS, &success);
	if (success == 0)
	{
		fprintf(stderr, "Error linking shader program");
		exit(1);
	}

	glValidateProgram(m_program);

	glGetProgramiv(m_program, GL_VALIDATE_STATUS, &success);
	if (!success) {
		fprintf(stderr, "Invalid shader program");
		exit(1);
	}

	glUseProgram(m_program);
}