//
//  ColliderComponent.h
//  SDL wizard
//
//  Created by Miguel Lopes on 15/02/2019.
//  Copyright © 2019 Miniclip. All rights reserved.
//

#pragma once
#include <string>
#include <SDL2/SDL.h>
#include "Components.h"
#include "../TextureManager.hpp"

class ColliderComponent : public Component{
public:
    SDL_Rect collider;
    std::string tag;
    
//    SDL_Texture* tex;
//    SDL_Rect srcR, destR;
    
    TransformComponent* transform;
    
    ColliderComponent(std::string t){
        tag = t;
    }
    
    ColliderComponent(std::string t, int xpos, int ypos, int size){
        tag = t;
        collider.x = xpos;
        collider.y = ypos;
        collider.h = collider.w = size;
    }
    
    void init() override{
        if (!entity->hasComponent<TransformComponent>()){
            entity->addComponent<TransformComponent>();
        }
        
        transform = &entity->getComponent<TransformComponent>();
        
//        tex = TextureManager::LoadTexture("assets/coltex.png");
//        srcR = { 0, 0, 32, 32 };
//        destR = { collider.x, collider.y, collider.w, collider.h };
        
    }
    
    void update() override{
        collider.x = static_cast<int>(transform->position.x);
        collider.y = static_cast<int>(transform->position.y);
        collider.w = transform->width * transform->scale;
        collider.h = transform->height * transform->scale;
        
//        destR.x = collider.x - Game::camera.x;
//        destR.y = collider.y - Game::camera.y;
    }
    
//    void draw() override{
//        TextureManager::Draw(tex, srcR, destR, SDL_FLIP_NONE);
//    }
    
private:
    
};

