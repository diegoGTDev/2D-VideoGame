#include <SDL.h>
#include <stdio.h>
#include <exception>
#include "Game.h"
#include"Engine.h"
#include<chrono>
int main(int argc, char* args[]) {
    
    try {
        Engine::GetInstance()->Init();
        //Gestionar eventos
        auto lastTime = std::chrono::system_clock::now();
        while (Engine::GetInstance()->isRunning()) {
            auto current = std::chrono::system_clock::now();
            std::chrono::duration<double> elapsedSeconds = current - lastTime;
            Engine::GetInstance()->HandleEvents();
            //printf("Elapsed time: %f\n", elapsedSeconds.count());
            Engine::GetInstance()->Update(elapsedSeconds.count());
            Engine::GetInstance()->Render();
            lastTime = current;
        }
    }
    catch (std::exception& exception) {
		printf("Error: %s", exception.what());
        SDL_Quit();
        return -1;
	}

    

        
    
    Engine::GetInstance()->Release();

    return 0;
}