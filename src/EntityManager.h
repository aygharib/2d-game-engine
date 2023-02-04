#pragma once

#include <memory>
#include <vector>

#include "Entity.h"

using EntityVec = std::vector<std::shared_ptr<Entity>>;
using EntityMap = std::map<std::string, EntityVec>;

class EntityManager {
public:
    auto update() -> void;

    auto addEntity(const std::string& tag) -> std::shared_ptr<Entity>;
    auto removeEntity(const std::string& tag) -> void;

    auto getEntities()                       -> EntityVec&;
    auto getEntities(const std::string& tag) -> EntityVec&;
private:
    size_t    totalEntities = 0;
    size_t    totalDeleted  = 0;
    EntityVec entities;
    EntityVec toAddEntities;
    EntityMap entityMap;
};