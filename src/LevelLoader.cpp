//
// Created by cub3d on 11/08/18.
//

#include "LevelLoader.h"

level loadLevel(const std::string &str) {
    level l;
    l.waves = std::vector<waveData>();

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
        printf("Skipping: %s\n", line.c_str());
        while(!stream.eof()) {
            // Read 4 values from each line
            int data[2];
            for(int i = 0; i < 2; i++) {
                stream >> line;
                if(line == "###") { // Marks the end of this block
                    goto loadpos;
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

    loadpos: {
        std::getline(stream, line);
        printf("Skipping %s\n", line.c_str());

        // Read 4 values from each line
        int data[2];
        for(int i = 0; i < 2; i++) {
            stream >> line;
            ss << line;
            ss >> data[i];
            ss.clear();
        }

        l.spawnPos.x = data[0];
        l.spawnPos.y = data[1];

        printf("Spawnpos: %d, %d\n", data[0], data[1]);
    };

    std::getline(stream, line);
    std::getline(stream, line);
    printf("Skipping %s\n", line.c_str());
    std::vector<int> nums;
    while(!stream.eof()) {
        while (std::getline(stream, line)) {

            std::string part;
            std::stringstream ls(line);

            while (std::getline(ls, part, ' ')) {
                int num;
                std::stringstream ss;
                ss << part;
                ss >> num;
                nums.push_back(num);
            }
        }
    }

    for(int i = 0; i < nums.size(); i+=3) {
        pathNode node;
        node.x = nums[i];
        node.y = nums[i+1];
        node.angle = nums[i+2];
        l.pathingNodes.push_back(node);
    }




//        int data[3];
//        for(int i = 0; i < 3; i++) {
//            stream >> line;
//            if(line == "###") { // Marks the end of this block
//                //goto loadpos;
//            }
//            ss << line;
//            ss >> data[i];
//            printf("%s = %d", line.c_str(), data[i]);
//            ss.clear();
//        }
//
//        pathNode node;
//        node.x = data[0];
//        node.y = data[1];
//        node.angle = data[2];
//
//        printf("Pathing node: %d %d\n", node.x, node.y);
//
//        l.pathingNodes.push_back(node);
    //}

    return l;
}
