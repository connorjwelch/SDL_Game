//
//  game.hpp
//  2D_Game
//
//  Created by Connor Welch on 2/8/18.
//  Copyright © 2018 Connor Welch. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include "SDL2/SDL.h"

class Game {
public:
    Game(int w, int h) : width(w), height(h) {}
    ~Game();
    void run();
    void eventHandle();
    void render();
    void update();
    void clean();
    bool isRunning();
    
private:
    int width, height;
    bool running;
    SDL_Window *window;
    SDL_Renderer *renderer;
    
};


#endif /* game_hpp */
