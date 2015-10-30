
#include <engine\CoreEngine.h>
#include "TestGame.h"
int main()
{
	TestGame game;

	CoreEngine engine(1280, 720, 60, &game);
	engine.createWindow("Assignment 2 is go!");
	engine.start();
}