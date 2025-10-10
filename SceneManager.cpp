#include "SceneManager.hpp"

SceneManager SceneManager::instance;

SceneManager::SceneManager()
{

}

SceneManager& SceneManager::Get()
{
    return instance;
}

void SceneManager::LoadScene(std::string name)
{
    for (int i = 0; i < sceneList.size(); i++)
    {
        if (sceneList[i]->name == name)
        {
            currentScene->Unload();
            currentScene = sceneList[i];
            currentScene->Load();
            return;
        }
    }
}

void SceneManager::LoadScene(int index)
{
    currentScene->Unload();
    currentScene = sceneList[index];
    currentScene->Load();
}

Scene* SceneManager::GetScene(std::string name)
{
    for (int i = 0; i < sceneList.size(); i++)
    {
        if (sceneList[i]->name == name) 
        {
            return sceneList[i];
        }
    }
}

Scene* SceneManager::GetScene(int index)
{
    return sceneList[index];
}

