// src/solvers/SolverFactory.cpp
#include "SolverFactory.h"
#include "GaussSeidelSolver.h"
#include "RedBlackGaussSeidelSolver.h"
#include <stdexcept>

std::unique_ptr<SolverStrategy> SolverFactory::createSolver(const std::string& solverType) {
    if (solverType == "GaussSeidel") {
        return std::make_unique<GaussSeidelSolver>();
    } else if (solverType == "RedBlackGaussSeidel") {
        return std::make_unique<RedBlackGaussSeidelSolver>();
    } else {
        throw std::invalid_argument("Unknown solver type: " + solverType);
    }
}
