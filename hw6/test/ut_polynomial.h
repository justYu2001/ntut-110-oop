#include "../src/polynomial.h"

class PolynomialTest : public::testing::Test {
protected:
    Polynomial polynomial1, polynomial2;
    void SetUp() override {
        std::vector<Term> terms(3);
        terms[0] = Term(-3, 2);
        terms[1] = Term(3, 0);
        terms[2] = Term(6, 3);
        polynomial1 = Polynomial(terms, 3);

        std::vector<Term> terms2(4);
        terms2[0] = Term(3, 2);
        terms2[1] = Term(1, 0);
        terms2[2] = Term(1, 1);
        terms2[3] = Term(4, 3);
        polynomial2 = Polynomial(terms2, 3);
    }
};

TEST(Polynomial, ConstructorExcpetion) {
    std::vector<Term> terms(4);
    terms[0] = Term(-3, 2);
    terms[1] = Term(3, 0);
    terms[2] = Term(6, 3);
    terms[3] = Term(0, 3);
    ASSERT_THROW(Polynomial polynomial(terms, 3), std::string);
}

TEST_F(PolynomialTest, TermNotExist) {
    ASSERT_EQ(0, polynomial1.term(1).coefficient());
}

TEST_F(PolynomialTest, Add) {
    Polynomial result = polynomial1 + polynomial2;
    ASSERT_EQ(4, result.term(0).coefficient());
    ASSERT_EQ(1, result.term(1).coefficient());
    ASSERT_EQ(0, result.term(2).coefficient());
    ASSERT_EQ(10, result.term(3).coefficient());
}

TEST_F(PolynomialTest, MultiplyTerm) {
    Term term(2, 2);
    Polynomial result = polynomial1 * term;
    ASSERT_EQ(0, result.term(0).coefficient());
    ASSERT_EQ(0, result.term(1).coefficient());
    ASSERT_EQ(6, result.term(2).coefficient());
    ASSERT_EQ(0, result.term(3).coefficient());
    ASSERT_EQ(-6, result.term(4).coefficient());
    ASSERT_EQ(12, result.term(5).coefficient());
}

TEST_F(PolynomialTest, MultiplyPolynomial) {
    Polynomial result = polynomial1 * polynomial2;
    ASSERT_EQ(3, result.term(0).coefficient());
    ASSERT_EQ(3, result.term(1).coefficient());
    ASSERT_EQ(6, result.term(2).coefficient());
    ASSERT_EQ(15, result.term(3).coefficient());
    ASSERT_EQ(-3, result.term(4).coefficient());
    ASSERT_EQ(6, result.term(5).coefficient());
    ASSERT_EQ(24, result.term(6).coefficient());
}