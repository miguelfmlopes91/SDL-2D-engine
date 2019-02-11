//
//  Game.hpp
//  SDL wizard
//
//  Created by Miguel Lopes on 11/02/2019.
//  Copyright © 2019 Miniclip. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "SDL2/SDL.h"

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
    
private:
    bool isRunning = false;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
};
#endif /* Game_hpp */
