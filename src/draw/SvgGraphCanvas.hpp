#pragma once

#include <filesystem>
#include <fstream>

#include "GraphCanvas.hpp"

namespace planwem {
class SvgGraphCanvas : public GraphCanvas {
  public:
    SvgGraphCanvas(const std::filesystem::path& output);

    void draw(const shapes::Circle&) override;

    void draw(const shapes::Segment&) override;

    shapes::Vec2 size() const noexcept override;

    void flush() noexcept;

    bool isContinuing() const noexcept;

    void checkContinuing() const;

    ~SvgGraphCanvas();

  private:
    std::filesystem::path outputPath;
    std::ofstream os;
    bool continuing = true;
};
} // namespace planwem
