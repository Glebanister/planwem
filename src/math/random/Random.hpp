#pragma once

#include <cstdint>
#include <random>

namespace planwem {

namespace math {
namespace random {

namespace detail {
static std::mt19937 rng(1);
} // namespace detail

inline std::uint32_t randInt() {
    return detail::rng();
}

inline double randDouble() {
    std::uniform_real_distribution<double> unif(0, 1);
    return unif(detail::rng);
}

} // namespace random
} // namespace math
} // namespace planwem
