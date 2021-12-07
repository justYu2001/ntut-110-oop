#include <string>
#include "gcd.h"

using std::string;
using std::to_string;

class Fraction {
public:

  // default value is +0/1
  // i.e., _sign='+', _numerator=0, _denominator=1
  Fraction() {
      _sign = '+';
      _numerator = 0;
      _denominator = 1;
  }

  // default value is an integer (denominator=1)
  // e.g., Fraction f(-3) has its _sign='-', _numerator=3, _denominator=1
  Fraction(int num) {
      _sign = num >= 0 ? '+' : '-';
      _numerator = abs(num);
      _denominator = 1; 
  }

  // hint: use gcd
  // throw exception when the denominator is 0
  Fraction(int numerator, int denominator) {
      if(denominator == 0) {
          throw string("undefined");
      }

      int gcdOfNumeratorAndDenominator = gcd(numerator, denominator);
      _numerator = abs(numerator / gcdOfNumeratorAndDenominator);
      _denominator = abs(denominator / gcdOfNumeratorAndDenominator);

      if(numerator < 0 || denominator < 0) {
          _sign = '-';
      } else {
          _sign = '+';
      }
  }

  // get the numerator of the fraction
  int numerator() const {
      return _numerator;
  }

  // get the denominator of the fraction
  int denominator() const {
      return _denominator;
  }

  // get positive or negative sign of the fraction
  char sign() const {
      return _sign;
  }

  // display the fraction by string
  std::string toString() const {
      string numeratorString = to_string(_numerator);
      string denominatorString = to_string(_denominator);

      if(_numerator == 0) {
          return "0";
      }

      if(_denominator == 1) {
          return _sign == '+' ? numeratorString : "-" + numeratorString;
      }

      string fractionString = numeratorString + "/" + denominatorString;
      return _sign == '+' ? fractionString : "-" + fractionString;
  }

  // addition of two Fractions
  Fraction operator + (Fraction const & f) const {
      int newNumerator = _numerator * f._denominator + f._numerator * _denominator;
      int newDenominator = _denominator * f._denominator;
      return Fraction(newNumerator, newDenominator);
  }

  // subtraction of two Fractions
  Fraction operator - (Fraction const & f) const {
      int newNumerator = _numerator * f._denominator - f._numerator * _denominator;
      int newDenominator = _denominator * f._denominator;
      return Fraction(newNumerator, newDenominator);
  }

  // division of two Fractions
  Fraction operator / (Fraction const & f) const {
      int newNumerator = _numerator * f._denominator;
      int newDenominator = _denominator * f._numerator;
      return Fraction(newNumerator, newDenominator);
  }

private:
  // both numerator and denominator should be positive
  int _numerator;
  int _denominator;
  char _sign;

  int abs(int number) {
      return number >= 0 ? number : -number;
  }
};
