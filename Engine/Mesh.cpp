#include "Mesh.h"
#include <GL/glew.h>
#include <iostream>
#include "OBJ_Loader.h"

Mesh::Mesh()
{

}

Mesh::Mesh(const std::string& fileName)
{
	IndexedModel model = OBJModel(fileName).ToIndexedModel();

	std::vector<Vertex> vertices;

	for (unsigned int i = 0; i < model.positions.size(); i++)
		vertices.push_back(Vertex(model.positions[i], model.texCoords[i], model.normals[i]));

	addVertices(&vertices[0], vertices.size(), (int*)&model.indices[0], model.indices.size(), false);
}

Mesh::Mesh(Vertex* vertices, int vertSize, int* indices, int indexSize, bool calcNormals)
{
	addVertices(vertices, vertSize, indices, indexSize, calcNormals);
}

Mesh::~Mesh()
{
	glDeleteBuffers(1, &m_vbo);
	glDeleteBuffers(1, &m_ibo);
}

void Mesh::addVertices(Vertex* vertices, int vertSize, int* indices, int indexSize, bool calcNormals)
{
	if (!m_vbo) glGenBuffers(1, &m_vbo);
	if (!m_ibo) glGenBuffers(1, &m_ibo);
	m_size = indexSize; //che che check it baby

	if (calcNormals)
		this->CalcNormals(vertices, vertSize, indices, indexSize);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, vertSize * sizeof(Vertex), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexSize * sizeof(int), indices, GL_STATIC_DRAW);

	
}

void Mesh::draw()
{
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	//tell openGL how to interpret data
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex,pos));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));
	glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glDrawElements(GL_TRIANGLES, m_size, GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(3);
}

void Mesh::CalcNormals(Vertex* vertices, int vertSize, int* indices, int indexSize)
{
	for (int i = 0; i < indexSize; i += 3)
	{
		int i0 = indices[i];
		int i1 = indices[i + 1];
		int i2 = indices[i + 2];

		glm::vec3 v1 = vertices[i1].pos - vertices[i0].pos;
		glm::vec3 v2 = vertices[i2].pos - vertices[i0].pos;

		glm::vec3 normal = glm::normalize(glm::cross(v1,v2));

		vertices[i0].normal += normal;
		vertices[i1].normal += normal;
		vertices[i2].normal += normal;
	}

	for (int i = 0; i < vertSize; i++)
		vertices[i].normal = glm::normalize(vertices[i].normal);
}