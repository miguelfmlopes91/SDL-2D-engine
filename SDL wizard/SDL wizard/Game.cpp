//
//  Game.cpp
//  SDL wizard
//
//  Created by Miguel Lopes on 11/02/2019.
//  Copyright © 2019 Miniclip. All rights reserved.
//

#include "Game.hpp"
#include <iostream>
#include "GameObject.hpp"
#include "Map.hpp"
#include "Collision.hpp"
#include "ECS/Components.h"


SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
bool Game::isRunning = false;

Map* map;

Manager manager;
auto& player(manager.addEntity());
auto& wall(manager.addEntity());


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
    //Initializing the SDL_image library and handling initialization errors
    int flag = IMG_INIT_PNG;
    if (!(IMG_Init(flag) & flag)) {
        
        printf("IMG Initialization Error: %s\n", IMG_GetError());
        isRunning = false;
    }
    //player = new GameObject("Assets/player.png",0,0);
    map = new  Map();
    
    player.addComponent<TransformComponent>(100,100);
    player.addComponent<TransformComponent>().scale = 1;
    player.addComponent<SpriteComponent>("Assets/player.png");
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");
    
    wall.addComponent<TransformComponent>(300.0f,300.0f,300,20,1);
    wall.addComponent<SpriteComponent>("Assets/dirt.png");
    wall.addComponent<ColliderComponent>("wall");
    
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
    manager.refresh();
    manager.update();
    
    if(Collision::AABB(player.getComponent<ColliderComponent>().collider,
                       wall.getComponent<ColliderComponent>().collider)){
        player.getComponent<TransformComponent>().velocity * -1;
        std::cout << "WALL HIT !"<< std::endl;
    }
}

void Game::render(){
    SDL_RenderClear(renderer);
    map->DrawMap();
    manager.draw();
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
