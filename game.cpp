//
//  game.cpp
//  2D_Game
//
//  Created by Connor Welch on 2/8/18.
//  Copyright © 2018 Connor Welch. All rights reserved.
//

#include "game.hpp"
#include "SDL2/SDL.h"
#include <iostream>

Game::~Game() {
    clean();
}


void Game::run() {
    window = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0);
    
    bg_tex = loadTexture("bg.bmp", renderer);
    
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
    SDL_RenderCopy(renderer, bg_tex, NULL, NULL);
    //rendering
    SDL_RenderPresent(renderer);
}
void Game::update() {
   SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    //update
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(bg_tex);
    SDL_Quit();
}

bool Game::isRunning() {
    return running;
}

SDL_Texture* loadTexture(std::string path, SDL_Renderer* render) {
    SDL_Texture *tex;
    SDL_Surface *surf = SDL_LoadBMP(path.c_str());
    //std::cout << SDL_GetError() << std::endl;
    tex = SDL_CreateTextureFromSurface(render, surf);
    SDL_FreeSurface(surf);
    return tex;
    
}


