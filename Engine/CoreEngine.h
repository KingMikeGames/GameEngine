#pragma once

#include "Game.h"
#include <string>
#include "RenderingEngine.h"
#include "AbstractRenderer.h"
/*
Initializes the engine 
creates the window
runs the game loop
keeps track of important objects like rendering engine
*/

class CoreEngine
{
public:
	/*
	@param width window width
	@param height window height
	@param frameRate desired framerate of the game
	@param the game that you're making
	*/
	CoreEngine(int width, int height, double frameRate, Game* game);
	virtual ~CoreEngine();

	/*
	Creates window
	@param title the title of the window
	*/
	void createWindow(const std::string& title = "Change your title");

	/*
	Sets is running to true
	*/
	void start();

	/*
	sets is running to false if not already false
	*/
	void stop();

private:
	//private so you can't use them
	CoreEngine(const CoreEngine& other) {}
	void operator=(const CoreEngine& other) {}

	/*
	runs the game loop
	*/
	void Run();

	/*
	true if running
	false if game attempts to close
	*/
	bool m_isRunning;

	// width of window
	int m_width;

	// height of window
	int m_height;

	// time frame should take in seconds
	double m_frameTime;

	// the running game
	Game* m_game;

	// the abstract render used for opengl
	AbstractRenderer* m_renderingEngine;
};

