#include "StdoutGraphCanvas.hpp"

#include <iostream>

namespace planwem {

std::ostream &operator<<(std::ostream &os, const shapes::Vec2 &p) {
    return os << "(" << p.x << ' ' << p.y << ")";
}

void StdoutGraphCanvas::draw(const shapes::Circle &circle) {
    std::cout << "Circle: {" << circle.center << ", " << circle.r << "}" << std::endl;
}

void StdoutGraphCanvas::draw(const shapes::Segment &segment) {
    std::cout << "Circle: {" << segment.a << ", " << segment.b << "}" << std::endl;
}

shapes::Vec2 StdoutGraphCanvas::size() const noexcept { return {512, 512}; }

}  // namespace planwem
