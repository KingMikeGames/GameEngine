#pragma once
#include "Mesh.h"
#include "Shader.h"
#include "Transform.h"
#include "Camera.h"
#include "Texture.h"
#include "Material.h"
#include "GameObject.h"
#include "MeshRenderer.h"

class Game
{
public:
	Game();
	virtual ~Game();

	void init();
	void input();
	void update();

	inline GameObject& getRoot() { return m_root; }

private:
	Game(Game& game) {}
	void operator=(Game& game) {}

	GameObject m_root;
	GameObject m_cube0;
	GameObject m_cube1;

	Mesh* m_mesh;
	Shader* m_shader;
	Texture m_texture;
	Material m_material;
	Transform m_transform;
	MeshRenderer* m_meshRenderer;
};