#pragma once

#include "Component.h"
#include "Vec2.h"

class CTransform : public Component {
public:
    Vec2  position        {0.F, 0.F};
    Vec2  previousPosition{0.F, 0.F};
    Vec2  scale           {0.F, 0.F};
    Vec2  velocity        {0.F, 0.F};
    float angle           {0};

    CTransform() = default;
    CTransform(Vec2 position);
};