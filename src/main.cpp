#include "draw/StdoutGraphCanvas.hpp"
#include "draw/SvgGraphCanvas.hpp"
#include "graph/CycledSpringSystem.hpp"

using namespace planwem;

int main() {
    const std::size_t K = 11;
    const double RIG = 0.1;
    const double L = 0.33;

    CycledSpringSystem graph{K, RIG, L};

    graph.addCycle({1, 2, 3, 4, 5});
    graph.addCycle({4, 6, 5});
    graph.addCycle({0, 7, 3, 2});
    graph.addCycle({7, 8, 10, 0});
    graph.addCycle({8, 9, 10});

     auto zeros = [](int x) {
         std::size_t len = std::to_string(x).size();
         std::string res;
         for (int i = 0; i < 3 - len; ++i) {
             res += '0';
         }
         return res;
     };

    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            graph.tick(0.02);
        }
         SvgGraphCanvas canvas(std::filesystem::path("tmp/" + zeros(i + 1) + std::to_string(i + 1)
         + ".svg")); graph.draw(canvas);
    }

    SvgGraphCanvas canvas("temp.svg");
    graph.draw(canvas);
}
