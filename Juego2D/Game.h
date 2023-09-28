
#ifndef SDL_PROJECT_JUEGO_H
#define SDL_PROJECT_JUEGO_H

#include<SDL.h>
class Texture;
class Dino;
class Rock;

class Game {
public:
	void Init();
	void Update(double elapsedSeconds);
	void Release();
	void HandleEvents();
	void Render();
	bool isRunning();
	
	static SDL_Event Event;

private:
	void _InitSDL();
	void _CreateWindowAndRenderer();
	SDL_Window *_window;
	SDL_Renderer *_renderer;
	bool _isRunning;
	Dino *_dino;
	Rock* _rock;
	Texture *_background;
	SDL_Rect _destBackgroundRect;

};

#endif // !SDL_PROJECT_JUEGO_H
