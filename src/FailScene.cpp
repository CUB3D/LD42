//
// Created by cub3d on 11/08/18.
//

#include "FailScene.h"
#include "Sounds.h"

FailScene::FailScene() : Scene("Fail"), background("res/Lose Screen.png"), soundPlayed(false) {
}

void FailScene::render() const {
    Scene::render();

    this->background.render(0, 0);
}

void FailScene::update() {
    if(!soundPlayed) {
        Sounds::getSounds().towerDestroy.playSingle();
        soundPlayed = true;
    }
}
