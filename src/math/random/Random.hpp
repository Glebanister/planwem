#pragma once

#include <cstdint>
#include <random>

namespace planwem::math::random {

namespace detail {

static std::mt19937 rng(12);

}  // namespace detail

inline std::uint32_t randInt() { return detail::rng(); }

inline double randDouble() {
    std::uniform_real_distribution<double> uniform(0, 1);
    return uniform(detail::rng);
}

}  // namespace planwem::math::random
