#include "Graphics.hpp"

Graphics Graphics::instance;

Graphics& Graphics::Get()
{
    return instance;
}

Graphics::Graphics()
{
    
}

Graphics::~Graphics()
{

}

bool Graphics::Init()
{
    if (!SDL_CreateWindowAndRenderer(title, width, height, 0, &window, &renderer))
    {
        return false;
    }
    return true;
}

void Graphics::ShutDown()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = NULL;
    window = NULL;
}

SDL_Renderer* Graphics::Renderer()
{
    return renderer;
}

void Graphics::DrawLine(Vector2 start, Vector2 end, Color color)
{
    SDL_SetRenderDrawColorFloat(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderLine(renderer, start.x, start.y, end.x, end.y);
}

void Graphics::DrawLine(Line line, Color color)
{
    SDL_SetRenderDrawColorFloat(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderLine(renderer, line.start.x, line.start.y, line.end.x, line.end.y);
}

void Graphics::DrawRect(Vector2 pos, Vector2 size, Color color, bool centered)
{
    SDL_SetRenderDrawColorFloat(renderer, color.r, color.g, color.b, color.a);
    SDL_FRect rect = SDL_FRect();
    rect.w = size.x;
    rect.h = size.y;
    if (centered)
    {
        rect.x = pos.x - (rect.w / 2);
        rect.y = pos.y - (rect.h / 2);
    }
    else
    {
        rect.x = pos.x;
        rect.y = pos.y;
    }

    SDL_RenderFillRect(renderer, &rect);
}

Vector2 Graphics::WindowCenter()
{
    return Vector2(width / 2, height / 2);
}

Vector2 Graphics::WindowSize()
{
    return Vector2(width, height);
}

