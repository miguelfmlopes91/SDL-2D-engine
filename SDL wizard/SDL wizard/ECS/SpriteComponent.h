//
//  SpriteComponent.h
//  SDL wizard
//
//  Created by Miguel Lopes on 14/02/2019.
//  Copyright © 2019 Miniclip. All rights reserved.
//

#pragma once
#include "Components.h"
#include "TransformComponent.h"
#include "SDL2/SDL.h"
#include "../TextureManager.hpp"

class SpriteComponent : public Component
{
public:
    SpriteComponent() = default;
    SpriteComponent(const char* path) {
        setTexture(path);
    };
    ~SpriteComponent(){
        SDL_DestroyTexture(texture);
    }
    
    void init() override {
        
        //initializse position as a entity a component of type Transform Component
        transform = &entity->getComponent<TransformComponent>();
        
        srcRect.x = srcRect.y = 0;
        srcRect.w = transform->width;
        srcRect.h = transform->height;
    }
    void update() override {
        destRect.x = static_cast<int>(transform->position.x);
        destRect.y = static_cast<int>(transform->position.y);
        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;
    }
    void draw() override {
        TextureManager::Draw(texture, srcRect, destRect);
    }
    
    void setTexture(const char* path) {
        texture = TextureManager::LoadTexture(path);
    }
    
private:
    //reference to the posiiton because spritecomponent is responsible for drawing itself on the screen
    TransformComponent* transform;
    
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;
    
};
