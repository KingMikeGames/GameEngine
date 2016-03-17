#include "testGame.h"

void TestGame::Init()
{

	m_mesh = new Mesh("res/models/crate.obj");
	m_texture = new Texture("posx.jpg", "negx.jpg", "posy.jpg", "negy.jpg", "posz.jpg", "negz.jpg");
	//m_texture = new Texture("cat_diff.tga");
	m_material = Material(m_texture, glm::vec3(1, 1, 1));
	m_meshRenderer = new MeshRenderer(*m_mesh, m_material);

	cube.AddComponent(m_meshRenderer);
	cube.GetTransform().setPosition(glm::vec3(0, 0, 0));
	cube.GetTransform().setScale(glm::vec3(1, 1, 1));
	AddToScene(cube);

}

static float temp = 0;
void TestGame::Update(float delta)
{
	temp += delta / 2;
}

TestGame::~TestGame()
{
	if (m_texture) delete m_texture;
	if (m_mesh) delete m_mesh;
	if (m_meshRenderer) delete m_meshRenderer;
}