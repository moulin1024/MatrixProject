#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
public:
    virtual ~Matrix() = default;
    virtual void solves() const = 0;
    virtual void times() const = 0;
    virtual void print() const = 0;
};

#endif // MATRIX_H