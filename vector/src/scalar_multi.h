#ifndef MULTI_H
#define MULTI_H

double *scalarMutiple(double v[], int dim, double a){
    if(dim < 0) {
        throw std::string("undefined.");
    }

    double *u = new double[dim];
    for(int i = 0; i < dim; i++){
        u[i] = v[i] * a;
    }
    return u;
}

MathVector scalarMutiple(MathVector mv, double a) {
    double *u = new double[mv.dimension()];
    for(int i = 0; i < mv.dimension(); i++) {
        u[i] = mv.at(i) * a;
    }
    MathVector result(mv.dimension(), u);
    delete[] u;
    return result;
}

MathVector operator*(double a, MathVector mv) {
    return scalarMutiple(mv, a);
}

#endif