//
// Created by cub3d on 11/08/18.
//

#ifndef UNKNOWN_GAME_LEVELLOADER_H
#define UNKNOWN_GAME_LEVELLOADER_H

#include "Log.h"
#include <filesystem>
#include <fstream>

enum Type {
    TowerBase
};

struct levelElement {
    Type type;
    int x;
    int y;
    int data;
};

std::vector<levelElement> loadLevel(const std::string& str) {
    std::vector<levelElement> elements;

    // Create stream for file
    std::filesystem::path file(str);
    std::ifstream stream(file, std::ios::in);

    std::stringstream ss;
    std::string line;

    // Skip first line
    std::getline(stream, line);

    while(!stream.eof()) {
        // Read 4 values from each line
        int data[4];
        for(int i = 0; i < 4; i++) {
            stream >> line;
            ss << line;
            ss >> data[i];
            UK_LOG_INFO(line, "=", ::Unknown::intToString(data[i]));
            ss.clear();
        }

        levelElement e;
        e.type = (Type)data[0];
        e.x = data[1];
        e.y = data[2];
        e.data = data[3];

#ifdef LVL_DBG
        printf("Loaded %d,%d,%d,%d\n", e.type, e.x, e.y, e.data);
#endif

        elements.push_back(e);
    }

    return elements;
}

#endif //UNKNOWN_GAME_LEVELLOADER_H
