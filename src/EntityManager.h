#pragma once

#include <map>
#include <memory>
#include <vector>

#include "Entity.h"

using EntityVec = std::vector<std::shared_ptr<Entity>>;
using EntityMap = std::map<EntityTag, EntityVec>;

class EntityManager {
public:
    size_t    totalEntities{0};
    size_t    totalDeleted {0};
    EntityVec entities     {};
    EntityVec toAddEntities{};
    EntityMap entityMap    {};

    auto update() -> void;

    auto addEntity(EntityTag tag) -> std::shared_ptr<Entity>;
    auto removeEntity(EntityTag tag) -> void;

    auto getEntities() -> EntityVec&;
    auto getEntities(EntityTag tag) -> EntityVec&;
};