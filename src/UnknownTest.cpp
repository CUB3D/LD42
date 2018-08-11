// Unknown Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include "Unknown.h"
#include "Scene/Scene.h"

#include "GameScene.h"
#include "FailScene.h"
#include "WinScene.h"

#include "Font.h"

std::shared_ptr<Unknown::Graphics::TTFont> font;


void init() {
    font = std::make_shared<Unknown::Graphics::TTFont>("res/Fonts/Arimo-Regular.ttf", 15, UK_COLOUR_RGB(0, 0, 0));

    UK_ADD_SCENE(std::make_shared<WinScene>());
	UK_ADD_SCENE(std::make_shared<GameScene>(font));
	UK_ADD_SCENE(std::make_shared<FailScene>());
	UK_LOAD_SCENE("Game");
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
