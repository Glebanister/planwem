#include "draw/StdoutGraphCanvas.hpp"
#include "draw/SvgGraphCanvas.hpp"
#include "graph/SpringSystem.hpp"

using namespace planwem;

int main() {
    const std::size_t K = 11;
    const double RIG = 0.1;
    const double L = 0.33;

    SpringSystem graph{K};

    auto addSpring = [&](std::size_t from, std::size_t to) { graph.addSpring({from, to, RIG, L, true}); };

    addSpring(0, 1);
    addSpring(1, 2);
    addSpring(2, 3);
    addSpring(3, 4);
    addSpring(4, 5);
    addSpring(5, 6);
    addSpring(6, 7);
    addSpring(7, 8);
    addSpring(8, 9);
    addSpring(9, 10);
    addSpring(10, 0);
    addSpring(10, 1);
    addSpring(7, 2);
    addSpring(5, 2);

     auto zeros = [](int x) {
         std::size_t len = std::to_string(x).size();
         std::string res;
         for (int i = 0; i < 3 - len; ++i) {
             res += '0';
         }
         return res;
     };

    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 20; ++j) {
            graph.tick(0.02);
        }
         SvgGraphCanvas canvas(std::filesystem::path("tmp/" + zeros(i + 1) + std::to_string(i + 1)
         + ".svg")); graph.draw(canvas);
    }

    SvgGraphCanvas canvas("temp.svg");
    graph.draw(canvas);
}
