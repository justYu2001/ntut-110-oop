#include <iostream>
#include "length.h"
using namespace std;

int main() {
    double v[2] = {3, 4};
    int len = 2;
    double result = length(v, len);
    cout << result << endl;
    return 0;
}