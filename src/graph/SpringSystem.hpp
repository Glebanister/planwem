#pragma once

#include <deque>
#include <unordered_map>
#include <unordered_set>

#include "draw/Drawable.hpp"
#include "draw/GraphCanvas.hpp"
#include "shapes/Vec2.hpp"

namespace planwem {

struct Spring {
    std::size_t from, to;
    double rigidity;
    double relaxedLength;
    bool visible;
};

class SpringSystem : public Drawable {
   public:
    explicit SpringSystem(std::size_t joints);

    void addSpring(Spring);

    [[nodiscard]] bool hasNode(std::size_t) const noexcept;

    [[nodiscard]] bool hasSpring(std::size_t from, std::size_t to) const noexcept;

    void checkHasNode(std::size_t) const;

    void tick(double delta);

    void draw(GraphCanvas &canvas) override;

   private:
    std::deque<shapes::Vec2> joints_;
    std::deque<Spring> springs_;
    std::unordered_map<std::size_t, std::unordered_map<std::size_t, std::size_t>> springId_;
    std::vector<std::vector<std::size_t>> adj_;
    std::size_t ticks_ = 0;
    double timePassed_ = 0.0;
};

}  // namespace planwem
