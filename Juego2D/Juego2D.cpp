#include <SDL.h>
#include <stdio.h>
#include <exception>
#include "Game.h"
#include<chrono>
int main(int argc, char* args[]) {
    Game game = Game();
    try {
        game.Init();
        //Gestionar eventos
        auto lastTime = std::chrono::system_clock::now();
        while (game.isRunning()) {
            auto current = std::chrono::system_clock::now();
            std::chrono::duration<double> elapsedSeconds = current - lastTime;
            game.HandleEvents();
            //printf("Elapsed time: %f\n", elapsedSeconds.count());
            game.Update(elapsedSeconds.count());
            game.Render();
            lastTime = current;
        }
    }
    catch (std::exception& exception) {
		printf("Error: %s", exception.what());
        SDL_Quit();
        return -1;
	}

    

        
    
    game.Release();

    return 0;
}