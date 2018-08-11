#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "stdafx.h"
#include "Scene/Scene.h"

class GameScene : public ::Unknown::Scene {
public:
	GameScene();

	virtual void render() const override;
	virtual void update() override;
};

#endif