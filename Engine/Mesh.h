#pragma once
#include "Vertex.h"

class Mesh
{
public:
	Mesh();
	~Mesh();
	void addVertices(Vertex* vertices, int vertsize, int* indices, int indexSize);
	void draw();
private:
	unsigned int m_vbo;
	unsigned int m_ibo;
	int m_size;
};