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

class Entity {
public:
    size_t id                {0};
    std::string tag          {"default"};
    bool active              {true};
    ComponentTuple components{};

    Entity() = default;
    Entity(size_t id, std::string tag);

    auto destroy() -> void;

    template<typename T>
    auto hasComponent() -> bool;

    auto addCInputComponent(CInput cInput) -> CInput&;
    auto addCShapeComponent(CShape cShape) -> CShape&;
    auto addCTransformComponent(CTransform cTransform) -> CTransform&;
    auto addCBoundingBoxComponent(CBoundingBox cBoundingBox) -> CBoundingBox&;

    auto getCInputComponent() -> CInput&;
    auto getCShapeComponent() -> CShape&;
    auto getCTransformComponent() -> CTransform&;
    auto getCBoundingBoxComponent() -> CBoundingBox&;

    template<typename T>
    auto removeComponent() -> void;
};
