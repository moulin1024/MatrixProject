#ifndef OPERATION_H
#define OPERATION_H

#include "DenseMatrix.h"
#include "SparseMatrix.h"
#include <vector>

class Operation {
public:
    static SparseMatrix toSparseMatrix(const DenseMatrix& denseMatrix);
    static void nonSingularInit(DenseMatrix& matrix, int x);
    static std::vector<double> randomInitVector(int size); // New method declaration
};

#endif // OPERATION_H
