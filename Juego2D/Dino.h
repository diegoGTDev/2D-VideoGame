#ifndef DINO_H
#define DINO_H
#include<SDL_render.h>
#include"Character.h"

class Dino : public Character
{
    public:
        Dino(Properties* props, SDL_Renderer* renderer);
        
        void Init();
        void virtual Release();

        void  virtual Update(double dt);

        void virtual Render();

    private:
        SDL_Renderer* _renderer;
        Animation* _dinoAnimation;
        SDL_Rect _destDinoRect;
        float _DinoXPosition;

};


#endif