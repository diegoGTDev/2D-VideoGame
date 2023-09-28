#include "Rock.h"
#include"Animation.h"
Rock::Rock(SDL_Renderer* renderer) : _renderer(renderer)
{

}

void Rock::Init()
{
    //_rockAnimation;

    _destRockRect.x = 500;
    _destRockRect.y = 625;
    _destRockRect.w = 35;
    _destRockRect.h = 35;

    _rockXPosition = 0;
}


void Rock::Update(double elapsedSeconds)
{
    if (_destRockRect.x == 0) {
		_rockXPosition = 500;
	}
    _rockXPosition -= 180 * elapsedSeconds;
    _destRockRect.x = _rockXPosition;

    //_rockAnimation->Update(elapsedSeconds);
}

void Rock::Render()
{
    //_rockAnimation->Render(&_destRockRect);
}

void Rock::Release() {
    ///_rockAnimation->Release();
    //delete _rockAnimation;
}
