//
// Created by cub3d on 11/08/18.
//

#ifndef UNKNOWN_GAME_WAVELOGIC_H
#define UNKNOWN_GAME_WAVELOGIC_H

#include "Timer.h"
#include "LevelLoader.h"
#include "Scene/Scene.h"

using namespace ::Unknown;

class WaveLogic
{
public:
    Timer spawnTimer;
    int currentWavePosition;
    int currentWave;
    bool doneSpawning;

    WaveLogic();

    void update(level level, Scene &scene);
};


#endif //UNKNOWN_GAME_WAVELOGIC_H
