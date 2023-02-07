#include "Entity.h"

Entity::Entity(size_t id, std::string tag) : id{id}, tag{std::move(tag)} {}

auto Entity::destroy() -> void {
    active = false;
}

template<typename T>
auto Entity::hasComponent() -> bool {
    return getComponent<T>().has;
}

auto Entity::addCInputComponent(CInput cInput) -> CInput& {
    auto& component = getCInputComponent();
    component = cInput;
    component.has = true;
    return component;
}
auto Entity::addCShapeComponent(CShape cShape) -> CShape& {
    auto& component = getCShapeComponent();
    component = cShape;
    component.has = true;
    return component;
}
auto Entity::addCTransformComponent(CTransform cTransform) -> CTransform& {
    auto& component = getCTransformComponent();
    component = cTransform;
    component.has = true;
    return component;
}
auto Entity::addCBoundingBoxComponent(CBoundingBox cBoundingBox) -> CBoundingBox& {
    auto& component = getCBoundingBoxComponent();
    component = cBoundingBox;
    component.has = true;
    return component;
}

auto Entity::getCInputComponent() -> CInput& {
    return std::get<CInput>(components);
}
auto Entity::getCShapeComponent() -> CShape& {
    return std::get<CShape>(components);
}
auto Entity::getCTransformComponent() -> CTransform& {
    return std::get<CTransform>(components);
}
auto Entity::getCBoundingBoxComponent() -> CBoundingBox& {
    return std::get<CBoundingBox>(components);
}

template<typename T>
auto Entity::removeComponent() -> void {
    getComponent<T>() = T();
}