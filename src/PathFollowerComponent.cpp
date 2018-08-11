//
// Created by cub3d on 11/08/18.
//

#include "PathFollowerComponent.h"
#include "Unknown.h"

void PathFollowerComponent::update(Unknown::Entity &ent) {
    int endX = curlvl.pathingNodes[this->currentNodeIndex].x;
    int endY = curlvl.pathingNodes[this->currentNodeIndex].y;

    printf("%d, %d\n", endX, endY);

    double delta = Unknown::getUnknown()->lastUpdateTimeMS;

    bool atEnd = true;

    if(ent.position.x < endX) {
        ent.position.x += endX * speed * delta;
        atEnd = false;
    }
    if(ent.position.y < endY) {
        ent.position.y += endY * speed * delta;
        atEnd = false;
    }

    if(atEnd) {
        this->currentNodeIndex++;

        // If we just passed the last node we have reached end of path
        if(this->currentNodeIndex == curlvl.pathingNodes.size())
            this->speed = 0;
    }
}

PathFollowerComponent::PathFollowerComponent(struct level leve) : curlvl(leve){

}
