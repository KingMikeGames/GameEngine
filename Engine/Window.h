#pragma once
#include <SDL\SDL.h>
#include <GL/glew.h>
#include <string>

enum WindowFlags
{
	INVISIBLE = 0x1,
	FULLSCREEN = 0x2,
	BORDERLESS = 0x4
};

class Window
{
public:
	Window();
	~Window();

	int create(std::string windowTitle, int screenWidth, int screenHeight, unsigned int currentFlags );

	int getScreenWidth() { return _screenWidth; }
	int getScreenHeight() { return _screenHeight; }

	void swapBuffers();
private:
	SDL_Window* _sdlWindow;
	int _screenHeight, _screenWidth;
};

