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

	virtual void Render(const Transform& transform, Shader* shader)
	{
		shader->bind();
		shader->updateUniforms(transform.getTransformation(), transform.getProjectedTransformation(), *m_material);
		m_mesh->draw();
	}
protected:
private:
	Mesh* m_mesh;
	Material* m_material;
};