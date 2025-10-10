#pragma once
#include "SDL3/SDL.h"

class Time
{
public:
	static Time& Get();
	float DeltaTime();
	Uint64 LastFrame();
	Uint64 CurrentFrame();

	void Start();
	void Tick();
private:
	static Time instance;
	Time();

	float delta;
	Uint64 last;
	Uint64 now;

};
