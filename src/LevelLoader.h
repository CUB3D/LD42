//
// Created by cub3d on 11/08/18.
//

#ifndef UNKNOWN_GAME_LEVELLOADER_H
#define UNKNOWN_GAME_LEVELLOADER_H

#include "Log.h"
#include <filesystem>
#include <fstream>
#include "Utils.h"

enum Type {
    TowerBase
};

struct levelElement {
    Type type;
    int x;
    int y;
    double angle;
};

struct waveData {
    int count;
    int delay;
};

struct level {
    std::vector<levelElement> elements;
    std::vector<waveData> waves;
};

level loadLevel(const std::string &str);

#endif //UNKNOWN_GAME_LEVELLOADER_H
