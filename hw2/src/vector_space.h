double *add(double *vector1, int dimension1, double *vector2, int dimension2) {
    if(dimension1 <= 0 || dimension2 <= 0) {
        throw std::string("undefined.");
    }

    if(dimension1 != dimension2) {
        throw std::string("undefined.");
    }

    double *result = new double[dimension1];
    for(int i = 0; i < dimension1; i++) {
        result[i] = vector1[i] + vector2[i];
    }

    return result;
}

double *scale(double *vector, int dimension, double scalar) {
    if(dimension <= 0) {
        throw std::string("undefined.");
    }

    double *result = new double[dimension];

    for(int i = 0; i < dimension; i++) {
        result[i] = vector[i] * scalar;
    }

    return result;
}