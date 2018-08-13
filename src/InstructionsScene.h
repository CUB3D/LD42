//
// Created by cub3d on 13/08/18.
//

#ifndef UNKNOWN_GAME_INSTRUCTIONSSCENE_H
#define UNKNOWN_GAME_INSTRUCTIONSSCENE_H

#include "Scene/Scene.h"
#include "Input.h"

class InstructionsScene : public ::Unknown::Scene
{
public:
    InstructionsScene();

    virtual void render() const;
    void onMouseEvent(Unknown::MouseEvent evnt);
};


#endif //UNKNOWN_GAME_INSTRUCTIONSSCENE_H
