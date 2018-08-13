//
// Created by cub3d on 11/08/18.
//

#ifndef UNKNOWN_GAME_SOUNDS_H
#define UNKNOWN_GAME_SOUNDS_H

#include "Audio/WAVSound.h"

using namespace ::Unknown;

class Sounds
{
public:
    WAVSound loss; // Y
    WAVSound gun; // N
    WAVSound towerDestroy; // Y
    WAVSound wavestart; // N
    WAVSound build; // Y
    WAVSound death; // Y

    static Sounds& getSounds();

protected:
    Sounds() :
    loss("res/audio/isthisloss.wav"),
    gun("res/audio/gun.wav"),
    towerDestroy("res/audio/towerdestroy.wav"),
    wavestart("res/audio/wavestart.wav"),
    build("res/audio/build.wav"),
    death("res/audio/death.wav")
    {}
};


#endif //UNKNOWN_GAME_SOUNDS_H
