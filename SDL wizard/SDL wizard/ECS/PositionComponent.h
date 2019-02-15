//
//  PositionComponent.h
//  SDL wizard
//
//  Created by Miguel Lopes on 13/02/2019.
//  Copyright © 2019 Miniclip. All rights reserved.
//

#pragma once

#include "Components.h"

class PositionComponent : public Component{
    
public:
    PositionComponent() {
        xpos = 0;
        ypos = 0;
    }
    PositionComponent(int x, int y) {
        xpos = x;
        ypos = y;
    }
    
    //expose and set the y and x position
    int x() {
        return xpos;
    }
    
    int y() {
        return ypos;
    }
    
    void init() override{
    }
    
    void update() override{
        xpos++;
        ypos++;
    }
    
    void setPos(int x, int y) {
        xpos = x;
        ypos = y;
    }
    
private:
    int xpos;
    int ypos;
};
