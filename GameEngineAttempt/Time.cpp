#include "Time.hpp"


Time Time::instance;

Time::Time()
{

}

Time& Time::Get()
{
	return instance;
}

float Time::DeltaTime()
{
	return delta;
}

Uint64 Time::LastFrame()
{
	return last;
}

Uint64 Time::CurrentFrame()
{
	return now;
}

void Time::Start()
{
	delta = 0;
	last = 0;
	now = SDL_GetPerformanceCounter();

}

void Time::Tick()
{
	last = now;
	now = SDL_GetPerformanceCounter();
	delta = (double)((now - last) * 1000 / (double)SDL_GetPerformanceFrequency());
}
