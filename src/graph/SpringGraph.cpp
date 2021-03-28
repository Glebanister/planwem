#include <algorithm>
#include <stdexcept>

#include "SpringGraph.hpp"

namespace planwem {

SpringGraph::SpringGraph(std::size_t nodes,
                         double springK,
                         double resistK,
                         double springRelax)
    : springK_(springK),
      resistK_(resistK),
      springRelax_(springRelax),
      nodes_(nodes),
      adj_(nodes) {
    for (shapes::Vec2& crd : nodes_) {
        crd = shapes::Vec2::random();
    }
}

bool SpringGraph::hasNode(node v) const noexcept {
    return v <= nodes_.size();
}

void SpringGraph::checkHasNode(node v) const {
    if (hasNode(v)) {
        return;
    }
    throw std::invalid_argument("Impossible to access node " +
                                std::to_string(v) +
                                " in graph of size " +
                                std::to_string(nodes_.size()));
}

void SpringGraph::addEdge(node a, node b, double k, bool vis) {
    checkHasNode(a);
    checkHasNode(b);
    adj_.at(a).push_back({b, k, vis});
    adj_.at(b).push_back({a, k, vis});
}

void SpringGraph::addSpring(node a, node b) {
    addEdge(a, b, springK_, true);
}

void SpringGraph::addResist(node a, node b) {
    addEdge(a, b, resistK_, false);
}

void SpringGraph::addSprings(const std::vector<std::pair<node, node>>& list) {
    for (const auto& [a, b] : list) {
        addSpring(a, b);
    }
}

void SpringGraph::tick(double delta) {
    using namespace shapes;
    if (nodes_.empty()) {
        return;
    }
    std::deque<Vec2> newNodes = nodes_;
    for (node v = 0; v < nodes_.size(); ++v) {
        Vec2 F = {0, 0};
        for (Edge adj : adj_[v]) {
            Vec2 ai = nodes_[adj.to],
                 a0 = nodes_[v];
            Vec2 Fi = ((ai - a0) / abs(ai - a0)) * adj.k * (abs(ai - a0) - springRelax_);
            F += Fi;
        }
        newNodes[v] = nodes_[v] + F * delta;
    }
    nodes_ = std::move(newNodes);
    ticks += 1;
    timePassed += delta;
}

void SpringGraph::draw(GraphCanvas& canvas) {
    using namespace shapes;

    if (nodes_.empty()) {
        return;
    }
    std::deque<Vec2> norm = nodes_;

    Vec2 min = {std::min_element(nodes_.begin(), nodes_.end(), cmpX())->x,
                std::min_element(nodes_.begin(), nodes_.end(), cmpY())->y};

    Vec2 max = {std::max_element(nodes_.begin(), nodes_.end(), cmpX())->x,
                std::max_element(nodes_.begin(), nodes_.end(), cmpY())->y};

    // Vec2 diff = max - min;

    // for (Vec2& v : norm) {
    //     v.x = (v.x - min.x) / diff.x;
    //     v.y = (v.y - min.y) / diff.y;
    // }

    const Vec2 canSize = canvas.size();

    for (const Vec2& v : norm) {
        canvas.draw(
            Circle{
                {v.x * canSize.x, v.y * canSize.y},
                10.0});
    }

    for (node v = 0; v < nodes_.size(); ++v) {
        for (Edge adj : adj_[v]) {
            if (!adj.visible) {
                continue;
            }
            const Vec2 from = norm[v];
            const Vec2 to = norm[adj.to];
            canvas.draw(
                Segment{
                    {from.x * canSize.x, from.y * canSize.y},
                    {to.x * canSize.x, to.y * canSize.y}});
        }
    }
}

} // namespace planwem
