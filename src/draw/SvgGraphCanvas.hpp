#pragma once

#include <filesystem>
#include <fstream>

#include "GraphCanvas.hpp"

namespace planwem {
class SvgGraphCanvas : GraphCanvas {
  public:
    SvgGraphCanvas(const std::filesystem::path &output);

    void draw(const Circle&) override;

    void draw(const Segment&) override;

    ~SvgGraphCanvas();

  private:
    std::filesystem::path outputPath;
    std::ofstream os;
};
} // namespace planwem
