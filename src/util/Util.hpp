#pragma once

#include <ostream>

namespace planwem::util {
template <typename... Args>
void print(std::ostream& os, Args&&... args) {
    (os << ... << std::forward(args));
}
} // namespace planwem::util
