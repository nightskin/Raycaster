#include "Game.hpp"
#include "GameScene.hpp"
#include "MenuScene.hpp"
#include "Input.hpp"

Game::Game()
{

}

SDL_AppResult Game::Init()
{
    if (!SDL_Init(SDL_INIT_VIDEO)) 
    {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    if (!Graphics::Get().Init())
    {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }


    //SceneManager::Get().sceneList.push_back(new MenuScene());
    SceneManager::Get().sceneList.push_back(new GameScene());

    SceneManager::Get().currentScene = SceneManager::Get().sceneList[0];
    SceneManager::Get().currentScene->Load();

    return SDL_APP_CONTINUE;
}

void Game::HandleEvents()
{
    Input::Get().keyboard = SDL_GetKeyboardState(NULL);
    Input::Get().mouse = SDL_GetMouseState(&Input::Get().mouseX, &Input::Get().mouseY);
}

void Game::Update()
{
    
    SceneManager::Get().currentScene->Update();
}

void Game::Draw()
{
    SDL_SetRenderDrawColorFloat(Graphics::Get().Renderer(), Graphics::Get().bgColor.r, Graphics::Get().bgColor.g, Graphics::Get().bgColor.b, 1);
    SDL_RenderClear(Graphics::Get().Renderer());
    SceneManager::Get().currentScene->Draw();
    SDL_RenderPresent(Graphics::Get().Renderer());
}

void Game::Quit()
{
    for ( int i = 0; i < SceneManager::Get().sceneList.size(); i++)
    {
        delete SceneManager::Get().sceneList[i];
    }
}

bool Game::GameClosed()
{
    return closed;
}


