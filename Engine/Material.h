#pragma once

#include "Texture.h"
#include <glm/glm.hpp>

/*
holds texture and color
*/
struct Material
{
	Texture* texture;
	glm::vec3 color;

	/*
	set texture and color
	@param texture texture of material
	@param color color of material default white
	*/
	Material(Texture* texture = NULL, const glm::vec3& color = glm::vec3(1.0f, 1.0f, 1.0f))
	{
		this->texture = texture;
		this->color = color;
	}
};