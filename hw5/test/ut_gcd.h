TEST(GCD, positive) {
    int a = 5;
    int b = 3;
    int result = gcd(a, b);
    ASSERT_EQ(1, result);
}

TEST(GCD, negative) {
    int a = 5;
    int b = -10;
    int result = gcd(a, b);
    ASSERT_EQ(5, result);
}