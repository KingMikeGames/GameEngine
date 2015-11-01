#include "testGame.h"
#include <vector>
void TestGame::Init()
{
	m_mesh = new Mesh("./res/models/neptune.obj");

	
	mats.emplace_back(new Texture("neptune/1.jpg"), glm::vec3(1.0f, 1.0f, 1.0f));
	mats.emplace_back(new Texture("neptune/2.jpg"), glm::vec3(1.0f, 1.0f, 1.0f));
	mats.emplace_back(new Texture("neptune/4.jpg"), glm::vec3(1.0f, 1.0f, 1.0f));
	mats.emplace_back(new Texture("neptune/5.jpg"), glm::vec3(1.0f, 1.0f, 1.0f));
	m_meshRenderer = new MeshRenderer(*m_mesh, mats);

	m_cube.AddComponent(m_meshRenderer);
	m_cube.GetTransform().setPosition(glm::vec3(0, 0, 3));
	m_cube.GetTransform().setScale(glm::vec3(1.0f,1.0f,1.0f));
	
	AddToScene(m_cube);
	//AddToScene(m_cube1);
}

void TestGame::Update(float delta)
{
	static float temp = 0;
	temp += delta;

	m_cube.GetTransform().setRotation(glm::angleAxis(temp, glm::vec3(0, 1, 0)));
}

TestGame::~TestGame()
{
	if (m_meshRenderer) delete m_meshRenderer;
}