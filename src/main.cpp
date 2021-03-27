#include "draw/StdoutGraphCanvas.hpp"
#include "draw/SvgGraphCanvas.hpp"
#include "graph/SpringGraph.hpp"

using namespace planwem;

int main() {
    SpringGraph graph{11, 0.2, 0.01};

    graph.addEdges({
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

    SvgGraphCanvas canvas(std::filesystem::path("graph.svg"));
    graph.draw(canvas);
}
