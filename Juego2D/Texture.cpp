#include "Texture.h"
#include<SDL_image.h>
#include<SDL.h>
#include <assert.h>
Texture::Texture(std::string path, SDL_Renderer* renderer) : _path(std::move(path)), _renderer(renderer),_sourceRect(), _texture(nullptr)
{
}

void Texture::Init()
{
    SDL_Surface* surfaceTemp = IMG_Load(_path.c_str());
    _texture = SDL_CreateTextureFromSurface(_renderer, surfaceTemp);
    SDL_QueryTexture(_texture, nullptr, nullptr, &_sourceRect.w, &_sourceRect.h);
    SDL_FreeSurface(surfaceTemp);
}
void Texture::SetSourceRect(const SDL_Rect *rect) {
    _sourceRect.x = rect->x;
    _sourceRect.y = rect->y;
    _sourceRect.w = rect->w;
    _sourceRect.h = rect->h;

}
void Texture::Render(const SDL_Rect *destRect) const
{
    assert(_texture != nullptr && "Texture is not initialized, try to call to Init first");
    SDL_RenderCopyEx(_renderer, _texture, &_sourceRect, destRect, NULL,nullptr, SDL_FLIP_NONE);
}

void Texture::Release() {
    SDL_DestroyTexture(_texture);
    _texture = nullptr;
}