#pragma once

#include <vector>
#include "Transform.h"
#include "GameComponent.h"

class RenderingEngine;

/*
The base object in the game engine that can 
be rendered and or have logic
*/
class GameObject
{
public:
	GameObject() {}
	/*
	add a child gameObject to the gameObject
	@param child the object being added as child
	*/
	void AddChild(GameObject& child);

	/*
	adds component to gameObject
	@param component mesh, meshRenderer, etc.
	*/
	void AddComponent(GameComponent* component);

	/*
	handles keyboard and mouse events
	@param delta time between frames
	*/
	void Input(float delta);
	/*
	updates logic
	@param delta time between frames
	*/
	void Update(float delta);
	/*
	renders gameobject in scene
	@param shader the shader being used
	@param renderingEninge abstract rendering engine
	*/
	void Render(Shader* shader, RenderingEngine* renderingEngine);

	/*
	gets the transform of the gameobject
	*/
	inline Transform& GetTransform() { return m_transform; }
protected:
private:

	/*
	All children of the gameobject
	*/
	std::vector<GameObject*> m_children;
	std::vector<GameComponent*> m_components;
	Transform m_transform;
};