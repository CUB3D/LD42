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

void AntAiComponent::update(Unknown::Entity &ent) {
    auto scene = Unknown::getUnknown()->globalSceneManager.getScene<Unknown::Scene>();
    float minDist(-1);
    std::shared_ptr<Unknown::Entity> TargetObj;
    for(auto& obj : scene->getObjects<Unknown::Entity>("TowerBody")) {
        // Get the component etc
        float dist = sqrt(pow(obj->position.x - ent.position.x,2) + pow(obj->position.x - ent.position.y,2));
        if (dist < minDist and minDist != -1) {
            minDist = dist;
            TargetObj = obj;
        }
    }
    if (TargetObj != NULL) {
        TowerHealthBar targetBar = *TargetObj->getComponent<TowerHealthBar>();
        targetBar.health -= rate;
    }
}
AntAiComponent::AntAiComponent(struct level leve,int rate) : curlvl(leve), rate(rate){

}
