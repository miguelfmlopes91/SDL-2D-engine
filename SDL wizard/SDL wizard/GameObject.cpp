//
//  GameObject.cpp
//  SDL wizard
//
//  Created by Miguel Lopes on 12/02/2019.
//  Copyright © 2019 Miniclip. All rights reserved.
//

#include "GameObject.hpp"
#include "TextureManager.hpp"
GameObject::GameObject(const char* texturesheet, int x, int y) : xpos(x),ypos(y){
    objTexture = TextureManager::LoadTexture(texturesheet);
}

GameObject::~GameObject(){
    
}

void GameObject::update(){
    xpos++;
    ypos++;
    
    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;
    
    destRect.h = srcRect.h * 2;
    destRect.w = srcRect.w * 2;
    destRect.x = xpos;
    destRect.y = ypos;
    
}

void GameObject::render(){
    TextureManager::Draw(objTexture, srcRect, destRect, SDL_FLIP_NONE);
}
