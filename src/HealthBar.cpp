//
// Created by cub3d on 11/08/18.
//

#include "HealthBar.h"
#include "UI2D.h"

void HealthBar::render(const Entity &ent, double Xoffset, double Yoffset) const {
    Component::render(ent, Xoffset, Yoffset);
    int height = 5;
    int offset = 32;
    UK_DRAW_RECT(ent.position.x, ent.position.y + offset, 25, height, Colour::RED);
    UK_DRAW_RECT(ent.position.x, ent.position.y + offset, health, height, Colour::GREEN);
}

void HealthBar::update(Entity &ent) {
    if(this->health <= 0)
        ent.queueDisable();
}

HealthBar::HealthBar() : health(25) {}
