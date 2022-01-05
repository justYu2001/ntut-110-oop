#include <vector>
#include <string>

using std::vector;
using std::string;

#include "../src/pet.h"
#include "../src/dog.h"
#include "../src/cat.h"
#include "../src/algo.h"

TEST(MaxPet, CompareWeight) {
    vector<Pet *> petArray = {
        new Cat("Kitty", 3),
        new Dog("Money", 23),
        new Dog("Apollo", 12)
    };

    auto result = maxPet(petArray.begin(), petArray.end(), compareWeight);
    ASSERT_EQ("Money", (*result)->name());
    ASSERT_NEAR(23, (*result)->weight(), 0.01);
    for(int i = 0; i < petArray.size(); i++) {
        delete petArray[i];
    }
}

TEST(MaxPet, CompareLengthOfName) {
    vector<Pet *> petArray = {
        new Cat("Kitty", 3),
        new Dog("Money", 23),
        new Dog("Apollo", 12)
    };

    auto result = maxPet(petArray.begin(), petArray.end(), compareLengthOfName);
    ASSERT_EQ("Apollo", (*result)->name());
    ASSERT_NEAR(12, (*result)->weight(), 0.01);
    for(int i = 0; i < petArray.size(); i++) {
        delete petArray[i];
    }
}