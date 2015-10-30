#include "CoreEngine.h"
#include "Time.h"
#include "Window.h"
#include "Input.h"
#include "Util.h"

#include <stdio.h>

bool IGNORE_FRAME_CAP = false;

CoreEngine::CoreEngine(int width, int height, double frameRate, Game * game) :
	m_isRunning(false),
	m_width(width),
	m_height(height),
	m_frameTime(1.0 / frameRate),
	m_game(game),
	m_renderingEngine(nullptr) {}

CoreEngine::~CoreEngine()
{
	Window::dispose();
	delete m_renderingEngine;
}

void CoreEngine::createWindow(const std::string & title)
{
	Window::create(m_width, m_height, title);
	m_renderingEngine = new RenderingEngine();
}

void CoreEngine::start()
{
	if (m_isRunning)
		return;

	Run();
}

void CoreEngine::stop()
{
	if (!m_isRunning)
		return;

	m_isRunning = false;
}

void CoreEngine::Run()
{
	m_isRunning = true;

	m_game->init();

	double lastTime = Time::getTime();
	double unprocessedTime = 0;
	double frameCounter = 0;
	int frames = 0;

	while (m_isRunning)
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

		while (unprocessedTime > m_frameTime)
		{
			render = true;

			if (Window::isCloseRequested())
			{
				stop();
			}
				

			Time::setDelta(m_frameTime);
			Input::update();

			m_game->input();
			m_renderingEngine->Input();
			m_game->update();

			unprocessedTime -= m_frameTime;
		}

		if (render || IGNORE_FRAME_CAP)
		{
			m_renderingEngine->Render(&m_game->getRoot());
			Window::render();
			frames++;
		}
		else
		{
			Util::sleep(1);
		}
	}


}
