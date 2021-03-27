#pragma once

#include <cmath>

#include "math/random/Random.hpp"

namespace planwem {
namespace shapes {

struct Vec2 {
    double x, y;

    inline static Vec2 random() {
        return {math::random::randDouble(), math::random::randDouble()};
    }
};

inline double abs(const Vec2& v) noexcept {
    return std::sqrt(v.x * v.x + v.y * v.y);
}

inline Vec2 operator+(const Vec2& a, const Vec2& b) {
    return {a.x + b.x,
            a.y + b.y};
}

inline Vec2 operator-(const Vec2& a, const Vec2& b) {
    return {a.x - b.x,
            a.y - b.y};
}

inline Vec2 operator*(const Vec2& a, double k) {
    return {a.x * k,
            a.y * k};
}

inline Vec2 operator/(const Vec2& a, double k) {
    return {a.x / k,
            a.y / k};
}

inline Vec2& operator+=(Vec2& a, const Vec2& b) {
    a.x += b.x;
    a.y += b.y;
    return a;
}

inline Vec2& operator-=(Vec2& a, const Vec2& b) {
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

inline Vec2& operator*=(Vec2& a, double k) {
    a.x *= k;
    a.y *= k;
    return a;
}

inline Vec2& operator/=(Vec2& a, double k) {
    a.x /= k;
    a.y /= k;
    return a;
}

inline auto cmpX() {
    return [](const Vec2& a, const Vec2& b) { return a.x < b.x; };
}

inline auto cmpY() {
    return [](const Vec2& a, const Vec2& b) { return a.y < b.y; };
}
} // namespace shapes
} // namespace planwem
