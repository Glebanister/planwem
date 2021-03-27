#include "draw/StdoutGraphCanvas.hpp"
#include "draw/SvgGraphCanvas.hpp"
#include "graph/SpringGraph.hpp"

#include <iostream>

using namespace planwem;

int main() {
    SpringGraph graph{6, 1.0, 0.1};
    StdoutGraphCanvas debug;
    // graph.addEdge(0, 1);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);
    graph.addEdge(5, 0);
    graph.addEdge(3, 0);

    graph.draw(debug);

    std::cout << std::endl;

    for (int i = 0; i < 10; ++i) {
        graph.tick(1.0);
        graph.draw(debug);
    }

    SvgGraphCanvas canvas(std::filesystem::path("graph.svg"));

    graph.draw(canvas);
}
