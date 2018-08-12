//
// Created by cub3d on 11/08/18.
//

#ifndef UNKNOWN_GAME_FAILSCENE_H
#define UNKNOWN_GAME_FAILSCENE_H

#include "Scene/Scene.h"

using namespace ::Unknown::Graphics;

class FailScene : public ::Unknown::Scene
{
public:
    Image background;
    bool soundPlayed;

    FailScene();
    virtual void render() const override;
};


#endif //UNKNOWN_GAME_FAILSCENE_H
