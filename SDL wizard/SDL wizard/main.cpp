//
//  main.cpp
//  SDL wizard
//
//  Created by Miguel Lopes on 16/01/2019.
//  Copyright © 2019 Miniclip. All rights reserved.
//

#include <iostream>
#include "SDL2/SDL.h"
int main(int argc, const char * argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    
    SDL_Window *window = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    
    SDL_RenderClear(renderer);
    
    SDL_RenderPresent(renderer);
    
    SDL_Delay(3000);
    
    

}
