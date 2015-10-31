#pragma once

#include "Transform.h"
#include "Shader.h"

class RenderingEngine;
class Shader;

/*
Components of a gameobject with their own logic
Updated through the gameobject's update loop
*/

class GameComponent
{
public:
	virtual ~GameComponent() {}

	/*
	handles keyboard and mouse input events
	@param transform the gameobject's transform
	@param delta deltaTime
	*/
	virtual void Input(const Transform& transform, float delta) {}
	/*
	Updates component logic at games frame rate
	@param transform the gameobject's transform
	@param delta deltaTime
	*/
	virtual void Update(const Transform& transform, float delta) {}
	/*
	Render the game object
	@param gameobject transform
	@param shader the shader program being used
	@param the abstract renderer
	*/
	virtual void Render(const Transform& transform, Shader* shader, RenderingEngine* renderingEngine) {}
};
