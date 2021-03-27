#pragma once

#include "GraphCanvas.hpp"

namespace planwem {
class StdoutGraphCanvas : public GraphCanvas {
  public:
    void draw(const shapes::Circle&) override;

    void draw(const shapes::Segment&) override;

    shapes::Vec2 size() const noexcept override;
};
} // namespace planwem
