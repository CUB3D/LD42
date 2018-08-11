//
// Created by cub3d on 11/08/18.
//

#ifndef UNKNOWN_GAME_PATHFOLLOWERCOMPONENT_H
#define UNKNOWN_GAME_PATHFOLLOWERCOMPONENT_H

#include "Entity/Component.h"
#include "LevelLoader.h"

class PathFollowerComponent : public Unknown::Component {
public:
    PathFollowerComponent(level currentlvl);

    struct level curlvl;
    int currentNodeIndex = 0;
    double speed = 10;
    bool stopped;

    virtual void update(Unknown::Entity& ent) override;

};


#endif //UNKNOWN_GAME_PATHFOLLOWERCOMPONENT_H
