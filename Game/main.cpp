
#include <engine\Engine.h>
#include "TestGame.h"
int main()
{
	TestGame game;

	Engine engine(1280, 720, 60, &game);
	engine.createWindow("Assignment 2 is go!");
	engine.start();
}