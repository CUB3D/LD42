
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
#include "TowerHealthBar.h"
#include "Font.h"
#include "Sounds.h"
#include "TowerAiComponent.h"
#include "Entity/AnimationRenderComponent.h"
#include "AnimationHelper.h"


using namespace ::Unknown;
using namespace ::Unknown::Graphics;

// TODO: moar tower bases
//TODO: fix towers / enemies
// TODO: repair packs
//TODO: Real win/ loss screens (scott)



int levelID = 1;

Image background("res/Backgrounds/1.png");
KeyBind key(SDLK_q, "edit");
SharedVariable health("health", 10.0);
SharedVariable funds("funds", 100.0);
SharedVariable currentWave("currentWave", 0.0);
SharedVariable maxWave("maxWave", 0.0);

int selectedTower = -1;
double selectedCost = 20.0;

UIContainer ui;

void GameScene::uiCallback(std::shared_ptr<UIEvent> evnt) {
    if(evnt->componentName == "Tower1") {
        selectedTower = 0;
        selectedCost = 20.0;
    }
    if(evnt->componentName == "Tower2") {
        selectedTower = 1;
        selectedCost = 50;
    }
    if(evnt->componentName =="NextLevel")
    {
        this->advanceLevel();
    }

    printf("%d\n", selectedTower);
}

void GameScene::onClick(MouseEvent evnt) {
    // Is it on a tower
    if(evnt.buttonState != PRESSED)
        return;

    if(selectedTower < 0)
        return;

    int x = evnt.location.x;
    int y = evnt.location.y;
    if((double)funds >= selectedCost) {
        // Find which base is being clicked
        for (auto &l : this->currentLevel.elements) {
            if(l.placed) {
                //TODO: thunk
                continue;
            }
            if (x > l.x && x < l.x + 64) {
                if (y > l.y && y < l.y + 16) {
                    Sounds::getSounds().build.playSingle();

                    if(selectedTower == 0) {
                        // gun
                        auto b = UK_LOAD_ENTITY_AT("Entities/Tower_weapon.json", l.x - 16, l.y - 91);
                        b->angle = l.angle;
                        this->addObject(b);
                        // Add the tower
                        auto a = UK_LOAD_ENTITY_AT("Entities/Tower_Body.json", l.x, l.y - 91);
                        a->angle = l.angle;
                        a->components.push_back(std::make_shared<TowerHealthBar>(b, [](Entity& ent) {
                            auto scene = ::Unknown::getUnknown()->globalSceneManager.getScene<Scene>();
                            auto ded = ::Unknown::Loader::loadEntityAt("Entities/TurretDead.json", *scene, ent.position.x - 5, ent.position.y);
                            //TODO: way to load from json
                            ded->components.push_back(std::make_shared<::Unknown::AnimationRenderComponent>(AnimationHelper::getExplodeAnimation()));
                            scene->addObject(ded);
                        }));
                        a->components.push_back(std::make_shared<TowerAiComponent>(0.4, 140));
                        this->addObject(a);
                        // Remove funds
                        funds = (double) funds - selectedCost;
                        l.placed = true;
                    }
                    if(selectedTower == 1) {
                        // Tesla
                        auto b = UK_LOAD_ENTITY_AT("Entities/Tower_Tesla.json", l.x - 16, l.y - 91);
                        b->components.push_back(std::make_shared<TowerHealthBar>(b, [](Entity& ent) {
                        //TODO: death animation
                        }));
                        this->addObject(b);

                        funds = (double) funds - selectedCost;
                        l.placed = true;
                    }
                }
            }
        }
    }
}

GameScene::GameScene(std::shared_ptr<::Unknown::Graphics::TTFont> font) : Scene("Game") {
	UK_ADD_UI_LISTENER_INTERNAL(uiCallback, "uicallback");

	ui = Loader::loadUI("res/GameUI.json");
	ui.setGlobalFont(font);
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
    printf("loading level %d\n", levelID);

    this->renderables.clear();
    this->updatables.clear();
    this->tagables.clear();
    std::string lvl = "Level/Level" + intToString(levelID) + ".txt";

    this->currentLevel = ::loadLevel(lvl);

    background = Image("res/Backgrounds/" + intToString(levelID) + ".png");

    for(levelElement& element : this->currentLevel.elements) {
        if(element.type == TowerBase) {
            auto ent = UK_LOAD_ENTITY_AT("Entities/Tower_Base.json", element.x, element.y);
            ent->angle = element.angle;
            this->addObject(ent);
        }
    }

    this->logic.reset();
}

void GameScene::render() const {
    background.render(0, 0);

    Scene::render();

    this->e.render();


    // Rerender on the front
    for(auto& tower : getObjects<IRenderable>("TowerBody")) {
        tower->render(0, 0);
    }

    // TODO: do this for destroyed ones too
    //TODO: play death sound for ant
    // Add moar towers
    //TODO: dead towers dont render anymore, why?
    //remove debug
    //TODO: death animations


    ui.render(0, 0);
}

void GameScene::update() {
    Scene::update();

    if(key.pressed())
        e.edit = true;

    logic.update(currentLevel, *this);

    currentWave = (double) (logic.currentWave + 1);
    maxWave = (double) currentLevel.waves.size();

    bool allAntsDead = true;
    for(auto& ant : this->getObjects<Unknown::Entity>("Ant")) {
        if(ant->enabled) {
            allAntsDead = false;
            break;
        }
    }

    if(logic.doneSpawning && allAntsDead) {
        advanceLevel();
    }

    this->e.update();
}

void GameScene::advanceLevel() {
    levelID++;

    //TODO: update this to represent the end
    if(levelID == 3) {
        UK_LOAD_SCENE("Win");
        return;
    }

    loadLevel();
}
