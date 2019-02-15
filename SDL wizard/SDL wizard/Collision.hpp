//
//  Collision.hpp
//  SDL wizard
//
//  Created by Miguel Lopes on 15/02/2019.
//  Copyright © 2019 Miniclip. All rights reserved.
//

#pragma once
#include <SDL2/SDL.h>

class ColliderComponent;

class Collision
{
public:
    static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
    static bool AABB(const ColliderComponent& colA, const ColliderComponent& colB);
};
