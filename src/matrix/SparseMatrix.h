// src/matrix/SparseMatrix.h
#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include "Matrix.h"
#include <vector>

class SparseMatrix : public Matrix {
public:
    SparseMatrix(int rows, int cols, const std::vector<double>& values, const std::vector<int>& col_indices, const std::vector<int>& row_ptr);
    int getNumRows() const override;
    int getNumCols() const override;
    double getValue(int row, int col) const override;
    void setValue(int row, int col, double value) override;
    void print() const;

private:
    int rows, cols;
    std::vector<double> values;       // Non-zero values
    std::vector<int> col_indices;     // Column indices of the non-zero values
    std::vector<int> row_ptr;         // Row pointers
};

#endif // SPARSEMATRIX_H
