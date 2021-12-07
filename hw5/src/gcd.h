// return the (positive) greatest common divisor of two integers
// a, b may be positive or negative
int gcd(int a, int b) {
    return a % b != 0 ? gcd(b, a % b) : b;
}
