#pragma once

#include "shapes/Circle.hpp"
#include "shapes/Segment.hpp"

namespace planwem {

class GraphCanvas {
  public:
    virtual void draw(const Circle&) = 0;
    virtual void draw(const Segment&) = 0;
};

} // namespace planwem
