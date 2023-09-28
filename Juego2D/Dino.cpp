#include "Dino.h"
#include"Animation.h"
#include"GameObject.h"
Dino::Dino(Properties* props, SDL_Renderer* renderer): Character(props), _renderer(renderer)
{
    _destDinoRect.x = 200;
    _destDinoRect.y = 610;
    _destDinoRect.w = 76;
    _destDinoRect.h = 76;

}

void Dino::Init()
{
    _dinoAnimation = new Animation("assets/dino.png", _renderer, 6, 2, 24,24);
    _dinoAnimation->Init();

    _DinoXPosition = 0; 
}


void Dino::Update(double elapsedSeconds)
{
    //_DinoXPosition += 180 * elapsedSeconds;
    //_destDinoRect.x = _DinoXPosition;

    _dinoAnimation->Update(elapsedSeconds);
}

void Dino::Render()
{
   _dinoAnimation->Render(&_destDinoRect);
}

void Dino::Release() {
   // _dinoAnimation->Release();
    //delete _dinoAnimation;
}
