#include "SparseMatrix.h"
#include <iostream>

SparseMatrix::SparseMatrix(int rows, int cols) : rows(rows), cols(cols), row_ptr(rows + 1, 0) {
    // Constructor implementation, row_ptr is initialized with size rows + 1, filled with 0
}

SparseMatrix::SparseMatrix(int rows, int cols, const std::vector<double>& values, const std::vector<int>& col_indices, const std::vector<int>& row_ptr)
    : rows(rows), cols(cols), values(values), col_indices(col_indices), row_ptr(row_ptr) {
    // Constructor implementation
}

void SparseMatrix::solves() const {
    std::cout << "Solving system with Sparse Matrix (CSR) implementation." << std::endl;
}

void SparseMatrix::times() const {
    std::cout << "Multiplying matrices with Sparse Matrix (CSR) implementation." << std::endl;
}

void SparseMatrix::print() const {
    std::cout << "Printing Sparse Matrix (CSR format):" << std::endl;
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
