// SolverStrategy.h
#ifndef SOLVERSTRATEGY_H
#define SOLVERSTRATEGY_H

#include "Matrix.h"
#include <vector>

class SolverStrategy {
public:
    virtual ~SolverStrategy() = default;
    virtual std::vector<double> solve(const Matrix& A, const std::vector<double>& b, int max_iter, double tol) const = 0;
};

#endif // SOLVERSTRATEGY_H
