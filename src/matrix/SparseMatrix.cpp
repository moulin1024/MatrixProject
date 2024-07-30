// src/matrix/SparseMatrix.cpp
#include "SparseMatrix.h"
#include <iostream>
#include <stdexcept>

SparseMatrix::SparseMatrix(int rows, int cols, const std::vector<double>& values, const std::vector<int>& col_indices, const std::vector<int>& row_ptr)
    : rows(rows), cols(cols), values(values), col_indices(col_indices), row_ptr(row_ptr) {
    if (row_ptr.size() != rows + 1) {
        throw std::invalid_argument("Row pointer size must be equal to number of rows plus one.");
    }
}

int SparseMatrix::getNumRows() const {
    return rows;
}

int SparseMatrix::getNumCols() const {
    return cols;
}

double SparseMatrix::getValue(int row, int col) const {
    for (int i = row_ptr[row]; i < row_ptr[row + 1]; ++i) {
        if (col_indices[i] == col) {
            return values[i];
        }
    }
    return 0.0;
}

void SparseMatrix::setValue(int row, int col, double value) {
    // This is a simplified version and does not actually modify the CSR structure
    for (int i = row_ptr[row]; i < row_ptr[row + 1]; ++i) {
        if (col_indices[i] == col) {
            values[i] = value;
            return;
        }
    }
    throw std::runtime_error("Setting new non-zero values not implemented.");
}

void SparseMatrix::print() const {
    std::cout << "Sparse Matrix (CSR format):" << std::endl;
    std::cout << "Values: ";
    for (const auto& val : values) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Column indices: ";
    for (const auto& idx : col_indices) {
        std::cout << idx << " ";
    }
    std::cout << std::endl;

    std::cout << "Row pointers: ";
    for (const auto& ptr : row_ptr) {
        std::cout << ptr << " ";
    }
    std::cout << std::endl;
}
