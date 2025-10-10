#include "GameScene.hpp"

GameScene::GameScene()
{
	name = "Game";
	paused = true;
	player = Player();
}

GameScene::~GameScene()
{

}

void GameScene::Load()
{
	lvl = Level();
	lvl.ProcGen();

	player.Load();
	player.position = lvl.GetPositionInMap();
	player.rotation = Vector2(0, 0);
}

void GameScene::Update()
{
	player.Update();
}

void GameScene::Draw()
{
	if (paused)
	{
		player.Draw();
		lvl.DrawTopDown();
	}
	else
	{
		lvl.DrawPerspective(player.position, player.rotation);
	}
}

void GameScene::Unload()
{
	
}
