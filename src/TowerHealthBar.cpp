//
// Created by cub3d on 11/08/18.
//

#include "TowerHealthBar.h"
#include "UI2D.h"
#include "Scene/Scene.h"
#include "Loader.h"
#include "AnimationHelper.h"
#include "Entity/AnimationRenderComponent.h"
#include "Sounds.h"

void TowerHealthBar::update(Entity &ent) {
    if(this->health <= 0) {
        ent.queueDisable();
        turret->queueDisable();

        if(func)
            func(ent);

        Sounds::getSounds().towerDestroy.playSingle();
    }
}

void TowerHealthBar::render(const Entity &ent, double Xoffset, double Yoffset) const {
    Component::render(ent, Xoffset, Yoffset);

    int height = 5;
    int offset = -15;
    UK_DRAW_RECT(ent.position.x + 12, ent.position.y + offset, 25, height, Colour::RED);
    UK_DRAW_RECT(ent.position.x + 12, ent.position.y + offset, health, height, Colour::GREEN);

    //::Unknown::Graphics::drawCircle(ent.position.x + 24, ent.position.y + 90, 120, Colour::BLUE);
}

TowerHealthBar::TowerHealthBar(std::shared_ptr<Entity> turret, std::function<void(Entity& ent)> func)
    : turret(turret), func(func) {
}
