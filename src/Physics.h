#pragma once

#include "Entity.h"

#include <memory>

class Physics {
public:
    static auto getOverlap(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b) -> Vec2;
    static auto getPreviousOverlap(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b) -> Vec2;
};