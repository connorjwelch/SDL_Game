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
#include "SDL2_image/SDL_image.h"
#include "SDL2_image/SDL_image.h"



Game::~Game() {
    clean();
}


void Game::run() {
    window = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    bg_tex = IMG_LoadTexture(renderer, "bg.bmp");
    bg_rect.w = 800;
    bg_rect.h = 600;
    bg_rect.x = 0;
    bg_rect.y = 0;
    
    ship = IMG_LoadTexture(renderer, "ship.png");
    ship_rect.w = 40;
    ship_rect.h = 80;
    ship_rect.x = 400;
    ship_rect.y = 300;
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    
    running = true;
}
void Game::eventHandle() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type) {
        case SDL_QUIT:
            running = false;
            break;
            
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym) {
                case SDLK_LEFT:
                    vx = -1;
                    break;
                case SDLK_RIGHT:
                    vx = 1;
                    break;
                case SDLK_UP:
                    vy = -1;
                    break;
                case SDLK_DOWN:
                    vy = 1;
                    break;
            }
            break;
        case SDL_KEYUP:
            switch(event.key.keysym.sym) {
                case SDLK_LEFT:
                    vx = 0;
                    break;
                case SDLK_RIGHT:
                    vx = 0;
                    break;
                case SDLK_UP:
                    vy = 0;
                    break;
                case SDLK_DOWN:
                    vy = 0;
                    break;
            }
        default:
            break;
    }
}

void Game::render() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, bg_tex, NULL, &bg_rect);
    SDL_RenderCopy(renderer, ship, NULL, &ship_rect);
    //rendering
    SDL_RenderPresent(renderer);
}
void Game::update() {
   SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    ship_rect.x += vx;
    ship_rect.y += vy;
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



