//
// Created by cub3d on 11/08/18.
//

#ifndef UNKNOWN_GAME_TOWERHEALTHBAR_H
#define UNKNOWN_GAME_TOWERHEALTHBAR_H

#include "HealthBar.h"
#include "Font.h"

class TowerHealthBar : public HealthBar
{
public:
    std::shared_ptr<Unknown::Entity> turret;
    std::function<void(Entity& ent)> func;

    TowerHealthBar(std::shared_ptr<Entity> turret, std::function<void(Entity& ent)> func);

    virtual void update(Entity& ent) override;
    virtual void render(const Entity &ent, double Xoffset, double Yoffset) const override;
};


#endif //UNKNOWN_GAME_TOWERHEALTHBAR_H
