#include "testGame.h"

void TestGame::Init()
{
	m_mesh = new Mesh("./res/models/cube.obj");
	m_texture = new Texture("small.png");
	m_material = Material(m_texture, glm::vec3(1, 1, 1));

	m_meshRenderer = new MeshRenderer(*m_mesh, m_material);
	m_cube.AddComponent(m_meshRenderer);
	m_cube.GetTransform().setTranslation(glm::vec3(0, -1, 5));
	m_cube.GetTransform().setScale(glm::vec3(1.0,1.0,1.0));

	m_cube1.AddComponent(m_meshRenderer);
	m_cube1.GetTransform().setTranslation(glm::vec3(5, -1, 5));
	m_cube1.GetTransform().setScale(glm::vec3(1.0, 1.0, 1.0));

	AddToScene(m_cube);
	AddToScene(m_cube1);
}

void TestGame::Update(float delta)
{
	static float temp = 0;
	temp += delta;

	m_cube.GetTransform().setRotation(glm::angleAxis(temp, glm::vec3(0, 1, 0)));
	m_cube1.GetTransform().setRotation(glm::angleAxis(-temp, glm::vec3(1, 1, 0)));
	m_cube1.GetTransform().setTranslation(glm::vec3(sin(temp*2),sin(temp*3),sin(temp*8)));
}

TestGame::~TestGame()
{
	if (m_texture) delete m_texture;
	if (m_mesh) delete m_mesh;
	if (m_meshRenderer) delete m_meshRenderer;
}