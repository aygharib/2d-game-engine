#pragma once

#include "Vec2.h"

class CTransform {
public:
    Vec2  position;
    Vec2  velocity;
    float angle;

    CTransform(Vec2 position, Vec2 velocity, float angle)
        : position{position}, velocity{velocity}, angle{angle} {}
};