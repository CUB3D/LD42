#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "stdafx.h"
#include "Scene/Scene.h"
#include "Editor.h"

class GameScene : public ::Unknown::Scene {
public:
    Editor e;

	GameScene();

	virtual void render() const override;
	virtual void update() override;
};

#endif