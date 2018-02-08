//
//  game.cpp
//  2D_Game
//
//  Created by Connor Welch on 2/8/18.
//  Copyright © 2018 Connor Welch. All rights reserved.
//

#include "game.hpp"
#include "SDL2/SDL.h"



Game::~Game() {
    clean();
}


void Game::run() {
    window = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    running = true;
}
void Game::eventHandle() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type) {
        case SDL_QUIT:
            running = false;
        default:
            break;
    }
}

void Game::render() {
    SDL_RenderClear(renderer);
    //rendering
    SDL_RenderPresent(renderer);
}
void Game::update() {
    //update
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Game::isRunning() {
    return running;
}
