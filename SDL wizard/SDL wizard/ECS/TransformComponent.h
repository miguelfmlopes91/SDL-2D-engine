//
//  TransformComponent.h
//  SDL wizard
//
//  Created by Miguel Lopes on 13/02/2019.
//  Copyright © 2019 Miniclip. All rights reserved.
//

#pragma once

#include "Components.h"
#include "../Vector2D.hpp"

class TransformComponent : public Component{
    
public:
    TransformComponent() {
        position.Zero();
    }
    TransformComponent(int sc) {
        position.Zero();
        scale = sc;
    }
    TransformComponent(float x, float y) {
        position.x = x;
        position.y = y;
    }
    
    TransformComponent(float x, float y, int h, int w, int sc) {
        position.x = x;
        position.y = y;
        height = h;
        width = w;
        scale = sc;
    }
    
    void init() override{
        velocity.Zero();
    }
    
    void update() override{
        position.x += static_cast<int>(velocity.x * speed);
        position.y += static_cast<int>(velocity.y * speed);
    }
    
    //public for now, this should class should be a Struct?
    Vector2D position;
    Vector2D velocity;
    int height = 32;
    int width = 32;
    int scale = 1;
private:
    int speed = 3;

};
