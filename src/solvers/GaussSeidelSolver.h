// src/solvers/GaussSeidelSolver.h
#ifndef GAUSSSEIDELSOLVER_H
#define GAUSSSEIDELSOLVER_H

#include "SolverStrategy.h"
#include <vector>

class GaussSeidelSolver : public SolverStrategy {
public:
    std::vector<double> solve(const Matrix& A, const std::vector<double>& b, int max_iter, double tol) const override;
};

#endif // GAUSSSEIDELSOLVER_H
