#include "SparseMatrix.h"
#include "DenseMatrix.h"

int main() {
    SparseMatrix sparse(3, 3); // Creating a 3x3 sparse matrix in CSR format
    DenseMatrix dense(5, 5);   // Creating a 3x3 dense matrix

    sparse.solves();
    sparse.times();
    sparse.print();
    
    dense.solves();
    dense.times();
    dense.print();  // This will print the dense matrix initialized with 0.0

    dense.nonSingularInit(10); // Insert 5 random elements into the dense matrix ensuring non-singularity
    dense.print();  // This will print the dense matrix with random elements ensuring non-singularity

    return 0;
}
