//
// Created by scott on 11/08/18.
//

#include <Entity/Entity.h>
#include "AntAiComponent.h"
#include "Unknown.h"
#include "SharedVariable.h"
#include "Scene/Scene.h"
#include "AntAiComponent.h"

void AntAiComponent::update(Unknown::Entity &ent) {
    auto scene = Unknown::getUnknown()->globalSceneManager.getScene<Unknown::Scene>();
    for(auto& obj : scene->getObjects<Unknown::Entity>("asdf")) {
        // Get the component etc
        auto comp = obj->getComponent<AntAiComponent>();
    }
}

AntAiComponent::AntAiComponent(struct level leve) : curlvl(leve) {

}
