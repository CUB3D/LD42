
#include "GameScene.h"

#include "Unknown.h"
#include "Image.h"
#include "Log.h"
#include "Loader.h"
#include "Map.h"
#include "LevelLoader.h"
#include "KeyBind.h"

using namespace ::Unknown;
using namespace ::Unknown::Graphics;


int levelID = 0;

Image background("res/Backgrounds/Flooding-Level-Bg.png");
KeyBind key(SDLK_q, "edit");

GameScene::GameScene() : Scene("Game") {
	UK_LOG_INFO("Loading game scene");

	auto x = [this](auto me) {
        if(!e.edit)
            return;

        Unknown::Point<int> pos;
        UK_GET_MOUSE_POS(pos);

        printf("%d,%d\n", pos.x, pos.y);
        ::Unknown::getUnknown()->globalSceneManager.currentScene->addObject(Loader::loadEntityAt("Entities/Tower1.json", *this, pos.x, pos.y));
    };

    registerMouseListener(x, "editor");


	for(levelElement& element : loadLevel("Level/Level1.txt")) {
		if(element.type == TowerBase) {
		    auto ent = UK_LOAD_ENTITY_AT("Entities/Tower1.json", element.x, element.y);
		    ent->angle = element.angle;
			this->addObject(ent);
		}
	}
}

void GameScene::render() const {
    background.render(0, 0);

    Scene::render();

    this->e.render();
}

void GameScene::update() {
    Scene::update();

    if(key.pressed())
        e.edit = true;

    this->e.update();
}
