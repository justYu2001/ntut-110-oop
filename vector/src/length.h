#include <cmath>
#include "math_vector.h"

double length(double v[], int dim) {
    double sumOfSquare = 0;
    for(int i = 0; i < dim; i++){
        sumOfSquare += v[i] * v[i];
    }
    return sqrt(sumOfSquare);
}

double length(MathVector v) {
    double sumOfSquare = 0;
    for(int i = 0; i < v.dimension(); i++) {
        sumOfSquare += v.at(i) * v.at(i);
    }
    return sqrt(sumOfSquare);
}