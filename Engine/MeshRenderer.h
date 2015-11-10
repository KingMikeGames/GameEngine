#include "gameComponent.h"
#include "mesh.h"
#include "basicShader.h"

/*
* The MeshRenderer class is a component that renders meshes
*/
class MeshRenderer : public GameComponent
{
public:
	/*
	* Sets the mesh and material
	* @param mesh Mesh to render
	* @param material Material of the mesh being rendered
	*/
	MeshRenderer(Mesh& mesh, Material& material)
	{
		m_mesh = &mesh;
		m_material = &material;
	}

	/*
	* Renders the mesh
	* @param transform Transform of the GameObject
	* @param shader Shader program to be used for rendering
	* @param renderingEngine The renderer
	*/
	virtual void Render(const Transform& transform, Shader* shader, AbstractRenderer* renderingEngine)
	{
		shader->bind();
		shader->UpdateUniforms(transform, *m_material, renderingEngine);
		m_mesh->Draw();
	}
protected:
private:
	/* The currently targeted mesh to be drawn */
	Mesh* m_mesh;
	/* Color and texture of the mesh */
	Material* m_material;
};