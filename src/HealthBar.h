//
// Created by cub3d on 11/08/18.
//

#ifndef UNKNOWN_GAME_HEALTHBAR_H
#define UNKNOWN_GAME_HEALTHBAR_H

#include "Entity/Component.h"

using namespace ::Unknown;

class HealthBar : public ::Unknown::Component
{
public:
    double health;

    HealthBar();

    virtual void render(const Entity &ent, double Xoffset, double Yoffset) const override;

    void update(Entity& ent) override;
};


#endif //UNKNOWN_GAME_HEALTHBAR_H
