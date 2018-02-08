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
    Game *game = new Game(800, 600);
    game->run();
    while(game->isRunning()) {
        game->eventHandle();
        game->update();
        game->render();
    }
    delete game;
}
