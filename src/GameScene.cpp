
#include "GameScene.h"

#include "Unknown.h"
#include "Image.h"
#include "Log.h"
#include "Loader.h"
#include "Map.h"
#include "LevelLoader.h"
#include "KeyBind.h"
#include "UI.h"
#include "Timer.h"
#include "SharedVariable.h"

using namespace ::Unknown;
using namespace ::Unknown::Graphics;

//TODO: load next level when this one is done
// TODO: kill enemies
//TODO: turrets can be attacked
//TODO: destroyed turret

int levelID = 1;

Image background("res/Backgrounds/Flooding-Level-Bg.png");
KeyBind key(SDLK_q, "edit");
SharedVariable health("health", 10.0);

int selectedTower = 0;

UIContainer ui;

void GameScene::uiCallback(std::shared_ptr<UIEvent> evnt) {
    if(evnt->componentName == "Tower1") {
        selectedTower = 1;
    }
    if(evnt->componentName == "Reload") {
        this->loadLevel();
    }

    printf("%d\n", selectedTower);
}

void GameScene::onClick(MouseEvent evnt) {
    // Is it on a tower

    int x = evnt.location.x;
    int y = evnt.location.y;

    for(auto& l : this->currentLevel.elements) {
        if(x > l.x && x < l.x + 64) {
            if(y > l.y && y < l.y + 16) {
                auto a = UK_LOAD_ENTITY_AT("Entities/Tower_Body.json", l.x, l.y - 91);
                a->angle = l.angle;
                this->addObject(a);
                auto b = UK_LOAD_ENTITY_AT("Entities/Tower_weapon.json", l.x - 16, l.y - 91);
                b->angle = l.angle;
                this->addObject(b);
            }
        }
    }
}

GameScene::GameScene() : Scene("Game") {
	UK_LOG_INFO("Loading game scene");

	UK_ADD_UI_LISTENER_INTERNAL(uiCallback, "uicallback");

	ui = Loader::loadUI("res/GameUI.json");
	ui.setGlobalFont(std::make_shared<TTFont>("res/Fonts/Arimo-Regular.ttf", 15, UK_COLOUR_RGB(0, 0, 0)));
	ui.initUI();



	auto x = [this](auto me) {
        if(!e.edit)
            return;

        Unknown::Point<int> pos;
        UK_GET_MOUSE_POS(pos);

        printf("%d,%d\n", pos.x, pos.y);
        levelElement e;
        e.type = (Type)0;
        e.x = pos.x;
        e.y = pos.y;
        e.angle = 0;
        this->currentLevel.elements.push_back(e);


        printf("## Format is Type, X, Y, angle (note first line is skipped)\n");
        for(auto& a : this->currentLevel.elements) {
            printf("%d %d %d %d\n", a.type, a.x, a.y, a.angle);
        }
    };

    registerMouseListener(x, "editor");

    UK_ADD_MOUSE_LISTENER_INTERNAL(onClick, "towerplace");

    loadLevel();
}

void GameScene::loadLevel() {
    this->renderables.clear();
    this->updatables.clear();
    this->tagables.clear();
    std::string lvl = "Level/Level" + intToString(levelID) + ".txt";

    this->currentLevel = ::loadLevel(lvl);

    for(levelElement& element : this->currentLevel.elements) {
        if(element.type == TowerBase) {
            auto ent = UK_LOAD_ENTITY_AT("Entities/Tower_Base.json", element.x, element.y);
            ent->angle = element.angle;
            this->addObject(ent);
        }
    }
}

void GameScene::render() const {
    background.render(0, 0);

    Scene::render();

    this->e.render();

    ui.render(0, 0);
}

void GameScene::update() {
    Scene::update();

    if(key.pressed())
        e.edit = true;

    logic.update(currentLevel, *this);

    this->e.update();
}
