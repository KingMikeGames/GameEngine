#pragma once

#include <glm\glm.hpp>

struct Vertex
{
	glm::vec3 pos;
	glm::vec3 normal;
	glm::vec2 uv;
	glm::vec3 color;

	Vertex(glm::vec3 pos)
	{
		this->pos = pos;
	}
};