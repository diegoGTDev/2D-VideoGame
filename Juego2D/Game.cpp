#include "Game.h"
#include "SDL_Exception.h"
#include<SDL_image.h>
#include"resource1.h"
#include<iostream>
#include"Texture.h"
#include"Dino.h"
#include"Rock.h"
#include"Transform.h"
#include"GameObject.h"


void Game::Init()
{
    _InitSDL();
    _CreateWindowAndRenderer();
    SDL_SetRenderDrawColor(_renderer, 252, 198, 3, 255);
    _destBackgroundRect.x = 0;
    _destBackgroundRect.y = 0;
    _destBackgroundRect.w = 1020;
    _destBackgroundRect.h = 720;

    _background = new Texture("assets/background.png", _renderer);
    _background->Init();
    Transform tf;
    tf.Log(); 
    _rock = new Rock(_renderer);
    _rock->Init();
    _dino = new Dino(new Properties("assets/dino.png",35, 35, 100,610), _renderer);
    _dino->Init();
    _isRunning = true;
}

void Game::Update(double elapsedSeconds)
{

    _dino->Update(elapsedSeconds);
    _rock->Update(elapsedSeconds);
}

void Game::Release()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
   _dino->Release();
    delete _dino;
    _background->Release();
    delete _background;
    _rock->Release();
    delete _rock;
    SDL_Quit();
}

void Game::HandleEvents()
{
    SDL_Event e;
    if (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            _isRunning = false;
        }
    }
}

void Game::Render()
{
    
    //Limpiamos el render
    SDL_RenderClear(_renderer);


    _background->Render(&_destBackgroundRect);
    _dino->Render();
    _rock->Render();
    SDL_RenderPresent(_renderer);
}

bool Game::isRunning()
{
    return _isRunning;
}

void Game::_InitSDL()
{
    auto isInitialized = SDL_Init(SDL_INIT_VIDEO) >= 0;

    if (!isInitialized) {
        throw SDL_Exception(SDL_GetError());
    }
}

void Game::_CreateWindowAndRenderer()
{
    SDL_CreateWindowAndRenderer(1020, 720, SDL_WINDOW_SHOWN, &_window, &_renderer);
    if (_window == NULL || _renderer == NULL) {
        throw SDL_Exception(SDL_GetError());

    }
}
