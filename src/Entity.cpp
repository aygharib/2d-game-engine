#include "Entity.h"

Entity::Entity(size_t id, EntityTag tag) : id(id), tag(tag) {}

auto Entity::destroy() -> void {
    active = false;
}