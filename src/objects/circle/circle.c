//
// Created by saintedlittle on 30.07.2023.
//

#include "circle.h"

struct circle create_circle(float cx, float cy, float r, int num_segments) {
    struct circle out = {
            cx,
            cy,
            r,
            num_segments
    };

    return out;
}
