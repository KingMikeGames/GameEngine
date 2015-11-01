#include "testGame.h"

void TestGame::Init()
{
	m_mesh = new Mesh("./res/models/crate.obj");
	m_texture = new Texture("animu_tex.jpg");
	m_material = Material(m_texture, glm::vec3(1, 1, 1));

	m_meshRenderer = new MeshRenderer(*m_mesh, m_material);

	m_cube.AddComponent(m_meshRenderer);
	m_cube.GetTransform().setPosition(glm::vec3(-1.5, 0, 3));

	m_cube1.AddComponent(m_meshRenderer);
	m_cube1.GetTransform().setPosition(glm::vec3(1.5, -0, 3));
	
	AddToScene(m_cube);
	AddToScene(m_cube1);
}

void TestGame::Update(float delta)
{
	static float temp = 0;
	temp += delta;

	m_cube.GetTransform().setRotation(glm::angleAxis(temp, glm::vec3(0, 1, 0)));
	m_cube1.GetTransform().setRotation(glm::angleAxis(-temp, glm::vec3(0, 1, 0)));
}

TestGame::~TestGame()
{
	if (m_texture) delete m_texture;
	if (m_mesh) delete m_mesh;
	if (m_meshRenderer) delete m_meshRenderer;
}