#include "Vec2.h"

Vec2::Vec2(float x, float y) : x{x}, y{y} {}

auto Vec2::operator == (const Vec2& rhs) const -> bool {
    return x == rhs.x && y == rhs.y;
}

auto Vec2::operator != (const Vec2& rhs) const -> bool {
    return x != rhs.x || y != rhs.y;
}

auto Vec2::operator + (const Vec2& rhs) const -> Vec2 {
    return Vec2{x + rhs.x, y + rhs.y};
}

auto Vec2::operator - (const Vec2& rhs) const -> Vec2 {
    return Vec2{x - rhs.x, y - rhs.y};
}

auto Vec2::operator * (const float value) const -> Vec2 {
    return Vec2{x * value, y * value};
}

auto Vec2::operator / (const float value) const -> Vec2 {
    return Vec2{x / value, y / value};
}

auto Vec2::operator += (const Vec2& rhs) -> void {
    x += rhs.x;
    y += rhs.y;
}

auto Vec2::operator -= (const Vec2& rhs) -> void {
    x -= rhs.x;
    x -= rhs.y;
}

auto Vec2::operator *= (const float value) -> void {
    x *= value;
    y *= value;
}

auto Vec2::operator /= (const float value) -> void {
    x /= value;
    y /= value;
}
