#pragma once

#include <sdl/SDL.h>

class Time
{
public:

	// return system time
	static double getTime();

	// get time that passes between frames
	static double getDelta();

	static void setDelta(double value);
protected:
private:
	static double m_delta;
};