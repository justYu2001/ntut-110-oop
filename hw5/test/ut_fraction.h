#include "../src/fraction.h"

class FractionTest : public::testing::Test {
protected:
    Fraction fraction, negativeFraction, fraction1, fraction2;
    void SetUp() override {
        fraction = Fraction(1, 3);
        negativeFraction = Fraction(-1, 3);
        fraction1 = Fraction(3, 2);
        fraction2 = Fraction(1, 2);
    }
};

TEST(Fraction, DefaultConstructor) {
    Fraction fraction;
    ASSERT_EQ('+', fraction.sign());
    ASSERT_EQ(0, fraction.numerator());
    ASSERT_EQ(1, fraction.denominator());
}

TEST(Fraction, OneParameterConstructor1) {
    Fraction fraction(3);
    ASSERT_EQ('+', fraction.sign());
    ASSERT_EQ(3, fraction.numerator());
    ASSERT_EQ(1, fraction.denominator());
}

TEST(Fraction, OneParameterConstructor2) {
    Fraction fraction(-3);
    ASSERT_EQ('-', fraction.sign());
    ASSERT_EQ(3, fraction.numerator());
    ASSERT_EQ(1, fraction.denominator());
}

TEST_F(FractionTest, TwoParameterConstructor1) {
    ASSERT_EQ('-', negativeFraction.sign());
    ASSERT_EQ(1, negativeFraction.numerator());
    ASSERT_EQ(3, negativeFraction.denominator());
}

TEST(Fraction, TwoParameterConstructor2) {
    Fraction fraction(2, 4);
    ASSERT_EQ('+', fraction.sign());
    ASSERT_EQ(1, fraction.numerator());
    ASSERT_EQ(2, fraction.denominator());
}

TEST(Fraction, TwoParameterConstructor3) {
    ASSERT_THROW(Fraction fraction(2, 0), std::string);
}

TEST_F(FractionTest, ToString1) {
    ASSERT_EQ(fraction.toString(), "1/3");
}

TEST(Fraction, ToString2) {
    Fraction fraction(-3, 1);
    ASSERT_EQ(fraction.toString(), "-3");
}

TEST_F(FractionTest, ToString3) {
    ASSERT_EQ(negativeFraction.toString(), "-1/3");
}

TEST_F(FractionTest, Add) {
    Fraction result = fraction1 + fraction2;
    ASSERT_EQ(result.toString(), "2");
}

TEST_F(FractionTest, Minus) {
    Fraction result = fraction1 - fraction2;
    ASSERT_EQ(result.toString(), "1");
}

TEST_F(FractionTest, Divide) {
    Fraction result = fraction1 / fraction2;
    ASSERT_EQ(result.toString(), "3");
}

TEST_F(FractionTest, Numerator) {
    ASSERT_EQ(fraction.numerator(), 1);
}

TEST_F(FractionTest, Denominator) {
    ASSERT_EQ(fraction.denominator(), 3);
}

TEST_F(FractionTest, Sign) {
    ASSERT_EQ(fraction.sign(), '+');
}