#include "SvgGraphCanvas.hpp"
#include "util/Util.hpp"

namespace planwem {

SvgGraphCanvas::SvgGraphCanvas(const std::filesystem::path& output)
    : outputPath(output), os(output.string()) {
    os << "<?xml version=\"1.0\" standalone=\"no\"?>"
          "<svg width=\"512\" height=\"512\" style='background: white' version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">";
}

void SvgGraphCanvas::draw(const shapes::Circle& circle) {
    os << "<circle"
       << " cx=\"" << static_cast<int>(circle.center.x)
       << "\" cy=\"" << static_cast<int>(circle.center.y)
       << "\" r=\"" << static_cast<int>(circle.r) << "\"/>";
}

void SvgGraphCanvas::draw(const shapes::Segment& segment) {
    os << "<line "
       << "   x1=\"" << static_cast<int>(segment.a.x)
       << "\" y1=\"" << static_cast<int>(segment.a.y)
       << "\" x2=\"" << static_cast<int>(segment.b.x)
       << "\" y2=\"" << static_cast<int>(segment.b.y)
       << "\"  stroke=\"black\" stroke-width=\"3\"/>";
}

shapes::Vec2 SvgGraphCanvas::size() const noexcept {
    return {512, 512};
}

SvgGraphCanvas::~SvgGraphCanvas() {
    os << "</svg>";
}
} // namespace planwem
