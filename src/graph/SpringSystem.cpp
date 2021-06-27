#include "SpringSystem.hpp"

#include <algorithm>
#include <stdexcept>

namespace planwem {

SpringSystem::SpringSystem(std::size_t joints) : joints_(joints), adj_(joints) {
    for (shapes::Vec2 &crd : joints_) {
        crd = shapes::Vec2::random();
    }
}

bool SpringSystem::hasNode(std::size_t v) const noexcept { return v <= joints_.size(); }

void SpringSystem::checkHasNode(std::size_t v) const {
    if (hasNode(v)) {
        return;
    }
    throw std::invalid_argument("Impossible to access node " + std::to_string(v) +
                                " in graph of size " + std::to_string(joints_.size()));
}

void SpringSystem::addSpring(Spring s) {
    checkHasNode(s.from);
    checkHasNode(s.to);
    springs_.push_back(s);
    adj_[s.from].push_back(s.to);
    adj_[s.to].push_back(s.from);
    springId_[s.from][s.to] = springs_.size() - 1;
    springId_[s.to][s.from] = springs_.size() - 1;
}

void SpringSystem::tick(double delta) {
    using namespace shapes;
    if (joints_.empty()) {
        return;
    }
    std::deque<Vec2> jointForces(joints_.size(), {0.0, 0.0});

    for (const Spring &spring : springs_) {
        Vec2 a0 = joints_[spring.from], ai = joints_[spring.to];
        Vec2 Fi =
            ((ai - a0) / abs(ai - a0)) * spring.rigidity * (abs(ai - a0) - spring.relaxedLength);
        jointForces[spring.from] += Fi * 2;
        jointForces[spring.to] -= Fi * 2;
    }

    for (std::size_t jointI = 0; jointI < joints_.size(); ++jointI) {
        joints_[jointI] += jointForces[jointI] * delta;
    }

    ticks_ += 1;
    timePassed_ += delta;
}

void SpringSystem::draw(GraphCanvas &canvas) {
    using namespace shapes;

    if (joints_.empty()) {
        return;
    }
    std::deque<Vec2> norm = joints_;

    Vec2 min = {std::min_element(joints_.begin(), joints_.end(), cmpX())->x,
                std::min_element(joints_.begin(), joints_.end(), cmpY())->y};

    Vec2 max = {std::max_element(joints_.begin(), joints_.end(), cmpX())->x,
                std::max_element(joints_.begin(), joints_.end(), cmpY())->y};

    // Vec2 diff = max - min;

    // for (Vec2& v : norm) {
    //     v.x = (v.x - min.x) / diff.x;
    //     v.y = (v.y - min.y) / diff.y;
    // }

    const Vec2 canSize = canvas.size();

    for (const Vec2 &v : norm) {
        canvas.draw(Circle{{v.x * canSize.x, v.y * canSize.y}, 7.0});
    }

    for (const Spring &spring : springs_) {
        if (!spring.visible) {
            continue;
        }
        const Vec2 from = norm[spring.from];
        const Vec2 to = norm[spring.to];
        canvas.draw(Segment{{from.x * canSize.x, from.y * canSize.y},
                            {to.x * canSize.x, to.y * canSize.y}});
    }
}

bool SpringSystem::hasSpring(std::size_t from, std::size_t to) const noexcept {
    if (!hasNode(from) || !hasNode(to)) {
        return false;
    }
    auto springsFrom = springId_.find(from);
    if (springsFrom == springId_.end()) {
        return false;
    }
    return springsFrom->second.find(to) != springsFrom->second.end();
}

}  // namespace planwem
