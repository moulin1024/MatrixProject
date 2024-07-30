#include "Operation.h"
#include <random>
#include <iostream>

SparseMatrix Operation::toSparseMatrix(const DenseMatrix& denseMatrix) {
    int rows = denseMatrix.getNumRows();
    int cols = denseMatrix.getNumCols();
    std::vector<double> values;
    std::vector<int> col_indices;
    std::vector<int> row_ptr = {0};

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            double value = denseMatrix.getValue(i, j);
            if (value != 0.0) {
                values.push_back(value);
                col_indices.push_back(j);
            }
        }
        row_ptr.push_back(values.size());
    }

    return SparseMatrix(rows, cols, values, col_indices, row_ptr);
}

void Operation::nonSingularInit(DenseMatrix& matrix, int x) {
    int rows = matrix.getNumRows();
    int cols = matrix.getNumCols();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist_row(0, rows - 1);
    std::uniform_int_distribution<> dist_col(0, cols - 1);
    std::uniform_real_distribution<> dist_val(1.0, 10.0);  // Adjust range as needed

    for (int i = 0; i < x; ++i) {
        int row = dist_row(gen);
        int col = dist_col(gen);
        double value = dist_val(gen);
        matrix.setValue(row, col, value);
    }

    // Ensure diagonal dominance
    for (int i = 0; i < rows; ++i) {
        double sum = 0.0;
        for (int j = 0; j < cols; ++j) {
            if (i != j) {
                sum += std::abs(matrix.getValue(i, j));
            }
        }
        matrix.setValue(i, i, sum + dist_val(gen));  // Ensure diagonal element is greater than the sum of non-diagonal elements
    }
}

std::vector<double> Operation::randomInitVector(int size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist_val(1.0, 10.0);  // Adjust range as needed

    std::vector<double> vec(size);
    for (int i = 0; i < size; ++i) {
        vec[i] = dist_val(gen);
    }
    return vec;
}
