#include "Game.h"
#include "Vertex.h"
#include "Util.h"
#include "ResourceLoader.h"
#include "Time.h"
#include <math.h>
#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>
#include "Window.h"

float temp = 0.0f;
float tempAmount = 0.0f;

Game::Game()
{
	//Vertex data[] = { Vertex(glm::vec3(-0.75, -1, -0.75)), //BBL
	//	Vertex(glm::vec3(0, 1, 0)),							//TOP
	//	Vertex(glm::vec3(-0.75, -1, .75)),					//fbl
	//	Vertex(glm::vec3(.75, -1, -.75)),					//bbr
	//	Vertex(glm::vec3(.75, -1, .75)) };					//fbr

	//int indices[] = { 0, 1, 3,
	//	3, 1, 4,
	//	4, 1, 2,
	//	2, 1, 0 };

	//mesh.addVertices(data, ARRAY_SIZE(data), indices, ARRAY_SIZE(indices));

	ResourceLoader::loadMesh("cube.obj", mesh);
	shader.addVertexShaderFromFile(ResourceLoader::loadShader("basicVertex.vs"));
	shader.addFragmentShaderFromFile(ResourceLoader::loadShader("basicFragment.fs"));
	shader.compileShader();

	transform.setProjection(45.0, Window::getWidth(), Window::getHeight(), 0.1f, 100.0f);
	shader.addUniform("transform");
}
Game::~Game()
{

}

void Game::input()
{

}

void Game::update()
{
	temp += Time::getDelta();
	transform.setScale(glm::vec3(1.0f, 1.0f, 1.0f));
	transform.setTranslation(glm::vec3(0.0f, 0.0f, -5.0f));
	transform.setRotation(glm::angleAxis(temp, glm::vec3(0, 1, 0)));
}

void Game::render()
{
	shader.bind();
	shader.setUniform("transform", transform.getProjectedTransformation());
	mesh.draw();
}
