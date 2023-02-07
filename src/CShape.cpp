#include "CShape.h"
#include "Vec2.h"

#include <iostream>
#include <SFML/System/Vector2.hpp>

CShape::CShape(float width, float height) : shape{sf::Vector2f{width, height}} {
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(width, height);
};