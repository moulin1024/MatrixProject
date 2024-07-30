// src/solvers/RedBlackGaussSeidelSolver.h
#ifndef REDBLACKGAUSSSEIDELSOLVER_H
#define REDBLACKGAUSSSEIDELSOLVER_H

#include "SolverStrategy.h"
#include <vector>

class RedBlackGaussSeidelSolver : public SolverStrategy {
public:
    std::vector<double> solve(const Matrix& A, const std::vector<double>& b, int max_iter, double tol) const override;
};

#endif // REDBLACKGAUSSSEIDELSOLVER_H
