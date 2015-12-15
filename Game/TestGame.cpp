#include "testGame.h"

void TestGame::Init()
{
	//0 = wall
	//1 = open
	//2 = start
	//3 = end

	maze[0][0] = 0; maze[0][1] = 0; maze[0][2] = 2; maze[0][3] = 0; maze[0][4] = 0; maze[0][5] = 0; maze[0][6] = 0; maze[0][7] = 0; maze[0][8] = 0; maze[0][9] = 0;
	maze[1][0] = 0; maze[1][1] = 1; maze[1][2] = 1; maze[1][3] = 1; maze[1][4] = 1; maze[1][5] = 1; maze[1][6] = 1; maze[1][7] = 1; maze[1][8] = 1; maze[1][9] = 0;
	maze[2][0] = 0; maze[2][1] = 0; maze[2][2] = 0; maze[2][3] = 0; maze[2][4] = 0; maze[2][5] = 1; maze[2][6] = 0; maze[2][7] = 0; maze[2][8] = 1; maze[2][9] = 0;
	maze[3][0] = 0; maze[3][1] = 0; maze[3][2] = 1; maze[3][3] = 1; maze[3][4] = 1; maze[3][5] = 1; maze[3][6] = 0; maze[3][7] = 0; maze[3][8] = 0; maze[3][9] = 0;
	maze[4][0] = 0; maze[4][1] = 0; maze[4][2] = 1; maze[4][3] = 0; maze[4][4] = 1; maze[4][5] = 0; maze[4][6] = 0; maze[4][7] = 0; maze[4][8] = 1; maze[4][9] = 0;
	maze[5][0] = 0; maze[5][1] = 1; maze[5][2] = 1; maze[5][3] = 0; maze[5][4] = 1; maze[5][5] = 1; maze[5][6] = 1; maze[5][7] = 1; maze[5][8] = 1; maze[5][9] = 0;
	maze[6][0] = 0; maze[6][1] = 1; maze[6][2] = 1; maze[6][3] = 0; maze[6][4] = 0; maze[6][5] = 0; maze[6][6] = 0; maze[6][7] = 0; maze[6][8] = 1; maze[6][9] = 0;
	maze[7][0] = 0; maze[7][1] = 1; maze[7][2] = 0; maze[7][3] = 1; maze[7][4] = 0; maze[7][5] = 0; maze[7][6] = 0; maze[7][7] = 0; maze[7][8] = 0; maze[7][9] = 0;
	maze[8][0] = 0; maze[8][1] = 1; maze[8][2] = 1; maze[8][3] = 1; maze[8][4] = 1; maze[8][5] = 1; maze[8][6] = 1; maze[8][7] = 1; maze[8][8] = 1; maze[8][9] = 0;
	maze[9][0] = 0; maze[9][1] = 0; maze[9][2] = 0; maze[9][3] = 0; maze[9][4] = 3; maze[9][5] = 0; maze[9][6] = 0; maze[9][7] = 0; maze[9][8] = 0; maze[9][9] = 0;


	m_mesh = new Mesh("res/models/crate.obj");
	m_texture = new Texture("crate_tex3.jpg");
	m_texture1 = new Texture("animu_tex.jpg");
	m_texture2 = new Texture("start_tex.png");
	m_texture3 = new Texture("animu_tex.jpg");
	m_material = Material(m_texture, glm::vec3(1, 1, 1));
	m_material1 = Material(m_texture1, glm::vec3(1, 1, 1));
	m_material2 = Material(m_texture2, glm::vec3(1, 1, 1));
	m_material3 = Material(m_texture3, glm::vec3(1, 1, 1));
	m_meshRenderer = new MeshRenderer(*m_mesh, m_material);
	m_meshRenderer1 = new MeshRenderer(*m_mesh, m_material1);
	m_meshRenderer2 = new MeshRenderer(*m_mesh, m_material2);
	m_meshRenderer3 = new MeshRenderer(*m_mesh, m_material3);


	for (unsigned int i = 0; i < 10; ++i)
	{
		for (unsigned int j = 0; j < 10; ++j)
		{
			switch (maze[i][j])
			{
			case 0:
				AddCube(glm::vec3(j * 4, -1, i * 4 + 3), m_meshRenderer);
				break;
			case 1:
				AddCube(glm::vec3(j * 4, -4, i * 4 + 3), m_meshRenderer);
				break;
			case 2:
				AddCube(glm::vec3(j * 4, -4, i * 4 + 3), m_meshRenderer2);
				position[0] = i;
				position[1] = j;
				break;
			case 3:
				AddCube(glm::vec3(j * 4, -1, i * 4 + 3), m_meshRenderer3);
				break;
			default:
				break;
			}
		}
	}
	for (unsigned int i = 0; i < mazeObjects.size(); ++i)
	{
		AddToScene(mazeObjects[i]);
	}
	dir = UP;
}

void TestGame::Update(float delta)
{
	if (Input::getKeyDown(KEY::KEY_W))
	{
		switch (dir)
		{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			break;
		}
	}
	else if (Input::getKeyDown(KEY::KEY_S))
	{
		switch (dir)
		{
		case 0:
			if (maze[(position[0] + 1) % 10][position[1]] != 0 || maze[(position[0] + 1) % 10][position[1]] != 3)
			break;
		case 1:
			if (maze[(position[0])][(position[1] + 1) % 10] != 0 || maze[position[0]][(position[1] + 1) % 10] != 3)
			break;
		case 2:
			if (maze[(position[0] + 9) % 10][position[1]] != 0 || maze[(position[0] + 9) % 10][position[1]] != 3)
			break;
		case 3:
			if (maze[(position[0])][(position[1] + 9) % 10] != 0 || maze[position[0]][(position[1] + 9) % 10] != 3)
			break;
		default:
			break;
		}
	}
	else if (Input::getKeyDown(KEY::KEY_A))
	{
		++dir %= 4;
	}
	else if (Input::getKeyDown(KEY::KEY_D))
	{
		dir += 3;
		dir %= 4;
	}
}

TestGame::~TestGame()
{
	if (m_texture) delete m_texture;
	if (m_mesh) delete m_mesh;
	if (m_meshRenderer) delete m_meshRenderer;
}

void TestGame::AddCube(glm::vec3 position, MeshRenderer* meshRenderer)
{
	GameObject cube;

	cube.AddComponent(meshRenderer);
	cube.GetTransform().setPosition(position);
	cube.GetTransform().setScale(glm::vec3(4.f, 3.f, 4.f));
	mazeObjects.push_back(cube);
}