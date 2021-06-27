#include "CycledSpringSystem.hpp"

namespace planwem {

CycledSpringSystem::CycledSpringSystem(std::size_t joints, double springRigidity,
                                       double springRelaxedLength)
    : SpringSystem(joints),
      springRigidity_(springRigidity),
      springRelaxedLength_(springRelaxedLength) {}

void CycledSpringSystem::addCycle(const std::vector<std::size_t> &cycle) {
    const std::size_t cycleLen = cycle.size();
    if (cycle.size() < 3) {
        throw std::invalid_argument("Cycle length must be at least 3");
    }
    for (std::size_t j : cycle) {
        checkHasNode(j);
    }
    for (std::size_t j = 0, nj = 1; j < cycleLen; ++j, ++nj) {
        std::size_t firstJoint = cycle[j];
        std::size_t secondJoint = cycle[nj % cycleLen];
        if (!hasSpring(firstJoint, secondJoint)) {
            addSpring(Spring{firstJoint, secondJoint, springRigidity_, springRelaxedLength_, true});
        }
    }

    const double polygonAngle = (M_PI * static_cast<double>(cycleLen - 2) / static_cast<double>(cycleLen));
    const double spacerLen = std::sqrt(2.0 * springRelaxedLength_ * springRelaxedLength_ * (1.0 - std::cos(polygonAngle)));

    for (std::size_t j = 0, nj = 2; j < cycleLen; ++j, ++nj) {
        std::size_t firstJoint = cycle[j];
        std::size_t secondJoint = cycle[nj % cycleLen];
        addSpring(Spring{firstJoint, secondJoint, springRigidity_, spacerLen, false});
    }
}

}  // namespace planwem
