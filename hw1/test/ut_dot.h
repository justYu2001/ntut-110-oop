#include "../src/dot.h"

// A single test case has the following form:

TEST(Dot, TwoDimDotTwoDim) {
    double u[2] = {2, 3};
    int dim_u = 2;
    double v[2] = {3, 4};
    int dim_v = 2;
    double result = dot(u, dim_u, v, dim_v);
    ASSERT_NEAR(18.0, result, 0.01);
}

TEST(Dot, TwoDimDotTwoDim2) {
    double u[2] = {5, 8};
    int dim_u = 2;
    double v[2] = {5, 5};
    int dim_v = 2;
    double result = dot(u, dim_u, v, dim_v);
    ASSERT_NEAR(65.0, result, 0.01);
}

TEST(Dot, ThreeDimDotThreeDim) {
    double u[3] = {1, 3, -5};
    int dim_u = 3;
    double v[3] = {4, -2, -1};
    int dim_v = 3;
    double result = dot(u, dim_u, v, dim_v);
    ASSERT_NEAR(3.0, result, 0.01);
}

TEST(Dot, ThreeDimDotThreeDim2) {
    double u[3] = {4, 5, 6};
    int dim_u = 3;
    double v[3] = {1, 2, 3};
    int dim_v = 3;
    double result = dot(u, dim_u, v, dim_v);
    ASSERT_NEAR(32.0, result, 0.01);
}

TEST(Dot, ThreeDimDotFourDim) {
    double u[3] = {2, 3, 1};
    int dim_u = 3;
    double v[4] = {3, 4, 5, 6};
    int dim_v = 4;
    ASSERT_THROW(dot(u, dim_u, v, dim_v), std::string);
}

TEST(Dot, ThreeDimDotFourDim2) {
    double u[3] = {5, 8, 9};
    int dim_u = 3;
    double v[4] = {1, 2, 3, 4};
    int dim_v = 4;
    ASSERT_THROW(dot(u, dim_u, v, dim_v), std::string);
}

TEST(Dot, DotException) {
    double u[3] = {4, 0, 3};
    int dim_u = -1;
    double v[4] = {5, 8, 1, 2};
    int dim_v = 4;
    ASSERT_THROW(dot(u, dim_u, v, dim_v), std::string);
}

TEST(Dot, DotException2) {
    double u[3] = {2, 3, 1};
    int dim_u = 3;
    double v[4] = {3, 4, 5, 6};
    int dim_v = -1;
    ASSERT_THROW(dot(u, dim_u, v, dim_v), std::string);
}
