#include <string>

#include "../src/pet.h"
#include "../src/dog.h"

using std::string;

TEST(Dog, Constructor) {
    string name = "Money";
    double weight = 11;
    Pet *dog = new Dog(name, weight);
    ASSERT_EQ("Money", dog->name());
    ASSERT_NEAR(11, dog->weight(), 0.001);
    delete dog;
}

TEST(Dog, ConstructorException) {
    string name = "Money";
    double weight = 1;
    ASSERT_THROW(Dog(name, weight), std::range_error);
}

TEST(Dog, Feed) {
    string name = "Money";
    double weight = 11;
    Pet *dog = new Dog(name, weight);
    dog->feed();
    ASSERT_NEAR(11.8, dog->weight(), 0.001);
    delete dog;
}

TEST(Dog, FeedExpection) {
    string name = "Money";
    double weight = 49.5;
    Pet *dog = new Dog(name, weight);
    ASSERT_THROW(dog->feed(), std::out_of_range);
    delete dog;
}