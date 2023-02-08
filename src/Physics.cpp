#include "Physics.h"
#include "CBoundingBox.h"

#include <iostream>

auto Physics::getOverlap(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b) -> Vec2 {
    auto delta = Vec2{std::abs(a->getComponent<CTransform>().position.x - b->getComponent<CTransform>().position.x),
                            std::abs(a->getComponent<CTransform>().position.y - b->getComponent<CTransform>().position.y)};
    
    auto overlapX = a->getComponent<CBoundingBox>().halfSize.x + b->getComponent<CBoundingBox>().halfSize.x - delta.x;
    auto overlapY = a->getComponent<CBoundingBox>().halfSize.y + b->getComponent<CBoundingBox>().halfSize.y - delta.y;
    return Vec2{overlapX, overlapY};
}

auto Physics::getPreviousOverlap(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b) -> Vec2 {
    auto delta = Vec2{std::abs(a->getComponent<CTransform>().previousPosition.x - b->getComponent<CTransform>().previousPosition.x),
                            std::abs(a->getComponent<CTransform>().previousPosition.y - b->getComponent<CTransform>().previousPosition.y)};
    
    auto overlapX = a->getComponent<CBoundingBox>().halfSize.x + b->getComponent<CBoundingBox>().halfSize.x - delta.x;
    auto overlapY = a->getComponent<CBoundingBox>().halfSize.y + b->getComponent<CBoundingBox>().halfSize.y - delta.y;

    return Vec2{overlapX, overlapY};
}
