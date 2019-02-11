//
//  main.cpp
//  SDL wizard
//
//  Created by Miguel Lopes on 16/01/2019.
//  Copyright © 2019 Miniclip. All rights reserved.
//

#include "Game.hpp"
Game *game = nullptr;

int main(int argc, char *argv[])
{
    
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    
    Uint32 frameStart;
    int frameTime;
    
    game = new Game();
    game->init("GameWindow", 800, 640, false);
    
    while (game->running())
    {
        
        frameStart = SDL_GetTicks();
        
        game->handleEvents();
        game->update();
        game->render();
        
        frameTime = SDL_GetTicks() - frameStart;
        
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    
    game->clean();
    return 0;
}
