#pragma once

#include <deque>
#include <unordered_set>

#include "draw/Drawable.hpp"
#include "draw/GraphCanvas.hpp"
#include "shapes/Vec2.hpp"

namespace planwem {
struct Edge {
    std::size_t to;
    double k;
    bool visible;
};

class SpringGraph : public Drawable {
  public:
    using node = std::size_t;

  public:
    SpringGraph(std::size_t nodes,
                double springK,
                double resistK,
                double springRelax);

    void addSpring(node, node);

    void addResist(node, node);

    void addEdge(node, node, double weight, bool visible);

    void addSprings(const std::vector<std::pair<node, node>>&);

    bool hasNode(node) const noexcept;

    void checkHasNode(node) const;

    void tick(double delta);

    void draw(GraphCanvas& canvas) override;

  private:
    const double springK_;
    const double resistK_;
    const double springRelax_;
    std::deque<shapes::Vec2> nodes_;
    std::deque<std::vector<Edge>> adj_;
    std::size_t ticks = 0;
    double timePassed = 0.0;
};
} // namespace planwem
