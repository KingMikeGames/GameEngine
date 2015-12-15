#include <engine\3DEngine.h>
#include <vector>

class TestGame : public Game
{
public:
	TestGame() {}

	virtual void Init();
	virtual void Update(float delta);
	virtual ~TestGame();

	void AddCube(glm::vec3 position, MeshRenderer* meshRenderer);
protected:
private:
	TestGame(const TestGame& other) {}
	void operator=(const TestGame& other) {}

	int maze[10][10];
	int position[2];
	enum direction 
	{	UP = 0,
		LEFT = 1,
		DOWN = 2,
		RIGHT = 3
	};
	int dir;
	std::vector<GameObject> mazeObjects;

	Mesh* m_mesh;
	Material m_material;
	Material m_material1;
	Material m_material2;
	Material m_material3;
	Texture* m_texture;
	Texture* m_texture1;
	Texture* m_texture2;
	Texture* m_texture3;
	MeshRenderer* m_meshRenderer;
	MeshRenderer* m_meshRenderer1;
	MeshRenderer* m_meshRenderer2;
	MeshRenderer* m_meshRenderer3;
};