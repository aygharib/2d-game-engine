#pragma once

#include <memory>
#include <string>
#include <tuple>
#include <vector>

#include "CInput.h"
#include "CTransform.h"
#include "CShape.h"
#include "CBoundingBox.h"

using ComponentTuple = std::tuple<CTransform, CInput, CShape, CBoundingBox>;

enum class EntityTag {
    PLAYER,
    ENEMY
};

class Entity {
public:
    size_t id{0};
    EntityTag tag;
    bool active{true};
    ComponentTuple components{};

    Entity() = default;
    Entity(size_t id, EntityTag tag);

    auto destroy() -> void;

    template<typename T, typename... TArgs>
    auto addComponent(TArgs&&... args) -> T& {
        auto& component = getComponent<T>();
        component = T(std::forward<TArgs>(args)...);
        component.has = true;
        return component;
    }

    template<typename T>
    auto removeComponent() -> void {
        getComponent<T>() = T();
    }

    template<typename T>
    auto getComponent() -> T& {
        return std::get<T>(components);
    }

    template<typename T>
    auto hasComponent() -> bool {
        return getComponent<T>().has;
    }
};