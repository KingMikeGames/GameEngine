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

	GameObject m_neptune;
	GameObject m_neptune1;

	Mesh* m_mesh;
	std::vector<Material> mats;
	std::vector<Material> mats1;
	Texture* m_texture;
	MeshRenderer* m_meshRenderer;
	MeshRenderer* m_meshRenderer1;
};