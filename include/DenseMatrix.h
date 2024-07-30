#ifndef DENSEMATRIX_H
#define DENSEMATRIX_H

#include "Matrix.h"
#include <vector>

class SparseMatrix; // Forward declaration

class DenseMatrix : public Matrix {
public:
    DenseMatrix(int rows, int cols);
    void solves() const override;
    void times() const override;
    void print() const override;
    void nonSingularInit(int x);
    SparseMatrix toCSR() const;  // Method to convert to CSR format

private:
    int rows, cols;
    std::vector<std::vector<double>> data; // stores matrix data
};

#endif // DENSEMATRIX_H
