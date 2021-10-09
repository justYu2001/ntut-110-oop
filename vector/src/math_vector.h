#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H

#include <cmath>

class MathVector {
private:
    int _dim;
    double* _vec;
public:
    MathVector() {

    }

    MathVector(int dim, double* v) {
        _dim = dim;
        _vec = new double[dim];
        for(int i = 0; i < dim; i++) {
            _vec[i] = v[i];
        }
    }

    double length() {
        double sumOfSquare = 0;
        for(int i = 0; i < _dim; i++){
            sumOfSquare += _vec[i] * _vec[i];
        }
        return sqrt(sumOfSquare);
    }

    double at(int index) {
        return _vec[index];
    }

    void setIndex(int index, double input) {
        if(index >= _dim) {
            throw std::string("undefined.");
        }
        _vec[index] = input;
    }
};


#endif