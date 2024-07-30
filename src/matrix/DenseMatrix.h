// src/matrix/DenseMatrix.h
#ifndef DENSEMATRIX_H
#define DENSEMATRIX_H

#include "Matrix.h"
#include <vector>

class DenseMatrix : public Matrix {
public:
    DenseMatrix(int rows, int cols);
    int getNumRows() const override;
    int getNumCols() const override;
    double getValue(int row, int col) const override;
    void setValue(int row, int col, double value) override;
    void print() const;

private:
    int rows, cols;
    std::vector<std::vector<double>> data; // stores matrix data
};

#endif // DENSEMATRIX_H
