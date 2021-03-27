#include "SvgGraphCanvas.hpp"
#include "util/Util.hpp"

namespace planwem {

SvgGraphCanvas::SvgGraphCanvas(const std::filesystem::path& output)
    : outputPath(output), os(output.string()) {
    os << "<?xml version=\"1.0\" standalone=\"no\"?>"
          "<svg width=\"512\" height=\"512\" style='stroke-width: 0px; background: blue;' version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">";
}

void SvgGraphCanvas::draw(const Circle& circle) {
    os << "<circle cx=\"" << circle.center.x << "\" cy=\"" << circle.center.y << "\" r=\"" << circle.r << "\"/>";
}

void SvgGraphCanvas::draw(const Segment& segment) {
    os << "<line x1=\"" << segment.a.x << "\" x2=\"" << segment.b.x << "\" y1=\"" << segment.a.y << "\" y2=\"" << segment.b.y << "\"  stroke=\"black\" stroke-width=\"5\"/>";
}

SvgGraphCanvas::~SvgGraphCanvas() {
    os << "</svg>";
}
} // namespace planwem
