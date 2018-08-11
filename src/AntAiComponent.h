//
// Created by scott on 11/08/18.
//

#ifndef UNKNOWN_GAME_ANTAICOMPONENT_H
#define UNKNOWN_GAME_ANTAICOMPONENT_H

#include "Entity/Component.h"
#include "LevelLoader.h"
#include "Scene/Scene.h"
class AntAiComponent : public Unknown::Component {
public:
    AntAiComponent( level currentlvl);
    struct level curlvl;

    virtual void update(Unknown::Entity& ent) override;

};


#endif //UNKNOWN_GAME_ANTAICOMPONENT_H