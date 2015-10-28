#pragma once

#include "Texture.h"
#include <glm/glm.hpp>

struct Material
{
	Texture* texture;
	glm::vec3 color;

	Material(Texture* texture = NULL, const glm::vec3& color = glm::vec3(1.0f, 1.0f, 1.0f))
	{
		this->texture = texture;
		this->color = color;
	}
};