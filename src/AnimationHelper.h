//
// Created by cub3d on 12/08/18.
//

#ifndef UNKNOWN_GAME_ANIMATIONHELPER_H
#define UNKNOWN_GAME_ANIMATIONHELPER_H

#include "Animation.h"

class AnimationHelper
{
private:
    AnimationHelper() = default;

public:
    static Unknown::Graphics::Animation getExplodeAnimation();
};


#endif //UNKNOWN_GAME_ANIMATIONHELPER_H
