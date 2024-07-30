// src/matrix/Matrix.h
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix {
public:
    virtual ~Matrix() = default;
    virtual int getNumRows() const = 0;
    virtual int getNumCols() const = 0;
    virtual double getValue(int row, int col) const = 0;
    virtual void setValue(int row, int col, double value) = 0;
};

#endif // MATRIX_H
