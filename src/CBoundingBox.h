#pragma once

#include "Component.h"
#include "Vec2.h"

class CBoundingBox : public Component {
public:
    Vec2 size    {0.F, 0.F};
    Vec2 halfSize{0.F, 0.F};

    CBoundingBox() = default;
    CBoundingBox(Vec2 size);
};