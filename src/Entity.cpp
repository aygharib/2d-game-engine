#include "Entity.h"

#include "CCollision.h"
#include "CShape.h"
#include "CTransform.h"
#include "Vec2.h"

Entity::Entity(std::string tag, size_t id) : tag{std::move(tag)}, id{id} {}

auto Entity::getTag() -> const std::string& {
    return tag;
}