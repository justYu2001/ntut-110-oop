#include "../src/cat.h"

#include <string>

using std::string;

// add your test here

TEST(Cat, CatGetName1) {
    string name = "Kitty";
    double weight = 3.0;
    Cat cat(name, weight);
    string result = cat.getName();
    EXPECT_TRUE(name == result);
}

TEST(Cat, CatGetName2) {
    string name = "Lilly";
    double weight = 2.8;
    Cat cat(name, weight);
    string result = cat.getName();
    EXPECT_TRUE(name == result);
}

TEST(Cat, CatGetWeight1) {
    string name = "Kitty";
    double weight = 3.0;
    Cat cat(name, weight);
    double result = cat.getWeight();
    EXPECT_NEAR(3.0, result, 0.001);
}

TEST(Cat, CatGetWeight2) {
    string name = "Lilly";
    double weight = 2.8;
    Cat cat(name, weight);
    double result = cat.getWeight();
    EXPECT_NEAR(2.8, result, 0.001);
}

TEST(Cat, CatAddNewToy1) {
    string name = "Kitty";
    double weight = 3.0;
    Cat cat(name, weight);
    cat.addNewToy("ball");
    EXPECT_TRUE("ball" == cat.getToy(0));
}

TEST(Cat, CatAddNewToy2) {
    string name = "Lilly";
    double weight = 2.8;
    Cat cat(name, weight);
    cat.addNewToy("cat teaser wand");
    EXPECT_TRUE("cat teaser wand" == cat.getToy(0));
}

TEST(Cat, CatGetToy1) {
    string name = "Kitty";
    double weight = 3.0;
    Cat cat(name, weight);
    cat.addNewToy("ball");
    cat.addNewToy("cat teaser wand");
    EXPECT_TRUE("ball" == cat.getToy(0));
    EXPECT_TRUE("cat teaser wand" == cat.getToy(1));
}

TEST(Cat, CatGetToy2) {
    string name = "Lilly";
    double weight = 2.8;
    Cat cat(name, weight);
    cat.addNewToy("cat teaser wand");
    cat.addNewToy("catnip mice");
    cat.addNewToy("ball");
    EXPECT_TRUE("cat teaser wand" == cat.getToy(0));
    EXPECT_TRUE("catnip mice" == cat.getToy(1));
    EXPECT_TRUE("catnip mice" == cat.getToy(1));
    EXPECT_TRUE("ball" == cat.getToy(2));
}