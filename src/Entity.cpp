#include "Entity.h"

Entity::Entity(size_t id, std::string tag) : id{id}, tag{std::move(tag)} {}

auto Entity::destroy() -> void {
    active = false;
}