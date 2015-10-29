#include "GameObject.h"


void GameObject::AddChild(GameObject& child)
{
	m_children.push_back(&child);
}

void GameObject::AddComponent(GameComponent* component)
{
	m_components.push_back(component);
}

void GameObject::Input()
{
	for (unsigned int i = 0; i < m_components.size(); i++)
		m_components[i]->Input(m_transform);

	for (unsigned int i = 0; i < m_children.size(); i++)
		m_children[i]->Input();
}

void GameObject::Update()
{
	for (unsigned int i = 0; i < m_components.size(); i++)
		m_components[i]->Update(m_transform);

	for (unsigned int i = 0; i < m_children.size(); i++)
		m_children[i]->Update();
}

void GameObject::Render()
{
	for (unsigned int i = 0; i < m_components.size(); i++)
		m_components[i]->Render(m_transform);

	for (unsigned int i = 0; i < m_children.size(); i++)
		m_children[i]->Render();
}