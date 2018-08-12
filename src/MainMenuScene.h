//
// Created by cub3d on 11/08/18.
//

#ifndef UNKNOWN_GAME_MAINMENUSCENE_H
#define UNKNOWN_GAME_MAINMENUSCENE_H

#include "Scene/Scene.h"
#include "Font.h"

class MainMenuScene : public ::Unknown::MenuScene
{
public:
    MainMenuScene(std::shared_ptr<Unknown::Graphics::TTFont> font);
};


#endif //UNKNOWN_GAME_MAINMENUSCENE_H
