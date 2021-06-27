#pragma once

#include "SpringSystem.hpp"

namespace planwem {

class CycledSpringSystem : public SpringSystem {
   public:
    explicit CycledSpringSystem(std::size_t joints,
                                double springRigidity,
                                double springRelaxedLength);

    void addCycle(const std::vector<std::size_t> &cycle);

   private:
    const double springRigidity_;
    const double springRelaxedLength_;
};

}  // namespace planwem
