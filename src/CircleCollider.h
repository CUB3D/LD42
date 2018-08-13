//
// Created by cub3d on 13/08/18.
//

#ifndef UNKNOWN_GAME_CIRCLECOLLIDER_H
#define UNKNOWN_GAME_CIRCLECOLLIDER_H

#include "Box2D/Box2D.h"
#include "Entity/Entity.h"
#include "Entity/Component.h"
#include "Vector.h"
#include "Scene/Scene.h"
#include "Utils.h"

class CircleCollider : public ::Unknown::Component
{
public:
    b2BodyDef bodyDefinition;
    b2Body* body;
    b2CircleShape shape;
    b2FixtureDef fixtureDefinition;
    b2Fixture* fixture;
    b2Filter filter;

    Unknown::Vector lastForce;

    //public:
    CircleCollider(std::shared_ptr<Unknown::Entity> ent, Unknown::Scene *scene);

    virtual void update(Unknown::Entity &ent) override;
};


#endif //UNKNOWN_GAME_CIRCLECOLLIDER_H
