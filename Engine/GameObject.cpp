#include "gameObject.h"

void GameObject::AddChild(GameObject& child)
{
	m_children.push_back(&child);
	child.GetTransform().setParent(this->GetTransform());
}

void GameObject::AddComponent(GameComponent* component)
{
	m_components.push_back(component);
}

Shader* GameObject::GetShader()
{
	return activeShader;
}

void GameObject::Input(float delta)
{
	for (unsigned int i = 0; i < m_components.size(); i++)
		m_components[i]->Input(m_transform, delta);

	for (unsigned int i = 0; i < m_children.size(); i++)
		m_children[i]->Input(delta);
}

void GameObject::Update(float delta)
{
	for (unsigned int i = 0; i < m_components.size(); i++)
		m_components[i]->Update(m_transform, delta);

	for (unsigned int i = 0; i < m_children.size(); i++)
	{
		if (GetTransform().hasChanged())
		{
			m_children[i]->GetTransform().setParentTransform();
		}
		m_children[i]->Update(delta);
	}
}

void GameObject::Render(Shader* shader, AbstractRenderer* renderingEngine)
{
	for (unsigned int i = 0; i < m_components.size(); i++)
		m_components[i]->Render(m_transform, shader, renderingEngine);

	for (unsigned int i = 0; i < m_children.size(); i++)
		m_children[i]->Render(shader, renderingEngine);
}

void GameObject::Use(Shader* shader)
{
	activeShader = shader;
}