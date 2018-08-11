//
// Created by cub3d on 11/08/18.
//

#include "WaveLogic.h"
#include "Scene/Scene.h"
#include "Loader.h"
#include "PathFollowerComponent.h"
#include "HealthBar.h"


void WaveLogic::update(level level, Scene &scene) {
    if(spawnTimer.isTickComplete()) { // Time to spawn new enemy
        printf("Spawning wave of size %d\n", level.waves.size());

        currentWavePosition++;
        auto en = Loader::loadEntityAt("Entities/Ant.json", scene, level.spawnPos.x, level.spawnPos.y);
        en->components.push_back(std::make_shared<PathFollowerComponent>(level));
        en->components.push_back(std::make_shared<HealthBar>());
        scene.addObject(en);

        // If this wave is done
        if(currentWavePosition == level.waves[currentWave].count) {
            // get next wave and setup timer
            spawnTimer.timerSpeed = level.waves[currentWave++].delay;
            // Reset spawn count
            currentWavePosition = 0;

            if(currentWave == level.waves.size()) {
                printf("Load next level");
                this->spawnTimer.timerSpeed = 99999999;
            }
        }
    }
}

WaveLogic::WaveLogic() : currentWavePosition(0), currentWave(0), spawnTimer((float)1.0) {

}
