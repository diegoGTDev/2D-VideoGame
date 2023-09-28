#include "Animation.h"
#include "TextureManager.h"
#include<utility>


void Animation::Update(double elapsedSeconds) {
	_currentTime += elapsedSeconds;

	if (_currentTime > _animationSpeed) {
		_currentTime -= _animationSpeed;
	}

	_spriteFrame = int(_currentTime / _animationSpeed * _frames);

	_sourceRect.x = _spriteFrame * _frameWidth;
	//_texture->SetSourceRect(&_sourceRect);
}

void Animation::SetProps(std::string textureID, SDL_Renderer* renderer, int frames, float duration, int spriteRow, int animationSpeed, SDL_RendererFlip flip)
{
	_textureID = std::move(textureID);
	_spriteRow = spriteRow;
	_animationSpeed = animationSpeed;
	_frames = frames;
	_flip = flip;

}

void Animation::Render(const SDL_Rect* destRect) const {
	TextureManager::GetInstance()->Draw(_textureID, destRect->x, destRect->y, _frameWidth, _frameHeight);
}

void Animation::Release() {
	TextureManager::GetInstance()->Release();
	delete _texture;
}