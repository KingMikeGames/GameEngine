#pragma once

#include "Transform.h"
#include "Shader.h"

class RenderingEngine;
class Shader;
class GameObject;

/*
* Components of a Game Object with their own logic in the game's Update loop
*/
class GameComponent
{
public:
	GameComponent() :
		m_parent(0) {}
	virtual ~GameComponent() {}

	/*
	* Handles all keyboard and mouse input events
	* @param transform Transform of the GameObject
	* @param delta Time between frames
	*/
	virtual void Input(const Transform& transform, float delta) {}

	/*
	* Updates game logic at your game's desired frame rate
	* @param transform Transform of the GameObject
	* @param delta Time between frames
	*/
	virtual void Update(const Transform& transform, float delta) {}

	/*
	* Renders the GameObject
	* @param transform Transform of the GameObject
	* @param shader Shader program being used to render
	* @param renderingEngine The renderer
	*/
	virtual void Render(const Transform& transform, Shader* shader, RenderingEngine* renderingEngine) {}

	virtual void SetParent(GameObject* parent);
	GameObject* GetParent();
private:
	GameObject* m_parent;

	GameComponent(const GameComponent& other) {}
	void operator=(const GameComponent& other) {}
};
