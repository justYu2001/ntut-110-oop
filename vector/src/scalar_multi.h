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