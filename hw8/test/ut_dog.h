#include "../src/dog.h"
#include "../src/pet.h"

#include <stdexcept>

using std::string;

class DogTest : public ::testing::Test {
protected:
    void SetUp() override {
        ASSERT_EQ(0, Pet::amount());
        ASSERT_EQ(0, Dog::amount());
    }

    void TearDown() override {
        ASSERT_EQ(0, Pet::amount());
        ASSERT_EQ(0, Dog::amount());
    }

    string name = "Money";
    const double DELTA = 0.001;
};


TEST_F(DogTest, AmountConstructor) {
  Dog dog("Dog", 30);
  ASSERT_EQ(1, Dog::amount());
}

TEST_F(DogTest, AmountCopyConstructor) {
  Dog dog_1("Dog", 30);
  Dog dog_2 = dog_1;
  ASSERT_EQ(2, Dog::amount());
}

TEST_F(DogTest, AmountPolymorphism) {
  Pet * pet = new Dog("Dog", 30);
  ASSERT_EQ(1, Pet::amount());
  ASSERT_EQ(1, Dog::amount());
  delete pet;
}

TEST_F(DogTest, Constructor) {
    double weight = 11;
    Dog dog(name, weight);
    ASSERT_EQ("DOG", dog.kind());
    ASSERT_EQ("Money", dog.name());
    ASSERT_NEAR(11, dog.weight(), DELTA);
}

TEST_F(DogTest, ConstructorException) {
    double weight = 1;
    ASSERT_THROW(Dog(name, weight), std::range_error);
}

TEST_F(DogTest, Feed) {
    double weight = 11;
    Dog dog(name, weight);
    dog.feed();
    ASSERT_NEAR(11.8, dog.weight(), DELTA);
}

TEST_F(DogTest, FeedExpection) {
    double weight = 49.5;
    Dog dog(name, weight);
    ASSERT_THROW(dog.feed(), std::out_of_range);
}