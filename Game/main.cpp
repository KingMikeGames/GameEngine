
#include <engine\CoreEngine.h>
#include "TestGame.h"
int main()
{
	TestGame game;

	CoreEngine engine(1280, 720, 60, &game);
	engine.createWindow("Assignment 2 has all the stuff for assignment 3 sorry!");
	engine.start();
}