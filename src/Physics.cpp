#include "Physics.h"
#include "CBoundingBox.h"

#include <iostream>

auto Physics::getOverlap(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b) -> Vec2 {
    auto delta = Vec2{std::abs(a->getCTransformComponent().position.x - b->getCTransformComponent().position.x),
                            std::abs(a->getCTransformComponent().position.y - b->getCTransformComponent().position.y)};
    
    auto overlapX = a->getCBoundingBoxComponent().halfSize.x + b->getCBoundingBoxComponent().halfSize.x - delta.x;
    auto overlapY = a->getCBoundingBoxComponent().halfSize.y + b->getCBoundingBoxComponent().halfSize.y - delta.y;
    return Vec2{overlapX, overlapY};
}

auto Physics::getPreviousOverlap(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b) -> Vec2 {
    auto delta = Vec2{std::abs(a->getCTransformComponent().previousPosition.x - b->getCTransformComponent().previousPosition.x),
                            std::abs(a->getCTransformComponent().previousPosition.y - b->getCTransformComponent().previousPosition.y)};
    
    auto overlapX = a->getCBoundingBoxComponent().halfSize.x + b->getCBoundingBoxComponent().halfSize.x - delta.x;
    auto overlapY = a->getCBoundingBoxComponent().halfSize.y + b->getCBoundingBoxComponent().halfSize.y - delta.y;

    return Vec2{overlapX, overlapY};
}
