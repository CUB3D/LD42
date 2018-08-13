//
// Created by cub3d on 13/08/18.
//

#include "CircleCollider.h"

void CircleCollider::update(Unknown::Entity &ent) {
    ent.position.x = body->GetPosition().x;
    ent.position.y = body->GetPosition().y;
    ent.angle = body->GetAngle();
}

CircleCollider::CircleCollider(std::shared_ptr<Unknown::Entity> ent, Unknown::Scene *scene) {
    this->bodyDefinition.type = b2_dynamicBody;
    // this->bodyDefinition.fixedRotation = true; //TODO:
    this->bodyDefinition.position.Set(ent->position.x, ent->position.y);
    this->bodyDefinition.bullet = true;

    this->bodyDefinition.fixedRotation = false;


    this->body = scene->world.CreateBody(&this->bodyDefinition);

    this->shape.m_p.Set(0, 0);
    this->shape.m_radius = 0.25;

    this->fixtureDefinition.shape = &this->shape;
    this->fixtureDefinition.density = 1.0f; //TODO:
    this->fixtureDefinition.friction = 0.1f; //TODO:
    this->fixtureDefinition.filter = filter;
    this->fixtureDefinition.restitution = 0.3;

    this->fixture = this->body->CreateFixture(&this->fixtureDefinition);
}
