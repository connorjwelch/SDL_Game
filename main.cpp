//
//  main.cpp
//  2D_Game
//
//  Created by Connor Welch on 2/8/18.
//  Copyright © 2018 Connor Welch. All rights reserved.
//


#include <iostream>
#include "game.hpp"


int main() {
    const int FPS = 60;
    const int frameDelay  = 1000/FPS;
    
    Uint32 frameStart;
    int frameTime;
    
    Game *game = new Game(800, 600);
    SDL_Init(SDL_INIT_VIDEO);
    game->run();
    while(game->isRunning()) {
        frameStart = SDL_GetTicks();
        game->eventHandle();
        game->update();
        game->render();
        
        frameTime = SDL_GetTicks() - frameStart;
        //need to stall before next loop
        if(frameTime < frameDelay) {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    delete game;
}
