#pragma once
#include "SceneManager.hpp"
#include "Graphics.hpp"
#include "Time.hpp"

class Game
{
public:
	Game();
	SDL_AppResult Init();
	void HandleEvents();
	void Update();
	void Draw();
	void Quit();
	bool GameClosed();
private:
	bool closed = false;
};