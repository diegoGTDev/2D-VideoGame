#ifndef ROCK_H
#define ROCK_H
#include<SDL_render.h>

class Texture;
class Animation;
class Rock
{
public:
    Rock(SDL_Renderer* renderer);
    void Init();
    void Release();

    void Update(double elapsedSeconds);

    void Render();

private:
    SDL_Renderer* _renderer;

    Animation* _rockAnimation;  
    SDL_Rect _destRockRect;
    float _rockXPosition;

};


#endif