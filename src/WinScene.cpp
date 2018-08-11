//
// Created by cub3d on 11/08/18.
//

#include "WinScene.h"

WinScene::WinScene() : Scene("Win"), img("res/Tower.png") {

}

void WinScene::render() const {
    Scene::render();

    img.render(0, 0);
}
