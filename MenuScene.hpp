#pragma once
#include "Scene.hpp"

class MenuScene : public Scene
{
public:
	MenuScene();
	~MenuScene();
	void Load() override;
	void Update() override;
};
