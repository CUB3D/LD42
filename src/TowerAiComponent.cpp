//
// Created by scott on 11/08/18.
//

#include "TowerAiComponent.h"
#include "Unknown.h"
#include "HealthBar.h"
#include "SharedVariable.h"
#include "Scene/Scene.h"
#include <Entity/Entity.h>

void TowerAiComponent::update(::Unknown::Entity &ent)
{
    auto ants = ::Unknown::getUnknown().globalSceneManager.getScene<::Unknown::Scene>()->getObjects<::Unknown::Entity>("Ant");

    double minDist(99999);
    std::shared_ptr<::Unknown::Entity> TargetObj;

    for(auto& obj : ants) {
        if(!obj->enabled)
            continue;
        // Get the component etc
        double dist = sqrt(pow(obj->position.x - (ent.position.x + 16),2) + pow(obj->position.x - (ent.position.y + 24),2));

        if (dist < minDist && dist < range) {
            minDist = dist;
            TargetObj = obj;
        }
    }
    if (TargetObj)
    {
        auto targetBar = TargetObj->getComponent<HealthBar>();
        targetBar->health -= rate;
    }
}

TowerAiComponent::TowerAiComponent(double rate, double range) : rate(rate), range(range){

}

