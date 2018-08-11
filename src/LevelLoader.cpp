//
// Created by cub3d on 11/08/18.
//

#include "LevelLoader.h"

level loadLevel(const std::string &str) {
    level l;

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
            if(line == "###") { // Marks the end of this block
                goto next;
            }
            ss << line;
            ss >> data[i];
            ss.clear();
        }

        levelElement e;
        e.type = (Type)data[0];
        e.x = data[1];
        e.y = data[2];
        e.angle = (data[3] / 180.0) * PI;

#ifdef LVL_DBG
        printf("Loaded %d,%d,%d,%d\n", e.type, e.x, e.y, e.data);
#endif

        l.elements.push_back(e);
    }

    next: {
        std::getline(stream, line);
        while(!stream.eof()) {
            // Read 4 values from each line
            int data[2];
            for(int i = 0; i < 2; i++) {
                stream >> line;
                if(line == "###") { // Marks the end of this block
                    goto next;
                }
                ss << line;
                ss >> data[i];
                ss.clear();
            }

            waveData wave;
            wave.count = data[0];
            wave.delay = data[1];

            l.waves.push_back(wave);
        }
    };

    return l;
}

