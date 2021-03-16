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


    EXPECT_EQ(true, false);
    a.printGenes();

}