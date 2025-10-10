#pragma once
#include "Scene.hpp"

class SceneManager
{
public:
	static SceneManager& Get();
	void LoadScene(std::string name);
	void LoadScene(int index);
	Scene* GetScene(std::string name);
	Scene* GetScene(int index);
	Scene* currentScene;
	std::vector<Scene*> sceneList;
private:
	static SceneManager instance;
	SceneManager();
};
