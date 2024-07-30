// src/matrix/DenseMatrix.cpp
#include "DenseMatrix.h"
#include <iostream>
#include <iomanip>
#include <random>

DenseMatrix::DenseMatrix(int rows, int cols) : rows(rows), cols(cols), data(rows, std::vector<double>(cols, 0.0)) {
    // Constructor implementation initializes all elements to 0.0
}

int DenseMatrix::getNumRows() const {
    return rows;
}

int DenseMatrix::getNumCols() const {
    return cols;
}

double DenseMatrix::getValue(int row, int col) const {
    return data[row][col];
}

void DenseMatrix::setValue(int row, int col, double value) {
    data[row][col] = value;
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
