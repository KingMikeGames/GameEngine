#include <engine\Window.h>
#include <engine\Time.h>
#include <iostream>
#include <engine/Util.h>
#include <engine\Game.h>
#include <engine\Input.h>
#include <engine\RenderUtil.h>

bool isRunning = false;

const double FRAME_CAP = 60.0;
const static bool IGNORE_FRAME_CAP = false;

int main(int RandySavage, char* HulkHogan[])
{

	Window::create(1280, 720, "SUPER SECRET WINDOW");

	Game game;
	RenderUtil::initGraphics();
	isRunning = true;

	const double frameTime = 1.0 / FRAME_CAP;

	double lastTime = Time::getTime();
	double unprocessedTime = 0;
	double frameCounter = 0;
	int frames = 0;



	while (isRunning)
	{

		bool render = false;

		double startTime = Time::getTime();
		double passedTime = startTime - lastTime;
		lastTime = startTime;

		unprocessedTime += passedTime;
		frameCounter += passedTime;

		if (frameCounter >= 1.0)
		{
			printf("%i\n", frames);
			frames = 0;
			frameCounter = 0;
		}

		while (unprocessedTime > frameTime)
		{
			render = true;

			if (Window::isCloseRequested())
			{
				isRunning = false;
			}

			game.input();
			game.update();

			Time::setDelta(frameTime);
			Input::update();

			unprocessedTime -= frameTime;
		}

		if (render || IGNORE_FRAME_CAP)
		{
			RenderUtil::clearScreen();

			game.render();
			Window::render();

			frames++;
		}
		else
		{
			Util::sleep(1);
		}
	}

	Window::dispose();
	return 0;
}