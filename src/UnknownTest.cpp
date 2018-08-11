// Unknown Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include "Unknown.h"
#include "Scene/Scene.h"

#include "GameScene.h"

void init() {
	UK_ADD_SCENE(std::make_shared<GameScene>());
	UK_LOAD_SCENE("GameScene");
}

#ifdef _WIN32
int _tmain(int argc, _TCHAR* argv[])
#else
int main(int argc, char* argv[])
#endif
{
    UK_CREATE_WINDOW();

	init();

    UK_INIT_GAME();

	return 0;
}
