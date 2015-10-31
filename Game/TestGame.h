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

	GameObject m_cube;

	Mesh* m_mesh;
	std::vector<Material> mats;
	Texture* m_texture;
	MeshRenderer* m_meshRenderer;
};