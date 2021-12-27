#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <algorithm>

#include "term.h"

class Polynomial {
public:
    Polynomial() {}

    Polynomial(std::vector<Term> terms, int degree) {
        _degree = degree;
        _terms = terms;

        std::vector<int> book(degree + 1, 0);
        for(int i = 0; i < terms.size(); i++) {
            if(book[terms[i].exponent()] == 0) {
                book[terms[i].exponent()]++;
            } else {
                throw std::string("undefined");
            }
        }

        std::stable_sort(_terms.begin(), _terms.end(), Polynomial::orderByExponent);

        for(int i = 0; i <= degree; i++) {
            if(book[i] == 0) {
                Term newTerm(0, i);
                _terms.push_back(newTerm);
            }
        }

        std::stable_sort(_terms.begin(), _terms.end(), Polynomial::orderByExponent);
    }

    // get a term by exponent
    // If the term does not exist, return the term (0, exponent)
    Term term(int exponent) const {
        for(int i = 0; i < _terms.size(); i++) {
            if(_terms[i].exponent() == exponent) {
                return _terms[i];
            }
        }

        return Term(0, exponent);
    }

    // get the degree
    int degree() const {
        return _degree;
    }

    // add two polynomials
    Polynomial operator+ (const Polynomial & q) const {
        std::vector<Term> newTerms;
        int newDegree = std::max(_degree, q._degree);
        newTerms.reserve(newDegree);

        Polynomial polynomial1(_terms, newDegree);
        Polynomial polynomial2(q._terms, newDegree);

        for(int i = 0; i <= newDegree; i++) {
            Term sumTerm = polynomial1.term(i) + polynomial2.term(i);
            newTerms.push_back(sumTerm);
        }

        while(newTerms.size() > 1 && newTerms.back().coefficient() == 0) {
            newTerms.pop_back();
            newDegree--;
        }

        return Polynomial(newTerms, newDegree);
    }

    // multiply by a term
    Polynomial operator* (Term t) const {
        std::vector<Term> newTerms;
        newTerms.reserve(_degree);

        for(int i = 0; i <= _degree; i++) {
            Term productTerm = t * term(i);
            newTerms.push_back(productTerm);
        }

        return Polynomial(newTerms, _degree + t.exponent());
    }

    // multiply by another Polynomial
    Polynomial operator* (const Polynomial & q) const {
        int newDegree = _degree + q._degree;
        std::vector<Term> newTerms;
        newTerms.reserve(newDegree);

        for(int i = 0; i <= newDegree; i++) {
            newTerms.push_back(Term(0, i));
        }

        for(int i = 0; i <= _degree; i++) {
            for(int j = 0; j <= q._degree; j++) {
                newTerms[i + j] = newTerms[i + j] + term(i) * q.term(j);
            }
        }

        return Polynomial(newTerms, newDegree);
    }

private:
    std::vector<Term> _terms;
    int _degree;

    static bool orderByExponent(const Term& a, const Term& b) {
        return a.exponent() < b.exponent();
    }
};

#endif