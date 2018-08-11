//
// Created by scott on 11/08/18.
//

#ifndef UNKNOWN_GAME_TOWERAICOMPONENT_H
#define UNKNOWN_GAME_TOWERAICOMPONENT_H

#include "Unknown.h"
#include "Entity/Component.h"

class TowerAiComponent : public Unknown::Component {
public:
    TowerAiComponent( double rate, int range);
    double rate;
    int range;

    virtual void update(Unknown::Entity& ent) override;
};


#endif //UNKNOWN_GAME_TOWERAICOMPONENT_H
