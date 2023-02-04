#include <iostream>
#include <memory>

#include "EntityManager.h"
#include "Entity.h"

auto EntityManager::update() -> void {
    // Add entities
    for (const auto& entity : toAddEntities) {
        entities.push_back(entity);
        entityMap[entity->getTag()].push_back(entity);
    }
    toAddEntities.clear();

    // Remove entities
    auto pend = std::remove_if(entities.begin(), entities.end(), [](auto e){ return !e->alive; });
    entities.erase(pend, entities.end());
}

auto EntityManager::addEntity(const std::string& tag) -> std::shared_ptr<Entity> {
    auto entity = std::make_shared<Entity>(tag, totalEntities++);
    toAddEntities.push_back(entity);

    return entity;
}

auto EntityManager::removeEntity(const std::string& tag) -> void {
    if (totalDeleted < totalEntities - 1)
        entityMap.at(tag).at(totalDeleted++)->alive = false;
}

auto EntityManager::getEntities() -> EntityVec& {
    return entities;
}

auto EntityManager::getEntities(const std::string& tag) -> EntityVec& {
    return entityMap.at(tag);
}