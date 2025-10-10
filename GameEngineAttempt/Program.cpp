#define SDL_MAIN_USE_CALLBACKS 1 
#include "Game.hpp"
#include "Time.hpp"
#include <SDL3/SDL_main.h>

Game game;

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
    game = Game();
    Time::Get().Start();
    return game.Init();  
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
    if (event->type == SDL_EVENT_QUIT)
    {
        return SDL_APP_SUCCESS;
    }
    game.HandleEvents();
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appstate)
{
    Time::Get().Tick();
    game.Update();
    game.Draw();

    if (game.GameClosed())
    {
        return SDL_APP_SUCCESS;
    }
    else
    {
        return SDL_APP_CONTINUE;
    }
}

void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
    game.Quit();
}
