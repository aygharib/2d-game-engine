#pragma once

#include "Component.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics.hpp>

class CShape : public Component {
public:
    sf::RectangleShape shape{};

    CShape() = default;
    CShape(float width, float height);
};