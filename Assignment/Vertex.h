#pragma once

#include <GL/glew.h>
#include <glm\glm.hpp>
class Vertex
{
public:
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec4 color;
	glm::vec2 uv;
};