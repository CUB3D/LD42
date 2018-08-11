//
// Created by cub3d on 11/08/18.
//

#ifndef UNKNOWN_GAME_TURRETAICOMPONENT_H
#define UNKNOWN_GAME_TURRETAICOMPONENT_H

#include "Entity/Component.h"
#include "LevelLoader.h"
#include "Scene/Scene.h"
class TurretAiComponent : public Unknown::Component {
public:
    TurretAiComponent(level currentlvl, double rate);
    double rate;
    struct level curlvl;

    virtual void update(Unknown::Entity& ent) override;

};


#endif //UNKNOWN_GAME_TURRETAICOMPONENT_H