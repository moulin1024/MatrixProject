// src/solvers/SolverFactory.h
#ifndef SOLVERFACTORY_H
#define SOLVERFACTORY_H

#include "SolverStrategy.h"
#include <string>
#include <memory>

class SolverFactory {
public:
    static std::unique_ptr<SolverStrategy> createSolver(const std::string& solverType);
};

#endif // SOLVERFACTORY_H
