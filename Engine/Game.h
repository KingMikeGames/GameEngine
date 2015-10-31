#pragma once
#include "gameObject.h"

#include "gameObject.h"

/*
the class you create for your custom game
*/

class Game
{
public:
	Game() {}
	virtual ~Game() {}

	/*
	Initialize whatever you want here
	*/
	virtual void Init() {}

	/*
	runs all input events (keyboard, mouse)
	polls sdl events
	*/
	virtual void Input(float delta);

	/*
	your game logic updates
	updates at your games desired frame rate
	*/
	virtual void Update(float delta);

	/*
	gets the root of the scene graph
	*/
	inline GameObject& GetRoot() { return m_root; }
protected:

	/*
	Adds objects to the scene graph
	@param child Gameobject to add to the scene
	*/
	void AddToScene(GameObject& child) { m_root.AddChild(child); }
private:
	Game(Game& game) {}
	void operator=(Game& game) {}

	GameObject m_root;
};