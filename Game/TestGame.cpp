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

	mats1.emplace_back(new Texture("neptune/1.jpg"), glm::vec3(1.0f, 1.0f, 1.0f));
	mats1.emplace_back(new Texture("neptune/2.jpg"), glm::vec3(1.0f, 1.0f, 1.0f));
	mats1.emplace_back(new Texture("neptune/3.jpg"), glm::vec3(1.0f, 1.0f, 1.0f));
	mats1.emplace_back(new Texture("neptune/5.jpg"), glm::vec3(1.0f, 1.0f, 1.0f));
	m_meshRenderer1 = new MeshRenderer(*m_mesh, mats1);

	m_neptune.AddComponent(m_meshRenderer);
	m_neptune.GetTransform().setPosition(glm::vec3(-8, 0, 15));
	m_neptune.GetTransform().setScale(glm::vec3(0.1f,0.1f,0.1f));
	
	m_neptune1.AddComponent(m_meshRenderer1);
	m_neptune1.GetTransform().setPosition(glm::vec3(8, 0, 15));
	m_neptune1.GetTransform().setScale(glm::vec3(0.1f, 0.1f, 0.1f));

	AddToScene(m_neptune);
	AddToScene(m_neptune1);
}

void TestGame::Update(float delta)
{
	static float temp = 0;
	temp += delta;

	m_neptune.GetTransform().setRotation(glm::angleAxis(temp, glm::vec3(1, 0, 0)));
	m_neptune1.GetTransform().setRotation(glm::angleAxis(temp, glm::vec3(-1, 0, 0)));
}

TestGame::~TestGame()
{
	if (m_meshRenderer) delete m_meshRenderer;
}