#pragma once

#include <unordered_map>
#include <string>
#include <glm\glm.hpp>
#include "Material.h"
#include "RenderingEngine.h"
#include "Transform.h"


/*
Shader class is used to create and store any type of shader
*/
class Shader
{
public:

	/*
	Creates the shader program
	*/
	Shader();
	~Shader();

	/*
	takes in the name of a uniform, finds it in the shader file and adds it
	to a map for later use if it exists.
	@param uniform name of the uniform in the shader
	*/
	void addUniform(const std::string& uniform);

	/*
	takes in the address of the shader
	converts the file to a string
	adds the vertex shader to program
	@param text file address
	*/
	void addVertexShaderFromFile(const std::string& text);

	/*
	takes in the address of the shader
	converts the file to a string
	adds the geometry shader to program
	@param text file address
	*/
	void addGeometryShaderFromFile(const std::string& text);

	/*
	takes in the address of the shader
	converts the file to a string
	adds the fragment shader to program
	@param text file address
	*/
	void addFragmentShaderFromFile(const std::string& text);

	/*
	adds the shader to the bound program
	@param text shader in string format
	*/
	void addVertexShader(const std::string& text);

	/*
	adds the shader to the bound program
	@param text shader in string format
	*/
	void addGeometryShader(const std::string& text);

	/*
	adds the shader to the bound program
	@param text shader in string format
	*/
	void addFragmentShader(const std::string& text);

	/*
	modifies the value of an integer uniform
	@param name key to uniform in unordered map
	@param value The value of the uniform
	*/
	void setUniformi(const std::string& name, int value);

	/*
	modifies the value of an float uniform
	@param name key to uniform in unordered map
	@param value The value of the uniform
	*/
	void setUniformf(const std::string& name, float value);

	/*
	modifies the value of an vector 3 uniform
	@param name key to uniform in unordered map
	@param value The value of the uniform
	*/
	void setUniform(const std::string& name, const glm::vec3& value);

	/*
	modifies the value of an matrix 4 uniform
	@param name key to uniform in unordered map
	@param value The value of the uniform
	*/
	void setUniform(const std::string& name, const glm::mat4& value);

	/*
	compiles the shader program
	checks for errors in the program
	*/
	void compileShader();

	/*
	calls glUseProgram
	uses the program for rendering
	*/
	void bind();

	/*
	Updates uniforms using objects transform and material
	takes rendering engine so it can get the mainCamera's view
	@param transform the objects transform
	@param material the objects material
	@param renderingEngine 
	*/
	virtual void UpdateUniforms(const Transform& transform, const Material& material, RenderingEngine* renderingEngine);

private:
	/*
	compiles the shader and attaches it to the program
	@param text The shader string
	@param type The type of shader (GL_VERTEX_SHADER, GL_FRAGMENT_SHADER, GL_FRAGMENT_SHADER)
	*/
	void addProgram(const std::string& text, int type);

	// The shader program
	int m_program;

	//list of uniforms with the names as keys
	std::unordered_map<std::string, int> m_uniforms;
};