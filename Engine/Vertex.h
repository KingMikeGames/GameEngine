#pragma once

#include <glm\glm.hpp>

struct Vertex
{
	glm::vec3 pos;

	Vertex(glm::vec3 pos)
	{
		this->pos = pos;
	}
};