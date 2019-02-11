//
//  Game.cpp
//  SDL wizard
//
//  Created by Miguel Lopes on 11/02/2019.
//  Copyright © 2019 Miniclip. All rights reserved.
//

#include "Game.hpp"
#include <iostream>
#include <SDL2/SDL_ttf.h>

Game::Game(){
   
}

Game::~Game(){
    
}

void Game::init(const char* title, int width, int height, bool fullscreen){
    int flags = 0;
    
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }
        
        isRunning = true;
    }
    
    if (TTF_Init() == -1)
    {
        std::cout << "Error : SDL_TTF" << std::endl;
    }
}

void Game::handleEvents(){
    SDL_PollEvent(&event);
    
    switch (event.type)
    {
        case SDL_QUIT :
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update(){
    
}

void Game::render(){
    SDL_RenderClear(renderer);
    
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Game::running(){
    return isRunning;
}
