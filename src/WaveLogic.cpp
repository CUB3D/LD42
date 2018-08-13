//
// Created by cub3d on 11/08/18.
//

#include "WaveLogic.h"
#include "Scene/Scene.h"
#include "Loader.h"
#include "PathFollowerComponent.h"
#include "AntAiComponent.h"
#include "HealthBar.h"
#include "GameScene.h"
#include "Sounds.h"
#include "LanderAIComponent.h"


void WaveLogic::update(level level, Scene &scene) {
    if(doneSpawning)
        return;

    if(spawnTimer.timerSpeed < 0) {
        spawnTimer.timerSpeed = level.waves[currentWave].delay;
    }


    if(spawnTimer.isTickComplete()) { // Time to spawn new enemy
        printf("Spawning %d/%d/%d\n", currentWavePosition, level.waves[currentWave].count, spawnTimer.timerSpeed);
        if(currentWavePosition < level.waves[currentWave].count) {
            currentWavePosition++;
            auto en = Loader::loadEntityAt("Entities/Ant.json", scene, level.spawnPos.x, level.spawnPos.y);
            en->components.push_back(std::make_shared<PathFollowerComponent>(level));
            en->components.push_back(std::make_shared<HealthBar>());
            en->components.push_back(std::make_shared<AntAiComponent>(level, 0.05));
            scene.addObject(en);
        }

        // If this wave is done
        if(currentWavePosition >= level.waves[currentWave].count) {
            // get next wave and setup timer
            currentWave++;
            spawnTimer.timerSpeed = level.waves[currentWave].delay;
            // Reset spawn count
            currentWavePosition = 0;

            if(currentWave == level.waves.size()) {
                doneSpawning = true;
                currentLevel++;
            } else { // Play wave start for the next wave
                Sounds::getSounds().wavestart.playSingle();

                //If on level2 spawn lander randomly
                if(currentLevel == 1 && currentWave > 1) {
                    auto& nodes = level.pathingNodes;
                    long long int pos = RANDINT(0, nodes.size());
                    auto& node = nodes[pos];


                    auto scene = ::Unknown::getUnknown().globalSceneManager.getScene<Scene>();
                    auto ded = ::Unknown::Loader::loadEntityAt("Entities/Spawner.json", *scene, node.x, node.y - 40);
                    ded->components.push_back(std::make_shared<LanderAIComponent>(40, pos));
                    //TODO: way to load from json
                    //ded->components.push_back(std::make_shared<::Unknown::AnimationRenderComponent>(AnimationHelper::getExplodeAnimation()));
                    scene->addObject(ded);
                }
            }
        }
    }
}

WaveLogic::WaveLogic() : currentWavePosition(0), currentWave(0), spawnTimer((float)-1), doneSpawning(false), currentLevel(0) {

}

void WaveLogic::reset() {
    currentWave = 0;
    currentWavePosition = 0;
    doneSpawning = false;
    spawnTimer.timerSpeed=-1;
}
