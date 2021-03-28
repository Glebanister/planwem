#include "draw/StdoutGraphCanvas.hpp"
#include "draw/SvgGraphCanvas.hpp"
#include "graph/SpringGraph.hpp"

using namespace planwem;

int main() {
    const std::size_t K = 11;

    SpringGraph graph{K, 0.3, 0.0, 0.33};

    graph.addSprings({
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5},
        {5, 6},
        {6, 7},
        {7, 8},
        {8, 9},
        {9, 10},
        {10, 0},
        {10, 1},
        {7, 2},
        {5, 2},
    });

    for (size_t i = 0; i < K; ++i) {
        for (size_t j = i + 1; j < K; ++j) {
            graph.addResist(i, j);
        }
    }

    // auto zeros = [](int x) {
    //     int len = std::to_string(x).size();
    //     std::string res = "";
    //     for (int i = 0; i < 3 - len; ++i) {
    //         res += '0';
    //     }
    //     return res;
    // };

    for (int i = 0; i < 300; ++i) {
        graph.tick(0.1);
        // SvgGraphCanvas canvas(std::filesystem::path("tmp/" + zeros(i + 1) + std::to_string(i + 1) + ".svg"));
        // graph.draw(canvas);
    }

    SvgGraphCanvas canvas(std::filesystem::path("assets/graph.svg"));
    graph.draw(canvas);
}
