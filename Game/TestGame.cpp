#include "testGame.h"


void TestGame::Init()
{
	 Vertex vertices[8] = {
		Vertex(glm::vec3(-0.5, -0.5, 0.5), glm::vec2(0,0), glm::vec3(0,0,0), glm::vec4(1,0,0,1)),
		Vertex(glm::vec3(-0.5, 0.5, 0.5), glm::vec2(0,0), glm::vec3(0,0,0), glm::vec4(0,1,0,1)),
		Vertex(glm::vec3(0.5, 0.5, 0.5), glm::vec2(0,0), glm::vec3(0,0,0), glm::vec4(0,0,1,1)),
		Vertex(glm::vec3(0.5, -0.5, 0.5), glm::vec2(0,0), glm::vec3(0,0,0), glm::vec4(1,1,0,1)),
		Vertex(glm::vec3(0.5, -0.5, -0.5), glm::vec2(0,0), glm::vec3(0,0,0), glm::vec4(1,0,1,1)),
		Vertex(glm::vec3(0.5, 0.5, -0.5), glm::vec2(0,0), glm::vec3(0,0,0), glm::vec4(0,1,1,1)),
		Vertex(glm::vec3(-0.5, 0.5, -0.5), glm::vec2(0,0), glm::vec3(0,0,0), glm::vec4(0,0,0,1)),
		Vertex(glm::vec3(-0.5, -0.5, -0.5), glm::vec2(0,0), glm::vec3(0,0,0), glm::vec4(1,1,1,1)),
	};

	int indices[36]{
		3,2,0,2,1,0,
		0,1,7,1,6,7,
		7,6,4,6,5,4,
		4,5,3,5,2,3,
		2,5,3,5,7,1,
		4,3,7,3,0,7
	};

	m_mesh = new Mesh(vertices, 8, indices, 36, false);
	m_texture = new Texture("animu_tex.jpg"); // not being applied in the shader
	m_material = Material(m_texture, glm::vec3(1, 1, 1));

	m_meshRenderer = new MeshRenderer(*m_mesh, m_material);

	
	m_cube.AddComponent(m_meshRenderer);
	m_cube.GetTransform().setPosition(glm::vec3(0, 0, 3));

	m_cube1.AddComponent(m_meshRenderer);
	m_cube1.GetTransform().setPosition(glm::vec3(0, 1, 0));
	m_cube1.GetTransform().setRotation(glm::angleAxis(45.f, glm::vec3(0, 1, 0)));
	
	m_cube.AddChild(m_cube1);

	AddToScene(m_cube);
}

void TestGame::Update(float delta)
{
	static float temp = 0;
	temp += delta;
	m_cube.GetTransform().setRotation(glm::angleAxis(temp, glm::vec3(0, 1, 0)));
}

TestGame::~TestGame()
{
	if (m_texture) delete m_texture;
	if (m_mesh) delete m_mesh;
	if (m_meshRenderer) delete m_meshRenderer;
}