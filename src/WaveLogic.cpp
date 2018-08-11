//
// Created by cub3d on 11/08/18.
//

#include "WaveLogic.h"
#include "Scene/Scene.h"
#include "Loader.h"
#include "PathFollowerComponent.h"

void WaveLogic::update(level level, Scene &scene) {
    if(spawnTimer.isTickComplete()) { // Time to spawn new enemy
        printf("Spawning wave of size %d\n", level.waves.size());

        currentWavePosition++;
        auto en = Loader::loadEntityAt("Entities/Ant.json", scene, level.spawnPos.x, level.spawnPos.y);
        en->components.push_back(std::make_shared<PathFollowerComponent>(level));
        scene.addObject(en);

        // If this wave is done
        if(currentWavePosition == level.waves[currentWave].count) {
            // get next wave and setup timer
            spawnTimer.timerSpeed = level.waves[currentWave++].delay;
            // Reset spawn count
            currentWavePosition = 0;
        }
    }
}
