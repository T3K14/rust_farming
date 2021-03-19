#include <gtest/gtest.h>
#include <array>
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
    std::array<Gene, 6> expected; // {Y, G, G, W, G, X};

    expected[0].setGene(Gene('Y'));
    expected[1].setGene(Gene('G'));
    expected[2].setGene(Gene('G'));
    expected[3].setGene(Gene('W'));
    expected[4].setGene(Gene('G'));
    expected[5].setGene(Gene('X'));


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

    std::array<Gene, 6> expected;

    expected[0].setGene(Gene('X'));
    expected[1].setGene(Gene('G'));
    expected[2].setGene(Gene('Y'));
    expected[3].setGene(Gene('X'));
    expected[4].setGeneProb(Gene('Y'), Gene('H'));
    expected[5].setGeneProb(Gene('X'), Gene('W'));

    // a.printGenes();

    EXPECT_EQ(expected, res);

    // a.printGenes();
}

TEST(TestSuite2, Test3) {

    Plant a("YYYWYX");
    
    Plant b("GGHGHY");
    Plant c("HHGGGY");

    a.addNeighbour(b);
    a.addNeighbour(c);

    a.crossbread();
    auto res = a.getGenes();
    std::array<Gene, 6> expected; 
    expected[0].setGene(Gene('Y'));
    expected[1].setGene(Gene('Y'));
    expected[2].setGene(Gene('Y'));
    expected[3].setGene(Gene('G'));
    expected[4].setGene(Gene('Y'));
    expected[5].setGene(Gene('Y'));


    EXPECT_EQ(expected, res);
    // a.printGenes();
}