#include "TextureCache.h"
#include "ImageLoader.h"
#include <iostream>

TextureCache::TextureCache()
{
}


TextureCache::~TextureCache()
{
}

GLTexture TextureCache::getTexture(std::string texturePath)
{
	//lookup the texture and see if its in the map
	auto it = _textureMap.find(texturePath);

	//check if its not in the map
	if (it == _textureMap.end())
	{
		//load texture
		GLTexture newTexture = ImageLoader::loadPNG(texturePath);

		//insert it into the map
		_textureMap.insert(make_pair(texturePath,newTexture));

		std::cout << "added new texture into cache!\n" << std::endl;
		return newTexture;
	}

	std::cout << "loaded cached texture\n" << std::endl;
	return it->second;
}
