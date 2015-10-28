#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv;
layout (location = 3) in vec3 color;

out vec4 colour;

uniform mat4 transform;

void main()
{
	colour = vec4(color, 1.0);
	gl_Position = transform * vec4(position, 1.0);
}