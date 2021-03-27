#pragma once

#include "GraphCanvas.hpp"

namespace planwem {
class Drawable {
    virtual void draw(GraphCanvas&) = 0;
};
} // namespace planwem
