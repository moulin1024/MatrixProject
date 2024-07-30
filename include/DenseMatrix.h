#ifndef DENSEMATRIX_H
#define DENSEMATRIX_H

#include "Matrix.h"

class DenseMatrix : public Matrix {
public:
    void solves() const override;
    void times() const override;
    void print() const override;
};

#endif // DENSEMATRIX_H
