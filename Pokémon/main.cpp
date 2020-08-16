#include <SDL.h>
#include <iostream>
#include "combat.cpp"
#include "encounter.cpp"


int createWindow(SDL_Window* window, SDL_Renderer* renderer) {
    window = SDL_CreateWindow("Pokemon", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    if (window == 0) {
        std::cout << "Error while creating the window : " << SDL_GetError() << std::endl;
        SDL_Quit();

        return -1;
    }
    return 0;
}

int initializationOfSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Error during the initialization of  SDL : " << SDL_GetError() << std::endl;
        SDL_Quit();

        return -1;
    }
    return 0;
}

int closeWindow(SDL_Window* window) {
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

int main(int argc, char** argv)
{
    SDL_Window* window(0);
    SDL_Renderer* renderer(0);
    SDL_Event events;
    bool isEnding(false);

    initializationOfSDL();
    createWindow(window, renderer);

    while (!isEnding) {
        SDL_WaitEvent(&events);

        if (events.window.event == SDL_WINDOWEVENT_CLOSE) {
            isEnding = true;
        }
    }

    closeWindow(window);

    return 0;
}