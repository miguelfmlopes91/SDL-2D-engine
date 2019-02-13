//
//  ECS.cpp
//  SDL wizard
//
//  Created by Miguel Lopes on 13/02/2019.
//  Copyright © 2019 Miniclip. All rights reserved.
//

#include "ECS.h"

void Entity::addGroup(Group mGroup)
{
    groupBitset[mGroup] = true;
    manager.AddToGroup(this, mGroup);
}
