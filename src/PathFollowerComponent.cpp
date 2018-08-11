//
// Created by cub3d on 11/08/18.
//

#include "PathFollowerComponent.h"
#include "Unknown.h"
#include "SharedVariable.h"

void PathFollowerComponent::update(Unknown::Entity &ent) {
    int endX = curlvl.pathingNodes[this->currentNodeIndex].x;
    int endY = curlvl.pathingNodes[this->currentNodeIndex].y;

    printf("%d, %d\n", endX, endY);

    double delta = 0.16;

    bool atEnd = true;

    if(endX > 0) {
        if (ent.position.x < endX) {
            ent.position.x += speed * delta;
            atEnd = false;
        }
    } else {
        if (ent.position.x > -endX) {
            ent.position.x -= speed * delta;
            atEnd = false;
        }
    }

    if(endY > 0) {
        if (ent.position.y < endY) {
            ent.position.y += speed * delta;
            atEnd = false;
        }
    } else {
        if (ent.position.y > -endY) {
            ent.position.y -= speed * delta;
            atEnd = false;
        }
    }

    if(atEnd) {
        this->currentNodeIndex++;

        // If we just passed the last node we have reached end of path
        if(this->currentNodeIndex == curlvl.pathingNodes.size()) {
            ent.enabled=false;
            *Unknown::getUnknown()->variablelookup["health"] = Unknown::getUnknown()->variablelookup["health"]->operator double() - 1;
            if(Unknown::getUnknown()->variablelookup["health"]->operator double() == 0) {
                UK_LOAD_SCENE("Fail");
            }
        }
    }
}

PathFollowerComponent::PathFollowerComponent(struct level leve) : curlvl(leve){

}
