//
// Created by cub3d on 11/08/18.
//

#include "MainMenuScene.h"

void ui(std::shared_ptr<Unknown::UIEvent> evt) {
    if(evt->componentName == "PlayButton") {
        UK_LOAD_SCENE("Game");
    }

    if(evt->componentName == "QuitButton") {
        Unknown::getUnknown()->quit(0);
    }

    UK_REMOVE_UI_LISTENER("mainmenu");
}


MainMenuScene::MainMenuScene(std::shared_ptr<Unknown::Graphics::TTFont> font) : MenuScene("MainMenu", "res/MainMenu.json", font) {
    ::Unknown::registerUIListener(ui, "mainmenu");
}