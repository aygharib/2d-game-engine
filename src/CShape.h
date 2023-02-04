#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics.hpp>

class CShape {
public:
    sf::CircleShape shape;

    CShape(float radius, size_t points) : shape(radius, points) {
        shape.setFillColor(sf::Color::White);
        shape.setOrigin(radius, radius);
    };
};