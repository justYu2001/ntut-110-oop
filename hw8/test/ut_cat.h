#include "../src/cat.h"
#include "../src/pet.h"

#include <stdexcept>

using std::string;

class CatTest : public ::testing::Test {
protected:
    void SetUp() override {
        ASSERT_EQ(0, Pet::amount());
        ASSERT_EQ(0, Cat::amount());
    }

    void TearDown() override {
        ASSERT_EQ(0, Pet::amount());
        ASSERT_EQ(0, Cat::amount());
    }

    string name = "Kitty";
    const double DELTA = 0.001;
};


TEST_F(CatTest, AmountConstructor) {
  Cat cat("Cat", 3);
  ASSERT_EQ(1, Cat::amount());
}

TEST_F(CatTest, AmountCopyConstructor) {
  Cat cat_1("Cat", 3);
  Cat cat_2 = cat_1;
  ASSERT_EQ(2, Cat::amount());
}

TEST_F(CatTest, AmountPolymorphism) {
  Pet * pet = new Cat("Cat", 3);
  ASSERT_EQ(1, Pet::amount());
  ASSERT_EQ(1, Cat::amount());
  delete pet;
}

TEST_F(CatTest, Constructor) {
    double weight = 2.3;
    Cat cat(name, weight);
    ASSERT_EQ("CAT", cat.kind());
    ASSERT_EQ("Kitty", cat.name());
    ASSERT_NEAR(2.3, cat.weight(), DELTA);
}

TEST_F(CatTest, ConstructorException) {
    double weight = 1;
    ASSERT_THROW(Cat(name, weight), std::range_error);
}

TEST_F(CatTest, Feed) {
    double weight = 2.3;
    Cat cat(name, weight);
    cat.feed();
    ASSERT_NEAR(2.5, cat.weight(), DELTA);
}

TEST_F(CatTest, FeedExpection) {
    double weight = 5.9;
    Cat cat(name, weight);
    ASSERT_THROW(cat.feed(), std::out_of_range);
}
