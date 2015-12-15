#include "GameComponent.h"

void GameComponent::SetParent(GameObject* parent) 
{ 
	m_parent = parent; 
}

GameObject* GameComponent::GetParent()
{
	return m_parent;
}