//
//  GameObject.hpp
//  SDL wizard
//
//  Created by Miguel Lopes on 12/02/2019.
//  Copyright © 2019 Miniclip. All rights reserved.
//
#include "Game.hpp"
#pragma once

class GameObject{
public:
    GameObject(const char* texturesheet,int x, int y);
    ~GameObject();
    
    void update();
    void render();
private:
    int xpos=0;
    int ypos=0;
    
    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
};
