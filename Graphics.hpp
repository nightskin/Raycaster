#pragma once
#include <SDL3/SDL.h>
#include "Util.hpp"

class Graphics
{
public:
	static Graphics& Get();
	bool Init();
	void ShutDown();
	SDL_Renderer* Renderer();
	void DrawLine(Vector2 start, Vector2 end, Color color = Color(1, 1, 1));
	void DrawLine(Line line, Color color = Color(1, 1, 1));
	void DrawRect(Vector2 pos, Vector2 size, Color color = Color(1, 1, 1), bool centered = true);
	Vector2 WindowCenter();
	Vector2 WindowSize();

	Color bgColor = Color();

	~Graphics();

private:
	const char* title = "";
	int width = 800;
	int height = 600;
	SDL_Renderer* renderer;
	SDL_Window* window;
	static Graphics instance;
	Graphics();
};
