#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include "Matrix.h"
#include <vector>

class SparseMatrix : public Matrix {
public:
    SparseMatrix(int rows, int cols);
    SparseMatrix(int rows, int cols, const std::vector<double>& values, const std::vector<int>& col_indices, const std::vector<int>& row_ptr);
    void solves() const override;
    void times() const override;
    void print() const override;

private:
    int rows, cols;
    std::vector<double> values;       // Non-zero values
    std::vector<int> col_indices;     // Column indices of the non-zero values
    std::vector<int> row_ptr;         // Row pointers
};

#endif // SPARSEMATRIX_H
