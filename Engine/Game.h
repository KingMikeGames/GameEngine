#pragma once
#include "Mesh.h"
#include "Shader.h"
#include "Transform.h"
#include "Camera.h"
#include "Texture.h"
#include "Material.h"
#include "GameObject.h"

class Game
{
public:
	Game();
	virtual ~Game();

	void init();
	void input();
	void update();
	void render();
private:
	Game(Game& game) {}
	void operator=(Game& game) {}

	GameObject m_root;


	Mesh m_mesh;
	Shader* m_shader;
	Texture m_texture;
	Material m_material;
	Transform m_transform;
	Camera m_camera = Camera(glm::vec3(0, 0, 5), glm::vec3(0, 0, -1), glm::vec3(0, 1, 0));
};