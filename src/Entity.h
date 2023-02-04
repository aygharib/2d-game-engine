#pragma once

#include <memory>
#include <string>
#include <vector>

#include "CInput.h"
#include "CCollision.h"
#include "CShape.h"
#include "CTransform.h"

class Entity {
public:
    bool alive = true;

    std::shared_ptr<CInput>     cInput;
    std::shared_ptr<CCollision> cCollision;
    std::shared_ptr<CShape>     cShape;
    std::shared_ptr<CTransform> cTransform;

    Entity(std::string tag, size_t id);

    auto getTag() -> const std::string&;
private:
    const size_t      id    = 0;
    const std::string tag   = "Default";
};