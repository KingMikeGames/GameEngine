#pragma once

#include "vertex.h"
#include <string>
#include <map>
#include <vector>
#include <memory>

/*
holds mesh data so it can be passed to abstract renderers
*/
class MeshData
{
public:
	/*
	initializes the buffers
	@param indexSize the length of the index array
	*/
	MeshData(int indexSize);
	virtual ~MeshData();

	/*
	returns the vertex buffer object
	*/
	inline unsigned int GetVBO() { return m_vbo; }

	/*
	returns the index buffer object
	*/
	inline unsigned int GetIBO() { return m_ibo; }

	/*
	returns the length of the index buffer
	*/
	inline int GetSize() { return m_size; }
protected:
private:

	/*
	vertex buffer object
	*/
	unsigned int m_vbo;

	/*
	index buffer object
	*/
	unsigned int m_ibo;

	/*
	length of index buffer
	*/
	int m_size;
};

/*
A drawable mesh in the engine which is rendered by the mesh renderer
*/
class Mesh
{
public:
	/*
	creates mesh from file on drive
	@param fileName filePath
	*/
	Mesh(const std::string& fileName);

	/*
	creates a mesh from data
	@param vertices the array of vertices
	@param vertsize  number of vertices
	@param indice array of indices
	@param indexSize number of indices
	@param calcNormals calculates normals if true
	*/
	Mesh(Vertex* vertices, int vertSize, int* indices, int indexSize, bool calcNormals);
	virtual ~Mesh();

	/*
	called by the render to draw the mesh
	*/
	void Draw(int index) const;
	int numParts() { return m_meshData.size(); }
protected:
private:
	/*
	holds all meshes currently loaded into memory
	*/
	static std::map<std::string, std::vector<std::shared_ptr<MeshData>>> s_resourceMap;

	Mesh(Mesh& mesh) {}
	void operator=(Mesh& mesh) {}

	/*
	calculates polygonal normal
	@param vertices the array of vertices
	@param vertsize  number of vertices
	@param indice array of indices
	@param indexSize number of indices
	*/
	void CalcNormals(Vertex* vertices, int vertSize, int* indices, int indexSize);

	/*
	generates buffers if data was passed instead of loaded from file path
	@param vertices the array of vertices
	@param vertsize  number of vertices
	@param indice array of indices
	@param indexSize number of indices
	@param calcNormals calculates normals if true
	*/
	void InitMesh(Vertex* vertices, int vertSize, int* indices, int indexSize, bool calcNormals = true);

	/*
	filepath of mesh
	*/
	std::string m_fileName;

	/*
	vertex and index data
	*/

	std::vector<std::shared_ptr<MeshData>> m_meshData;
};