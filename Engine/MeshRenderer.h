#include "gameComponent.h"
#include "mesh.h"
#include "basicShader.h"

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
	MeshRenderer(Mesh& mesh, Material& material)
	{
		m_mesh = &mesh;
		m_material = &material;
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
		shader->UpdateUniforms(transform, *m_material, renderingEngine);
		m_mesh->Draw();
	}
protected:
private:
	/*
	the currently targeted mesh to be rendered
	*/
	Mesh* m_mesh;

	/*
	the color and texture of the mesh
	*/
	Material* m_material;
};