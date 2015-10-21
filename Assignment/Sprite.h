#pragma once
#include <GL/glew.h>
#include <glm\glm.hpp>
#include "GLTexture.h"
#include <string>
//A 2D quad that can be rendered to the screen

class Rectangle
{
public:
	Rectangle() {};
	Rectangle(glm::vec3 pos, float wid, float heig) : position(pos), width(wid), height(heig) {}
	glm::vec3 position;
	float width;
	float height;
};

class Sprite
{
public:
    Sprite();
    ~Sprite();

    void init(Rectangle rect, std::string texturePath);

    void draw();
    
private:
	Rectangle _rect;
    GLuint _vboID;
	GLTexture _texture;

};

