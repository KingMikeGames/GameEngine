#include "testGame.h"

void TestGame::Init()
{

	Vertex verts[8] = {
		Vertex(glm::vec3(-0.5f, -0.5f, 0.5f)),
		Vertex(glm::vec3(-0.5f, 0.5f, 0.5f)),
		Vertex(glm::vec3(0.5f, 0.5f, 0.5f)),
		Vertex(glm::vec3(-0.5f, -0.5f, 0.5f)),
		Vertex(glm::vec3(-0.5f, -0.5f, 0.5f)),
		Vertex(glm::vec3(-0.5f, -0.5f, 0.5f)),
		Vertex(glm::vec3(-0.5f, -0.5f, 0.5f)),
		Vertex(glm::vec3(-0.5f, -0.5f, 0.5f))
	};

	int indices[24] = {

	};
	//m_mesh = new Mesh(verts, 8, indices, 24, true);

	m_mesh = new Mesh("res/models/cube.obj");
	m_texture = new Texture("posx.jpg", "negx.jpg", "posy.jpg", "negy.jpg", "posz.jpg", "negz.jpg");
	m_material = Material(m_texture, glm::vec3(1, 1, 1));
	m_meshRenderer = new MeshRenderer(*m_mesh, m_material);

	cube.AddComponent(m_meshRenderer);
	cube.GetTransform().setPosition(glm::vec3(0, 0, 0));
	cube.GetTransform().setScale(glm::vec3(50, 50, 50));
	AddToScene(cube);

}

static float temp = 0;
void TestGame::Update(float delta)
{
	temp += delta / 2;
	cube.GetTransform().setRotation(glm::angleAxis(temp, glm::vec3(0, 1, 0)));
}

TestGame::~TestGame()
{
	if (m_texture) delete m_texture;
	if (m_mesh) delete m_mesh;
	if (m_meshRenderer) delete m_meshRenderer;
}