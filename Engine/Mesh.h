#pragma once
#include "Vertex.h"
#include <string>

class Mesh
{
public:
	Mesh();
	Mesh(const std::string& fileName);
	Mesh(Vertex * vertices, int vertSize, int * indices, int indexSize, bool calcNormals = true);
	~Mesh();
	void addVertices(Vertex* vertices, int vertsize, int* indices, int indexSize, bool calcNormals = true);
	void draw();
	void CalcNormals(Vertex * vertices, int vertSize, int * indices, int indexSize);
private:
	unsigned int m_vbo = 0;
	unsigned int m_ibo = 0;
	int m_size = 0;
};