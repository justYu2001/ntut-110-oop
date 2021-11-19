#include "../src/cat.h"
#include "../src/toy.h"

#include <string>

using std::string;

// add your test here

TEST(Cat, CatConstructor) {
    string name = "Lilly";
    double weight = 12.8;
    Cat cat(name, weight);
    EXPECT_EQ("Lilly", cat.getName());
    EXPECT_NEAR(12.8, cat.getWeight(), 0.001);
}

TEST(Cat, CatCopyConstructor) {
    string name = "Kitty";
    double weight = 13.0;
    Cat cat1(name, weight);
    Cat cat2(cat1);
    EXPECT_EQ("Kitty", cat2.getName());
    EXPECT_NEAR(13.0, cat2.getWeight(), 0.001);
}

TEST(Cat, CatCopyAssignment) {
    string name = "Lilly";
    double weight = 12.8;
    Cat cat1(name, weight);
    Cat cat2;
    cat2 = cat1;
    EXPECT_EQ("Lilly", cat2.getName());
    EXPECT_NEAR(12.8, cat2.getWeight(), 0.001);
}

TEST(Cat, CatAddNewToy) {
    string name = "Kitty";
    double weight = 13.0;
    Cat cat(name, weight);
    Toy ball("ball");
    cat.addNewToy(ball);
    EXPECT_EQ("ball", cat.getToy(0).getName());
}

TEST(Cat, CatGetToy) {
    string name = "Lilly";
    double weight = 12.8;
    Cat cat(name, weight);
    Toy catTeaserWand("cat teaser wand");
    Toy ball("ball");
    cat.addNewToy(catTeaserWand);
    cat.addNewToy(ball);
    EXPECT_EQ("cat teaser wand", cat.getToy(0).getName());
    EXPECT_EQ("ball", cat.getToy(1).getName());
}

TEST(Cat, CatIsHeavierThan) {
    string nameOfCat1 = "Kitty";
    double weightOfCat1 = 13.0;
    Cat cat1(nameOfCat1, weightOfCat1);
    string nameOfCat2 = "Lilly";
    double weightOfCat2 = 12.8;
    Cat cat2(nameOfCat2, weightOfCat2);
    EXPECT_TRUE(cat1.isHeavierThan(cat2));
}