#pragma once

#include "shapes/Circle.hpp"
#include "shapes/Segment.hpp"

namespace planwem {

class GraphCanvas {
  public:
    virtual void draw(const shapes::Circle&) = 0;
    virtual void draw(const shapes::Segment&) = 0;
    virtual shapes::Vec2 size() const noexcept = 0;
};

} // namespace planwem
