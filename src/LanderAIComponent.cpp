//
// Created by cub3d on 13/08/18.
//

#include "LanderAIComponent.h"
#include "Unknown.h"
#include "Loader.h"
#include "PathFollowerComponent.h"
#include "HealthBar.h"
#include "AntAiComponent.h"
#include "GameScene.h"

LanderAIComponent::LanderAIComponent(int decend, int currentIndex) : decend(decend), toSpawn(3), t(1.0f), curIndex(currentIndex) {}

void LanderAIComponent::update(Unknown::Entity &ent) {
    Component::update(ent);

    if(decend > 0) {
        ent.position.y++;
        decend--;
        return;
    }

    auto scene = ::Unknown::getUnknown().globalSceneManager.getScene<GameScene>();

    // Spawn extra ants
    if(t.isTickComplete() && toSpawn > 0) {
        auto en = Loader::loadEntityAt("Entities/Ant.json", *scene, ent.position.x, ent.position.y);
        auto p = std::make_shared<PathFollowerComponent>(scene->currentLevel);
        p->currentNodeIndex = curIndex;
        en->components.push_back(p);
        en->components.push_back(std::make_shared<HealthBar>());
        en->components.push_back(std::make_shared<AntAiComponent>(scene->currentLevel, 0.05));
        scene->addObject(en);

        //TODO: explode and dissapear
        //

        this->toSpawn--;
    }
}
