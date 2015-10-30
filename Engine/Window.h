#pragma once

#include <string>

class Window
{
public:
	// Initialize SDL, Create a window, Initialize glew
	static void create(int width, int height, const std::string& title);

	// Swap Buffers
	static void render();

	// Destroy window and quit SDL
	static void dispose();

	// Check if close has been requested
	static bool isCloseRequested();

	// Get window width
	static int getWidth();

	// Get window height
	static int getHeight();

	//return heigh / width
	static float GetAspect();

	// Get window title
	static const std::string& getTitle();

	//set fullscreen true or false
	static void setFullScreen(bool value);

protected:
private:
	static int m_width;
	static int m_height;
	static std::string m_title;
};
