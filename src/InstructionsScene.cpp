//
// Created by cub3d on 13/08/18.
//

#include "InstructionsScene.h"
#include "Image.h"
#include "Timer.h"

Unknown::Graphics::Image instructions("res/instructions.png");
Unknown::Timer t(0.4f);
bool b = false;


InstructionsScene::InstructionsScene() : Scene("Instruction") {
    UK_ADD_MOUSE_LISTENER_INTERNAL(onMouseEvent, "instruction");
}

void InstructionsScene::render() const {
    instructions.render(0, 0);
}

void InstructionsScene::onMouseEvent(Unknown::MouseEvent evnt) {
    if(evnt.buttonState != Unknown::PRESSED)
        return;

    if(t.isTickComplete())
        b = true;

    if(Unknown::getUnknown().globalSceneManager.currentSceneName == "Instruction" && b) {
        UK_REMOVE_MOUSE_LISTENER("instruction");
        UK_LOAD_SCENE("Game");
    }
}
