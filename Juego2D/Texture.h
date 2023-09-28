#ifndef TEXTURE_H
#define TEXTURE_H
#include<SDL_render.h>
#include<string>
class  Texture
{
	public:
	Texture(std::string path, SDL_Renderer* renderer);

	void Init();
	void SetSourceRect(const SDL_Rect* rect);
	void Render(const SDL_Rect *destRect) const;

	void Release();

private: 
	std::string _path;
	SDL_Renderer *_renderer;
	SDL_Texture *_texture;
	SDL_Rect _sourceRect;

};
#endif

