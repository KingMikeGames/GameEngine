#pragma once

#include <glm\glm.hpp>

struct Vertex
{
	glm::vec3 pos;
	glm::vec3 normal;
	glm::vec2 uv;
	glm::vec4 color;

	Vertex(glm::vec3 pos, glm::vec2 uv = glm::vec2(0,0), glm::vec3 normal = glm::vec3(0,0,0), glm::vec4 color = glm::vec4(0,0,0,0))
	{
		this->pos = pos;
		this->uv = uv;
		this->normal = normal;
		this->color = color;
	}
};