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
    WAVSound loss;
    WAVSound gun;
    WAVSound towerDestroy;
    WAVSound wavestart;

    static Sounds& getSounds();

protected:
    Sounds() :
    loss("res/audio/isthisloss.wav"),
    gun("res/audio/gun.wav"),
    towerDestroy("res/audio/towerdestroy.wav"),
    wavestart("res/audio/wavestart.wav")
    {}
};


#endif //UNKNOWN_GAME_SOUNDS_H
