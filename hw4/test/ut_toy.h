#include "../src/toy.h"

#include <string>

using std::string;

// add your test here

TEST(Toy, ToyGetName) {
    string name = "ball";
    Toy toy(name);
    EXPECT_EQ("ball", toy.getName());
}