#pragma once
#include <SDL3/SDL.h>

class Input
{
public:
	static Input& Get();
	const bool* keyboard;
	SDL_MouseButtonFlags mouse;
	float mouseX;
	float mouseY;
private:
	static Input instance;
	Input();
};
