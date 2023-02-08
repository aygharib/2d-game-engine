#include <algorithm>
#include <iostream>
#include <memory>

#include "EntityManager.h"
#include "Entity.h"

auto EntityManager::update() -> void {
    // Add entities
    for (const auto& entity : toAddEntities) {
        entities.push_back(entity);
        entityMap[entity->tag].push_back(entity);
    }
    toAddEntities.clear();

    // Remove entities
    auto pend = std::remove_if(entities.begin(), entities.end(), [](auto e){ return !e->active; });
    entities.erase(pend, entities.end());
}

auto EntityManager::addEntity(EntityTag tag) -> std::shared_ptr<Entity> {
    auto entity = std::make_shared<Entity>(totalEntities++, tag);
    toAddEntities.push_back(entity);

    return entity;
}

auto EntityManager::removeEntity(EntityTag tag) -> void {
    if (totalDeleted < totalEntities - 1)
        entityMap.at(tag).at(totalDeleted++)->active = false;
}

auto EntityManager::getEntities() -> EntityVec& {
    return entities;
}

auto EntityManager::getEntities(EntityTag tag) -> EntityVec& {
    return entityMap.at(tag);
}