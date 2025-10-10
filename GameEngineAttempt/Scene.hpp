#pragma once
#include <vector>
#include <string>
#include "GameObject.hpp"

class Scene
{
public:
	Scene();
	~Scene();
	std::vector<GameObject*> objectList;
	std::string name = "";
	virtual void Load();
	virtual void Update();
	virtual void Draw();
	virtual void Unload();
};