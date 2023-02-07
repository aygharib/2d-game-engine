#pragma once

#include "Component.h"

class CInput : public Component {
public:
    int x;
    bool up   {false};
    bool down {false};
    bool left {false};
    bool right{false};

    CInput() = default;
};