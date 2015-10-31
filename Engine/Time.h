#pragma once

#include <sdl/SDL.h>
/*
A wrapper for time keeping functions
*/
class Time
{
public:

	/*
	returns time since program started
	*/
	static double getTime();

	/*
	returns time since last frame
	*/
	static double getDelta();


	/*
	sets delta time to the time between frames
	*/
	static void setDelta(double value);
protected:
private:

	/*
	time between between
	*/
	static double m_delta;
};