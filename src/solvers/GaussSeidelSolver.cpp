// src/solvers/GaussSeidelSolver.cpp
#include "GaussSeidelSolver.h"
#include "DenseMatrix.h"
#include "SparseMatrix.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

std::vector<double> GaussSeidelSolver::solve(const Matrix& A, const std::vector<double>& b, int max_iter, double tol) const {
    int rows = A.getNumRows();
    int cols = A.getNumCols();

    if (rows != cols) {
        throw std::invalid_argument("Matrix must be square to solve linear system.");
    }
    if (b.size() != rows) {
        throw std::invalid_argument("Dimension mismatch between matrix and vector.");
    }

    std::vector<double> x(rows, 0.0);

    for (int iter = 0; iter < max_iter; ++iter) {
        for (int i = 0; i < rows; ++i) {
            double sum = 0.0;
            for (int j = 0; j < cols; ++j) {
                if (j != i) {
                    sum += A.getValue(i, j) * x[j];
                }
            }
            x[i] = (b[i] - sum) / A.getValue(i, i);
        }

        // Check for convergence
        double max_diff = 0.0;
        for (int i = 0; i < rows; ++i) {
            double Ax_i = 0.0;
            for (int j = 0; j < cols; ++j) {
                Ax_i += A.getValue(i, j) * x[j];
            }
            max_diff = std::max(max_diff, std::fabs(b[i] - Ax_i));
        }
        if (max_diff < tol) {
            break;
        }
    }

    return x;
}
