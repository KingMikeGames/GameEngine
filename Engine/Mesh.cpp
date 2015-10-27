#include "Mesh.h"
#include <GL/glew.h>

Mesh::Mesh()
{
	glGenBuffers(1, &m_vbo);
	glGenBuffers(1, &m_ibo);
	m_size = 0;
}

Mesh::~Mesh()
{
	glDeleteBuffers(1, &m_vbo);
	glDeleteBuffers(1, &m_ibo);
}

void Mesh::addVertices(Vertex* vertices, int vertsize, int* indices, int indexSize)
{
	m_size = indexSize; //che che check it baby

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, vertsize * sizeof(Vertex), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexSize * sizeof(int), indices, GL_STATIC_DRAW);
}

void Mesh::draw()
{
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	//tell openGL how to interpret data
	glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(Vertex), 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glDrawElements(GL_TRIANGLES, m_size, GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);
}