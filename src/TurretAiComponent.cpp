//
// Created by cub3d on 11/08/18.
//

#include <Entity/Entity.h>
#include "TurretAiComponent.h"
#include "Unknown.h"
#include "SharedVariable.h"
#include "Scene/Scene.h"
#include "AntAiComponent.h"
#include "math.h"
#include "TowerHealthBar.h"
#include "PathFollowerComponent.h"

void TurretAiComponent::update(Unknown::Entity &ent) {
    double MAX_DIST = 300;

    auto towers = Unknown::getUnknown()->globalSceneManager.getScene<Unknown::Scene>()->getObjects<Unknown::Entity>("Ant");

    double minDist(99999);
    std::shared_ptr<Unknown::Entity> TargetObj;

    for(auto& obj : towers) {
        if(!obj->enabled)
            continue;
        // Get the component etc
        double dist = sqrt(pow(obj->position.x - ent.position.x,2) + pow(obj->position.x - ent.position.y,2));

        if (dist < minDist && dist < MAX_DIST) {
            minDist = dist;
            TargetObj = obj;
        }
    }
    if (TargetObj) {
        auto targetBar = TargetObj->getComponent<HealthBar>();
        targetBar->health -= rate;
    }
}
TurretAiComponent::TurretAiComponent(struct level leve, double rate) : curlvl(leve), rate(rate) {

}
