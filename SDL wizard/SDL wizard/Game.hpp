//
//  Game.hpp
//  SDL wizard
//
//  Created by Miguel Lopes on 11/02/2019.
//  Copyright © 2019 Miniclip. All rights reserved.
//

#pragma once
#include "SDL2/SDL.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

class Game{
public:
    Game();
    ~Game();
    
    void init(const char* title, int width, int heigth, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    
    bool running();
    static SDL_Renderer *renderer;

private:
    bool isRunning = false;
    SDL_Window *window;
    SDL_Event event;
};
