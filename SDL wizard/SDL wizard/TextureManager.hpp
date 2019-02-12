//
//  TextureManager.hpp
//  SDL wizard
//
//  Created by Miguel Lopes on 12/02/2019.
//  Copyright © 2019 Miniclip. All rights reserved.
//

#pragma once

#include "Game.hpp"

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char* fileName);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip);
};
