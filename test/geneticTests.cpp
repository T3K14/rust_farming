#include <gtest/gtest.h>
#include "../plant.hpp"

TEST(TestSuite1, Test1) {

    Plant a("WWXXHY");
    
    Plant b("XXXGGG");
    Plant c("WWGGGW");
    Plant d("YGGWWX");
    Plant e("YGGWXX");

    a.addNeighbour(b);
    a.addNeighbour(c);
    a.addNeighbour(d);
    a.addNeighbour(e);
    a.crossbread();
    auto res = a.getGenes();
    auto expected = std::array<Gene, 6> {Y, G, G, W, G, X};

    EXPECT_EQ(expected, res);
    // a.printGenes();
}

TEST(TestSuite1, Test2) {
    Plant a("XXXXXX");

    Plant b("YGYXHW");
    Plant c("GHYYYW");
    Plant d("XGGWGX");
    Plant e("WYYHYX");
    Plant f("XGGWYH");
    Plant g("XGYXHG");
    Plant h("GHYXWX");
    Plant i("XYYXHW");

    a.addNeighbour(b);
    a.addNeighbour(c);
    a.addNeighbour(d);
    a.addNeighbour(e);
    a.addNeighbour(f);
    a.addNeighbour(g);
    a.addNeighbour(h);
    a.addNeighbour(i);
    a.crossbread();
    auto res = a.getGenes();

    EXPECT_EQ(true, false);

    a.printGenes();
}