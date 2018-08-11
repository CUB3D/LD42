
#include "GameScene.h"

#include "Unknown.h"
#include "Image.h"
#include "Log.h"
#include "Loader.h"

using namespace ::Unknown;
using namespace ::Unknown::Graphics;

Image dummy("res/Backgrounds/1.png");

GameScene::GameScene() : Scene("Game") {
	UK_LOG_INFO("Loading game scene");
	this->addObject(UK_LOAD_ENTITY_AT("Entities/Background.json", 1, 1));
}