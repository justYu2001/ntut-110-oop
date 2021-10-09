#include "../src/length.h"

TEST(Vector, Length) {
    double v[2] = {3, 4};
    int len = 2;
    double result = length(v, len);
    ASSERT_NEAR(5.0, result, 0.001);
}