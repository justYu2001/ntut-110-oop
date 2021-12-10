#ifndef GCD_H
#define GCD_H

int abs(int number) {
      return number >= 0 ? number : -number;
}
// return the (positive) greatest common divisor of two integers
// a, b may be positive or negative
int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    return a % b != 0 ? gcd(b, a % b) : b;
}

#endif