#include "../src/scalar_multi.h"

TEST(Vector, Scalar) {
    double v[2] = { 3, 4 };
    int dim = 2;
    double *result = scalarMutiple(v, dim, 3.0);
    ASSERT_NEAR(9.0, result[0], 0.001);
    ASSERT_NEAR(12.0, result[1], 0.001);
}

TEST(Vector, ScalarException) {
    double v[2] = { 3, 4 };
    int dim = -1;
    double a = 3.0;
    ASSERT_THROW(scalarMutiple(v, dim, a), std::string);
}