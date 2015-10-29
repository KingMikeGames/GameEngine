#pragma once

#include <vector>
#include "Transform.h"
#include "GameComponent.h"

class GameObject
{
public:
	GameObject() {}
	void AddChild(GameObject& child);
	void AddComponent(GameComponent* component);

	void Input();
	void Update();
	void Render(Shader* shader);

	inline Transform& GetTransform() { return m_transform; }
protected:
private:
	std::vector<GameObject*> m_children;
	std::vector<GameComponent*> m_components;
	Transform m_transform;
};