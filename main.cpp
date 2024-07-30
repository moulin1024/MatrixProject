#include "SparseMatrix.h"
#include "DenseMatrix.h"

int main() {
    Matrix* sparse = new SparseMatrix();
    Matrix* dense = new DenseMatrix();
    
    sparse->solves();
    sparse->times();
    sparse->print();
    
    dense->solves();
    dense->times();
    dense->print();
    
    delete sparse;
    delete dense;

    return 0;
}
