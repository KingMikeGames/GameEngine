#pragma once

#include <GL\glew.h>
#include <string>

/*
Images that are wrapped around meshes
*/
class Texture
{
public:

	/*
	loads and decompresses and img so it can be used by any renderer
	@param fileName filepath of image with file extension
	@param textureTarget the type of the texture
	@param filter GL_LINEAR, GL_NEAREST,  etc..
	*/
	Texture(const std::string& fileName, GLenum textureTarget = GL_TEXTURE_2D, GLfloat filter = GL_LINEAR);

	/*
	Texture created from raw data
	@param width width of texture
	@param height height of texture
	@param data a char array of RGB colors
	@param textureTarget type of texture
	@param filter GL_LINEAR, etc
	*/
	Texture(int width = 0, int height = 0, unsigned char* data = 0, GLenum textureTarget = GL_TEXTURE_2D, GLfloat filter = GL_LINEAR);
	~Texture();

	/*
	gets the texture ready to be drawn
	@param textureUnit the active texture location
	*/
	void bind(GLenum textureUnit = GL_TEXTURE0);

	Texture(Texture& texture);
	void operator= (Texture& texture);
private:

	/*
	Most recently bound stops you from rebinding a texture if it's already bound
	*/
	static Texture* m_lastBind;

	/*
	type of texture
	*/
	GLenum m_textureTarget;

	/*
	location of texture on video card
	*/
	GLuint m_textureID;

	/*
	If it's free to be delted
	*/
	bool m_freeTexture;

	/*
	Initializes texture when it's data
	@param fileName filepath of image with file extension
	@param textureTarget the type of the texture
	@param filter GL_LINEAR, GL_NEAREST,  etc..
	*/
	void initTexture(int width, int height, unsigned char* data, GLenum textureTarget, GLfloat filter);
};

