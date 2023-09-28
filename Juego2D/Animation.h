#ifndef ANIMATION_H
#define ANIMATION_H
#include<string>
#include<SDL.h>
class Texture;
class Animation
{
	public:
	Animation();
	void Init();
	void Render(const SDL_Rect* destRect) const;
	void Release();
	void Update(double elapsedSeconds);
	void SetProps(std::string textureID, SDL_Renderer* renderer, int frames, float duration, int spriteRow, int animationSpeed, SDL_RendererFlip flip=SDL_FLIP_NONE);
	private:	
		std::string _textureID;
		int _animationSpeed;
		int _spriteRow, _spriteFrame;
		SDL_RendererFlip _flip;
		Texture *_texture;
		int _frames;	
		double _currentTime;
		SDL_Rect _sourceRect;
		int _frameHeight;
		int _frameWidth;

};
#endif
