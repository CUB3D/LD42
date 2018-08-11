//
// Created by cub3d on 11/08/18.
//

#include "TowerHealthBar.h"
#include "UI2D.h"

void TowerHealthBar::update(Entity &ent) {
    if(this->health <= 0) {
        ent.queueDisable();

        //TODO: spawn ded towr
       // auto scene = ::Unknown::getUnknown()->globalSceneManager.getScene<Scene>();
       // scene->addObject(::Unknown::Loader::loadEntityAt("Entities/AntDead.json", *scene, ent.position.x, ent.position.y));
    }
}


void TowerHealthBar::render(const Entity &ent, double Xoffset, double Yoffset) const {
    Component::render(ent, Xoffset, Yoffset);
    int height = 5;
    int offset = -15;
    UK_DRAW_RECT(ent.position.x + 12, ent.position.y + offset, 25, height, Colour::RED);
    UK_DRAW_RECT(ent.position.x + 12, ent.position.y + offset, health, height, Colour::GREEN);
}