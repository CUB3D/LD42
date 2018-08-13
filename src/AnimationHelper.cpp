//
// Created by cub3d on 12/08/18.
//

#include "AnimationHelper.h"
#include "Loader.h"

using namespace ::Unknown::Graphics;

Unknown::Graphics::Animation AnimationHelper::getExplodeAnimation() {
    Animation anim;
    anim.loop = false;
    anim.addFrame(UK_LOAD_IMAGE("res/NewTurret.png"), 100);
    anim.addFrame(UK_LOAD_IMAGE("res/DestroyedTurretBlowingUp.png"), 100);
    // This type will be the death of me
    anim.addFrame(UK_LOAD_IMAGE("res/DestroyedTurret.png"), 100);
    return anim;
}
