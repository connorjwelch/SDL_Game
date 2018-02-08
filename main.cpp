//
//  main.cpp
//  2D_Game
//
//  Created by Connor Welch on 2/8/18.
//  Copyright © 2018 Connor Welch. All rights reserved.
//


#include <iostream>
#include "SDL2/SDL.h"


int main() {
    SDL_Init(SDL_INIT_VIDEO);
    
    SDL_Window *window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    
    if(!window) {
        std::cerr << "Could not create window\n";
        return 1;
    }
    SDL_Renderer *render = SDL_CreateRenderer(window, -1, 0);
    
    SDL_SetRenderDrawColor(render, 255, 20, 50, 1);
    
    SDL_RenderClear(render);
    
    SDL_RenderPresent(render);
    
    SDL_Delay(5000);
    
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
