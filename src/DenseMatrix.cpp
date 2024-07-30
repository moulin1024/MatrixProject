#include "DenseMatrix.h"
#include "SparseMatrix.h"
#include <iostream>
#include <random>
#include <iomanip>
#include <cmath> // for std::abs

DenseMatrix::DenseMatrix(int rows, int cols) : rows(rows), cols(cols), data(rows, std::vector<double>(cols, 0.0)) {
    // Constructor implementation initializes all elements to 0.0
}

void DenseMatrix::solves() const {
    std::cout << "Solving system with Dense Matrix implementation." << std::endl;
}

void DenseMatrix::times() const {
    std::cout << "Multiplying matrices with Dense Matrix implementation." << std::endl;
}

void DenseMatrix::print() const {
    std::cout << "Dense Matrix:" << std::endl;
    for (const auto& row : data) {
        for (const auto& val : row) {
            std::cout << std::setw(10) << val << " ";
        }
        std::cout << std::endl;
    }
}

void DenseMatrix::nonSingularInit(int x) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist_row(0, rows - 1);
    std::uniform_int_distribution<> dist_col(0, cols - 1);
    std::uniform_real_distribution<> dist_val(1.0, 10.0);  // Adjust range as needed

    for (int i = 0; i < x; ++i) {
        int row = dist_row(gen);
        int col = dist_col(gen);
        double value = dist_val(gen);
        data[row][col] = value;
    }

    // Ensure diagonal dominance
    for (int i = 0; i < rows; ++i) {
        double sum = 0.0;
        for (int j = 0; j < cols; ++j) {
            if (i != j) {
                sum += std::abs(data[i][j]);
            }
        }
        data[i][i] = sum + dist_val(gen);  // Ensure diagonal element is greater than the sum of non-diagonal elements
    }
}

SparseMatrix DenseMatrix::toCSR() const {
    std::vector<double> values;
    std::vector<int> col_indices;
    std::vector<int> row_ptr;
    const double epsilon = 1e-9; // Define a small tolerance value

    row_ptr.push_back(0);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (std::abs(data[i][j]) > epsilon) { // Use tolerance for comparison
                values.push_back(data[i][j]);
                col_indices.push_back(j);
            }
        }
        row_ptr.push_back(values.size());
    }

    return SparseMatrix(rows, cols, values, col_indices, row_ptr);
}
