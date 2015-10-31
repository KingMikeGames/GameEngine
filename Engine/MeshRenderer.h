#include "gameComponent.h"
#include "mesh.h"
#include "basicShader.h"
#include <vector>
/*
The MeshRenderer is a component that renders meshes
*/
class MeshRenderer : public GameComponent
{
public:
	/*
	sets a mesh and material
	@param mesh mesh to render
	@param material material of the mesh being rendered
	*/
	MeshRenderer(Mesh& mesh, std::vector<Material> materials)
	{
		m_mesh = &mesh;
		m_materials = materials;
		partsToRender = m_mesh->numParts();
	}

	/*
	Renders the mesh
	@param transform the transform of the object to be rendered
	@param shader the shader program to be used for rendering
	@renderingEngine the abstract randerer
	*/
	virtual void Render(const Transform& transform, Shader* shader, RenderingEngine* renderingEngine)
	{
		shader->bind();
		for (int i = 0; i < partsToRender; i++)
		{
			shader->UpdateUniforms(transform, m_materials[i], renderingEngine);
			m_mesh->Draw(i);
		}
		
	}
protected:
private:
	/*
	the currently targeted mesh to be rendered
	*/
	Mesh* m_mesh;
	int partsToRender = 0;
	/*
	the color and texture of the mesh
	*/
	std::vector<Material> m_materials;
};