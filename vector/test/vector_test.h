#include "../src/math_vector.h"

TEST(Vector, MathVector) {
    int dim = 2;
    double v[2] = {3, 4};
    MathVector mv(dim, v);
    ASSERT_NEAR(5, mv.length(), 0.01);
}

TEST(Vector, MathVectorIndex) {
    int dim = 2;
    double v[2] = {3, 4};
    MathVector mv(dim, v);
    ASSERT_NEAR(3, mv.at(0), 0.01);
    ASSERT_NEAR(4, mv.at(1), 0.01);
}

TEST(Vector, MathVectorSet) {
    int dim = 2;
    double v[2] = {3, 4};
    MathVector mv(dim, v);
    mv.setIndex(0, 4);
    mv.setIndex(1, 3);
    ASSERT_NEAR(4, mv.at(0), 0.01);
    ASSERT_NEAR(3, mv.at(1), 0.01);
}

TEST(Vector, MathVectorSetException) {
    int dim = 2;
    double v[2] = {3, 4};
    MathVector mv(dim, v);
    ASSERT_THROW(mv.setIndex(2, 4), std::string);
}

TEST(Vector, AddMathVector) {
    double v[2] = {3, 4};
    double u[2] = {5, 6};
    int dim = 2;
    MathVector mv1(dim, u);
    MathVector mv2(dim, v);

    MathVector result = mv1 + mv2;
    ASSERT_NEAR(8.0, result.at(0), 0.001);
    ASSERT_NEAR(10.0, result.at(1), 0.001);
    ASSERT_EQ(2, result.dimension());
}