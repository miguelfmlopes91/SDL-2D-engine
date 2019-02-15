//
//  SpriteComponent.h
//  SDL wizard
//
//  Created by Miguel Lopes on 14/02/2019.
//  Copyright © 2019 Miniclip. All rights reserved.
//

#pragma once
#include "Components.h"
#include "PositionComponent.h"
#include "SDL2/SDL.h"
#include "../TextureManager.hpp"

class SpriteComponent : public Component
{
public:
    SpriteComponent() = default;
    SpriteComponent(const char* path) {
        setTexture(path);
    };
    
    void init() override {
        
        //initializse position as a entity a component of type Position Component
        position = &entity->getComponent<PositionComponent>();
        
        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = 32;
        destRect.w = destRect.h = 64;
    }
    void update() override {
        destRect.x = position->x();
        destRect.y = position->y();
    }
    void draw() override {
        TextureManager::Draw(texture, srcRect, destRect);
    }
    
    void setTexture(const char* path) {
        texture = TextureManager::LoadTexture(path);
    }
    
private:
    //reference to the posiiton because spritecomponent is responsible for drawing itself on the screen
    PositionComponent* position;
    
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;
    
};
