
#include "GameScene.h"

#include "Unknown.h"
#include "Image.h"
#include "Log.h"
#include "Loader.h"
#include "Map.h"
#include "LevelLoader.h"

using namespace ::Unknown;
using namespace ::Unknown::Graphics;


int levelID = 0;

Image background("res/Backgrounds/1.png");

GameScene::GameScene() : Scene("Game") {
	UK_LOG_INFO("Loading game scene");

	for(levelElement& element : loadLevel("Level/Level1.txt")) {
		if(element.type == TowerBase) {
			this->addObject(UK_LOAD_ENTITY_AT("Entities/Tower1.json", element.x, element.y));
		}
	}
}

void GameScene::render() const {
    background.render(0, 0);

    Scene::render();
}

void GameScene::update() {
    Scene::update();
}
