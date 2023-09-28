#ifndef ANIMATION_H
#define ANIMATION_H
#include<string>
#include<SDL.h>
class Texture;
class Animation
{
	public:
	Animation(std::string path, SDL_Renderer* renderer, int frames, float duration, int frameHeight, int frameWidth);
	void Init();
	void Render(const SDL_Rect* destRect) const;
	void Release();
	void Update(double elapsedSeconds);
	private:	
	Texture *_texture;
	int _frames;
	float _duration;
	double _currentTime;
	SDL_Rect _sourceRect;
	int _frameHeight;
	int _frameWidth;

};
#endif
