// src/main.cpp
#include "Operation.h"
#include "SolverFactory.h"
#include <iostream>
#include <vector>

int main() {
    // Define the size of the matrix
    int size = 5000;

    // Create a DenseMatrix object
    DenseMatrix denseA(size, size);
    Operation::nonSingularInit(denseA, 100000); // Initialize with random non-singular values for the sake of the example

    // Randomly initialize the right-hand side vector b
    std::vector<double> b = Operation::randomInitVector(size);

    // Convert the dense matrix to a sparse matrix
    SparseMatrix sparseA = Operation::toSparseMatrix(denseA);

    // Create solver strategy objects using the factory
    std::unique_ptr<SolverStrategy> rbgsSolver = SolverFactory::createSolver("RedBlackGaussSeidel");

    // Solve the linear system Ax = b using Red-Black Gauss-Seidel method on the sparse matrix
    std::vector<double> x_rbgs_sparse = rbgsSolver->solve(sparseA, b, 1000, 1e-8);

    return 0;
}
