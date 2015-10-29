
#include <engine\CoreEngine.h>

int main()
{
	Game game;
	CoreEngine engine(1280, 720, 60, &game);
	engine.createWindow("Assignment 2 is go!");
	engine.start();
}