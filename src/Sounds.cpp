//
// Created by cub3d on 11/08/18.
//

#include "Sounds.h"

Sounds &Sounds::getSounds() {
    static Sounds s;
    return s;
}
