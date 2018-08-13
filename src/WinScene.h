//
// Created by cub3d on 11/08/18.
//

#ifndef UNKNOWN_GAME_WINSCENE_H
#define UNKNOWN_GAME_WINSCENE_H

#include "Scene/Scene.h"
#include "Timer.h"

class WinScene : public ::Unknown::Scene
{
public:
    Unknown::Graphics::Image img;
    Unknown::Timer timer;

    WinScene();

    virtual void render() const override;
    virtual void update() override;
};


#endif //UNKNOWN_GAME_WINSCENE_H
