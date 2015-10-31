#include <engine\3DEngine.h>

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

	GameObject m_cube;
	GameObject m_cube1;

	Mesh* m_mesh;
	Material m_material;
	Texture* m_texture;
	MeshRenderer* m_meshRenderer;
};