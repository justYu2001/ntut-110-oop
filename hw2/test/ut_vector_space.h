#include "../src/vector_space.h"

const double DELTA = 0.001;

// TEST example below.
// Using 'EXPECT' instead of 'ASSERT' here is because if 'ASSERT' fails,
// the delete statement will NOT be executed, which causes memory leak.

TEST(VectorTest, add_Test1) {
    double u[3] = {2, 0, 4};
    double v[3] = {1, 5, 6};

    double * result = add(u, 3, v, 3);

    EXPECT_NEAR(3.0, result[0], DELTA);
    EXPECT_NEAR(5.0, result[1], DELTA);
    EXPECT_NEAR(10.0, result[2], DELTA);

    delete [] result;
}

TEST(VectorTest, add_test1) {
    double u[2] = {2.3, 0.1};
    double v[2] = {1.6, 5.7};

    double * result = add(u, 2, v, 2);

    EXPECT_NEAR(3.9, result[0], DELTA);
    EXPECT_NEAR(5.8, result[1], DELTA);

    delete [] result;   // heap allocation in 'add'
}

TEST(VectorTest, add_exception1) {
    double u[2] = {2.3, 0.1};
    double v[3] = {1.6, 5.7, 3};

    ASSERT_THROW(add(u, 2, v, 3), std::string);
}

TEST(VectorTest, add_exception2) {
    double u[2] = {2.3, 0.1};
    double v[3] = {1.6, 5.7, 3};

    ASSERT_THROW(add(u, 0, v, 3), std::string);
}

TEST(VectorTest, scale_test1) {
    double u[3] = {5, 7, 9};

    double * result = scale(u, 3, 2);

    EXPECT_NEAR(10.0, result[0], DELTA);
    EXPECT_NEAR(14.0, result[1], DELTA);
    EXPECT_NEAR(18.0, result[2], DELTA);

    delete [] result;  // heap allocation in 'scale'
}

TEST(VectorTest, scale_test2) {
    double u[2] = {2.3, 9.7};

    double * result = scale(u, 2, 1.1);

    EXPECT_NEAR(2.53, result[0], DELTA);
    EXPECT_NEAR(10.67, result[1], DELTA);

    delete [] result;  // heap allocation in 'scale'
}

TEST(VectorTest, scale_exception) {
    double u[2] = {2.3, 9.7};

    ASSERT_THROW(scale(u, 0, 1.1), std::string);
}
