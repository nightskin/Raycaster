#pragma once
#include "Player.hpp"
#include "Level.hpp"
#include "Scene.hpp"

class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();
	void Load() override;
	void Update() override;
	void Draw() override;
	void Unload() override;
private:
	bool paused;
	Level lvl;
	Player player;
};
