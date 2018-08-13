//
// Created by cub3d on 13/08/18.
//

#ifndef UNKNOWN_GAME_LANDERAICOMPONENT_H
#define UNKNOWN_GAME_LANDERAICOMPONENT_H

#include "Entity/Component.h"
#include "Timer.h"

class LanderAIComponent : public ::Unknown::Component
{
public:
    int decend;
    int toSpawn;
    ::Unknown::Timer t;
    int curIndex;

    LanderAIComponent(int decend, int currentIndex);

    virtual void update(::Unknown::Entity& ent);

};


#endif //UNKNOWN_GAME_LANDERAICOMPONENT_H
