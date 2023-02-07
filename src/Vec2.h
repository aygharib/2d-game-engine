#pragma once

class Vec2 {
public:
    float x{0.F};
    float y{0.F};

    Vec2() = default;
    Vec2(float x, float y);

    // Overload copy assignment constructor
    Vec2(const Vec2& copy);

    auto operator == (const Vec2& rhs) const -> bool;
    auto operator != (const Vec2& rhs) const -> bool;

    auto operator + (const Vec2& rhs)  const -> Vec2;
    auto operator - (const Vec2& rhs)  const -> Vec2;
    auto operator * (float value)      const -> Vec2;
    auto operator / (float value)      const -> Vec2;

    auto operator += (const Vec2& rhs) -> void;
    auto operator -= (const Vec2& rhs) -> void;
    auto operator *= (float value)     -> void;
    auto operator /= (float value)     -> void;

    [[nodiscard]] auto dist(const Vec2& rhs) const -> float;
    [[nodiscard]] auto length()              const -> float;
    [[nodiscard]] auto normalize()           const -> Vec2;
};
