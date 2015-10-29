#pragma once

#include "Game.h"
#include <string>

class CoreEngine
{
public:
	CoreEngine(int width, int height, double frameRate, Game* game);
	virtual ~CoreEngine();

	void createWindow(const std::string& title);

	void start();
	void stop();

private:

	CoreEngine(const CoreEngine& other) {}
	void operator=(const CoreEngine& other) {}

	void Run();

	bool m_isRunning;
	int m_width;
	int m_height;
	double m_frameTime;
	Game* m_game;
};

