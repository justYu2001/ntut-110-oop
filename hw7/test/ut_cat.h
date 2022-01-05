#include <string>

#include "../src/pet.h"
#include "../src/cat.h"

using std::string;

TEST(Cat, Constructor) {
    string name = "Kitty";
    double weight = 2.3;
    Pet *cat = new Cat(name, weight);
    ASSERT_EQ("Kitty", cat->name());
    ASSERT_NEAR(2.3, cat->weight(), 0.001);
    delete cat;
}

TEST(Cat, ConstructorException) {
    string name = "Kitty";
    double weight = 1;
    ASSERT_THROW(Cat(name, weight), std::range_error);
}

TEST(Cat, Feed) {
    string name = "Kitty";
    double weight = 2.3;
    Pet *cat = new Cat(name, weight);
    cat->feed();
    ASSERT_NEAR(2.5, cat->weight(), 0.001);
    delete cat;
}

TEST(Cat, FeedExpection) {
    string name = "Kitty";
    double weight = 5.9;
    Pet *cat = new Cat(name, weight);
    ASSERT_THROW(cat->feed(), std::out_of_range);
    delete cat;
}