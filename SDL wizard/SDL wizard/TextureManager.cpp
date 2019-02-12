//
//  TextureManager.cpp
//  SDL wizard
//
//  Created by Miguel Lopes on 12/02/2019.
//  Copyright © 2019 Miniclip. All rights reserved.
//

#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* texture)
{
    SDL_Surface* tempSurface = IMG_Load(texture);
    if (tempSurface == NULL) {
        
        printf("Image Load Error: Path(%s) - Error(%s)\n", texture, IMG_GetError());
    }
    
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    if (tex == NULL) {
        
        printf("Create Texture Error: %s\n", SDL_GetError());
        
    }
    SDL_FreeSurface(tempSurface);
    
    return tex;
}
//TODO: Move this to a renderer
void TextureManager::Draw(SDL_Texture * tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip)
{
    SDL_RenderCopyEx(Game::renderer, tex, &src, &dest, NULL, NULL, flip);
}
