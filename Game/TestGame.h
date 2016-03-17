#include <engine\3DEngine.h>
#include <vector>

class TestGame : public Game
{
public:
	TestGame() {}

	virtual void Init();
	virtual void Update(float delta);
	virtual ~TestGame();

protected:
private:
	TestGame(const TestGame& other) {}
	void operator=(const TestGame& other) {}

	Mesh* m_mesh;
	Material m_material;
	Texture* m_texture;
	Skybox* m_skybox;
	MeshRenderer* m_meshRenderer;
	GameObject cube;
};