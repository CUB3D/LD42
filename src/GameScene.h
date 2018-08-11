#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "stdafx.h"
#include "Scene/Scene.h"
#include "Editor.h"
#include "LevelLoader.h"
#include "WaveLogic.h"

class GameScene : public ::Unknown::Scene {
public:
    level currentLevel;

    Editor e;
    WaveLogic logic;

	GameScene();

	virtual void render() const override;
	virtual void update() override;

	void advanceLevel();

	void loadLevel();
	void uiCallback(std::shared_ptr<Unknown::UIEvent> evt);
	void onClick(Unknown::MouseEvent evnt);
};

#endif