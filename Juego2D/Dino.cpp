#include "Dino.h"
#include"Animation.h"
#include"GameObject.h"
Dino::Dino(Properties* props, SDL_Renderer* renderer): Character(props), _renderer(renderer)
{
    _dinoAnimation = new Animation();
    _dinoAnimation->SetProps("dino", _renderer, 6, 2, 24, 24);
    _destDinoRect = { 100,100,76,76 };
}

void Dino::Init()
{
    _dinoAnimation->Render(&_destDinoRect);


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
    _dinoAnimation->Release();
	delete _dinoAnimation;
}
