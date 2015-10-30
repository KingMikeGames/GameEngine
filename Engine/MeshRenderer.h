#include "gameComponent.h"
#include "mesh.h"
#include "basicShader.h"

class MeshRenderer : public GameComponent
{
public:
	MeshRenderer(Mesh& mesh, Material& material)
	{
		m_mesh = &mesh;
		m_material = &material;
	}

	virtual void Render(const Transform& transform, Shader* shader, RenderingEngine* renderingEngine)
	{
		shader->bind();
		shader->UpdateUniforms(transform, *m_material, renderingEngine);
		m_mesh->draw();
	}
protected:
private:
	Mesh* m_mesh;
	Material* m_material;
};