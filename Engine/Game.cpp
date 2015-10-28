#include "Game.h"
#include "Vertex.h"
#include "Util.h"
#include "ResourceLoader.h"
#include "Time.h"
#include <math.h>
#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>
#include "Window.h"
#include "BasicShader.h"
#include <memory>
float temp = 0.0f;
float tempAmount = 0.0f;

Game::Game()
{						//		position						uv						normal						color
	Vertex data[] = {	Vertex(	glm::vec3(1.0f, -1.0f, -1.0f),	glm::vec2(0.0f,1.0f),	glm::vec3(0.0f,0.0f,0.0f),	glm::vec4(1.0f,1.0f,1.0f,1.0f)),
						Vertex(	glm::vec3(1.0f, -1.0f, 1.0f),	glm::vec2(1.0f,1.0f),	glm::vec3(0.0f,0.0f,0.0f),	glm::vec4(1.0f,1.0f,1.0f,1.0f)),
						Vertex(	glm::vec3(-1.0f, -1.0f, 1.0f),	glm::vec2(0.0f,1.0f),	glm::vec3(0.0f,0.0f,0.0f),	glm::vec4(1.0f,1.0f,1.0f,1.0f)),
						Vertex(	glm::vec3(-1.0f, -1.0f, -1.0f),	glm::vec2(1.0f,1.0f),	glm::vec3(0.0f,0.0f,0.0f),	glm::vec4(1.0f,1.0f,1.0f,1.0f)),
						Vertex(	glm::vec3(1.0f, 1.0f, -1.0f),	glm::vec2(0.0f,0.0f),	glm::vec3(0.0f,0.0f,0.0f),	glm::vec4(1.0f,1.0f,1.0f,1.0f)),
						Vertex(	glm::vec3(1.0f, 1.0f, 1.0f),	glm::vec2(1.0f,0.0f),	glm::vec3(0.0f,0.0f,0.0f),	glm::vec4(1.0f,1.0f,1.0f,1.0f)),
						Vertex(	glm::vec3(-1.0f, 1.0f, 1.0f),	glm::vec2(0.0f,0.0f),	glm::vec3(0.0f,0.0f,0.0f),	glm::vec4(1.0f,1.0f,1.0f,1.0f)),
						Vertex(	glm::vec3(-1.0f, 1.0f, -1.0f),	glm::vec2(1.0f,0.0f),	glm::vec3(0.0f,0.0f,0.0f),	glm::vec4(1.0f,1.0f,1.0f,1.0f)) };

	int indices[] = {	0, 1, 2,
						0, 2, 3,
						4, 7, 6,
						4, 6, 5,
						0, 4, 5,
						0, 5, 1,
						1, 5, 6, 
						1, 6, 2,
						2, 6, 7,
						2, 7, 3, 
						4, 0, 3,
						4, 3, 7,
						};

	m_mesh.addVertices(data, ARRAY_SIZE(data), indices, ARRAY_SIZE(indices));

	//ResourceLoader::loadMesh("cube.obj", m_mesh);
	m_shader = new BasicShader;
	m_texture = Texture("small.png");
	m_material = Material(&m_texture, glm::vec3(1.0f, 1.0f, 1.0f));

	m_transform.setProjection(45.0f, (float)Window::getWidth(), (float)Window::getHeight(), 0.1f, 100.0f);
	m_transform.setCamera(m_camera);
}
Game::~Game()
{

}

void Game::input()
{

}

void Game::update()
{
	m_camera.input();
	temp += (float)Time::getDelta();
	m_transform.setScale(glm::vec3(1.0f, 1.0f, 1.0f));
	m_transform.setTranslation(glm::vec3(0.0f, 0.0f, -1.0f));
	m_transform.setRotation(glm::angleAxis(temp, glm::vec3(0, 1, 0)));
}

void Game::render()
{
	m_shader->bind();
	m_shader->updateUniforms(m_transform.getTransformation(), m_transform.getProjectedTransformation(), m_material);
	m_texture.bind();
	m_mesh.draw();
}
