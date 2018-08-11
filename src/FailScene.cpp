//
// Created by cub3d on 11/08/18.
//

#include "FailScene.h"

FailScene::FailScene() : Scene("Fail"), background("res/isthisloss.png") {

}

void FailScene::render() const {
    Scene::render();

    this->background.render(0, 0);
}
