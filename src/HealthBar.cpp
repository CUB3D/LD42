//
// Created by cub3d on 11/08/18.
//

#include "HealthBar.h"
#include "UI2D.h"
#include "Scene/Scene.h"
#include "Loader.h"
#include "SharedVariable.h"

void HealthBar::render(const Entity &ent, double Xoffset, double Yoffset) const {
    Component::render(ent, Xoffset, Yoffset);
    int height = 5;
    int offset = 32;
    UK_DRAW_RECT(ent.position.x, ent.position.y + offset, 25, height, Colour::RED);
    UK_DRAW_RECT(ent.position.x, ent.position.y + offset, health, height, Colour::GREEN);

    ::Unknown::Graphics::drawCircle(ent.position.x + 24, ent.position.y - 16, 80, Colour::RED);

    auto ants = Unknown::getUnknown()->globalSceneManager.getScene<Unknown::Scene>()->getObjects<Unknown::Entity>("TowerBody");

    for(auto& obj : ants) {
        if(!obj->enabled)
            continue;
        // Get the component etc
        double dist = sqrt(pow(obj->position.x - (ent.position.x + 24),2) + pow(obj->position.y - (ent.position.y + 8),2));

        if (dist <= 80) {
            ::Unknown::Graphics::drawLine(ent.position.x + 24, ent.position.y + 8, obj->position.x, obj->position.y, ::Unknown::Colour::GREEN);
        } else {
            ::Unknown::Graphics::drawLine(ent.position.x + 24, ent.position.y+ 8, obj->position.x, obj->position.y, ::Unknown::Colour::RED);
        }

        font->drawString(intToString(dist), ent.position.x, ent.position.y);
    }
}

void HealthBar::update(Entity &ent) {
    if(this->health <= 0) {
        ent.queueDisable();

        auto scene = ::Unknown::getUnknown()->globalSceneManager.getScene<Scene>();
        scene->addObject(::Unknown::Loader::loadEntityAt("Entities/AntDead.json", *scene, ent.position.x, ent.position.y));
        //TODO: better shared var api
        *Unknown::getUnknown()->variablelookup["funds"] = Unknown::getUnknown()->variablelookup["funds"]->operator double() + 20;
    }
}

HealthBar::HealthBar() : health(25) {
    font = std::make_shared<Unknown::Graphics::TTFont>("res/Fonts/Arimo-Regular.ttf", 12, UK_COLOUR_RGB(0, 255, 0));
}
