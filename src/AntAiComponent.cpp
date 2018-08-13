//
// Created by scott on 11/08/18.
//

#include <Entity/Entity.h>
#include "AntAiComponent.h"
#include "Unknown.h"
#include "SharedVariable.h"
#include "Scene/Scene.h"
#include "AntAiComponent.h"
#include "math.h"
#include "TowerHealthBar.h"
#include "PathFollowerComponent.h"

void AntAiComponent::update(::Unknown::Entity &ent) {
    auto pathingcomp = ent.getComponent<PathFollowerComponent>();

    double MAX_DIST = 80;

    auto towers = ::Unknown::getUnknown().globalSceneManager.getScene<::Unknown::Scene>()->getObjects<::Unknown::Entity>("TowerBody");

    double minDist(99999);
    std::shared_ptr<::Unknown::Entity> TargetObj = nullptr;

    for(auto& obj : towers) {
        auto thb = obj->getComponent<TowerHealthBar>();
        if(!obj->enabled || !thb || thb->health <= 0)
            continue;
        // Get the component etc
        double dist = sqrt(pow(obj->position.x - (ent.position.x + 24),2) + pow(obj->position.y - (ent.position.y + 8),2));

        if (dist < minDist && dist < MAX_DIST) {
            minDist = dist;
            TargetObj = obj;
        }
    }

    if (TargetObj) {
        auto targetBar = TargetObj->getComponent<TowerHealthBar>();
        if(targetBar) {
            targetBar->health -= rate;
            // If attacking then they should stop moving
            pathingcomp->stopped = true;
        }
    } else {
        pathingcomp->stopped = false;
    }
}
AntAiComponent::AntAiComponent(struct level leve, double rate) : curlvl(leve), rate(rate) {

}
