/***********************************************************
* Project Name: Pokémon
* File Name: main.cpp
* Started on: 2020-08-15
************************************************************
* Author: Jimmy Béland-Bédard (NoxGamingQC)
* Last update author: Jimmy Béland-Bédard (NoxGamingQC)
* Last update: 2020-08-17
************************************************************
* Description:
************************************************************/

#include "main.h"

using namespace std;

int createWindow(SDL_Window* window, SDL_Renderer* renderer) {
    window = SDL_CreateWindow("Pokemon", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    if (window == 0) {
        cout << "Error while creating the window : " << SDL_GetError() << std::endl;
        SDL_Quit();

        return -1;
    }
    return 0;
}

int initializationOfSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Error during the initialization of  SDL : " << SDL_GetError() << std::endl;
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
    int language = 0;
    bool isEnding(false);

    initializationOfSDL();
    createWindow(window, renderer);
    checkSettingsFile(language);
    cout << "Current language: " << languageCode[getLanguage(languageCode, languageCount)] << endl;

    while (!isEnding) {
        SDL_WaitEvent(&events);

        if (events.window.event == SDL_WINDOWEVENT_CLOSE) {
            isEnding = true;
        }
    }

    closeWindow(window);

    return 0;
}