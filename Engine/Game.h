#pragma once
#include "gameObject.h"

#include "gameObject.h"

class Game
{
public:
	Game() {}
	virtual ~Game() {}

	virtual void Init() {}
	virtual void Input(float delta);
	virtual void Update(float delta);

	inline GameObject& GetRoot() { return m_root; }
protected:
	void AddToScene(GameObject& child) { m_root.AddChild(child); }
private:
	Game(Game& game) {}
	void operator=(Game& game) {}

	GameObject m_root;
};