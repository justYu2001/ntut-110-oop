#include <cmath>

double length(double v[], int dim) {
    double sumOfSquare = 0;
    for(int i = 0; i < dim; i++){
        sumOfSquare += v[i] * v[i];
    }
    return sqrt(sumOfSquare);
}