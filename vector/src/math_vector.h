#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H

#include <cmath>

class MathVector {
private:
    int _dim;
    double* _vec;

    void init(int dim, double *v) {
        this->_dim = dim;
        this->_vec = new double[this->_dim];
        for(int i = 0; i < this->_dim; i++) {
            this->_vec[i] = v[i];
        }

    }
public:
    MathVector() {

    }

    MathVector(int dim, double* v) {
        if(dim < 0) {
            throw std::string("undefined.");
        }
        init(dim, v);
    }

    // copy constructor
    MathVector(const MathVector& v) {
        init(v._dim, v._vec);
    }


    // deconstructor
    ~MathVector() {
        delete [] _vec;
    }

    // Copy assignment
    // MathVector& operator=(const MathVector &v) {
    //     init(v._dim, v._vec);
    // }

    // Getter

    double length() {
        double sumOfSquare = 0;
        for(int i = 0; i < _dim; i++){
            sumOfSquare += _vec[i] * _vec[i];
        }
        return sqrt(sumOfSquare);
    }

    double at(int index) const {
        return _vec[index];
    }

    int dimension() const {
        return _dim;
    }

    // Setter

    void setIndex(int index, double input) {
        if(index >= _dim) {
            throw std::string("undefined.");
        }
        _vec[index] = input;
    }

    MathVector operator+(const MathVector &v) {
        double *w = new double[this->dimension()];
        for(int i = 0; i < this->dimension(); i++) {
            w[i] = this->at(i) + v.at(i);
        }
        return MathVector(this->dimension(), w);
    }
};


#endif