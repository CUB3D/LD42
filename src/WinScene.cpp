//
// Created by cub3d on 11/08/18.
//

#include "WinScene.h"
#include "Loader.h"
#include "CircleCollider.h"

WinScene::WinScene() : Scene("Win"), img("res/Tower.png"), timer(0.15f) {
    this->addObject(UK_LOAD_ENTITY("Entities/EndGround.json"));
}

void WinScene::render() const {
    img.render(0, 0);

    Scene::render();
}

void WinScene::update() {
    Scene::update();

    if(timer.isTickComplete()) {
        auto a = UK_LOAD_ENTITY_AT("Entities/EndCoin.json", RANDINT(50, 600)/32.0, 0);
        a->components.push_back(std::make_shared<CircleCollider>(a, this));
        this->addObject(a);
    }
}
