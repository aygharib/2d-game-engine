#include "CShape.h"
#include "SFML/System/Vector2.hpp"
#include "Vec2.h"

#include <iostream>

CShape::CShape(float width, float height) : shape{sf::Vector2f{width, height}} {
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(width, height);
};