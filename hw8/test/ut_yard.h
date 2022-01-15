#include "../src/cat.h"
#include "../src/dog.h"
#include "../src/pet.h"
#include "../src/yard.h"

#include <gtest/gtest.h>
#include <vector>

using std::vector;

class YardTest : public ::testing::Test {
protected:
    void SetUp() override {
        ASSERT_EQ(0, Pet::amount());
        ASSERT_EQ(0, Cat::amount());
        ASSERT_EQ(0, Dog::amount());
    }

    void TearDown() override {
        ASSERT_EQ(0, Pet::amount());
        ASSERT_EQ(0, Cat::amount());
        ASSERT_EQ(0, Dog::amount());
    }

    const double DELTA = 0.001;
};

bool weightUnderThirty(Pet *pet) {
    return pet->weight() < 30;
}

TEST_F(YardTest, GetPetWithConditionNormal) {
    Yard yard;
    yard.addPet(new Cat("Kitty", 3));
    yard.addPet(new Dog("Money", 23));
    yard.addPet(new Dog("Apollo", 12));
    vector<Pet *> pets;
    pets = yard.getPetWithCondition(weightUnderThirty);
    ASSERT_EQ("Kitty", pets[0]->name());
    ASSERT_NEAR(3, pets[0]->weight(), DELTA);
    ASSERT_EQ("Money", pets[1]->name());
    ASSERT_NEAR(23, pets[1]->weight(), DELTA);
    ASSERT_EQ("Apollo", pets[2]->name());
    ASSERT_NEAR(12, pets[2]->weight(), DELTA);
}

class weightOverOne {
public:
    weightOverOne() {}

    bool operator()(Pet *pet) {
        return pet->weight() > 1;
    }
};

TEST_F(YardTest, GetPetWithConditionFunctor) {
    Yard yard;
    yard.addPet(new Cat("Kitty", 3));
    yard.addPet(new Dog("Money", 23));
    yard.addPet(new Dog("Apollo", 12));
    vector<Pet *> pets;
    pets = yard.getPetWithCondition(weightOverOne());
    ASSERT_EQ("Kitty", pets[0]->name());
    ASSERT_NEAR(3, pets[0]->weight(), DELTA);
    ASSERT_EQ("Money", pets[1]->name());
    ASSERT_NEAR(23, pets[1]->weight(), DELTA);
    ASSERT_EQ("Apollo", pets[2]->name());
    ASSERT_NEAR(12, pets[2]->weight(), DELTA);
}

TEST_F(YardTest, GetPetWithConditionLambda) {
    Yard yard;
    yard.addPet(new Cat("Kitty", 3));
    yard.addPet(new Dog("Money", 23));
    yard.addPet(new Dog("Apollo", 12));
    vector<Pet *> pets;
    pets = yard.getPetWithCondition(
        [](Pet *pet) {
            return pet->weight() < 30;
        }
    );
    ASSERT_EQ("Kitty", pets[0]->name());
    ASSERT_NEAR(3, pets[0]->weight(), DELTA);
    ASSERT_EQ("Money", pets[1]->name());
    ASSERT_NEAR(23, pets[1]->weight(), DELTA);
    ASSERT_EQ("Apollo", pets[2]->name());
    ASSERT_NEAR(12, pets[2]->weight(), DELTA);
}

TEST_F(YardTest, CopyConstructor) {
    Yard yard1;
    yard1.addPet(new Cat("Kitty", 3));
    yard1.addPet(new Dog("Money", 23));
    yard1.addPet(new Dog("Apollo", 12));
    Yard yard2(yard1);
    vector<Pet *> pets;
    pets = yard2.getPetWithCondition(weightUnderThirty);
    ASSERT_EQ("Kitty", pets[0]->name());
    ASSERT_NEAR(3, pets[0]->weight(), DELTA);
    ASSERT_EQ("Money", pets[1]->name());
    ASSERT_NEAR(23, pets[1]->weight(), DELTA);
    ASSERT_EQ("Apollo", pets[2]->name());
    ASSERT_NEAR(12, pets[2]->weight(), DELTA);
}

TEST_F(YardTest, CopyAssignment) {
    Yard yard1;
    yard1.addPet(new Cat("Kitty", 3));
    yard1.addPet(new Dog("Money", 23));
    yard1.addPet(new Dog("Apollo", 12));
    Yard yard2 = yard1;
    vector<Pet *> pets;
    pets = yard2.getPetWithCondition(weightUnderThirty);
    ASSERT_EQ("Kitty", pets[0]->name());
    ASSERT_NEAR(3, pets[0]->weight(), DELTA);
    ASSERT_EQ("Money", pets[1]->name());
    ASSERT_NEAR(23, pets[1]->weight(), DELTA);
    ASSERT_EQ("Apollo", pets[2]->name());
    ASSERT_NEAR(12, pets[2]->weight(), DELTA);
}

TEST_F(YardTest, Deconstructor) {
    Yard yard;
    yard.addPet(new Cat("Kitty", 3));
    yard.addPet(new Dog("Money", 23));
    yard.addPet(new Dog("Apollo", 12));
}