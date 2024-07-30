#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include "Matrix.h"

class SparseMatrix : public Matrix {
public:
    void solves() const override;
    void times() const override;
    void print() const override;
};

#endif // SPARSEMATRIX_H
